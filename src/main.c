#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define cls "clear"
#define msq "figlet Time to Work"
void prepareString(char *figlet, char *sec, char *min)
{
    strcpy(figlet, "figlet ");
    strcat(figlet, min);
    strcat(figlet, " : ");
    strcat(figlet, sec);
}
void timer()
{
    char figlet[] = "figlet ";
    char sec[3] = {0};
    char min[3] = {0};
    int seconds = 59;
    int minutes = 0;

    int workTime = 0;
    int smallBreak = 0;
    int bigBreak = 0;
    int cycles = 0;
    printf("Duration of Each Work Interval\t");
    scanf("%d", &workTime);
    printf("\n");

    printf("Duration of small break\t");
    scanf("%d", &smallBreak);
    printf("\n");

    printf("Duration of big break\t");
    scanf("%d", &bigBreak);
    printf("\n");

    minutes--;
    while (minutes >= 0)
    {
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", seconds);
        prepareString(figlet, sec, min);
        system(cls);
        system(msq);
        system(figlet);
        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop)
            ;
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

int main(void)
{
    char ch = '0';
    draw();
    scanf("%c", &ch);
    timer();
    return 0;
}
