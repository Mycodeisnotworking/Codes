
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(char *myWord, char **compareWord, int N) {
	int value = 0;
	for (int i = 0; i < N; i++) {
		if (!strcmp(myWord, compareWord[i]))
			value++;
	}
	return value;
}
int main(void)
{
	int test_case;
	int T;
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int i, j, n, m, N, Answer = 0;
		char S[4] = "";
		char changeN[4] = "";
		char keyPad[8][4] = { {'a','b','c'} , {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'},{'w','x','y','z' }
	};
		char **word = 0;
		char temp[4] = "";
		char tempArr[1000000];
		char *mytoken = NULL;

		scanf("%s", &S);
		scanf("%d", &N);

		for (i = 0; i < 8; i++)
			for (j = 0; j < 3; j++)
				keyPad[i][j] = 'a' + i * 3 + j;

		word = (char**)malloc(sizeof(char*)*N);
		for (i = 0; i < N; i++) {
			*word = (char*)malloc(sizeof(char) * (1000000/N));
		}
		for (i = 0; i < N; i++) {
			scanf("%s", &tempArr);
			strcpy(word[i], tempArr);
			printf("%s\n", word[i]);
		}

		for (i = 0; i < 4; i++) {
			temp[0] = keyPad[S[0]][i];
			if (!temp[1])
				Answer += compare(temp, word, N);
			for (j = 0; j < 4; j++) {
				temp[1] = keyPad[S[1]][j];
				if (!temp[2])
					Answer += compare(temp, word, N);
				for (n = 0; n < 4; n++) {
					temp[2] = keyPad[S[2]][n];
					if (!temp[3])
						Answer += compare(temp, word, N);
					for (m = 0; m < 4; m++) {
						temp[3] = keyPad[S[3]][m];
						Answer += compare(temp, word, N);
					}
				}
			}
		}
		printf("#%d %d\n", test_case, Answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}