#ifndef __cplusplus
#define static_assert _Static_assert
#endif
#define offsetof __builtin_offsetof

typedef volatile unsigned char reg8;
typedef volatile unsigned short reg16;
typedef volatile unsigned long reg32;

static_assert((sizeof (reg8)) == 1);
static_assert((sizeof (reg16)) == 2);
static_assert((sizeof (reg32)) == 4);

typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef long s32;

static_assert((sizeof (u8)) == 1);
static_assert((sizeof (s8)) == 1);
static_assert((sizeof (u16)) == 2);
static_assert((sizeof (s16)) == 2);
static_assert((sizeof (u32)) == 4);
static_assert((sizeof (s32)) == 4);

#define REG_UL(U, L) (((U) << 16) | (L))
