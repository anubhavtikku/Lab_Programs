using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApp1.Helper;

namespace UnitTestProject1
{
    [TestClass]
    public class MathTest
    {
        [TestMethod]
        public void TestAdd()
        {
            int result = MyMath.Add(20, 30);
            Assert.AreEqual(50, result);
        }
    }
}
