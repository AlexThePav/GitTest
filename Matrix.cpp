#include <iostream>
using namespace std;

int matrixOfZeroes ()
{
	
	int matrix[100][100];

	int n;

	printf("Cate randuri? ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		matrix[i][n-i-1] = 1;
		for (int j = 0; j<n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return matrix[100][100];
}

int main ()
{
	int zeromatrix = matrixOfZeroes();
	printf("Matrices, yeah!!\n");
	return 0;
}