using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ABC;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {  //Program pgm=new Program();
            Product p = new Product();
            p.InvalidId += WrongValue;
            // p.InvalidId += pgm.WrongValue;
            p.InvalidId +=DisplayError;
            int id;
            int.TryParse(Console.ReadLine(),out id);
            p.Id = id;
            //p.Id = -10;
            Console.WriteLine(p.Id);
            Console.Read();
        }

        static void WrongValue()
        {
            Console.WriteLine("Wrong Value ");
        }

        static void DisplayError()
        {
            Console.WriteLine("Error ");
        }
    }
}
