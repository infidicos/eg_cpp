#include "folder.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

#include "message.hpp"

Folder::Folder(const Folder& f)
	: tag_{f.tag_}, p_message_{f.p_message_}
{
	AddMessageOfFolder(f);
}
Folder& Folder::operator=(const Folder& f){
	DeleteMessageOfThisFolder();
	std::cout << "Ok 1 \n";
	Folder temp = f;
	temp.DeleteMessageOfThisFolder();
	std::cout << "Ok 2 \n";
	swap(temp, *this);
	std::cout << "Ok 3 \n";
	AddMessageOfFolder(*this);
	temp.AddMessageOfFolder(temp);
	std::cout << "Ok 4 \n";
	return *this;
}
Folder::~Folder(){
	DeleteMessageOfThisFolder();
}
void Folder::add_message(Message* m){
	p_message_.push_back(m);
}
void Folder::remove_message(Message* m){
	auto pos = std::find(p_message_.begin(), p_message_.end(), m);
	p_message_.erase(pos);
}
void Folder::AddMessageOfFolder(const Folder& f){
	for (auto pm : f.p_message_)
		pm->add_folder(this);
}
void Folder::DeleteMessageOfThisFolder(){
	for (auto pm : p_message_)
		pm->remove_folder(this);
}
std::ostream& operator<<(std::ostream& os, Folder& f){
	os << "Folder " << f.tag_ << ": ";
	if (f.p_message_.empty())
		os << "NO MEMBER";
	for (auto pm : f.p_message_)
		os << pm->content_ <<"| ";
	os << std::endl;
	return os;
}
void swap(Folder& lhs, Folder& rhs){
	std::swap(lhs.tag_, rhs.tag_);
	std::swap(lhs.p_message_, rhs.p_message_);
}
