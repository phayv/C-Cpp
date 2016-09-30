#include<math.h>
#include<stdio.h>

float func(float x);
float derivfunc(float x);

int main(void)
{
  //x^3+4x^2-10=0
  int i,n,N;
  float p[10000];
  float tol;
  float fa, fb;

  for (i=0; i<10000; i++) p[i]=0.0;
  
  N=10000;

  tol=1e-6;

  printf("one gusses\n");
  scanf("%f",&p[0]);
  fa=func(p[0]);
  
  for (i=0; i<=N-2; i++)
    {
      p[i+1]=p[i] - func(p[i])/derivfunc(p[i]);
      
      printf("%i  %f %f\n",i+1,p[i+1],p[i+1]-p[i]);

      if (fabs(p[i+1]-p[i])<tol) break;

    }
  
  if (i<N-2) printf("root with tol: %f is: %f\n",tol,p[i+1]);
  else    printf("did not converge\n");

}

float func(float x)
{
  return pow(x,3)+4*pow(x,2)-10;
}

float derivfunc(float x)
{
  return 3.0*pow(x,2)+8*x;

}
