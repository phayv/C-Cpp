#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* our probem is solve dy/dx=y-x2+1 with y(x=0) of 0.5  over x= 0 to 2 */

float dydx(float y, float x);
float dydxprime(float y, float x);
float dydxthird(float y, float x);


int main(void)
{

  int i, N;
  float a,b,h;
  float y[100],x[100],yexact[100],ysecond[100],ythird[100];
  
  b=2.0; a=0.0;
  N=50.0;

  /* initialize array */
  for (i=0; i<=99; i++) {x[i]=0.0; y[i]=0.0; yexact[i]=0.0; ysecond[i]=0.0; ythird[i]=0.0;}

  /* initial condition */
  y[0]=0.5;
  yexact[0]=0.5;
  ysecond[0]=0.5;
  ythird[0]=0.5;


  h=(b-a)/N;

  printf("i       x       yfirst        ysecond     ythird         yexact         diff       diffsecond   diffthird\n");

  for (i=0; i<=49; i++)
    {
      x[i]=a+i*h;
      y[i+1]=y[i]+h*dydx(x[i],y[i]);
      ysecond[i+1] = ysecond[i]+h*dydx(x[i],ysecond[i])+h*h/2.0*dydxprime(x[i],ysecond[i]);
      ythird[i+1] = ythird[i]+h*dydx(x[i],ythird[i])+h*h/2.0*dydxprime(x[i],ythird[i]) +
	h*h*h/6.0*dydxthird(x[i],ythird[i]);


      yexact[i]=(x[i]+1)*(x[i]+1)-0.5*exp(x[i]);


      printf("%i    %f    %f    %f    %f      %f    %f     %f     %f\n",i,x[i],y[i],ysecond[i],ythird[i],
	     yexact[i],fabs(y[i]-yexact[i]),
	     fabs(ysecond[i]-yexact[i]),
	     fabs(ythird[i]-yexact[i]));
    }

}



float dydx(float x, float y)
{
  float z;
  z=y-x*x+1.0;

  return z;
}

float dydxprime(float x, float y)
{
  float z;
  z=y-x*x-2*x+1.0;

  return z;
}

float dydxthird(float x, float y)
{
  float z;
  z=y-x*x-4*x-1.0;

  return z;
}
