#include <stdint.h>

extern "C" uint32_t __bss_link_start __asm("__bss_link_start");
extern "C" uint32_t __bss_link_end __asm("__bss_link_end");

typedef void(*init_t)(void);

extern "C" uint32_t __ctors_link_start __asm("__ctors_link_start");
extern "C" uint32_t __ctors_link_end __asm("__ctors_link_end");

extern void main();

extern "C"
void start(void)
{
  uint32_t * start;
  uint32_t * end;

  start = &__bss_link_start;
  end = &__bss_link_end;
  while (start < end) {
    *start++ = 0;
  }

  start = &__ctors_link_start;
  end = &__ctors_link_end;
  while (start < end) {
    (reinterpret_cast<init_t>(*start++))();
  }

  main();

  while (1);
}
