// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef JS_FUNCTIONS_H
#define JS_FUNCTIONS_H

#include "DefinedTypes.h"
#include "FileManager.h"

class JSFunctions {
private:
	vector<string> paramData;

public:
	bool IsInCode(const string& parameter);

	int GetCountOfParams();
	vector<string> GetFuncParamsList();

	void Alert();
	void ProcessJSCode();

	static void DeleteInstance(const JSFunctions& instance);

	class Console {
	public:
		void Log();
	};
};

#endif 