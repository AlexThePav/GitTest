#include <iostream>
#include <math.h>

using namespace std;

const int s = 50;
const int maxC = 5;

void readM(int matrix[s][s], int& n);
void printM(const int matrix[s][s], int n);
int isPrim(int& n);
int isSuperPrim (int& n);
void interschimbareElementeDinMatrice(int a[s][s], int i, int j, int k, int p);
void interschimbareTriunghiSuperiorInferior (int a[s][s], int n);

int main () {
	int x[s][s], n=0;
	readM(x, n);
	printf("Interschimbam elementul de pe 1,4 cu 3,5\n");
	interschimbareElementeDinMatrice(x, 1, 4, 3, 5);
	printM(x, n);

	system("pause");
	return 0;
}

void readM(int matrix[s][s], int& n) {
	printf("De cat pe cat sa fie, domnu'? \n");
	scanf("%i", &n);

	while (n<3){
		printf("Hai, macar 3...\n");
		scanf ("%i", &n);
	}

	printf("Introduceti elementele: \n");

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			scanf("%i", &matrix[i][j]);
		}
	}
}

void printM(const int matrix[s][s], int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}
}

int isPrim (int& n) {
	if (n==1)
		return 1;
	if ((n==0) || (n%2==0)) 
		return 0;
	for (int i = 3; i <= sqrt(n); i+=2)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int isSuperPrim(int n) {
	int nrTemp = 0;

	if (n==0)
		return 0;

	while (nrTemp != n){
		
		// while (n>0) {
		// 	nrTemp = nrTemp + n%10;
		// 	nrTemp = nrTemp *10;
		// 	n = n/10;
		// }
		// if (isPrim(nrTemp) == 1);
	}

	return 0;
}

// interschimbare elementul a[i][j] cu elementul a[k][p]
void interschimbareElementeDinMatrice(int a[s][s], int i, int j, int k, int p) {
	int aux = a[i][j];
	a[i][j] = a[k][p];
	a[k][p] = aux;
}

void interschimbareTriunghiSuperiorInferior (int a[s][s], int n) {
	for (int j = 0; j < n-1; ++j) {
		for (int i1 = 0; i1 < j; ++i1)
		{
			/* code */
		}
	}
}





