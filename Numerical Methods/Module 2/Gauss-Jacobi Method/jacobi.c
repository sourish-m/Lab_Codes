#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x,float y,float z)
{
  return ((17-y+2*z)/20);
//x=(17-y+2*z)/20
}

float s(float x,float y,float z)
{
  return ((-18+z-3*x)/20);
//y=(-18+z-3*x)/20
}

float t(float x,float y,float z)
{
  return ((25-2*x+3*y)/20);
//z=(25-2*x+3*y)/20
}

void main()
{
  float x0,y0,z0,x1=0,y1=0,z1=0,tempx,tempy,tempz,acc=0.0001;
  int itr=0;
  printf("Enter initial guesses:\n");
  scanf("%f%f%f",&x0,&y0,&z0);
  do
  {
    tempx=x1;
    tempy=y1;
    tempz=z1;

    x1=f(x0,y0,z0);
    y1=s(x0,y0,z0);
    z1=t(x0,y0,z0);

    printf("x1: %f\tx2:%f\tx3:%f at iteration %d\n",x1,y1,z1,itr);

    itr++;

    x0=x1;
    y0=y1;
    z0=z1;
  }while(fabs(tempx-x1)>acc && fabs(tempy-y1)>acc && fabs(tempz-z1)>acc);

  printf("\nThe solutions are:\n");
  printf("x=%f \ny=%f \nz=%f \n",x1,y1,z1);
  getch();
}
