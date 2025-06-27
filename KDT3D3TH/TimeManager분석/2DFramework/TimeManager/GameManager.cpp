#include "GameManager.h"
#include "TimeManager.h"


void CGameManager::a() {CGameManager::Instance().check++;
char buffer[64];
sprintf_s(buffer, "CGameManager::a() called! count = %d\n", check);
OutputDebugStringA(buffer);
}

bool CGameManager::Loop = true;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

bool CGameManager::Initialze(HINSTANCE _inst)
{

    InstanceHandle = _inst;

    lstrcpy(ClassName, TEXT("2DFramework"));
    lstrcpy(TitleName, TEXT("2DFramework"));

    RegisterWindowClass();

    //윈도우 창 생성
    if (!Create())
        return false;

    DCHandle = GetDC(WindowHandle);

    CTimeManager::Instance().Initialze();
    CTimeManager::Instance().Rent(); //만들어진 타이머를 활성화 타이머에 대입
    CTimeManager::Instance().TimerInit(0, true, 3.0, 0.0, []() {
        CGameManager::Instance().a(); // 나중에 실행할 함수
        });
    


	return true;
}

int CGameManager::Run()
{
    MSG msg;

    while (Loop)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Logic();
        }
    }

    return (int)msg.wParam;
}

bool CGameManager::Create()
{
    WindowHandle = CreateWindowW(ClassName, TitleName, WS_OVERLAPPEDWINDOW,
        0, 0, 1280, 720, nullptr, nullptr, InstanceHandle, nullptr);

    if (!WindowHandle)
        return FALSE;

    RECT windowRect = { 0,0,1280,720 };
    
    //윈도우 클라이언트 영역을 1280,720으로 하기 위해
    //맞춰준다.
    AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(WindowHandle, HWND_TOPMOST, 0, 0, windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top, SWP_NOMOVE | SWP_NOZORDER);

    //윈도우 창을 만들었다면 이걸 보여줄지 말지
    ShowWindow(WindowHandle, SW_SHOW);

    //클라이언트 영역을 강제로 다시 그리게 요청하는 함수
    UpdateWindow(WindowHandle);

    return true;
}

void CGameManager::RegisterWindowClass()
{
    WNDCLASSEXW wcex;

    //윈도우클래스 구조체의 크기를 나타낸다. 반드시 지정되어야 함.
    wcex.cbSize = sizeof(WNDCLASSEX);

    //화면에 출력 가능한 영역을 클라이언트영역
    //클라이언트 영역의 크기가(가로/세로) 변경 될 경우 다시 그려주도록 한다.
    wcex.style = CS_HREDRAW | CS_VREDRAW;

    //메시지큐에서 얻어온 메시지를 인자로 넣어서 호출해줄 함수의 주소를 넘겨준다.
    //전역함수, 정적함수
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;

    //운영제체가 부여해준 HINSTANCE를 넣어준다.
    wcex.hInstance = InstanceHandle;

    //아이콘
    wcex.hIcon = LoadIcon(InstanceHandle, MAKEINTRESOURCE(IDI_ICON1));

    //마우스커서 모양
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);

    //클라이언트 영역의 색상
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    //윈도우 메뉴를 지정
    //0을 대입하면 메뉴 없앰
    wcex.lpszMenuName = 0;

    //등록할 윈도우 클래스 이름
    wcex.lpszClassName = ClassName;

    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    RegisterClassExW(&wcex);
}

void CGameManager::Logic()
{
    //한프레임 흐른 시간
    CTimeManager::Instance().Update();
    float deltaTime = CTimeManager::Instance().GetDeltaTime();

    Input(deltaTime);

    Tick(deltaTime);

    Collision(deltaTime);

    Render(deltaTime);
}

void CGameManager::Input(float _deltaTime)
{
    //입력
}

void CGameManager::Tick(float _deltaTime)
{
    //갱신
   /* Player.Tick(_deltaTime);
    Monster.Tick(_deltaTime);
    Monster2.Tick(_deltaTime);

    size_t size = Bullets.size();
    for (size_t i = 0; i < size; ++i)
        Bullets[i].Tick(_deltaTime);

    size = MosnterBullets.size();
    for (size_t i = 0; i < size; ++i)
        MosnterBullets[i].Tick(_deltaTime);*/

    //CActorManager::Instance().Tick(_deltaTime);
}

void CGameManager::Collision(float _deltaTime)
{
    //충돌
  //  CActorManager::Instance().Collision(_deltaTime);
}

void CGameManager::Render(float _deltaTime)
{
    //render()
}

LRESULT CGameManager::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hwnd, &ps);
    }
    break;
    //윈도우 창 종료 메시지
    case WM_DESTROY:
        Loop = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

