// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "FileManager.h"

string FileManager::ReadFile(const string& file_name) {
	fstream file;
	string fileDataTemp;
	string path = Environment::GetEnvironmentPath() + file_name;
	file.open(path);
	if (file.is_open()) {
		string fileData((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		fileDataTemp = fileData;
	}
	else if (!IsCompiledScriptExists()) {
		printf("The file \"%s\" are not exist in folder\n", file_name.c_str());
		return "none";
	}
	file.close();
	return fileDataTemp;
}

string FileManager::GetHTMLcode() {
	return ReadFile("index.html");
}

string FileManager::GetCSScode() {
	return ReadFile("style.css");
}

string FileManager::GetJScode() {
	return ReadFile("script.js");
}

string FileManager::GetHTMLWindowTitle() {
	string data = GetWebpageCode();
	string title;
	for (int i = 0; i < data.length(); i++) {
		if (data.substr(i, 7) == "<title>") {
			int ci = i + 7;
			while (data[ci] != 60) {
				title += data[ci];
				ci++;
			}
		}
	}
	return title;
}

string FileManager::GetWebpageCode() {
	string fullData;

	if (IsCompiledScriptExists()) {
		fullData = CodeCompiler::Decompile();
	}
	else {
		string htmlData = GetHTMLcode();
		string cssData = GetCSScode();
		string jsData = GetJScode();
		fullData = htmlData;

		if (cssData != "none") fullData += "\n<style>\n" + cssData + "\n</style>";
		if (jsData != "none") fullData += "\n<script>\n" + jsData + "\n</script>";
	}
	return fullData;
}

void FileManager::CompileSourceCode() {
	fstream file;
	string path = (Environment::GetEnvironmentPath() + "stuff/compdat.cmp");
	string webData = GetWebpageCode();
	string finalData;

	for (int i = 0; i < webData.length() - 1; i++) {
		finalData += to_string((int)(wchar_t)webData[i] << 3) + " ";
	}

	file.open(path, fstream::out);
	file << finalData;
	file.close();

	// remove original source files after compiling it
	string env = Environment::GetEnvironmentPath();

	remove((env + "index.html").c_str());
	remove((env + "style.css").c_str());
	remove((env + "script.js").c_str());
}

bool FileManager::IsCompiledScriptExists() {
	string path = Environment::GetEnvironmentPath() + "stuff/compdat.cmp";
	filesystem::path cmp(path);
	return filesystem::exists(cmp);
}

bool FileManager::IsShowCMD() {
	string path = Environment::GetEnvironmentPath() + "stuff/config.txt";
	ifstream config(path);
	string data((istreambuf_iterator<char>(config)), istreambuf_iterator<char>());
	config.close();
	// showCMDonStartup = 1
	if (data[data.length() - 2] == '0') return false;
	return true;
}