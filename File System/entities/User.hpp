#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "FileServiceNode.hpp"

class User{
private:
	const string id;
	string name;
	FileServiceNode* rootDir;
public:
	User(const string &id,const string &name);
	~User();

	FileServiceNode* getRootDir() const;
	string getName() const;
	string getId() const;

	void createFolder(const string &name);
	void createFile(const string &type, const string &name);

	void readFile(FileServiceNode* fileNode);
};

