#pragma once
#include "TimeManager/GameManager.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//진입점
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    if (!CGameManager::Instance().Initialze(hInstance))
        return 0;

    int ret = CGameManager::Instance().Run();

#ifdef _DEBUG
    // 프로그램 종료 시 메모리 누수 자동 검사 기능 활성화
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    return ret;
}


