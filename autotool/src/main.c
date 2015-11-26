#include <config.h>
#include <stdio.h>

int main()
{
     puts("hello world");
     puts("this is " PACKAGE_STRING ".");
     puts(EXEC);
}
