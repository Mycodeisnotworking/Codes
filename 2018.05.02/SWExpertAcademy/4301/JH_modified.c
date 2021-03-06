#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _DEBUG
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


int CanYouAdd(int **arr, int x, int y, int M, int N) {
	if (x >= 2)
		if (arr[x - 2][y])
			return 0;
	if (y >= 2)
		if (arr[x][y - 2])
			return 0;
	return 1;
}
int main(void)
{
	int test_case;
	int T;
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif


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
		int N, M;
		scanf("%d %d", &N, &M);
		int i, j, Answer = 0, count = 0;
		int **arr;

		arr = (int**)malloc(sizeof(int*)*M);

		for (i = 0; i < M; i++)
			arr[i] = (int*)malloc(sizeof(int)*N);

		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				arr[i][j] = 0;
			}
		}

		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				if (!CanYouAdd(arr, i, j, M, N))
					continue;

				arr[i][j] = 1;
				Answer++;
			}
		}
		printf("#%d %d\n", test_case, Answer);
		for (int i = 0; i < M; i++)
			free(arr[i]);
		free(arr);

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}