// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "JSFunctions.h"

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

void JSFunctions::Alert() {
	if (IsInCode("alert(")) {
		MessageBoxA(nullptr, this->GetFuncParamsList()[0].c_str(), "alert box", MB_ICONWARNING);
	}
	else {
		printf("JSFunctions::Alert(): unable to call alert(), because it not was in script");
	}
}

void JSFunctions::ProcessJSCode() {
	JSFunctions::Console jconsole;

	if (this->IsInCode("alert(")) this->Alert();
	if (this->IsInCode("console.log(")) jconsole.Log();
}

void JSFunctions::DeleteInstance(const JSFunctions& instance) {
	delete &instance;
}

void JSFunctions::Console::Log() {
	JSFunctions jf;
	if (jf.IsInCode("console.log(")) {
		printf("%s", jf.GetFuncParamsList()[0].c_str());
	}
	else {
		printf("JSFunctions::Console::Log() unable to call console.log(), because it was not in script");
	}
}