// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef J_CONSOLE
#define J_CONSOLE

#include "JSFunctions.h"

#define SKY_COLOR 3
#define RED_COLOR 4
#define YELLOW_COLOR 6
#define DEFAULT_COLOR 7

#define this_class "JConsole::"

#define log(message) printf("[log]: %s\n", message)
#define error(message) printf("[error]: %s\n", message)
#define warn(message) printf("[warning]: %s\n", message)

class JConsole : public JSFunctions {
private:
	void SetColor(int color);
	void ResetColor();
public:
	void Log();
	void Error();
	void Warn();
	void Clear();
};

#endif