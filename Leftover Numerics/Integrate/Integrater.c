#include <stdio.h>
#include <math.h>

float fx(float x);

int main(void)
{
  float a,b,h,sum,xi,xiplusone;
  int n,i;

  a=0;
  b=5;

  n=10000;
  h=(b-a)/n;
  sum=0.0;

  for(i=0;i<=n-1;i++)
    {
      xi = a+i*h;
      xiplusone=a+(i+1)*h;
      sum=sum+h/2*(fx(xi)+fx(xiplusone));
    }

  printf("integral from %f to %f is  %.8f\n",a,b,sum);

}

float fx(float x)
{
  return sin(x);
}
