using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Descending_Order_Class_Exercise {
    class Program {
        private static double[] values = new double[3];

        static void Main(string[] args) {
            Console.WriteLine("Please enter a list of three doubles (seperated by spaces) to have them printed in order: ");
            string numbers = Console.ReadLine();
            string[] list = numbers.Split();
            
            for (int i = 0; i < list.Length; ++i) {
                values[i] = Double.Parse(list[i]);
            }

            sortD();

            for (int i = 0; i < list.Length; ++i)
            {
                Console.WriteLine(values[i]);
            }
        }

        private static void sortD()
        {
            Array.Sort(values);
            Array.Reverse(values);
        }
    }
}
