// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "JSFunctions.h"

#include "JWindow.h"
#include "JConsole.h"

bool JSFunctions::IsInCode(const string& parameter) {
	string data = CodeCompiler::Decompile();
	string decodedChar;
	string funcArg;

	int count = 0;

	bool IsExist = false;

	paramData.clear();

	for (int i = 0; i < data.size(); i++) {
		if (data.substr(i, parameter.length()) == parameter) {
			int temp = i + parameter.length() + 1;
			while (data[temp] != '\"') {
				funcArg += data[temp];
				temp++;
			}
			this->paramData.emplace_back(funcArg);
			IsExist = true;
		}
	}
	return IsExist;
}

int JSFunctions::GetCountOfParams() {
	if (this->paramData.size() == 0) {
		printf("JSFunctions::GetCountOfParams(): length are 0");
	}
	return this->paramData.size();
}

vector<string> JSFunctions::GetFuncParamsList() {
	return this->paramData;
}

void JSFunctions::ProcessJSCode() {
	JConsole jcons;
	JWindow jwin;

	if (this->IsInCode("console.log(")) jcons.Log();
	if (this->IsInCode("console.warn(")) jcons.Warn();
	if (this->IsInCode("console.error(")) jcons.Error();
	if (this->IsInCode("console.clear(")) jcons.Clear();

	if (this->IsInCode("alert(") || this->IsInCode("window.alert(")) jwin.Alert();
}

void JSFunctions::DeleteInstance(const JSFunctions& instance) {
	delete& instance;
}