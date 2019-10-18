//increment insertsort algorithm
#include <iostream>
#include <vector>
int main(){
  std::vector<int> seq;
  std::cout << "Enter sequence of int number: ";
  int num;
  while(std::cin >> num){
	seq.push_back(num);
  }
  //insertsort algorithm core
  for (int key_pos=1; key_pos<seq.size(); ++key_pos){
	int key{seq[key_pos]};
	int insert_pos{key_pos - 1};
	while (insert_pos>=0 && seq[insert_pos]>key){
	  //swap key to new positon
	  seq[insert_pos+1] = seq[insert_pos];
	  seq[insert_pos]=key;
	  key = seq[insert_pos];
	  --insert_pos;
	}
  }
  //==============================================
  std::cout << "Sequence sorted: ";
  for (auto ele : seq)
	std::cout << ele << " ";
  std::cout << std::endl;
  return 0;
}
