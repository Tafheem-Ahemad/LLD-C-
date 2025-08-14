#include "Folder.hpp"


Folder(const string &name,const User* creator,const FileServiceNode* parent = nullptr):
		IsFile(false), name(name), parentNode(nullptr), creator(creator), isCanAcccesEveryone(false),
		parentNode(parent) {
	createdAt = time(nullptr);
	lastModifiedAt = createdAt;
	childDir.clear();
	accessedUser.clear();
	accessedUser.insert(creator);
}
~Folder(){
	for (auto child : childDir) {
		delete child;
	}
	childDir.clear();
	accessedUser.clear();
}


bool isFile(){
	return IsFile;
}
void giveAccessToChild(const User* user = nullptr){
	if(accessedUser.find(user) != accessedUser.end()) {
		return;
	}
	accessedUser.insert(creator);
	for(auto child : childDir) {
		child->giveAccessToChild();
	}
}

void removeAccessToChild(const User* user = nullptr){
	auto it = accessedUser.find(user);
	if(it != accessedUser.end()) {
		accessedUser.erase(it);
	}
	for(auto child : childDir) {
		child->removeAccessToChild(user);
	}
}

void giveAccessToChild() {
	this->isCanAcccesEveryone = true;
	for(auto child : childDir) {
		child->giveAccessToChild();
	}
}

void removeAccessToChild() {
	this->isCanAcccesEveryone = false;
	for(auto child : childDir) {
		child->removeAccessToChild();
	}
}

void openAll(){
	// do something with the folder
	for(auto child : childDir) {
		child->openAll();
	}
}

User* getParentNode(){
	return parentNode;
}
bool isAccess(User* user){
	return accessedUser.find(user) != accessedUser.end();
}


string getName() const {
	return name;
}
void addChild(FileServiceNode* child) {
	if(child == nullptr) {
		return;
	}
	childDir.insert(child);
}
void removeChild(FileServiceNode* child){
	if(child == nullptr) {
		return;
	}
	auto it = childDir.find(child);
	if(it != childDir.end()) {
		childDir.erase(it);
		delete child;
	}
}

bool hasNode(const string &name) const {
	if(this->name == name) {
		return true;
	}
	for(auto child : childDir) {
		if(child->getName() == name) {
			return true;
		}
	}
	return false;
}