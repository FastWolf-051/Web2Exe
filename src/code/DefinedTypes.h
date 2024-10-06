// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#ifndef DEFINED_TYPES_H
#define DEFINED_TYPES_H

// disable warning about <codecvt> is deprecated since C++ 20
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <Windows.h>
#include <WebView2.h>
#include <wrl.h>
#include <string>
#include <fstream>
#include <codecvt> // work with wchar_t
#include <iostream>
#include <iterator>
#include <filesystem>

using namespace Microsoft::WRL;
using namespace std;

#define overflow static_cast<blockOverflow>

typedef ICoreWebView2 WebView;
typedef ICoreWebView2Controller WebController;
typedef ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler WebEnvironmentHandler;
typedef ICoreWebView2Environment WebEnvironment;
typedef ICoreWebView2NavigationCompletedEventArgs WebEventArgs;
typedef ICoreWebView2CreateCoreWebView2ControllerCompletedHandler WebControllerHandler;
typedef ICoreWebView2NavigationCompletedEventHandler WebNavigationHandler;

typedef HWND WindowHandle;
typedef HINSTANCE InstanceHandle;
typedef WNDCLASS WindowClass;
typedef MSG Message;

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type blockOverflow;

typedef const wchar_t* wchar_ptr;
typedef unsigned __int64 uint64; // wparam
typedef __int64 int64; // lparam, lresult
typedef tagRECT Bounds;
typedef unsigned int uint32; // uint
typedef long long64; // hresult

#endif