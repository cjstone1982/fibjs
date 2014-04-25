#include <osconfig.h>

#ifdef Linux

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#if defined(x64)
__asm__(".symver memcpy,memcpy@GLIBC_2.2.5");
void *__wrap_memcpy(void *dest, const void *src, size_t n)
{
    return memcpy(dest, src, n);
}
#endif

int __isoc99_sscanf(const char *s, const char *format, ...)
{
    va_list arg;
    int done;

    va_start(arg, format);
    done = vsscanf(s, format, arg);
    va_end(arg);

    return done;
}

#endif