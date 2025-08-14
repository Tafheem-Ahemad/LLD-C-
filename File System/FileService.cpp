#include "FileService.hpp"

static FileService& FileService::getIntance() const{
	static FileService instance;
	return instance;
}
User* FileService::getUser(const string &userId){
	auto it = mp.find(userId);
	if(it != mp.end()) {
		return it->second;
	}
	return nullptr; 
}
void FileService::giveAccesstAll(const FileServiceNode* node){
	if(node == nullptr) {
		throw runtime_error("Invalid node");
	}
	
	node->giveAccessToChild();
}

void FileService::removeAccesstAll(const FileServiceNode* node){
	if(node == nullptr) {
		throw runtime_error("Invalid node");
	}
	
	node->removeAccessToChild();
}

void FileService::giveAccess(const string &userId,FileServiceNode* node){
	if(node == nullptr) {
		throw runtime_error("Invalid File/Folder name");
	}
	
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	node->giveAccessToChild(user);
}
void FileService::removeAccess(const string &userId,FileServiceNode* node){
	if(node == nullptr) {
		throw runtime_error("Invalid File/Folder name");
	}
	
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	node->removeAccessToChild(user);
}

FileServiceNode* FileService::createFile(const string &userId,const string &name,const string &type){
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	FileServiceNode* fileNode = FileFactory::getIntance().createFile(type, name, user, user->getRootDir());
	
	user->getRootDir()->addChild(fileNode);
	return fileNode;
}

FileServiceNode* FileService::createFolder(const string &userId,const string &name){
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	if(user->getRootDir()->hasNode(name)) {
		throw runtime_error("Folder with this name already exists");
	}
	
	Folder* folder = new Folder(name, user, user->getRootDir());
	user->getRootDir()->addChild(folder);
	return folder;
}

FileServiceNode* FileService::createSubFile(const string &userId,const string &name,const string &type,FileServiceNode* parent){
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	if(parent == nullptr || !parent->isFile()) {
		throw runtime_error("Invalid parent node");
	}

	if(parent->hasNode(name)) {
		throw runtime_error("File with this name already exists in the parent folder");
	}
	if(!parent->isAccess(user)) {
		throw runtime_error("User does not have access to the parent folder");
	}
	
	FileServiceNode* fileNode = FileFactory::getIntance().createFile(type, name, user, parent);
	parent->addChild(fileNode);
	return fileNode;
}
FileServiceNode* FileService::createSubFolder(const string &userId,const string &name, FileServiceNode* parent){
	User* user = getUser(userId);
	if(user == nullptr) {
		throw runtime_error("User not found");
	}
	
	if(parent == nullptr || !parent->isFile()) {
		throw runtime_error("Invalid parent node");
	}

	if(parent->hasNode(name)) {
		throw runtime_error("Folder with this name already exists in the parent folder");
	}
	if(!parent->isAccess(user)) {
		throw runtime_error("User does not have access to the parent folder");
	}
	
	Folder* folder = new Folder(name, user, parent);
	parent->addChild(folder);
	return folder;
}

string FileService::generateUserId(){
	return "GAME" + randomString(8);
}


string FileService::randomString(const int length) {
    const string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    random_device rd;       
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, chars.size() - 1);

    string result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result += chars[distrib(gen)];
    }
    return result;
}