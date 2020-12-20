#include <iostream>
#include <cmath>
using namespace std;

long long factorial(long long n)
{
	long long f = 1;
	for (long long i = 1; i <= n; i++)
		f = f * i; //f *= i;

	return f;
}

long long double_factorial(long long n)
{
	long long f = 1;
	int flag = 2;
	if (n % 2 == 1)
		flag = 1;

	flag = 2 - n % 2; // analog
	for (long long i = flag; i <= n; i += 2)
		f = f * i; //f *= i;

	return f;
}

long long sum_of_func(long long n, long long x)
{
	long long S =  -x / (48 * x + 24); // при i = 1: -2 * x^1 / (2x+1)(0!)(6!!)
	long long sum = S;
	for (long long i = 2; i <= n; i++)
	{
		long long step1 = pow(-2, i);
		long long step2 = pow(x, (2 * i) - 1);
		long long step3 = (2 * x + 1);
		long long step4 = factorial(i - 1);
		long long step5 = double_factorial(2 * i + 4);
		S = step1 * step2 / (step3 * step4 * step5);
		sum = sum + S;
	}

	return sum;
}

int main()
{
	int n, x;
	cout << "Enter n:";
	cin >> n;
	cout << "Enter x:";
	cin >> x;
	cout << sum_of_func(n, x);
}