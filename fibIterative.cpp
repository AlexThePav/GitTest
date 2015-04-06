#include <iostream>

using namespace std;

int iterative_fib (int n) {
	if (n<=2) {
		return 1;
	}

	int a = 1, b = 1, sum = 0;

	for (int i = 0; i < n-2; ++i) {
		sum = a + b;
		printf("c = a + b: %d = %d + %d\n", c, a, b);
		b = a;
		printf("b = a: %d = %d\n", b, a);
		a = sum;
		printf("a = c: %d = %d\n", a, c);
	}
	return a;
}

int main () {
	int f, n;
	cout << "Gimme f:";
	cin >> n;

	f = iterative_fib(n);
	cout << "Iterative_fib(" << n << ") = " << f << endl;

	system("pause");
	return 0;
}