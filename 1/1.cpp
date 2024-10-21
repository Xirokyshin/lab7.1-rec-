#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1(it).cpp" // ���� �� ������ ����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				z[i] = new int[colCount];

			// ��������� Create �������
			Create(z, rowCount, colCount, 1, 10);

			// ����������, �� �� �������� ����������� � ����� Low � High
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					Assert::IsTrue(z[i][j] >= 1 && z[i][j] <= 10);
				}
			}

			for (int i = 0; i < rowCount; i++)
				delete[] z[i];
			delete[] z;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				z[i] = new int[colCount];

			// ���������� ������ ������ ��� ����������
			z[0][0] = 3; z[0][1] = 2; z[0][2] = 1;
			z[1][0] = 6; z[1][1] = 5; z[1][2] = 4;
			z[2][0] = 9; z[2][1] = 8; z[2][2] = 7;

			Sort(z, rowCount, colCount);

			// ����������, �� ����� ������������ ���������
			Assert::AreEqual(9, z[0][0]);
			Assert::AreEqual(6, z[1][0]);
			Assert::AreEqual(3, z[2][0]);

			for (int i = 0; i < rowCount; i++)
				delete[] z[i];
			delete[] z;
		}
	};
}
