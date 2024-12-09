#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define msg "clear"
void timer()
{
    char figlet[] = "figlet ";
    char sec[3] = {0};
    char min[3] = {0};
    int seconds = 59;
    int minutes = 0;
    printf("Minutes\t");
    scanf("%d", &minutes);
    minutes--;
    while (minutes >= 0)
    {
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", seconds);
        strcpy(figlet, "figlet ");
        strcat(figlet, min);
        strcat(figlet, " : ");
        strcat(figlet, sec);
        system(msg);
        system("figlet Time to Work");
        system(figlet);
        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop)
        {
        }
        seconds--;
        if (seconds == 0)
        {
            minutes--;
            seconds = 59;
        }
    }
    printf("Times up\n");
}
void print_image(FILE *fptr)
{
    char read_string[256];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}
int draw()
{
    char *filename = "assests/art.txt";
    FILE *fptr = NULL;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return 1;
    }
    print_image(fptr);
    fclose(fptr);
    return 0;
}
void showOptions()
{
    printf("1-Start timer\n");
}
int main(void)
{

    char ch = 0;
    draw();
    showOptions();
    scanf("%c", &ch);
    if (ch == '1')
    {
        system(msg);
        timer();
    }
    return 0;
}
