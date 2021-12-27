#include "md5.h"
#include "windows.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int           i;
    unsigned char source[] = { "b262e71e-b159-11e5-a82a-f82fa8eb090b" };
    unsigned char md5[16];

    MD5_CreateMD5(source, strlen(source), md5);

    printf("MD5:");
    for (i = 0; i < 16; i++)
    {
        printf("%02X", md5[i]);
    }
    printf("\r\n");
    system("pause");
    return 0;
}
