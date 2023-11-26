#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\smurf\OneDrive\Desktop\ipz3\ipz3\ipz3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(checkValidParams_Tests)
	{
	public:

		TEST_METHOD(calculate_get1_4_1_2_and_exceptionNotThrown)
		{
			double x = 1;
			double b = 4;
			double h = 1;
			double n = 2;
			try
			{
				checkValidParams(x, b, h, n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(calculate_get1_7_2_2_and_exceptionThrown)
		{
			double x = 1;
			double b = 7;
			double h = 2;
			double n = 2;
			try
			{
				checkValidParams(x, b, h, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_get1_3_and_0_returned)
		{
			double x = 1;
			int n = 3;
			double expected = 0;
			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculate_get_minus_1_2_and_14_returned)
		{
			double x = -1;
			int n = 2;
			double expected = calculate(x, n);
		}
	public:
		TEST_METHOD(wrongTest)
		{
			double x = -1;
			int n = 2;
			double expected = 0;
			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);
		}
	};
}