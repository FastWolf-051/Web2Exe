// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef CODE_COMPILER_H
#define CODE_COMPILER_H

#include "DefinedTypes.h"
#include "Environment.h"

class CodeCompiler {
public:
	static wchar_t DecompileChar(const string& character);

	static string Decompile();
	static string GetCompiledData();
};

#endif