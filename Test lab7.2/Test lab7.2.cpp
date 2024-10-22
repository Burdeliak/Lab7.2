#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2/lab7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testlab72
{
	TEST_CLASS(Testlab72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 4;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			
			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;   
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;   
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;   
			a[3][0] = 10; a[3][1] = 11; a[3][2] = 12; 

			
			int expectedSum = 3 + 9;

			
			int actualSum = SumOfMaxInEvenRows(a, rowCount, colCount);
			Assert::AreEqual(expectedSum, actualSum, L"Sum of max elements in even rows is incorrect.");
		}
	};
}
