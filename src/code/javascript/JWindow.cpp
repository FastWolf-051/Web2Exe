// Original created by fastwolf
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "JWindow.h"

void JWindow::Alert() {
	if (IsInCode("alert(")) {
		MessageBoxA(nullptr, this->GetFuncParamsList()[0].c_str(), "alert box", MB_ICONWARNING);
	}
	else callInability(this_class, env_func);
}