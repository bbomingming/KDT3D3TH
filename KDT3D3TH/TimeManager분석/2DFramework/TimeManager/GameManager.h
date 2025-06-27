#pragma once
#include "../Info.h"
#include "Singleton.h"
#include "Timer.h"
#include "TimeManager.h"
#include <vector>

class CGameManager : public SSingleton<CGameManager>
{
	friend SSingleton<CGameManager>;

protected:
	CGameManager();
	~CGameManager();

private:
	CGameManager(CGameManager&) = delete;
	CGameManager& operator=(const CGameManager&) = delete;

private:
	HINSTANCE InstanceHandle;
	HWND WindowHandle;
	HDC DCHandle;
	TCHAR ClassName[256] = {};
	TCHAR TitleName[256] = {};
	static bool Loop;
	float ClearColor[4] = {1,1,1,1};




public:
	bool Initialze(HINSTANCE _inst);
	int Run();
	HDC GetHDCHandle() { return DCHandle; }

	int check = 0;


private:
	bool Create();
	void RegisterWindowClass();
	void Logic();
	void Input(float _deltaTime);
	void Tick(float _deltaTime);
	void Collision(float _deltaTime);
	void Render(float _deltaTime);
	void a();

	static LRESULT CALLBACK    WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

