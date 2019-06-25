#include "complexnum.h"

struct ComplexNum Sub(struct ComplexNum a,struct ComplexNum b)
{
  struct ComplexNum result={a.real-b.real,a.img-b.img};

  return result;
}
