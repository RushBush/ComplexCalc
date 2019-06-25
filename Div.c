#include "complexnum.h"


struct ComplexNum Div(struct ComplexNum a,struct ComplexNum b)
{
  int num_real,denom,num_img;
  struct ComplexNum result;
  num_real=a.real*b.real+a.img*b.img;
  denom=b.real*b.real+b.img*b.img;
  num_img=b.real*a.img-b.img*a.real;

  if (b.real==0 && b.img==0)
  {
      printf("Can't divide by zero\n");
      return a;
  }

  result.real=num_real/denom;
  result.img=num_img/denom;

  return result;
}
