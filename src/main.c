#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <mpv/client.h>
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
    strcpy(figlet, "figlet ");
    strcat(figlet, min);
    strcat(figlet, " : ");
    strcat(figlet, sec);
}

void timer(int minutes, enum msg param)
{
    char currMsg[40] = "figlet time to work2\0";
    char figlet[50] = "figlet ";
    if (param == work)
    {
        strcpy(currMsg, "figlet Time to work");
    }
    if (param == longBreak)
    {
        strcpy(currMsg, "figlet Long Break!");
    }
    if (param == shortBreak)
    {
        strcpy(currMsg, "figlet Short break?");
    }
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
    system("mpv --no-vid --terminal=no assests/sound.mp3");
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

    printf("The number of cycles\t");
    scanf("%d", &cycles);
    printf("\n");

    printf("A long break will occure after two consecutive short ones");
    printf("A cycle consists of 2 work sessions 2 short breaks and 1 long one");
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
    filename = "assests/pokemon";
    fptr = fopen(filename, "r");
    print_image(fptr);
    fclose(fptr);
    return;
}

int main(void)
{
    system("tput civis");
    signal(SIGINT, intHandler);
    timer(2, work);
    system("tput cnorm");
    // return 0;
}