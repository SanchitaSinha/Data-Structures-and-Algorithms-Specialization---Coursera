#include <iostream>
#define ll long long
using namespace std;

ll Periodic(ll m) {
	ll a = 0, b = 1, c = a + b; 
	for (int i = 0; i < m*m; i++) {
		c = (a + b) % m; 
		a = b; 
		b = c; 
		if (a == 0 && b == 1)
			return i + 1; 
	}
}
int Solve(ll n, ll m) {
	long long remainder = n % Periodic(m);

	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
}
int main() {
	ll n, m; 
	cin >> n >> m; 
	cout << Solve(n, m) << endl;
}