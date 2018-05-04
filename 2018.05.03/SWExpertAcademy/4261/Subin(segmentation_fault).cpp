#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	char input_s[1000];
	char input_words[1000000];
	int N;

	freopen("input.txt", "r", stdin);
	cin >> T;

	int count = 0;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		count = 0;
		memset(input_s, 0, 1000);
		memset(input_words, 0, 1000000);
		cin >> input_s;

		cin >> N;

		cin.ignore();
		cin.getline(input_words, 1000000);

		string *code = new string[N];

		char **word = new char*[N];
		for (int i = 0; i < N; i++)
			word[i] = new char[1000000];

		for (int i = 0; i < N; i++) word[i] = NULL;

		word[0] = strtok(input_words, " ");

		for (int i = 1; i < N; i++)
			word[i] = strtok(NULL, " ");

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < (int)strlen(word[i]); j++)
			{
				if (word[i][j] == 'a' || word[i][j] == 'b' || word[i][j] == 'c')
					code[i] = code[i] + '2';
				else if (word[i][j] == 'd' || word[i][j] == 'e' || word[i][j] == 'f')
					code[i] = code[i] + '3';
				else if (word[i][j] == 'g' || word[i][j] == 'h' || word[i][j] == 'i')
					code[i] = code[i] + '4';
				else if (word[i][j] == 'j' || word[i][j] == 'k' || word[i][j] == 'l')
					code[i] = code[i] + '5';
				else if (word[i][j] == 'm' || word[i][j] == 'n' || word[i][j] == 'o')
					code[i] = code[i] + '6';
				else if (word[i][j] == 'p' || word[i][j] == 'q' || word[i][j] == 'r' || word[i][j] == 's')
					code[i] = code[i] + '7';
				else if (word[i][j] == 't' || word[i][j] == 'u' || word[i][j] == 'v')
					code[i] = code[i] + '8';
				else if (word[i][j] == 'w' || word[i][j] == 'x' || word[i][j] == 'y' || word[i][j] == 'z')
					code[i] = code[i] + '9';
			}

			if (code[i] == input_s)
				count++;
		}

		cout << "#" << test_case << " " << count << endl;

		delete[] code;
		//for (int i = 0; i < N; i++)
		//	delete[] word[i];
		delete[] word;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
