using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using TDD;
using System.IO;

namespace test_project
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.IsNotNull(Motel.getMotel());
        }

        [TestMethod]
        public void TestMethod2()
        {
            Motel m1 = Motel.getMotel();
            Motel m2 = Motel.getMotel();

            Assert.IsTrue(m1 == m2);
        }

        [TestMethod]
        public void TestMethod3()
        {
            try
            {
                StreamReader sr = new StreamReader("motel_config.sys");
                Assert.IsNotNull(sr);
            }
            catch (Exception)
            {
                Assert.IsTrue(false);
            }
        }

        [TestMethod]
        public void TestMethod4()
        {
            try
            {
                StreamReader sr = new StreamReader("motel_config.sys");
                Assert.IsNotNull(sr);

                string nks = sr.ReadLine();
                string nds = sr.ReadLine();
                string dp1s = sr.ReadLine();
                string dp2s = sr.ReadLine();
                int nk = int.Parse(nks);
                int nd = int.Parse(nds);
                double dp1 = double.Parse(dp1s);
                double dp2 = double.Parse(dp2s);

                Assert.IsTrue(nk >= 0 & nd >= 0 && dp1 >= 0.0 && dp2 >= 0.0);
            }
            catch (Exception)
            {
                Assert.IsTrue(false);
            }
        }
    }
}
