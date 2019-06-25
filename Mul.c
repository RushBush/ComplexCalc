#include "complexnum.h"

struct ComplexNum Mul(struct ComplexNum a,struct ComplexNum b)
{
  struct ComplexNum result={a.real*b.real-a.img*b.img,a.real*b.img+a.img*b.real};

  return result;
}
