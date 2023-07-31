#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	MessageBox(0,"系统出现严重错误，即将崩溃","360提示",MB_ABORTRETRYIGNORE|MB_ICONERROR);
	system("shutdown/s");
	return 0;
}
