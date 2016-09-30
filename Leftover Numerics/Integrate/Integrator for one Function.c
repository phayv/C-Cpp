#include <stdio.h>
#include <math.h>

float fx(float x);

int main() 
{

	float a, b, w, sum, xi, xi1;
	int n;

	n = 10000;

	printf("Welcome to the numerical integrator, which only works for one function\n\n");
	printf("Enter the the bounds a and b separated by spaces\n\n");
	scanf("%f %f", &a, &b);

	w = (b - a) / n;
	sum = 0.0;

	for (int i = 0; i <= n - 1; i++) {

		xi = a + i*w;
		xi1 = a + (i + 1)*w;
		sum += (w / 2)*(fx(xi) + fx(xi1));

	}
	printf("The integral of fx from a to b is %f\n\n", sum);
	system("PAUSE");
}

float fx(float x) 
{
	return(sin(1 / x) - cos(1 / x));
}
