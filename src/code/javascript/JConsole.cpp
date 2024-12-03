// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "JConsole.h"

void JConsole::SetColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void JConsole::ResetColor() {
	SetColor(DEFAULT_COLOR);
}

void JConsole::Log() {
	if (IsInCode("console.log(")) {
		SetColor(SKY_COLOR);
		log(GetFuncParamsList()[0].c_str());
		ResetColor();
	}
	else callInability(this_class, env_func);
}

void JConsole::Error() {
	if (IsInCode("console.error(")) {
		SetColor(RED_COLOR);
		error(GetFuncParamsList()[0].c_str());
		ResetColor();
	}
	else callInability(this_class, env_func);
}

void JConsole::Warn() {
	if (IsInCode("console.warn(")) {
		SetColor(YELLOW_COLOR);
		warn(GetFuncParamsList()[0].c_str());
		ResetColor();
	}
	else callInability(this_class, env_func);
}

void JConsole::Clear() {
	if (IsInCode("console.clear(")) {
		system("cls");
	}
	else callInability(this_class, env_func);
}