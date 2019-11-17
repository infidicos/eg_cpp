#include "message.hpp"

#include <algorithm>

#include "folder.hpp"

Message::Message(const Message& m)
	:content_{m.content_}, p_folder_{m.p_folder_}
{
	AddFolderOfMessage(m);
}
Message& Message::operator=(const Message& m){
	DeleteFolderOfThisMessage();
	content_ = m.content_;
	p_folder_ = m.p_folder_;
	AddFolderOfMessage(m);
	return *this;
}
Message::~Message(){
	DeleteFolderOfThisMessage();
}
void Message::SaveToFolder(Folder& f){
	p_folder_.push_back(&f);
	f.add_message(this);
}
void Message::RemoveFromFolder(Folder& f){
	auto pos = std::find(p_folder_.begin(), p_folder_.end(), &f);
	if (pos != p_folder_.end()){
		p_folder_.erase(pos);
		f.remove_message(this);
	}
}
void Message::add_folder(Folder* f){
	p_folder_.push_back(f);
}
void Message::remove_folder(Folder* f){
	auto pos = std::find(p_folder_.begin(), p_folder_.end(), f);
	p_folder_.erase(pos);
}
void Message::AddFolderOfMessage(const Message& m){
	for (auto pf : m.p_folder_)
		pf->add_message(this);
}
void Message::DeleteFolderOfThisMessage(){
	for (auto pf : p_folder_)
		pf->remove_message(this);
}

