#include <stdio.h>
int absolute(int x) {
    if (x > 0) return x;
    else return -x;
}
int main() {
    int bar;
    bar = 0x80000000;
    printf("(signed)bar = %d\n", bar);
    printf("(unsigned)bar = %u\n", bar);
    printf("absolute(bar) = %d\n", absolute(bar));
    printf("(raw bit)bar = %x\n", bar);
    return 0;
}