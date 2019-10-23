#include <iostream>
using std::cout;
using std::endl;
int (*inc_val(int (*arr)[5],int size_arr,int inc_num))[5]{
  for(auto i=0; i<size_arr ; ++i){
	(*arr)[i] += inc_num;
  }
  return arr;
}
int main(){
  int arr_int[1][5] = {1,2,3,4,5};
  cout << arr_int [0][2] << endl;
  cout << "---------------------" << endl;
  cout << (*inc_val(arr_int,5,2))[3] <<endl;
return 0;
}
