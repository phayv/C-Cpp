#include<math.h>
#include<stdio.h>

float func(float x);

int main(void)
{
  //x^3+4x^2-10=0
  int i,n,N;
  float a,b,p,fa,fb,fp,root,tol;
  
  tol=1e-8;

  do {
  printf("enter two initial gusses\n");
  scanf("%f %f",&a,&b);
  fa=func(a); fb=func(b);
  if (fa*fb<0) printf("success\n");
  } while (fa*fb>0);
  
  i=1;
  fa=func(a);
  
  N = log10((b-a)/tol)/log10(2.0);

  printf("i      a         b           p            fp\n");

  while (i < N)
    {
      p=a+(b-a)/2.0;
      fp=func(p);

      if (fp*fa > 0)
	{ a=p;
	  p=a+(b-a)/2.0;
	  fp=func(p);
	} else {
	b=p;
	p=a+(b-a)/2.0;
	fp=func(p);
      }
      i++;

      printf("%i  %f %f %f %f\n",i,a,b,p,fp);

    }
  printf("root with tol: %f is: %f\n",tol,p);
}


float func(float x)
{
  return pow(x,3)+4*pow(x,2)-10;
}
