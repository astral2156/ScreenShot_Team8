#include <Windows.h>
#include "bitmap.h"

int takeScreenshot(LPTSTR filename)
{
	printf("filename: %s\n", filename);
	HDC desktopDC = GetDC(NULL); // ���� DC
	HDC compatDC = CreateCompatibleDC(desktopDC); // �纻 DC DesktopDC�� ȣȯ��
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HBITMAP bitmap = CreateCompatibleBitmap(desktopDC, width, height); // �������� ��Ʈ�� ���
	HBITMAP destBitmap = SelectObject(compatDC, bitmap); // �纻�� bitmap�� ���������� �����Ѵ�.(�� ����) 


	// BitBlt = �׸� �����ϴ� �Լ� 
	BitBlt(compatDC, 0, 0, width, height,
		desktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	bitmap = SelectObject(compatDC, destBitmap);

	int ret = createBitmapFile(filename, bitmap, compatDC);

	DeleteDC(desktopDC);
	DeleteDC(compatDC);

	return ret;
}