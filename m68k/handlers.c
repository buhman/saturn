void auto_vector_1(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_1(void) { while (1); }
void auto_vector_2(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_2(void) { while (1); }
void auto_vector_3(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_3(void) { while (1); }
void auto_vector_4(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_4(void) { while (1); }
void auto_vector_5(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_5(void) { while (1); }
void auto_vector_6(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_6(void) { while (1); }
void auto_vector_7(void) __attribute__ ((weak, interrupt_handler));
void auto_vector_7(void) { while (1); }

void exception(void) __attribute__ ((weak, interrupt_handler, noreturn));
void exception(void) { while (1); }
