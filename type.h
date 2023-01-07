#define static_assert _Static_assert
#define offsetof __builtin_offsetof

typedef volatile unsigned char reg8;
typedef volatile unsigned short reg16;
typedef volatile unsigned long reg32;

static_assert((sizeof (reg8)) == 1);
static_assert((sizeof (reg16)) == 2);
static_assert((sizeof (reg32)) == 4);

typedef volatile unsigned short u16;
typedef volatile short s16;

static_assert((sizeof (u16)) == 2);
static_assert((sizeof (s16)) == 2);

#define REG_UL(U, L) (((U) << 16) | (L))
