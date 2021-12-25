#include "md5.h"
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void MD5Init(MD5_CTX *context);

int main(int argc, char *argv[])
{
    int           i;
    unsigned char source[] = { "gongzhonghao:embedded-system" };
    unsigned char md5[16];

    MD5_CTX md5Handle;

    MD5Init(&md5Handle);
    MD5Update(&md5Handle, source, strlen(source));
    MD5Final(&md5Handle, md5);

    printf("MD5:");
    for (i = 0; i < 16; i++)
    {
        printf("%02X", md5[i]);
    }
    printf("\r\n");
    system("pause");
    return 0;
}
