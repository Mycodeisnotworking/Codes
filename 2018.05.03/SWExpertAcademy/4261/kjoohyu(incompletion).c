
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
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
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
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}