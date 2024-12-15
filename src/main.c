#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define cls "clear"
#define workMsg "figlet Time to Work"

enum msg
{
    work,
    longBreak,
    shortBreak
};
void prepareString(char *figlet, char *sec, char *min)
{
    strcpy(figlet, "figlet ");
    strcat(figlet, min);
    strcat(figlet, " : ");
    strcat(figlet, sec);
}

void timer(int minutes)
{
    char figlet[] = "figlet ";
    char sec[3] = {0};
    char min[3] = {0};
    int seconds = 59;
    int min2 = minutes;
    min2--;
    while (min2 >= 0)
    {
        sprintf(min, "%d", min2);
        sprintf(sec, "%d", seconds);
        prepareString(figlet, sec, min);
        system(cls);
        system(workMsg);
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
void mainLoop()
{
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
}
void print_image(FILE *fptr)
{
    char read_string[256] = {0};

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}
void draw()
{
    char *filename = "assests/art";
    FILE *fptr = NULL;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return;
    }
    print_image(fptr);
    fclose(fptr);
    return;
}

int main(void)
{
    system(cls);
    char ch = '0';
    draw();
    scanf("%c", &ch);
    system(cls);
    timer(10);
    return 0;
}