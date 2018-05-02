#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T;
	int N = 0, M = 0;
	int seed_count = 0;
	int **a;
	int dRow[4] = { 0, 0, 2, -2 };
	int dCol[4] = { 2, -2, 0, 0 };

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		seed_count = 0;

		
		a = new int*[N];
		for (int i = 0; i < N; i++)
			a[i] = new int[M];


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				a[i][j] = 0;
		}


		a[0][0] = 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int Is_seed = 0;
				for (int k = 0; k < 4; k++) {
					if (i + dRow[k] < 0 || j + dCol[k] < 0)
						continue;
					else if (i + dRow[k] >= N || j + dCol[k] >= M)
						continue;

					int seed = a[i + dRow[k]][j + dCol[k]];

					if (seed == 1)
						Is_seed = 1;
				}

				if (Is_seed == 0)
				{
					a[i][j] = 1;
					seed_count++;
				}
			}
		}

		cout << "#" << test_case << " " << seed_count << endl;
		
		for (int i = 0; i < N; i++)
			delete [] a[i];
		delete [] a;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}