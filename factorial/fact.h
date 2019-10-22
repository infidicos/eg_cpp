#ifndef _FACT_H_INCLUDE_
#define _FACT_H_INCLUDE_
int fact();
int fact(int num){
  int ret=1;
  while(num>1)
	ret *=num--;
  return ret;
}
#endif
