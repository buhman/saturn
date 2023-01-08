extern unsigned long _load_addr __asm("_load_addr");

void _start(void)
{
	((void(*)())&_load_addr)();
}
