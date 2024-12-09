#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define msg "clear"
void timer()
{
    char figlet[] = "figlet ";
    char num[200] = {0};
    int seconds = 0;
    printf("Seconds\t");
    scanf("%d", &seconds);
    while (seconds >= 0)
    {
        sprintf(num, "%d", seconds);
        strcpy(figlet, "figlet ");
        strcat(figlet, num);
        system(msg);
        system(figlet);
        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop)
        {
        }
        seconds--;
    }
    printf("Times up\n");
    // struct tm *ptr;
    // time_t t;
    // t = time(NULL);
    // ptr = localtime(&t);
    // int startMins = ptr->tm_min;
    // int endMins = startMins;
    // printf("Start your timer-\n");
    // printf("Enter the time you want to start on");
    // int timer = 0;
    // scanf("%d", &timer);
    // while ((endMins - startMins) != timer)
    // {
    //     t = time(NULL);
    //     ptr = localtime(&t);
    //     endMins = ptr->tm_min;
    // }
    // t = time(NULL);
    // ptr = localtime(&t);
    // endMins = ptr->tm_min;
    // printf("%d\n", endMins);
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
    // char ch = 0;
    // draw();
    // showOptions();
    // scanf("%c", &ch);
    // system(msg);
    timer();
    return 0;
}
