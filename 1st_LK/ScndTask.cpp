#include <iostream>
#include <string.h>

int strConteins(char* a, char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ((strlen(str) - i) >= strlen(a) && str[i] == a[0])
        {
            for (int j = 0; j <= strlen(a); j++)
            {
                if (str[i+j] != a[j])
                {
                    break;
                }
                if (j == strlen(a))
                {
                    return i;
                }
            }
        }
    }
    return -1;
    
}