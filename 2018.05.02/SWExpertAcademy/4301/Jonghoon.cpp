#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int N, M;
int Map[1000][1000];

bool Search(int row, int col) {
	int dx[2] = { -2 , 0 };
	int dy[2] = { 0, -2 };
	for (int i = 0; i < 2; i++) {
		if (row < 2 && i == 0)
			continue;
		else if (col < 2 && i == 1)
			continue;

		if (Map[row + dx[i]][col + dy[i]] == 1) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	int test_case;
	int T;
	int Answer;
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
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Map[i][j] = 0;
			}
		}

		Map[0][0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 && j == 0)
					continue;
				if (Search(i, j)) {
					Map[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Answer += Map[i][j];
			}
		}

		printf("#%d %d\n",test_case, Answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}