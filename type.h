#include <stddef.h>
#include <stdint.h>

#ifndef __cplusplus
#define static_assert _Static_assert
#endif

typedef volatile uint8_t reg8;
typedef volatile uint16_t reg16;
typedef volatile uint32_t reg32;

static_assert((sizeof (reg8)) == 1);
static_assert((sizeof (reg16)) == 2);
static_assert((sizeof (reg32)) == 4);

typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;

static_assert((sizeof (u8)) == 1);
static_assert((sizeof (s8)) == 1);
static_assert((sizeof (u16)) == 2);
static_assert((sizeof (s16)) == 2);
static_assert((sizeof (u32)) == 4);
static_assert((sizeof (s32)) == 4);

#define REG_UL(U, L) (((U) << 16) | (L))
