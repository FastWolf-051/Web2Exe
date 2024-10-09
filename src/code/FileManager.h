// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "DefinedTypes.h"
#include "Environment.h"
#include "CodeCompiler.h"

class FileManager {
public:
	static string ReadFile(const string& file_name);
	static string GetHTMLcode();
	static string GetCSScode();
	static string GetJScode();
	static string GetHTMLWindowTitle();
	static string GetWebpageCode();

	static void CompileSourceCode();

	static bool IsCompiledScriptExists();
	static bool IsShowCMD();
};

#endif