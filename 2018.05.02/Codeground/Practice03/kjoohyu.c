/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <math.h>

double Answer = 0;
double bull, sTriple, eTriple, sDouble, eDouble;
double GetRange(int x, int y) {
	double mylenth = sqrt(((float)x*(float)x) + ((float)y*(float)y));
	if (mylenth < bull )
		return 50;
	else if (mylenth < sTriple )
		return 1;
	else if (mylenth < eTriple )
		return 3;
	else if (mylenth < sDouble )
		return 1;
	else if (mylenth < eDouble )
		return 2;
	else
		return 0;
}
int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);
	
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		int n, x, y, i;
		double Range, angle;
		
		scanf("%lf %lf %lf %lf %lf", &bull, &sTriple, &eTriple, &sDouble, &eDouble);
		scanf("%d", &n);

		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			Range = GetRange(x, y);
			if (Range == 0 || Range == 50) {
				Answer += Range;
				continue;
			}

			angle = atan2f((float)y, (float)x) * 180 / 3.14159265;
			
			if (angle < 0)
				angle = 360 + angle;
		
			if (angle > 0 && angle < 9) 
				Answer += Range * 6;
			else if (angle < 27)
				Answer += Range * 13;
			else if (angle < 45)
				Answer += Range * 4;
			else if (angle < 63) 
				Answer += Range * 18;
			else if (angle < 81) 
				Answer += Range * 1;
			else if (angle < 99)
				Answer += Range * 20;
			else if (angle < 117) 
				Answer += Range * 5;
			else if (angle < 135) 
				Answer += Range * 12;
			else if (angle < 153) 
				Answer += Range * 9;
			else if (angle < 171) 
				Answer += Range * 14;
			else if (angle < 189) 
				Answer += Range * 11;
			else if (angle < 207) 
				Answer += Range * 8;
			else if (angle < 225) 
				Answer += Range * 16;
			else if (angle < 243) 
				Answer += Range * 7;
			else if (angle < 261) 
				Answer += Range * 19;
			else if (angle < 279) 
				Answer += Range * 3;
			else if (angle < 297) 
				Answer += Range * 17;
			else if (angle < 315) 
				Answer += Range * 2;
			else if (angle < 333)
				Answer += Range * 15;
				
			else if (angle < 351)
				Answer += Range * 10;
				
			else
				Answer += Range * 6;

		}

		printf("Case #%d\n", test_case + 1);
		printf("%lf\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}