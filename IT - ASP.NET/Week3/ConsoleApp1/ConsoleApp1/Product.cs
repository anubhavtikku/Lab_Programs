using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC
{
    public delegate void InvalidIdDelegate();


    public class Product
    {
        public event InvalidIdDelegate InvalidId;

        private string Name
        {
            get;
            set;
         /*   get { return Name;}

            set { Name = value; }
            */

        }
        private int id;

        public int Id
        {

            get
            { return id; }

            set
            {
                if (value > 0)
                    id = value;

                else
                {
                    InvalidId?.Invoke();
                     }
            }

        }

    }
}
