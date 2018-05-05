#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;
int Answer;

void compare(char *word, char *S)
{
	char code;
	int len = 0;
	while (word[len] != '\0') { len++; }

	for (int i = 0; i < len; i++)
	{
		if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c')
			code = '2';
		else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f')
			code = '3';
		else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i')
			code = '4';
		else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l')
			code = '5';
		else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o')
			code = '6';
		else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's')
			code = '7';
		else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v')
			code = '8';
		else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z')
			code = '9';

		if (code != S[i])
			return;
	}
	Answer++;
}

int main(int argc, char** argv)
{
	int test_case, T, N;
	char S[1001], word[1001];

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> S >> N;
		Answer = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> word;
			compare(word, S);
		}
		cout << "#" << test_case << " " << Answer << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}