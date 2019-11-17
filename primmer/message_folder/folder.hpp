#ifndef FOLDER_HPP
#define FOLDER_HPP

#include <string>
#include <vector>

class Message;

class Folder{
public:
	Folder(std::string s = ""): tag_{s}{};
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

private:
	void AddMessageOfFolder(const Folder&);
	void DeleteMessageOfThisFolder();

	void add_message(Message*);
	void remove_message(Message*);

	std::string tag_;
	std::vector<Message*> p_message_;

	friend class Message;
	friend std::ostream& operator<<(std::ostream& b, Folder&);
	friend void swap(Folder&, Folder&);
};
#endif
