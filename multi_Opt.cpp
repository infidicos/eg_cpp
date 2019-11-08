#include <iostream>
//using namespace std;
//==========================================================

int multi_nO(int n, int term){ //nO: non Optimize
	if (n==1) return term;
	return multi_nO(n-1,term) + term;
}
//complex #(+) = O(n)
int multi_nO_acc(int acc, int n, int term){
	if (n==1) return acc+term;
	acc += term;
	return multi_nO_acc(acc, n-1, term);
}
int multi_nO_acc_1(int acc, int n, int term){
	if (n==0) return acc;
	acc += term;
	return multi_nO_acc_1(acc, n-1, term);
}

//==========================================================

int half(int x){return x >> 1;}; //cheap , half(x-1)=half(x);
bool odd(int x){return x & 0x1;}; //cheap
int x2(int x){return x << 1;}; //cheap
//==========================================================
int multi_O1(int n, int term){
	if (n==1) return term;
	if (odd(n)) return multi_O1(half(n),x2(term)) + term;
	return multi_O1(half(n),x2(term));
}
//complex #(+)= O(log(n)) + (pop(n)-1) // pop(): population()
int multi_O1_acc(int acc, int n, int term){
	if (n==1) return acc+term;
	if (odd(n)) acc +=term;
	return multi_O1_acc(acc, half(n), x2(term));
}//tail-recursion

//==========================================================

int multi_O1_acc_1(int acc, int n, int term){
	if (n==1) return acc+term;
	if (odd(n)) acc += term;
	term = x2(term);
	n = half(n);
	return multi_O1_acc_1(acc,n,term);
}//strictly tail-recursion
//==========================================================
int multi_acc_refactor(int acc, int n, int term){
	if (odd(n)){
		if (n==1) return acc+term;
		acc += term;
	}
	term = x2(term);
	n = half(n);
	return multi_acc_refactor(acc,n,term);
}
//==========================================================
int multi_iter(int acc, int n, int term){
	while(true){
		if (odd(n)){
			if (n==1) return acc+term;
			acc +=term;
		}
		term = x2(term);
		n = half(n);
	}
}
int multi_hack(int n, int term){
	while (!odd(n)){							//if n is power of 2, substract 1
		term = x2(term);						//is worst case!!!!
		n = half(n);
	}
	if (n==1) return term;
	return multi_iter(term,n-1,term);
}
//----------------------------------------------------------
int main(){
	std::cout << "What your two int number: ";
	int a,b;
	std::cin >> a >> b;
	int res = multi_hack(a,b);
	std::cout << "Multiplition of " << a << " and " << b << " are: " << res << std::endl;
}

