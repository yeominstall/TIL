/**
* ���� 2-6
*/
#include <stdio.h>

//int main(int argc, char* argv[])
//{
//	int i;
//	for (int i = 0; i < argc; i++)
//	{
//		fputws(argv[i], stdout);	// argv�� char*, fputws�� const wchar_t�� ���ڷ� �޴´�.
//		// ��������� �⺻������ ���ڸ� �ѱ� �� MBCS�� �ѱ�� ������, main �Լ� ��ü�� �ٲ�� �Ѵ�.
//	}
//	return 0;
//}

int wmain(int argc, wchar_t* argv[])	// argv Ÿ�� �Ӹ� �ƴ϶� main -> wmain���� �ٲ���� �Ѵ�.
{
	int i;
	for (int i = 0; i < argc; i++)
	{
		fputws(argv[i], stdout);
	}
	return 0;
}