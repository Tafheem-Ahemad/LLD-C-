#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "File.hpp"
#include "User.hpp"
#include "TextFile.hpp"
#include "ExcelFile.hpp"
#include "CSVFile.hpp"

class FileFactory{
private:
	FileFactory();
	~FileFactory();

	FileFactory (const FileFactory&) = delete;
	FileFactory& operator=(const FileFactory&) = delete;
	FileFactory (FileFactory&&) = delete;
	FileFactory& operator=(FileFactory&&) = delete;
public:
	static FileFactory& getIntance();
	static File* createFile(const string &type, const string &name, const User* creator, const FileServiceNode* parent = nullptr) {
		if (type == "text") {
			return new TextFile(name, creator, parent);
		} else if (type == "excel") {
			return new ExcelFile(name, creator, parent);
		} else if (type == "csv") {
			return new CSVFile(name, creator, parent);
		} else {
			throw runtime_error("Invalid file type");
		}
	}
}