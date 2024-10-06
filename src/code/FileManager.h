#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "DefinedTypes.h"
#include "Environment.h"

class FileManager {
public:
	static string ReadFile(const string& file_name);
	static string GetHTMLcode();
	static string GetCSScode();
	static string GetJScode();
	static string GetHTMLWindowTitle();
	static string GetWebpageCode();

	static void CompileSourceCode();
	static void DeleteCache();

	static bool IsCompiledScriptExists();
	static bool IsShowCMD();
};

#endif