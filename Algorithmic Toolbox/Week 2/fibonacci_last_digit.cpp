#include <iostream>

#include <algorithm>

#include <vector>


#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define endl '\n'

#define ll long long int


using namespace std;
ll fibCalc(int n)
{
	vector<ll> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = (fib[i - 1]%10 + fib[i - 2]%10)%10;
	return fib[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibCalc(n) << endl;
}