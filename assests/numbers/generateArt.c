#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *figlet[200] = {0};
    int n = 0;
    while (n <= 10)
    {
        sprintf(figlet, "%s %d %s %d", "figlet -f big ", n, " > ", n);
        printf("%s", figlet);
        n++;
        printf("\n");
        system(figlet);
    }
    return 0;
}
