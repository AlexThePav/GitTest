#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Elev
{
	char nume[10];
	float medie;
	int varsta;
};


int main () {
    int lungime = 0;

    FILE *f, *g;
    f = fopen("intrare.in", "r");
    g = fopen("iesire.out", "w");

    fscanf(f, "%i", &lungime);
    fprintf(g, "lungime: %i\n", lungime);

	Elev elevi[20];

	for (int i = 0; i < lungime; ++i)
	{
		printf("%i.\n", i);
		Elev elev = elevi[i];

		// elev.nume = "Ghita";
		// elev.medie = 2;
		// elev.varsta = 13;

		printf("Numele:");
		scanf("%s", &elev.nume);

		printf("Media:");
		scanf("%f", &elev.medie);

		printf("Varsta:");
		scanf("%i", &elev.varsta);

		elevi[i] = elev;
	}


	for (int i = 0; i < lungime; ++i)
	{
		printf("%s cu varsta de %i ani, are media %.2f\n", elevi[i].nume, elevi[i].varsta, elevi[i].medie);
	}

	fclose(f);
	fclose(g);

	system("pause");
	return 0;
}