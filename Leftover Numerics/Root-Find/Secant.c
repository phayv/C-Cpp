#include<math.h>
#include<stdio.h>

float func(float x);

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

  do {
  printf("enter two initial gusses\n");
  scanf("%f %f",&p[0],&p[1]);
  fa=func(p[0]); fb=func(p[1]);
  if (fa*fb<0) printf("success\n");
  } while (fa*fb>0);
  
  for (i=1; i<=N-2; i++)
    {
      p[i+1]=p[i] - func(p[i])*(p[i]-p[i-1])/(func(p[i])-func(p[i-1]));
      
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
