#include "TextFile.hpp"
TextFile::TextFile(const string &name, const User* creator, const FileServiceNode* parent)
	: File(name, creator, parent) , type("text") {
	// Additional initialization if needed
}
TextFile::~TextFile() {
	// Cleanup if needed
}

void TextFile::readFile() {
	// Implementation for reading text file
	cout << "Reading text file: " << getName() << endl;
}
void TextFile::WriteFile() {
	// Implementation for writing to text file
	cout << "Writing to text file: " << getName() << endl;
}