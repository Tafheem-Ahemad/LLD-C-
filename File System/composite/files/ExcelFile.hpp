#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "File.hpp"
#include "User.hpp"
#include "FileServiceNode.hpp"

class ExcelFile : public File{
private:
	/* data */
public:
	ExcelFile(const string &name,const User* creator,const FileServiceNode* parent = nullptr);
	~ExcelFile();

	void readFile() override;
	void WriteFile() override;
};

