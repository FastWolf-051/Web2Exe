// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef TOOLS_H
#define TOOLS_H

#include "DefinedTypes.h"

class Tools final {
public:
	static const wchar_t* ConvertToWideChar(const string& dat) {
		wstring_convert<codecvt_utf8<wchar_t>> converter;
		return converter.from_bytes(dat).c_str();
	}
	static string GetSetupHTMLstring() {
		return "data:text/html,";
	}
};

#endif