#include "fact.h"
int fact(int num){
  int ret=1;
  while(num > 1)
	ret *= num--;
  return ret;
}
