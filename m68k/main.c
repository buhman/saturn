#include "../scsp.h"

#define MVOL(n) (n << 0)

void start(void)
{
  scsp.reg.common[0] = SCSP__0__MEM4MB | SCSP__0__DAC18B | MVOL(15);


  while (1) {
  }
}
