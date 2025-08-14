#include "File.hpp"

File(const string &name,const User* creator,const FileServiceNode* parent = nullptr):
		IsFile(true), name(name), parentNode(parent), creator(creator), isCanAcccesEveryone(false) {
	createdAt = time(nullptr);
	lastModifiedAt = createdAt;
	accessedUser.clear();
	accessedUser.insert(creator);
}
~File(){
	accessedUser.clear();
}

bool isFile(){
	return IsFile;
}
void giveAccessToChild(){
	this->isCanAcccesEveryone = true;
}
void removeAccessToChild(){
	this->isCanAcccesEveryone = false;
}
void openAll(){
	// do something with the file
	cout<<"Opening file: " << name << endl;
}
void giveAccessToChild(const User* user){
	accessedUser.insert(user);
}
void removeAccessToChild(const User* user){
	auto it = accessedUser.find(user);
	if(it != accessedUser.end()) {
		accessedUser.erase(it);
	}
}

User* getParentNode(){
	return parentNode;
}
bool isAccess(User* user){
	return accessedUser.find(user) != accessedUser.end();
}


string getName() const{
	return name;
}
void addChild(FileServiceNode* child){
	throw runtime_error("Cannot add child to a file");
}
void removeChild(FileServiceNode* child){
	throw runtime_error("Cannot remove child from a file");
}

bool hasNode(const string &name) const {
	if(name == this->name) {
		return true;
	}
	return false; // Files do not have children
}