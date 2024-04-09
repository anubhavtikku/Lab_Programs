using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {   
            int a, b;
            DateTime dateTime = DateTime.Now;
            //dateTime.AddDays(10);
            dateTime.Add(TimeSpan.FromHours(1));
            Console.WriteLine("Enter two numbers ");
            //a=Convert.ToInt32(Console.ReadLine());
            //b=Convert.ToInt32(Console.ReadLine());
            if (int.TryParse(Console.ReadLine(), out a) && int.TryParse(Console.ReadLine(), out b))
            {
                Console.WriteLine("Sum is " + Sum(a,b));
            }
            else
            {
                Console.WriteLine("Invalid Input ");
            }
                Console.Read();

        }

        private static int Sum(int a, int b)
        {
            return a + b;
        }

    }


}
