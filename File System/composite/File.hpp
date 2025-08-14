#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "FileServiceNode.hpp"
#include "User.hpp"

class File : public FileServiceNode{
protected:
	const bool IsFile;
	string name;

	FileServiceNode* parentNode;

	User* creator;
	set<User*> accessedUser;
	bool isCanAcccesEveryone;

	time_t createdAt;
	time_t lastModifiedAt;
public:
	File(const string &name,const User* creator,const FileServiceNode* parent = nullptr);
	~File();

	bool isFile() const;
	void openAll() const;
	User* getParentNode() const;
	bool isAccess(User* user) const;

	void giveAccessToChild() const;
	void removeAccessToChild() const;
	void giveAccessToChild(const User* user) const;
	void removeAccessToChild(const User* user) const;

	string getName() const override;
	void addChild(FileServiceNode* child) override;
	void removeChild(FileServiceNode* child) override;

	bool hasNode(const string &name) const override;

	virtual void readFile()=0;
	virtual void WriteFile()=0;
};
