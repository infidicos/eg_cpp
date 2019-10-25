#include <iostream>
#incluse <string>
using namespace std;
struct sale_data{
  string isbn() const {return bookNo;};
  sale_data combine(sale_data sd1, sale_data sd2);
  double avr_sale();
  string bookNo;
  double revenue;
  unsigned units_sold;
}
