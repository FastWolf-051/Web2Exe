// Original created by fastdevil
// -- You can modify/rewrite this project to another language
// -- only with this license
// All rights reserved by @fastwolf. 2024

#include "DefinedTypes.h"
#include "FileManager.h"
#include "Tools.h"

ComPtr<WebController> webviewController;
ComPtr<WebView> webviewWindow;

bool IsDebug = FileManager::IsShowCMD();

void InitializeWebView2(HWND handle) {
    auto createWebView2Environment = [handle](long64 result, WebEnvironment* environment) -> long64 {
        auto createWebView2Controller = [handle](long64 result, WebController* controller) -> long64 {
            if (controller != nullptr) {
                webviewController = controller;
                webviewController->get_CoreWebView2(&webviewWindow);
            }

            Bounds clientBounds;
            GetClientRect(handle, &clientBounds);
            webviewController->put_Bounds(clientBounds);

            if (!FileManager::IsCompiledScriptExists()) {
                FileManager::CompileSourceCode();
            }

            string htmlData = Tools::GetSetupHTMLstring() + FileManager::GetWebpageCode();
            wchar_ptr htmlContent = Tools::ConvertToWideChar(htmlData); 
            webviewWindow->Navigate(htmlContent);

            return 0;
        };
    environment->CreateCoreWebView2Controller(handle, Callback<WebControllerHandler>(createWebView2Controller).Get());

    return 0;
    };

    CreateCoreWebView2EnvironmentWithOptions(nullptr, nullptr, nullptr, Callback<WebEnvironmentHandler>(createWebView2Environment).Get());
}

int64 __stdcall WindowProcess(WindowHandle handle, uint32 uMessage, uint64 wParam, int64 lParam) {
    switch (uMessage) {
        case 5: // wm_size
            if (webviewController != nullptr) {
                Bounds bounds;
                GetClientRect(handle, &bounds);
                webviewController->put_Bounds(bounds);
            }
            return 0;
        case 2: // wm_destroy
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(handle, uMessage, wParam, lParam);
}

int __stdcall wWinMain(InstanceHandle hInstance, InstanceHandle, wchar_t*, int nCmdShow) {
    if (IsDebug) {
        AllocConsole();

        FILE* console;
        freopen_s(&console, "conout$", "w", stdout);
        freopen_s(&console, "conin$", "r", stdin);
    }

    wchar_ptr className = L"WebViewClass";

    WindowClass wincls = {};
    wincls.lpfnWndProc = WindowProcess;
    wincls.hInstance = hInstance;
    wincls.lpszClassName = className;
    RegisterClassW(&wincls);

    WindowHandle handle = CreateWindowExW(
        0,
        className,
        L"None",
        WS_OVERLAPPEDWINDOW,
        GetSystemMetrics(SM_CXSCREEN) / 2 - (600 / 2),
        GetSystemMetrics(SM_CYSCREEN) / 2 - (400 / 2),
        600,
        400,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (!handle) return 0;

    ShowWindow(handle, nCmdShow);
    SetWindowTextA(handle, FileManager::GetHTMLWindowTitle().c_str());
    InitializeWebView2(handle);

    if (IsDebug) FreeConsole();

    Message msg = {};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}