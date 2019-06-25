#include "complexnum.h"

struct ComplexNum Module(struct ComplexNum a)
{
  struct ComplexNum result={a.real,-1*a.img};

  return result;
}
