#define static_assert _Static_assert
#define offsetof __builtin_offsetof

typedef volatile unsigned char reg8;
typedef volatile unsigned short reg16;
typedef volatile unsigned long reg32;

static_assert((sizeof (reg8)) == 1);
static_assert((sizeof (reg16)) == 2);
static_assert((sizeof (reg32)) == 4);

#define REG32_VAL(U, L) (((U) << 16) | (L))
