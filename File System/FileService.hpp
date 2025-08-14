#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "FileServiceNode.hpp"
#include "File.hpp"
#include "Folder.hpp"
#include "User.hpp"
#include "FileFactory.hpp"

class FileService{
private:
	
	map<string,User*>mp;

	FileService();
	~FileService();

	FileService (const FileService&) =delete;
	FileService& operator=(const FileService&) = delete;
	FileService (FileService&&) =delete;
	FileService& operator=(FileService&&) = delete;

public:

	static FileService& getIntance() const;
	User* getUser(const string &userId);
	
	void giveAccessAll(const FileServiceNode* node);
	void removeAccessAll(const FileServiceNode* node);

	void giveAccess(const string &userId,FileServiceNode* node);
	void removeAccess(const string &userId,FileServiceNode* node);

	FileServiceNode* createFile(const string &userId,const string &name,const string &type);
	FileServiceNode* createFolder(const string &userId,const string &name);

	FileServiceNode* createSubFile(const string &userId,const string &name,const string &type,FileServiceNode* parent);
	FileServiceNode* createSubFolder(const string &userId,const string &name, FileServiceNode* parent);

public:
	string generateUserId();
	string randomString(int length);
};

