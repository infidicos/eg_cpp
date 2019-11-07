#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

class Sales_data{
	string bookNo;
	int unitsSold;
	double revenue;
public:
	Sales_data(): bookNo{""}, unitsSold{0}, revenue{0.0} {};
	Sales_data(string str): bookNo{str} {};
	Sales_data(string str, int num, double rev): bookNo{str}, unitsSold{num}, revenue{rev} {};
	string isbn() const;
	Sales_data combine(const Sales_data&);
	int totalUnitsSold() const;
	double avgPrice() const;
	double getRevenue() const;
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
};

string Sales_data::isbn() const {return bookNo;}
Sales_data Sales_data::combine(const Sales_data& trans){
	if (isbn() == trans.isbn()){
		unitsSold += trans.unitsSold;
		revenue += trans.revenue;
	}
	return *this;
}
int Sales_data::totalUnitsSold() const {return unitsSold;}
double Sales_data::avgPrice() const {return unitsSold ? revenue/unitsSold : 0;}
double Sales_data::getRevenue() const {return revenue;}

Sales_data add(const Sales_data& item1, const Sales_data& item2){
		Sales_data resultAdd;
	if (item1.isbn() == item2.isbn()){
		resultAdd.bookNo = item1.isbn();
		resultAdd.unitsSold = item1.unitsSold + item2.unitsSold;
		resultAdd.revenue = item1.revenue + item2.revenue;
	}
	return resultAdd;
}

auto  read(istream& is, Sales_data& itemIn) -> istream& {
	is >> itemIn.bookNo >> itemIn.unitsSold >> itemIn.revenue ;
	return is;
}

auto  write(ostream& os, const Sales_data& itemOut) -> ostream& {
	return os << itemOut.isbn() << "-" << itemOut.totalUnitsSold() << "-" << itemOut.getRevenue() << endl;
}

#endif
