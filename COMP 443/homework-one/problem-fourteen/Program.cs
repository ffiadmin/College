using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_fourteen {
	class Example {
		public int X = 42;
	}

	class Program {
		static void Main(string[] args) {
			Example ex1 = new Example();
			ex1.X = 42;
			Console.WriteLine(ex1.X);

			Example ex2 = ex1;
			ex1.X = 43;
			Console.WriteLine(ex2.X);

			RefAlias(ref ex1);
			Console.WriteLine(ex1.X);

			Example out1;
			OutAlias(out out1);
			Console.WriteLine(out1.X);
		}

		static void RefAlias(ref Example ex) {
			ex.X = 44;
			Console.WriteLine(ex.X);
		}

		static void OutAlias(out Example ex) {
			ex = new Example();
			ex.X = 45;
			Console.WriteLine(ex.X);
		}
	}
}