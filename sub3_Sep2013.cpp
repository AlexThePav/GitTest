#include <iostream>

using namespace std;
#define nat unsigned int

void readS(nat* sir, nat& n);
void printS(nat* a, nat &size);
nat primeMaiMiciDecatNr(nat nr, nat *results);
nat isFactorPutereaIntai(nat x, nat i);
void adaugaNumarInSir(nat* sir, nat &lungimeSir, nat numar);
void insertNumar(nat *a, nat &lungime, int pozitie, int numar);

int main () {
	nat n = 0;
	nat x[500];
	readS(x, n);

	nat y[500];
	nat yPoz = 0;

	for (int i = 0; i < n; ++i)
	{
		nat plasa[500];
		nat pSize = primeMaiMiciDecatNr(x[i], plasa);
		
		for (int plasaPoz = 0; plasaPoz < pSize; ++plasaPoz)
		{
			nat prim = plasa[plasaPoz];
			// trebuie verficat mai intai
			// daca prim este un factor al lui x[i]
			if (x[i]%prim == 0 && isFactorPutereaIntai(x[i], prim))
			{
				// a fost gasit un numar prim 'prim'
				// care figureaza la puterea intai
				// in descompunerea numarului x[i]
				
				adaugaNumarInSir(y, yPoz, prim);
				// y contine numarul 'prim' o singura data
			}
		}
	}

	if (yPoz == 0)
	{
		// nu avem niciun element in sirul Y
		printf("Sirul Y e vid.");
	}
	else
	{
		printf("Y=");
		printS(y, yPoz);
	}

	system("pause");
	return 0; 
}

void readS(nat* sir, nat& n)  {
	nat i = 0;

	// se citeste lungimea sirului
	printf("Cate elemente ati dori, va rog?\n");
	scanf("%u", &n);

	// se citesc valorile sirului
	printf("Ce elemente ati dori, va rog?\n");
	for (i = 0; i < n; i++)
	{
		scanf("%u", &sir[i]);
	}
}

void printS(nat* a, nat& size) {
	for (nat i = 0; i < size; i++)
	{
		printf("%u ", a[i]);
	}
}

nat primeMaiMiciDecatNr(nat nr, nat *results) {
	nat i, j, pos = 0;

	for (i=2; i<=nr; i++) {

		//validare numar prim
		nat prim = 1;
		for (j=2; j<=i/2; j++) {
			if (i%j==0) {
				prim = 0;
			}
		}

		if (prim == 1)
		{
			results[pos] = i;
			// printf("Prime[pos] = %u\n", results[pos]);
			pos++;
		}
	}
	//lentgh of results
	return pos;
}

nat isFactorPutereaIntai(nat x, nat i) {
	if (x%(i*i) == 0)
	{
		return 0;
	}

	return 1;
}

// adauga un numar daca nu este deja in sir, la sfarsit
// nu este ordonat crescator!

// void adaugaNumarUnicSir(nat* sir, nat &lungimeSir, nat numar) {
	
// 	int gasit = 0;	
// 	for (int i = 0; i < lungimeSir; ++i)
// 	{
// 		if (sir[i] == numar)
// 		{	
// 			gasit = 1;
// 		}
// 	}

// 	if (!gasit)
// 	{
// 		sir[lungimeSir] = numar;
// 		lungimeSir++;
// 	}
// }

void adaugaNumarInSir(nat* sir, nat &lungimeSir, nat numar) {
	
	for (int i = 0; i < lungimeSir; ++i)
	{
		if (sir[i] == numar)
		{	
			// numar a fost gasit
			// nu e nevoie sa continue
			return;
		}

		// numar is not found yet
		if (sir[i]>numar)
		{
			insertNumar(sir, lungimeSir, i, numar);
			// functia se opreste
			// numar a fost adaugat cu succes
			return;
		}
	}
	//ajunge aici doar daca nu a fost gasit
	//if (!gasit)
	//{
		sir[lungimeSir] = numar;
		lungimeSir++;
	//}
}


void insertNumar(nat *a, nat &lungime, int pozitie, int numar) {
	for (int i = lungime-1; i >= pozitie; --i)
	{
		a[i+1] = a[i];
	}
	a[pozitie] = numar;
	lungime ++;
}
