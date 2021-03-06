#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#define PI 3.141592

using namespace std;

int Answer;
int scoreidx;

void SetIdx(double angle, pair<int, int> p);

int main(int argc, char** argv)
{
	const int Scores[20] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};
	int T, test_case;
	int A, B, C, D, E, N;
	double distance;
	pair<int, int> p;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

*	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
		scanf(" %d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &p.first, &p.second);
			distance = sqrt((double)((p.first)*(p.first) + (p.second)*(p.second)));
			
			double sinval = (double)p.second / distance;
			double angle = asin(sinval) * 180 / PI;
			
			SetIdx(angle, p);

			if (distance < A) {
				Answer += 50;
			}
			else if (distance >= B && distance < C) {
				Answer += 3 * Scores[scoreidx];
			}
			else if (distance >= D && distance < E) {
				Answer += 2 * Scores[scoreidx];
			}
			else if (distance < E) {
				Answer += Scores[scoreidx];
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

void SetIdx(double angle, pair<int, int> p) {
	if (p.first >= 0 && p.second >= 0) {
		if (angle >= 0 && angle < 9) {
			scoreidx = 5;
		}
		else if (angle >= 9 && angle < 27) {
			scoreidx = 4;
		}
		else if (angle >= 27 && angle < 45) {
			scoreidx = 3;
		}
		else if (angle >= 45 && angle < 63) {
			scoreidx = 2;
		}
		else if (angle >= 63 && angle < 81) {
			scoreidx = 1;
		}
		else if (angle >= 81) {
			scoreidx = 0;
		}
	}
	else if (p.first >= 0 && p.second < 0) {
		if (angle < 0 && angle >= -9) {
			scoreidx = 5;
		}
		else if (angle < -9 && angle >= -27) {
			scoreidx = 6;
		}
		else if (angle < -27 && angle >= -45) {
			scoreidx = 7;
		}
		else if (angle < -45 && angle >= -63) {
			scoreidx = 8;
		}
		else if (angle < -63 && angle >= -81) {
			scoreidx = 9;
		}
		else if (angle < -81) {
			scoreidx = 10;
		}
	}
	else if (p.first < 0 && p.second < 0) {
		if (angle < 0 && angle >= -9) {
			scoreidx = 15;
		}
		else if (angle < -9 && angle >= -27) {
			scoreidx = 14;
		}
		else if (angle < -27 && angle >= -45) {
			scoreidx = 13;
		}
		else if (angle < -45 && angle >= -63) {
			scoreidx = 12;
		}
		else if (angle < -63 && angle >= -81) {
			scoreidx = 11;
		}
		else if (angle < -81) {
			scoreidx = 10;
		}
	}
	else if (p.first < 0 && p.second >= 0) {
		if (angle >= 0 && angle < 9) {
			scoreidx = 15;
		}
		else if (angle >= 9 && angle < 27) {
			scoreidx = 16;
		}
		else if (angle >= 27 && angle < 45) {
			scoreidx = 17;
		}
		else if (angle >= 45 && angle < 63) {
			scoreidx = 18;
		}
		else if (angle >= 63 && angle < 81) {
			scoreidx = 19;
		}
		else if (angle >= 81) {
			scoreidx = 0;
		}
	}
}