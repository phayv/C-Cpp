//Quadratic Solver

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <process.h>

int main(void) {

	float A, B, C, soln1, soln2, dis, solnR, solnI;

	printf("Enter the values and A, B and C in Ax^2+Bx+C=0, separated by spaces:\n");
	scanf("%f %f %f", &A, &B, &C);

	if (A == 0)  {
		printf("A=0 only one solution\n");
		soln1 = -C / B;
		printf("The solution is %f\n", soln1);
	}

	else {

		dis = B*B - 4.0*A*C;

		if (dis == 0) {
			printf("There is one real solution:\n");
			soln1 = -B / (2 * A);
			printf("x = %f\n", soln1);
		}

		else if (dis > 0) {
			printf("There are two real solutions:\n");
			soln1 = (-B + sqrt(dis)) / (2 * A);
			soln2 = (-B - sqrt(dis)) / (2 * A);
			printf("x = %f and x = %f\n", soln1, soln2);
		}

		else {
			printf("There are two complex solutions:\n");
			solnR = -B / (2 * A);
			solnI = sqrt(-dis) / (2 * A);
			printf("x = %f + i*%f and x = %f - i*%f\n", solnR, solnI, solnR, solnI);
		}

	} // End A!=0  

	system("PAUSE");
	return 0;

} // End main
