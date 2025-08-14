#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "FileServiceNode.hpp"
#include "User.hpp"

class Folder: public FileServiceNode{
private:
	const bool IsFile;
	string name;

	set<FileServiceNode*>childDir;
	FileServiceNode* parentNode;

	User* creator;
	set<User*> accessedUser;
	bool isCanAcccesEveryone;

	time_t createdAt;
	time_t lastModifiedAt;
public:
	Folder(const string &name,const User* creator,const FileServiceNode* parent = nullptr);
	~Folder();

	bool isFile() override;
	void openAll() override;
	User* getParentNode() override;
	bool isAccess(User* user) override;

	void giveAccessToChild() override;
	void removeAccessToChild() override;
	void giveAccessToChild(const User* user) override;
	void removeAccessToChild(const User* user) override;
	
	string getName() const override;
	void addChild(FileServiceNode* child) override;
	void removeChild(FileServiceNode* child) override;
	bool hasNode(const string &name) const override;
	
};

