#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define cls "clear"
#define workMsg "figlet Time to Work"

enum msg
{
    work,
    longBreak,
    shortBreak
};
void SetTextCursorVisible(int visible)
{
    fputs((visible ? "\e[?25h" : "\e[?25l"), stdout);
}
void intHandler(int condt)
{
    system("tput cnorm");
    exit(1);
}

void prepareString(char *figlet, char *sec, char *min)
{
    strcpy(figlet, "figlet -f future ");
    strcat(figlet, min);
    strcat(figlet, " : ");
    strcat(figlet, sec);
}

void timer(int minutes, enum msg param)
{
    char currMsg[40] = "figlet time to work2\0";
    char figlet[50] = "";
    if (param == work)
    {
        strcpy(currMsg, "figlet -f future Time to Work");
    }
    if (param == longBreak)
    {
        strcpy(currMsg, "figlet -f future Long Break!");
    }
    if (param == shortBreak)
    {
        strcpy(currMsg, "figlet -f future Short break?");
    }
    char sec[3] = {0};
    char min[3] = {0};
    int seconds = 59;
    int min2 = minutes;
    min2--;
    while (min2 > -1)
    {
        sprintf(min, "%d", min2);
        sprintf(sec, "%d", seconds);
        prepareString(figlet, sec, min);
        system(cls);
        system(currMsg);
        system(figlet);
        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop)
            ;
        seconds--;

        if (seconds == 0)
        {
            min2--;
            seconds = 59;
        }
    }
    system(cls);
    system("figlet -f future 0:0");
    system("mpv --no-vid --terminal=no assests/sound.mp3");
}
void mainLoop()
{
    system(cls);
    int ch = 0;
    int workTime = 0;
    int smallBreak = 0;
    int bigBreak = 0;
    int cycles = 0;
    int breakCounter = 0;
    printf("Duration of Each Work Interval\t");
    scanf("%d", &workTime);
    printf("\n");

    printf("Duration of small break\t");
    scanf("%d", &smallBreak);
    printf("\n");

    printf("Duration of big break\t");
    scanf("%d", &bigBreak);
    printf("\n");

    printf("The number of cycles\t");
    scanf("%d", &cycles);
    printf("\n");

    while (cycles >= 0)
    {
        if (breakCounter == 2)
        {
            timer(bigBreak, longBreak);
            breakCounter = 0;
            cycles--;
            continue;
        }
        timer(workTime, work);
        timer(smallBreak, shortBreak);
        breakCounter++;
    }
}
void print_image(FILE *fptr)
{
    char read_string[256] = {0};

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}
char draw()
{
    char ch = 0;
    char *filename = "assests/art";
    FILE *fptr = NULL;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return ch;
    }
    print_image(fptr);
    fclose(fptr);
    filename = "assests/pokemon";
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return ch;
    }
    print_image(fptr);
    scanf("%c", &ch);
    return ch;
}

int main(void)
{
    system(cls);
    signal(SIGINT, intHandler);
    system("tput civis");
    draw();
    mainLoop();
    system("tput cnorm");
}