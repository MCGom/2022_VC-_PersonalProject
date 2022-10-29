#include "capture_screen.h"

HBITMAP capture_screen::capture_s()
{
    // ���� ������� �ػ󵵸� ���Ѵ�.
    int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    HDC hScrDC, hMemDC;
    HBITMAP hBitmap;

    // ȭ�� DC�� ��ũ������ ������ ��Ʈ���� �����Ѵ�.
    hScrDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
    hMemDC = CreateCompatibleDC(hScrDC);
    hBitmap = CreateCompatibleBitmap(hScrDC, ScreenWidth, ScreenHeight);
    SelectObject(hMemDC, hBitmap);

    // ���� ȭ���� ��Ʈ������ �����Ѵ�.
    BitBlt(hMemDC, 0, 0, ScreenWidth, ScreenHeight, hScrDC, 0, 0, SRCCOPY);

    DeleteDC(hMemDC);
    DeleteDC(hScrDC);

    return hBitmap;
}