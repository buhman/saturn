#include <stdint.h>

extern uint32_t * __bss_link_start;
extern uint32_t * __bss_link_end;
extern void main();

extern "C"
void start(void)
{
  uint32_t * start = __bss_link_start;
  uint32_t * end = __bss_link_end;
  while (start < end) {
    *start++ = 0;
  }

  main();

  while (1);
}
