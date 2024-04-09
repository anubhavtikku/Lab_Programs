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
            Product p = new Product();
            p.p +=PriceChanged;
            p.Price = -20;
            Console.Read();
        }

        static void PriceChanged(int price)
        {
            Console.WriteLine("Price of item changed to "+price);
        }

    }
}
