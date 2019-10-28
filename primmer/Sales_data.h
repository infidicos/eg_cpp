#ifndef sales_data_h
#define sales_data_h

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Sales_data{
	string bookNo;
	int unitsSold;
	double revenue;
public:
	Sales_data(): bookNo{""}, unitsSold{0}, revenue{0.0} {};
	Sales_data(string str): bookNo{str} {};
	Sales_data(string str, int num, double rev): bookNo{str}, unitsSold{num}, revenue{rev} {};
	string isbn();
	Sales_data& combine(const Sales_data&);
	int totalSold();
	double avgPrice();
	double getRevenue();
};

string Sales_data::isbn(){return bookNo;}
Sales_data& Sales_data::combine(const Sales_data& trans){
	if (bookNo == trans.bookNo){
		unitsSold += trans.unitsSold;
		revenue += trans.revenue;
	}
	return *this;
}
int Sales_data::totalSold(){return unitsSold;}
double Sales_data::avgPrice(){return unitsSold ? revenue/unitsSold : 0;}
double Sales_data::getRevenue(){return revenue;}
#endif
