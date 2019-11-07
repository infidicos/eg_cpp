#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"
using namespace std;
int main(int argc, char* argv[] ){
	Sales_data itemTotal;
	while(!cin.eof()){
	Sales_data item1;
	read(cin, item1);
	itemTotal.combine(item1);
	}
	cout << "\n";
	ofstream fileTotal(argv[1], fstream::app);
	write(fileTotal, itemTotal);
	fileTotal.close();
  return 0;
}
