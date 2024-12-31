#include <stdio.h>

int main() {
    #ifdef __STDC_NO_VLA__
        printf("VLAs are not supported by this compiler.\n");
    #else
        printf("VLAs are supported by this compiler.\n");
    #endif

    return 0;
}