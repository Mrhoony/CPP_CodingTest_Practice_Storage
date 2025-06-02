#include <iostream>
#include <cstddef>

char* str_copy(char* dest, const char* src)
{
    if (dest == nullptr || src == nullptr)
    {
        return nullptr;
    }

    char* original_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return original_dest;
}
