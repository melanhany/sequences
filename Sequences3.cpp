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
	long long S = -15 / (6 * x + 2); // при i = 0: -1 * 5!! / (3x + 1) * 2!
	long long sum = S;
	for (long long i = 1; i <= n; i++)
	{
		long long step1 = pow(-1, i + 1);
		long long step2 = double_factorial((2 * i) + 5);
		long long step3 = pow((3 * x) + 1, i + 1);
		long long step4 = factorial(i + 2);
		S = step1 * step2 / (step3 * step4);
		
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