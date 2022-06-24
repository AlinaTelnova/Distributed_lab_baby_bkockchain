#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;
int sundaram(int n)
{
	int* a = new int[n], i, j, k;
	memset(a, 0, sizeof(int) * n);
	for (i = 1; 3 * i + 1 < n; i++)
	{
		for (j = 1; (k = i + j + 2 * i * j) < n && j <= i; j++)
		{
			a[k] = 1;
		}
	}
	for (i = n - 1; i >= 1; i--)
	{
		if (a[i] == 0)
		{
			return (2 * i + 1);
			break;
		}
	}
	delete[] a;
}
int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}
class KeyPair
{
private:
	unsigned long long int privateKey;
public:
	unsigned long long publicKey;
	void genPairKey()
	{
		int p = rand() % 10000000000000000000;
		int q = rand() % 10000000000000000000;
		int p_prime = sundaram(p);
		int q_prime = sundaram(q);
		unsigned int n = p_prime * q_prime;
		int e, e_prime = 0;
		while (e_prime != 1)
		{
			e = rand() % 10000000000000000000;
			e_prime = gcd(e, ((p_prime - 1) * (q_prime - 1)));
		}
		unsigned int d = 0, d_prime = 0;
		while (d_prime != 1)
		{
			d += 1;
			d_prime = (e * d) % ((p_prime - 1) * (q_prime - 1));
		}
		publicKey = e;
		privateKey = d;
	}
	void printKeyPair()
	{
		cout << publicKey << '\t' << privateKey << endl;
	}
};
int main()
{
	KeyPair keypair;
	keypair.genPairKey();
	keypair.printKeyPair();
}
