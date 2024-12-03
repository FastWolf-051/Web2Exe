// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef JS_FUNCTIONS_H
#define JS_FUNCTIONS_H

#include "../DefinedTypes.h"
#include "../FileManager.h"

#define env_func __func__
#define callInability(env_class, e_func) printf("%s%s(): unable to call %s(), because this function not exists in script\n", env_class, e_func, e_func);

class JSFunctions {
private:
	vector<string> paramData;

public:
	bool IsInCode(const string& parameter);

	int GetCountOfParams();
	vector<string> GetFuncParamsList();

	void ProcessJSCode();

	static void DeleteInstance(const JSFunctions& instance);
};

#endif 