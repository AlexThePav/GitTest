#include <iostream>
#include <math.h>

using namespace std;

#define nat unsigned int
struct Pereche	
{
	nat element;
	nat frecventa;
};

void initSir (Pereche* sir, nat lungime);
void readS(nat* sir, nat& n);
void printS(nat* sir, nat& n);
void printS(Pereche* sir, nat& n);
nat isPrim(nat& numar);
nat sumaCifrelor(nat numar);
void adaugaNumarInSir (Pereche* sir, nat& lungime, nat numar);
void insereazaNrInSir (Pereche* sir, nat& lungime, nat pozitie, Pereche pereche);
nat frecventaNrInSir (nat* sir, nat& lungime, nat numar);

int main() {

	nat x[500];
	Pereche y[500];
	initSir(y, 500);

	nat ePrim, sumaC, n = 0, yPoz=0, freqPoz;
	readS(x, n);

	for (int i = 0; i < n; i++)
	{
		sumaC = sumaCifrelor(x[i]);
		ePrim = isPrim(sumaC);
		if (ePrim == 1)
		{
			printf("adaugaNumarInSir(poz:%u, x[%u]:%u)\n", yPoz, i, x[i]);
			adaugaNumarInSir(y, yPoz, x[i]);
			printS(y, yPoz);

		}
	}
	printf("\n");
	printS(y, yPoz);
	system("pause");
	return 0;
}

void readS(nat* sir, nat& n) {
	printf("Introduceti numerele, va rog. Atentie, citirea se va opri la introducerea numarului 0 sau > 10000.\n");
	scanf("%u", &sir[n]);

	while(sir[n]!=0 && sir[n]<=10000) 
	{
		n++;
		scanf("%u", &sir[n]);
	}
}

void printS(nat* sir, nat& n) {
	for (int i = 0; i < n; ++i)
		printf("%u ", sir[i]);
}

void printS(Pereche* sir, nat& n) {

	if (n > 0) 
	{
		printf("Y=(");
	} 
	else 
	{
		printf("Sirul este gol!\n");
	}
	for (int i = 0; i < n; ++i) {
		Pereche pereche = sir[i];	
		if (i < n-1) {
			printf("(%u, %u), ", pereche.element, pereche.frecventa);
		} else {
			printf("(%u, %u))\n", pereche.element, pereche.frecventa);
		}
	}
}

nat isPrim(nat& numar) {
	if (numar == 1 || numar == 2)
		return 1;
	if (numar%2 == 0)
		return 0;
	for (int i = 3; i <= sqrt(numar); i+=2)
		if (numar%i==0)
			return 0;
	return 1;
}

nat sumaCifrelor(nat numar) {
	nat ultimaCifra, suma = 0;
	while (numar>0) {
		ultimaCifra = numar%10;
		suma = suma + ultimaCifra;
		numar = numar/10;
	}
	return suma;
}

void initSir (Pereche* sir, nat lungime) {
	for (int i = 0; i < lungime; ++i)
	{
		Pereche perecheGoala = {0, 0};
		sir[i] = perecheGoala;
	}
}

void adaugaNumarInSir (Pereche* sir, nat& lungime, nat numar) {

	nat aFostAdaugat = 0;

	for (int i = 0; i < lungime; ++i)
	{
		Pereche pereche = sir[i];
		if (pereche.element == numar)
		{
			// printf("pereche.element == numar (%u = %u)\n", pereche.element, numar);
			pereche.frecventa++;
			sir[i] = pereche;
			aFostAdaugat = 1;
			return;
		}
		else if (pereche.element > numar) 
		{
			// printf("pereche.element > numar (%u > %u)\n", pereche.element, numar);
			// printf("vreau sa adaug %u aici pe %u\n", numar, i);
			Pereche newPereche;
			newPereche.element = numar;
			newPereche.frecventa = 1;
			insereazaNrInSir(sir, lungime, i, newPereche);
			aFostAdaugat = 1;
			return;
		}
	}

	if (!aFostAdaugat)
	{
		// printf("nu a fost adaugat pana acuma numarul %u\n", numar);
		Pereche newPereche;
		newPereche.element = numar;
		newPereche.frecventa = 1;
		sir[lungime] = newPereche;
		lungime++;
	}
}

void insereazaNrInSir (Pereche* sir, nat& lungime, nat pozitie, Pereche pereche) {
	// printf("insereazaNrInSir lungime: %u, pozitie: %u, pereche: (%u, %u)\n", lungime, pozitie, pereche.element, pereche.frecventa);
	for (nat i = lungime; i > pozitie; --i)
	{
		sir[i] = sir[i-1];

	}

	sir[pozitie] = pereche;
	lungime++;
	// printf("s-a inserat\n");
}

nat frecventaNrInSir (nat* sir, nat& lungime, nat numar) {
	nat gasit = 0;
	for (nat i = 0; i < lungime; ++i)
	{
		if (sir[i] == numar)
		gasit ++;
	}
	return gasit;
}