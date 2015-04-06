#include <iostream>
#include <string>
using namespace std;

int main() {
	const unsigned int numRows = 50;
	const unsigned int numCols = 2;
	double value[numRows][numCols];

	for (unsigned int i = 0; i < numRows; ++i)
	{
		for (unsigned int j = 0; j < numCols; ++j)
		{
			value[i][j] = 0;
		}
	}

	value[0][1] = 5;
	value[1][0] = 8;

	for (unsigned int i = 0; i < numRows; ++i)
	{
		for (unsigned int j = 0; j < numCols; ++j)
		{
			printf("%d ", value[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}