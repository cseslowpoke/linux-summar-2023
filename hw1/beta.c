#include <stdint.h>
#include <stdio.h>
static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        return (sz - 1 | mask) + 1;      
    }
    return (((sz + mask) / alignment) * alignment);
}

int main() {
    printf("%lu", align_up(0, 4));
}