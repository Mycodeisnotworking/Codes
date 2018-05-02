/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <math.h>
#define pi 3.14159265
using namespace std;
#pragma warning (disable:4996)

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Bull_r = 0, Triple_s_r = 0, Triple_e_r = 0, Double_s_r = 0, Double_e_r = 0;
		int shoot_num = 0;
		int x = 0, y = 0;
		int score = 0;
		double length = 0;
		double angle = 0;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		cin >> Bull_r;
		cin >> Triple_s_r;
		cin >> Triple_e_r;
		cin >> Double_s_r;
		cin >> Double_e_r;
		
		cin >> shoot_num;
		
		for (int i = 0; i < shoot_num; i++)
		{
			cin >> x;
			cin >> y;
			score = 0;

			length = sqrt(x * x + y * y);
			angle = (int)(asin(y / length) * 180 / pi);

			if (length < Bull_r)
			{
				Answer = Answer + 50;
				continue;
			}

			else if (Double_e_r < length)
				continue;

			/////////score

			if (x >= 0)
			{
				if (0 <= angle && angle < 9)
					score = 6;
				else if (9 <= angle && angle < 27)
					score = 13;
				else if (27 <= angle && angle < 45)
					score = 4;
				else if (45 <= angle && angle < 63)
					score = 18;
				else if (63 <= angle && angle < 81)
					score = 1;
				else if (81 <= angle && angle <= 90)
					score = 20;
				else if (-9 < angle && angle <= 0)
					score = 6;
				else if (-27 < angle && angle <= -9)
					score = 10;
				else if (-45 < angle && angle <= -27)
					score = 15;
				else if (-63 < angle && angle <= -45)
					score = 2;
				else if (-81 < angle && angle <= -63)
					score = 17;
				else if (-90 <= angle && angle <= -81)
					score = 3;
			}

			else if (x < 0)
			{
				if (0 <= angle && angle < 9)
					score = 11;
				else if (9 <= angle && angle < 27)
					score = 14;
				else if (27 <= angle && angle < 45)
					score = 9;
				else if (45 <= angle && angle < 63)
					score = 12;
				else if (63 <= angle && angle < 81)
					score = 5;
				else if (81 <= angle && angle <= 90)
					score = 20;
				else if (-9 < angle && angle <= 0)
					score = 11;
				else if (-27 < angle && angle <= -9)
					score = 8;
				else if (-45 < angle && angle <= -27)
					score = 16;
				else if (-63 < angle && angle <= -45)
					score = 7;
				else if (-81 < angle && angle <= -63)
					score = 19;
				else if (-90 <= angle && angle <= -81)
					score = 3;
			}

			if (Triple_s_r <= length && length <= Triple_e_r)
				Answer = Answer + score * 3;

			else if (Double_s_r <= length && length <= Double_e_r)
				Answer = Answer + score * 2;

			else
				Answer = Answer + score;


		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}