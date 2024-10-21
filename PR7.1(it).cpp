#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High, int i = 0, int j = 0);
void Print(int** z, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** z, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** z, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 67;
	int rowCount = 7;
	int colCount = 5;
	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];

	Create(z, rowCount, colCount, Low, High);

	cout << endl;
	Print(z, rowCount, colCount);
	cout << endl;  

	Sort(z, rowCount, colCount);

	cout << endl; 
	Print(z, rowCount, colCount);
	cout << endl; 

	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	cout << endl;  
	Print(z, rowCount, colCount);
	cout << endl;  

	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;

	return 0;
}

void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			z[i][j] = Low + rand() % (High - Low + 1);
			Create(z, rowCount, colCount, Low, High, i, j + 1);
		}
		else {
			Create(z, rowCount, colCount, Low, High, i + 1, 0);
		}
	}
}

void Print(int** z, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			cout << setw(4) << z[i][j];
			Print(z, rowCount, colCount, i, j + 1);
		}
		else {
			cout << endl;
			Print(z, rowCount, colCount, i + 1, 0);
		}
	}
}

void Sort(int** z, const int rowCount, const int colCount, int i0, int i1)
{
	if (i0 < rowCount - 1) {
		if (i1 < rowCount - i0 - 1) {
			if (z[i1][0] < z[i1 + 1][0] ||
				(z[i1][0] == z[i1 + 1][0] && z[i1][1] < z[i1 + 1][1]) ||
				(z[i1][0] == z[i1 + 1][0] && z[i1][1] == z[i1 + 1][1] && z[i1][2] < z[i1 + 1][2])) {
				Change(z, i1, i1 + 1, colCount);
			}
			Sort(z, rowCount, colCount, i0, i1 + 1);
		}
		else {
			Sort(z, rowCount, colCount, i0 + 1, 0);
		}
	}
}

void Change(int** z, const int row1, const int row2, const int colCount, int j)
{
	if (j < colCount) {
		int tmp = z[row1][j];
		z[row1][j] = z[row2][j];
		z[row2][j] = tmp;
		Change(z, row1, row2, colCount, j + 1);
	}
}

void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			if (!(z[i][j] % 2 == 0 && z[i][j] % 13 == 0)) {
				S += z[i][j];
				k++;
				z[i][j] = 0;
			}
			Calc(z, rowCount, colCount, S, k, i, j + 1);
		}
		else {
			Calc(z, rowCount, colCount, S, k, i + 1, 0);
		}
	}
}
