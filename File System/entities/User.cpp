#include "User.hpp"

user::User(const string &id,const string &name): id(id), name(name){
	rootDir = new Folder("user:"+is, this); 
}
user::~User() {
	if (rootDir) {
		delete rootDir;
		rootDir = nullptr;
	}
}

FileServiceNode* getRootDir() const{
	return rootDir;
}
string getName() const{
	return name;
}
string getId() const{
	return id;
}

void createFolder(const string &name){
	if(getRootDir()->hasNode(name)) {
		throw runtime_error("Folder with this name already exists");
	}

	Folder* folder = new Folder(name, this, getRootDir());
	getRootDir()->addChild(folder);
}

void createFile(const string &type, const string &name) {
	if(getRootDir()->hasNode(name)) {
		throw runtime_error("File with this name already exists");
	}

	File* file = createFile(type, name, this);
	if(file){
		getRootDir()->addChild(file);
	} else {
		throw runtime_error("Invalid file type");
	}
}


void readFile(FileServiceNode* fileNode) {
	if(fileNode == nullptr || !fileNode->isFile()) {
		throw runtime_error("Invalid file node");
	}

	if(!fileNode->isAccess(this)) {
		throw runtime_error("Access denied to read the file");
	}

	File* file = dynamic_cast<File*>(fileNode);
	if(file) {
		file->readFile();
	} else {
		throw runtime_error("Cannot read from a non-file node");
	}
}