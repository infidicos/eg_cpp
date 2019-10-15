
#include <iostream>
#include <vector>
int main(){
  std::vector<int> vecnum;
  std::cout << "Enter sequence of int number: ";
  int num;
  while(std::cin >> num){
	vecnum.push_back(num);
  }
  
  for (int i=1; i<vecnum.size(); ++i){
	int key{vecnum[i]};
	int j{i - 1};
	while (j>=0 && vecnum[j]>key){
	  vecnum[j+1] = vecnum[j];
	  vecnum[j]=key;
	  key = vecnum[j];
	  --j;
	}
  }
  
  std::cout << "The number sorted: ";
  for (auto n : vecnum)
	std::cout << n << " ";
  std::cout << std::endl;
  return 0;
}
