// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "DefinedTypes.h"

class Environment final {
public:
	static string GetEnvironmentPath() {
		char path[1024];
		DWORD result = GetModuleFileNameA(nullptr, path, sizeof(path));
		string envpath = path;
		return envpath.substr(0, envpath.length() - 10); // current path without exe name
	}
};

#endif