#include <iostream>
#include <string>
std::string::size_type find_char(const std::string& , char, std::string::size_type&);
int main(){
  std::cout << "What string do you want to find: ";
  std::string s;
  std::getline(std::cin,s);

  std::cout << "What character do you find: ";
  char c;
  std::cin >> c;
  std::string::size_type count;
  auto ret = find_char(s,c,count);
  std :: cout << c <<" occurs " << " the first time at "<< ret << " and "<< count-1 << " in remain of "<< s << std::endl;
  return 0;
}
std::string::size_type find_char(const std::string &s, char c, std::string::size_type &count){
  auto ret = s.size();
  count = 0;
  for (auto i=0; i<s.size(); ++i){
	if(s[i]==c){
	  if(ret==s.size())
		ret=i;
	  ++count;
	}
  }
  return ret;
}
