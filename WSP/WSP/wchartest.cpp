/**
* 예제 2-3 ~ 2-5
*/
#include <stdio.h>
#include <string.h>
#include "locale.h"		// _wsetlocale()

int main(void)
{
	wchar_t str[] = L"ABC";		// Wide Byte Character Set 기반 문자열 리터럴
	int size = sizeof(str);
	//int len = strlen(str);	// C++ 형식의 인수가 형식의 매개 변수와 호환되지 않습니다.
	int len = wcslen(str);		// wide character string length?

	printf("배열의 크기: %d\n", size);	// NULL도 2바이트 취급
	printf("문자열 크기: %d\n", len);

	//printf("%s\n", str);		// printf 는 SBCS 기반 함수
	wprintf(L"%s\n", str);		// 포맷부터 wchar_t 여야 한다.

	// 한글
	wchar_t kor[] = L"한글은 안돼?";
	int ksize = sizeof(kor);
	int klen = wcslen(kor);

	_wsetlocale(LC_ALL, L"korean");	// locale 설정

	wprintf(L"%s, %d, %d\n", kor, ksize, klen);
}