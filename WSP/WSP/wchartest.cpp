/**
* ���� 2-3 ~ 2-5
*/
#include <stdio.h>
#include <string.h>
#include "locale.h"		// _wsetlocale()

int main(void)
{
	wchar_t str[] = L"ABC";		// Wide Byte Character Set ��� ���ڿ� ���ͷ�
	int size = sizeof(str);
	//int len = strlen(str);	// C++ ������ �μ��� ������ �Ű� ������ ȣȯ���� �ʽ��ϴ�.
	int len = wcslen(str);		// wide character string length?

	printf("�迭�� ũ��: %d\n", size);	// NULL�� 2����Ʈ ���
	printf("���ڿ� ũ��: %d\n", len);

	//printf("%s\n", str);		// printf �� SBCS ��� �Լ�
	wprintf(L"%s\n", str);		// ���˺��� wchar_t ���� �Ѵ�.

	// �ѱ�
	wchar_t kor[] = L"�ѱ��� �ȵ�?";
	int ksize = sizeof(kor);
	int klen = wcslen(kor);

	_wsetlocale(LC_ALL, L"korean");	// locale ����

	wprintf(L"%s, %d, %d\n", kor, ksize, klen);
}