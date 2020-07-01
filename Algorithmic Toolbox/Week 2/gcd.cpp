#include <iostream>
#define ll long long
using namespace std;
int GCD(int a , int b) 
{
	if (a == 0)
		return b; 
	return GCD(b%a,a); 
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << GCD(a, b) << endl;
}