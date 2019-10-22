#include <iostream>
#include "fact.h"
int main(){  
  int num;
  std::cout << "Enter the number of factorial: ";
  while (std::cin>>num){
	std::cout << "The factorial of " << num << " is "<<fact(num)<<std::endl;
	std::cout << "Enter the number of factorial: ";
  }
  return 0;
} 
