/**
* 예제 2-6
*/
#include <stdio.h>

//int main(int argc, char* argv[])
//{
//	int i;
//	for (int i = 0; i < argc; i++)
//	{
//		fputws(argv[i], stdout);	// argv는 char*, fputws는 const wchar_t를 인자로 받는다.
//		// 윈도우즈는 기본적으로 인자를 넘길 때 MBCS로 넘기기 때문에, main 함수 자체를 바꿔야 한다.
//	}
//	return 0;
//}

int wmain(int argc, wchar_t* argv[])	// argv 타입 뿐만 아니라 main -> wmain으로 바꿔줘야 한다.
{
	int i;
	for (int i = 0; i < argc; i++)
	{
		fputws(argv[i], stdout);
	}
	return 0;
}