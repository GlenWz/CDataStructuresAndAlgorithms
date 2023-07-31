#include <time.h>
#include <mathgl.h>
#pragma comment(lib,"mathgl.lib")
int sample(mglGraph *gr)
{
	gr->Rotate(60, 40);
	gr->Box();
	gr->FSurf("x*x-y*y");
	return 0;
}
int main(int, char **)
{


	/*mglCanvasGLUT gr;
	gr.Window(0, 0, sample, "test");*/
	mglGraph gr;
	sample(&gr);
		time_t t; struct tm *p; char name[30];
	time(&t); p = localtime(&t);
	sprintf(name, "%d-%d-%d-%dh.%dm.%ds.bmp", 1900+p->tm_year,
		1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
	printf("%s", name);
	gr.WriteBMP(name);
	system(name);
	return 0;
}

