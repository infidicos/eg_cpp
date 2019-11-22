//find primes with sieve of Eratosthenes

#include <cmath>
#include <iostream>
#include <vector>

void FindPrime(int n){
	std::vector<bool> sieve((n-3)/2 + 1);
	//mark_sieve
	for (int i=0; i <= (std::sqrt(n) - 3)/2; ++i){
		int j = (std::pow((3+2*i),2) -3)/2; //index_square
		int factor = 2*i + 3; //step_sieve
		if (sieve[i] == false){
			int max_index = (n-3)/2;
			while (j <= max_index){
			sieve[j] = true;
			j += factor;
			}
		}
	}
	//display
		for (int i=0; i <= (n-3)/2; ++i){
			if (sieve[i] == false){
				std::cout << 2*i+3 << " | ";
			}
		}
	std::cout << std::endl;
}

int main(){
	while (true){
		std::cout << "n: ";
		int n;
		std::cin >> n;
		FindPrime(n);
	}
}
