#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"

class FileServiceNode{
public:
	virtual bool isFile()=0;
	virtual void openAll() = 0;
	virtual User* getParentNode() = 0;
	virtual bool isAccess(User* user) = 0;

	virtual void giveAccessToChild() = 0;
	virtual void removeAccessToChild() = 0;

	virtual void giveAccessToChild(const User* user) = 0;
	virtual void removeAccessToChild(const User* user) = 0;

	virtual string getName() const = 0;
	virtual void addChild(FileServiceNode* child) = 0;
	virtual void removeChild(FileServiceNode* child) = 0;
	virtual bool hasNode(const string &name) const=0;

	virtual ~FileServiceNode() = default;
};
