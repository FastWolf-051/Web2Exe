// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "CodeCompiler.h"

wchar_t CodeCompiler::DecompileChar(const string& character) {
    return (wchar_t)(stoi(character) >> 3);
}

string CodeCompiler::Decompile() {
	string decodedString;

	string cmpData = GetCompiledData();
	string decodedChar;

	for (int i = 0; i < cmpData.length(); i++) {
		if (cmpData[i] != ' ') {
			decodedChar += cmpData[i];
		}
		else {
			decodedChar = CodeCompiler::DecompileChar(decodedChar);
			decodedString += decodedChar;
			decodedChar = "";
		}
	}
	return decodedString;
}

string CodeCompiler::GetCompiledData() {
	ifstream cmpFile;
	cmpFile.open(Environment::GetEnvironmentPath() + "stuff/compdat.cmp");
	string cmpData((istreambuf_iterator<char>(cmpFile)), istreambuf_iterator<char>());
	return cmpData;
}