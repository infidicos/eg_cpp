#include <iostream>
int gcd(int a, int b){
	return b ? gcd(b,a%b)  : a;
}
int main(){
	std::cout << "What your number: ";
	int i,j;
	std::cin >> i >> j;
	std::cout << gcd(i,j) << std::endl;
}
