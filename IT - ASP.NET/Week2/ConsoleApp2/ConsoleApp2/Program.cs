using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b;
            Console.WriteLine("Enter two numbers ");

            if (int.TryParse(Console.ReadLine(), out a) && int.TryParse(Console.ReadLine(), out b))
            {
                Console.WriteLine("Sum is " + (a + b));
                Console.WriteLine("Difference is " + (a - b));
                Console.WriteLine("Multiplication is " + (a * b));
                Console.WriteLine("Division is " + (a / b));

            }
            else
            {
                Console.WriteLine("Error ");
            }
            Console.Read();
        }
    }
}
