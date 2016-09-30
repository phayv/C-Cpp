#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define a 10
#define b 0.001
#define c 0.1
#define d 10.0
#define e 0.1


float dRdt(float t, float R, float F);
float dFdt(float t, float R, float F);

int main(void)
{
  
  int i,N;
  float alpha,beta,h;  
  float t[10000],R[10000],F[10000];
  float tmin,tmax;
  float KR1, KR2, KR3, KR4, KF1, KF2, KF3, KF4;

  N=10000;
  
  for (i=0; i<=N-1; i++) {t[i]=0.0; R[i]=0.0; F[i]=0.0;}

  tmin=0.0; tmax=100.0;


  alpha=0.5; beta=0.5;
  
  h=(tmax-tmin)/N;
  
  R[0]=alpha;
  F[0]=beta;
  t[0]=tmin;


  printf("%f %f %f\n",t[0],R[0],F[0]);

  for (i=0; i<=N-1; i++)
    {
      t[i]=tmin+i*h;
      t[i+1]=tmin+(i+1)*h;
      
      KR1=h*dRdt(t[i],R[i],F[i]);
      KF1=h*dFdt(t[i],R[i],F[i]);

      KR2=h*dRdt(t[i]+h/2.0,R[i]+KR1/2.0,F[i]+KF1/2.0);
      KF2=h*dFdt(t[i]+h/2.0,R[i]+KR1/2.0,F[i]+KF1/2.0);

      KR3=h*dRdt(t[i]+h/2.0,R[i]+KR2/2.0,F[i]+KF2/2.0);
      KF3=h*dFdt(t[i]+h/2.0,R[i]+KR2/2.0,F[i]+KF2/2.0);

      KR4=h*dRdt(t[i]+h,R[i]+KR3,F[i]+KF3);
      KF4=h*dFdt(t[i]+h,R[i]+KR3,F[i]+KF3);

      R[i+1]=R[i]+1.0/6.0*(KR1+2.0*KR2+2.0*KR3+KR4);
      F[i+1]=F[i]+1.0/6.0*(KF1+2.0*KF2+2.0*KR3+KR4);
  
      printf("%f %f %f\n",t[i+1],R[i+1],F[i+1]);

  }

}

float dRdt(float t, float R, float F)
{
  float z;
  z=a*R-b*R*F-c*R*R;
  return z;
}

float dFdt(float t, float R, float F)
{
  float z;
  z=d*b*R*F-e*F;
  return z;
}
