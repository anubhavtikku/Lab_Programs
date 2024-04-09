%{
	#include<stdio.h>
        #include<stdlib.h>
	extern FILE *yyin;
   	int yyerror();
	int yylex();
%}

%token CLASS PROGRAM FOR IF ELSE CONTINUE BREAK RETURN CALLOUT PRINT ASSIGNMENT_OPERATOR IDENTIFIER VOID TYPE HEX_LITERAL DECIMAL_LITERAL
%token CHAR_LITERAL BOOL_LITERAL STRING_LITERAL

%left TYPE
%left OR
%left AND
%left EQUAL_EQUAL NOT_EQUAL
%left GREATER_EQUAL LESS_EQUAL '<' '>'
%left '+' '-' 
%left '*' '/' '%'
%nonassoc '!'

%%

program: CLASS PROGRAM  '{' field_decl_multiple method_decl_multiple '}'
         ;
																		
field_decl_multiple:	       |field_decl_multiple field_decl_single ';' 
        ;

field_decl_single: TYPE idList 							
                   ;   

idList: IDENTIFIER id_single |IDENTIFIER '[' int_literal ']' id_single  
        ;

id_single:             |',' IDENTIFIER id_single |',' IDENTIFIER '[' int_literal ']' id_single	
        ;	

						
method_decl_multiple:		 |method_decl_single method_decl_multiple  
             ;

method_decl_single:  TYPE IDENTIFIER argumentList block |VOID IDENTIFIER argumentList block
          ;

argumentList: '(' ')' |'(' TYPE IDENTIFIER arg ')'                
    ;

arg:          | ',' TYPE IDENTIFIER arg
     ; 					

block:	'{' var_decl_multiple statement_multiple '}'
     ;

var_decl_multiple:       |var_decl_single ';' var_decl_multiple 
        ;

var_decl_single: TYPE IDENTIFIER variableList
          ;

variableList:	        |',' IDENTIFIER variableList 
         ;	

statement_multiple:           |statement_multiple statement_single 
         ;

statement_single: location ASSIGNMENT_OPERATOR expr ';' 		
		 |method_call ';' 							
		 |IF condition block else_block 		    	
		 |FOR IDENTIFIER ASSIGNMENT_OPERATOR expr ',' expr block 	
		 |RETURN return_expr ';' 					
		 |BREAK ';' 									
		 |CONTINUE ';' 								
		 |block
                 | printstmt
                 ;				

printstmt: PRINT expr ';'
       ;

else_block:               |ELSE block 
              ;

condition:  '(' expr ')'                               
            ;

return_expr:           |expr
            ;

expr: location 	|method_call |literal |arith_expr |rel_expr |equal_expr |condition_expr |'-' expr |'!' expr  				 
             | '(' expr ')'
     ;							
							
location: IDENTIFIER |IDENTIFIER '[' expr ']'
          ; 				

method_call:	method_name '('parameterList')' |CALLOUT '(' STRING_LITERAL  callout_arg ')'
	    ;

method_name:IDENTIFIER                       
	    ;

parameterList:             | expr parameter                            
              ;

parameter:                  |',' expr parameter 						
         ;

literal: int_literal |CHAR_LITERAL |BOOL_LITERAL
        ;

int_literal:DECIMAL_LITERAL |HEX_LITERAL								
;

arith_expr:expr '*' expr |expr '/' expr |expr '%' expr |expr '+' expr |expr '-' expr 							
;

rel_expr: expr '<' expr |expr '>' expr 	|expr LESS_EQUAL expr|expr GREATER_EQUAL expr 					
;

equal_expr:expr EQUAL_EQUAL expr |expr NOT_EQUAL expr 						
;

condition_expr:	expr AND expr|expr OR expr 							
;

callout_arg:        |callout_arg ',' expr |callout_arg ',' STRING_LITERAL 			
;

%%

int yyerror(char *msg)
{
	printf("\nError : Decaf program compilation failed\n");
	exit(0);
}

int main()
{
	#ifdef YYDEBUG
		yydebug=1;
	#endif

yyin = fopen("b.txt", "r");
yyparse();
printf("\nDecaf Program succesfully compiled\n");
}
