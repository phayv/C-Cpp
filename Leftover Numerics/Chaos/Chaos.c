#include<stdio.h>
#include<math.h>

#define s 10
#define r 2.3
#define a 28

float dxdt(float t, float x, float y, float z);
float dydt(float t, float x, float y, float z);
float dzdt(float t, float x, float y, float z);

int main(void)
{

  int i, N;
  float h;
  float t[10000],x[10000],y[10000],z[10000];
  float kx1,kx2,kx3,kx4;
  float ky1,ky2,ky3,ky4;
  float kz1,kz2,kz3,kz4;


  N=10000;
  
  h=(10.0-0)/N;

  for (i=0; i<=N-1; i++) {t[i]=0.0; x[i]=0.0; y[i]=0.0; z[i]=0.0;}

  t[0]=0.0;
  x[0]=0.1; y[0]=0.1; z[0]=0.1;

  printf("%f %f %f %f\n",t[0],x[0],y[0],z[0]); 

  for (i=0; i<=N-1; i++)
    {
      
      t[i]=0+i*h;
      t[i+1]=0+(i+1)*h;

      kx1=h*dxdt(t[i],x[i],y[i],z[i]);
      ky1=h*dydt(t[i],x[i],y[i],z[i]);
      kz1=h*dzdt(t[i],x[i],y[i],z[i]);

      kx2=h*dxdt(t[i]+h/2.0,x[i]+kx1/2.0,y[i]+ky1/2.0,z[i]+kz1/2.0);
      ky2=h*dydt(t[i]+h/2.0,x[i]+kx1/2.0,y[i]+ky1/2.0,z[i]+kz1/2.0);
      kz2=h*dzdt(t[i]+h/2.0,x[i]+kx1/2.0,y[i]+ky1/2.0,z[i]+kz1/2.0);

      kx3=h*dxdt(t[i]+h/2.0,x[i]+kx2/2.0,y[i]+ky2/2.0,z[i]+kz2/2.0);
      ky3=h*dydt(t[i]+h/2.0,x[i]+kx2/2.0,y[i]+ky2/2.0,z[i]+kz2/2.0);
      kz3=h*dzdt(t[i]+h/2.0,x[i]+kx2/2.0,y[i]+ky2/2.0,z[i]+kz2/2.0);

      kx4=h*dxdt(t[i]+h,x[i]+kx3,y[i]+ky3,z[i]+kz3);
      ky4=h*dydt(t[i]+h,x[i]+kx3,y[i]+ky3,z[i]+kz3);
      kz4=h*dzdt(t[i]+h,x[i]+kx3,y[i]+ky3,z[i]+kz3);
      
      x[i+1]=x[i]+1.0/6.0*(kx1+2.0*kx2+2.0*kx3+kx4);
      y[i+1]=y[i]+1.0/6.0*(ky1+2.0*ky2+2.0*ky3+ky4);
      z[i+1]=z[i]+1.0/6.0*(kz1+2.0*kz2+2.0*kz3+kz4);

      printf("%f %f %f %f\n",t[i+1],x[i+1],y[i+1],z[i+1]); 

    }
}

float dxdt(float t, float x, float y, float z)
{
  return s*(y-x);
}

float dydt(float t, float x, float y, float z)
{
  return r*x-y-z;
}

float dzdt(float t, float x, float y, float z)
{
  return x*y-a*z;
} 
