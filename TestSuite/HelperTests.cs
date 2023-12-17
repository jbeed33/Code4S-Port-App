using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tests
{
    [TestClass]
    public class HelperTests
    {
        [TestMethod]
        public void TestFindFileInAppData()
        {
            string fileName = "shipState.shp";
            string filePath = WindowsFormsApp1.Helper.findFileInAppdatad(fileName);
            Assert.IsTrue(File.Exists(filePath));
        }

        [TestMethod]
        public void TestInputValidatorValid()
        {
            string name = "ValidName";
            string weight = "10";
            bool result = WindowsFormsApp1.Helper.inputValidator(name, weight);
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void TestInputValidatorInvalidName()
        {
            string name = "";
            string weight = "10";
            bool result = WindowsFormsApp1.Helper.inputValidator(name, weight);
            Assert.IsFalse(result);
        }

        [TestMethod]
        public void TestInputValidatorInvalidWeight()
        {
            string name = "ValidName";
            string weight = "-5";
            bool result = WindowsFormsApp1.Helper.inputValidator(name, weight);
            Assert.IsFalse(result);
        }
    }
}
