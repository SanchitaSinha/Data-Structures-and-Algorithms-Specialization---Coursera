#include<iostream>
using namespace std;

int main() 
{
	int Val; 
	cin >> Val; 
	int Sum = 0; 
	Sum += Val / 10; 
	Sum += (Val % 10) / 5; 
	Sum += ((Val % 10) % 5);
	cout << Sum << endl;
}