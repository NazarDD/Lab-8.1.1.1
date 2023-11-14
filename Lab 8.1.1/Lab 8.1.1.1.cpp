#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	if (strlen(str) < 3)
		return 0;
	int k = 0;
	for (int i = 0; str[i] != 0; i++)
		if (str[i] ==  'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
			k++;
	return k;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
		while (i < len && str[i + 2] != 0)
		{
			if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
			{
				strcat_s(t, strlen(t) + 4, "***");
				t += 3;
				i += 5;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, len * 4 / 3 + 1, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of 'while'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}

