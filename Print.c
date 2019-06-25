#include "complexnum.h"

void Print(struct ComplexNum a)
{
  if (a.real!=0)
    printf("%d",a.real);

  if (a.img!=0)
  {
    if (a.img>0 && a.real!=0)
      printf("+");
    printf("%di",a.img);
  }

  if (a.img==0 && a.real==0)
    printf("0");

  printf("\n");
}
