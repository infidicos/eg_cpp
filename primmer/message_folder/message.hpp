#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

class Folder;

class Message{
 public:
	Message(std::string s = ""): content_{s}{}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void SaveToFolder(Folder&);
	void RemoveFromFolder(Folder&);

 private:
	void AddFolderOfMessage(const Message&);
	void DeleteFolderOfThisMessage();

	void add_folder(Folder*);
	void remove_folder(Folder*);

	std::string content_;
	std::vector<Folder*> p_folder_;

	friend class Folder;
	friend std::ostream& operator<<(std::ostream&, Folder&);
};
#endif
