using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public delegate void PriceChanged(int val);

    class Product
    {
        public event PriceChanged p;


        public string name
        {
            get
            { return name;}

            set
            { name = value; }

        }
        private int price;

        public int Price
        {
            get
            { return price; }

            set
            {
                if (price > 0)
                {
                    price = value;
                    p?.Invoke(value);
                }
                else
                {
                    Console.WriteLine("Price is not valid ");
                }
            }

        }

    }
}
