#include "capture_screen.h"

HBITMAP capture_screen::capture_s()
{
    // 메인 모니터의 해상도를 구한다.
    int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    HDC hScrDC, hMemDC;
    HBITMAP hBitmap;

    // 화면 DC와 스크린샷을 저장할 비트맵을 생성한다.
    hScrDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
    hMemDC = CreateCompatibleDC(hScrDC);
    hBitmap = CreateCompatibleBitmap(hScrDC, ScreenWidth, ScreenHeight);
    SelectObject(hMemDC, hBitmap);

    // 현재 화면을 비트맵으로 복사한다.
    BitBlt(hMemDC, 0, 0, ScreenWidth, ScreenHeight, hScrDC, 0, 0, SRCCOPY);

    DeleteDC(hMemDC);
    DeleteDC(hScrDC);

    return hBitmap;
}