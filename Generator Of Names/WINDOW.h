#include <string>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

using namespace std;
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM lParam);
class WINDOW{
public:
    WINDOW();
    WINDOW(const WINDOW&) = delete;
    WINDOW& operator =(const WINDOW&) = delete;
    ~WINDOW();
    bool ProcessMessages();
    void RamdomNumber();
private:

    HINSTANCE m_hinstance;
    HWND m_hWnd;

};
