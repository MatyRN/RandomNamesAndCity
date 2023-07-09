#include "WINDOW.h"
#include <ctime>
#include <cstdlib>
//=======Other Variables=========/
int RamdomName_A;
int RamdomName_B;
//=================NAMES RANDOM===========//

LPCSTR TextName[]={"Alfred","George","Leon","Moris","Matias","Pedro","Juan","Susan","Linda","Melody","Julie","Blanca"};
LPCSTR TextLastName[]={"Ophen","Dot","Jackson","Smith","Davies","Evans","Wood","Cooper","Lee","Scoot","Ailen","Williams"};
LPCSTR NAMESRAMDOM;
//================CITY NAME=============//
LPCSTR TextNameCity[]={"Racoon","Monkey","King","Bear","Rock","Monolit","Television","Dragon","Magma","Music","Song","White"};
LPCSTR TextCity[]={"City","Island","Kimdom","Empire","Palace","City","City","Zone","City","City","Zone","Kimdom"};
LPCSTR CITYSRAMDOM;
//========================================//

HWND GenerateName;
HWND GenerateCity;
///========Generate Ramdom Number=========/////
void RamdomNumber(){
    srand((unsigned)time(0));
        RamdomName_A = (rand()%8)+1;
        RamdomName_B = (rand()%8)+1;
}

LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
switch(uMsg){
    case WM_CREATE:
        break;
    case WM_CLOSE:
            DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
            PostQuitMessage(0);
        break;
    case WM_COMMAND:{
        if(LOWORD(wParam) ==1){
            RamdomNumber();
            NAMESRAMDOM = (string(TextName[RamdomName_A]) + " " + string(TextLastName[RamdomName_B])).c_str();
            CITYSRAMDOM = (string(TextCity[RamdomName_A]) + " Of " + string(TextNameCity[RamdomName_B])).c_str();
            SetWindowText(GenerateName,NAMESRAMDOM);//Con esto Seteas el Texto de una propiedad de Ventana
            SetWindowText(GenerateCity,CITYSRAMDOM);//Con esto Seteas el Texto de una propiedad de Ventana
            //MessageBox(hWnd,NAMESRAMDOM,"Random-Name",1);
    }
}
    return 0;
}
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

WINDOW::WINDOW(): m_hinstance(GetModuleHandle(nullptr)){
////////////////////////////////////////////
    const char* CLASS_NAME = "Ventanita";
///=====Window PRELOAD======///
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hinstance;
    wndclass.hIcon = LoadIcon(NULL,IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    RegisterClass(&wndclass);
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
//WIDTH AND HEIGHT OF THE Window//
    int width = 200;
    int height = 200;
///==Window MEASUREMENTS===========////
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
///====================================///
    AdjustWindowRect(&rect, style, false);
///Window PROPERTIES
    m_hWnd = CreateWindowEx(0,CLASS_NAME,"Ramdom Names Generator",style,rect.left,rect.top,rect.right - rect.left,rect.bottom - rect.top,NULL,NULL,m_hinstance,NULL);
    ShowWindow(m_hWnd,SW_SHOW);
///CREATE ITEMS WindowS
HWND hWndTitleNames = CreateWindow(
        ("Static"),
        ("-Random Name-"),
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        50,
        5,
        150,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
GenerateName = CreateWindow(
        ("Edit"),
        (""),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        48,
        25,
        110,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
HWND hWndTitleCity = CreateWindow(
        ("Static"),
        ("-Random City-"),
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        55,
        80,
        150,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
GenerateCity = CreateWindow(
        ("Edit"),
        (""),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        35,
        100,
        140,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
HWND hWndButtonGeneralte = CreateWindow(
        ("Button"),
        ("Generate"),
        WS_VISIBLE| WS_CHILD | WS_BORDER,
        68,
        140,
        70,
        40,
        m_hWnd,
        (HMENU) 1,
        NULL,
        NULL);
}
////DestroyWindow//////
WINDOW::~WINDOW(){
////////////////////////////////////////////
  const char* CLASS_NAME = "Ventanita";
  UnregisterClass(CLASS_NAME, m_hinstance);
////////////////////////////////////////////
}
////Process////
bool WINDOW::ProcessMessages(){
    MSG msg ={};
//////////////////////////////////////////////////
   while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }
///////////////////////////////
TranslateMessage(&msg);
DispatchMessage(&msg);
///////////////////////////
    }
    return true;
}
