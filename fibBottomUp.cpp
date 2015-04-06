#include <iostream>

using namespace std;

int Fib(unsigned int n)
{
	int fib[401];
	fib[0]=1; fib[1]=1; // initial condition

	for (int i = 2; i<=n; i++)
	{
		fib[i] = fib[i-2] + fib[i-1];
	}
	return fib[n];
}

int main()
{
	unsigned int n, result;
	cout << "Give me an n: " << endl;
	cin >> n;

	result = Fib(n);
	cout << "Fibonacci of " << n << " is " << result << endl;
	
	system("pause");
	return 0;
}