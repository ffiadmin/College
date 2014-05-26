using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TDD
{
    public class Motel
    {
        private static Motel m = new Motel();

        private Motel() {
            try
            {
                StreamReader sr = new StreamReader("motel_config.sys");
            }
            catch (Exception)
            {
                StreamWriter sw = new StreamWriter("motel_config.sys");
                sw.Close();
            }
        }

        public static Motel getMotel() {
            return m;
        }
    }
}
