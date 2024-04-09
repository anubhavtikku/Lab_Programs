__kernel void vector_add (__global int *A, __global int *B, __global int *C) {

    int i = get_global_id(0);

    int dec=A[i];
    int oct= 0;
    int rem;
    while (dec>0) 
   {    rem=dec%8;
        oct=oct+rem*10;
        dec=dec/8;
    }
    C[i]=oct;
    

}

