#include <windows.h>
#include <math.h>
#define MYCNAME "MyWClass"
#define PI 3.14
void DrawRotateEllipse(HDC hdc, int x, int y, int r1, int r2, int ll, int rl, double a)
{
	double sina, cosa;
	int i, xorig, yorig, nx, ny;
	sina = sin(a);
	cosa = cos(a);
	for(i = 0; i < 361; i++)
	{
		xorig =  r1 * cos((i) * (PI / 180));
		yorig =  r2 * sin((i) * (PI / 180));
		nx = x + xorig * cosa + yorig * sina;
		ny = y + yorig * cosa - xorig * sina;

		if(!i || (nx<ll || nx>rl))
			MoveToEx(hdc, nx, ny, NULL);
		else
		{
		LineTo(hdc, nx, ny);
		}
	}
}
void MyDrawHeart(HWND hWnd, HDC mHDC)
{
	RECT wRect;
	HPEN mPen, mOldPen;
	HBRUSH mBrush, mOldBrush;
	int x, y;

	int oADR;

	GetClientRect(hWnd, &wRect);
	x = (wRect.right - wRect.left) / 2;
	y = (wRect.bottom - wRect.top) / 2;
	
	FillRect(mHDC, &wRect, (HBRUSH) (COLOR_WINDOW+1));

	mPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	mOldPen = SelectObject(mHDC, mPen);
	DrawRotateEllipse(mHDC, x, y, y/3, y*2/3, 0, x, PI / 4);
	DrawRotateEllipse(mHDC, x, y, y/3, y*2/3, x, x*2 , -PI / 4);
	SelectObject(mHDC, mOldPen);
	DeleteObject(mPen);
	
	mBrush = CreateHatchBrush (HS_DIAGCROSS,RGB(255,24,24));
	mOldBrush = SelectObject(mHDC, mBrush);
	FloodFill(mHDC, x, y, RGB(0,0,0));
	SelectObject(mHDC, mOldBrush);
	DeleteObject(mBrush);
		
}
LRESULT CALLBACK myWndProc(HWND hWnd, UINT Msg,
			   WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps; 
	HDC hDC;
    switch(Msg)
    {

