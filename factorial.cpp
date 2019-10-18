#include <iostream>
int fact(int val) {
	int ret=1;
	while(val>1){
	  ret *= val--;
	}
	return ret;
  }

int main(){  
  int num;
  std::cout << "Enter the number of factorial: ";
  while (std::cin>>num){
	std::cout << "The factorial of " << num << " is "<<fact(num)<<std::endl;
	std::cout << "Enter the number of factorial: ";
  }
  return 0;
}
