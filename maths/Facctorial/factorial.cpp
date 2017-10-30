#include <iostream>

using namespace std;

//Calculate the factorial of num recursively
int Factorial(int num) {
	if (num == 0)
		return 1;
	else 
		return (num*Factorial(num-1));
}

int main() {
	int num;
	cout << "What factorial do you want to know? ";
	cin >> num;
	cout << num << "! = " << Factorial(num);
	return 0;
}
