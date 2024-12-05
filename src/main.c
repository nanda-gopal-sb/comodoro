#include <stdio.h>
#include <time.h>
void timer()
{
    struct tm *ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    int startMins = ptr->tm_min;
    int endMins = startMins;
    printf("Start your timer-\n");
    int timer = 0;
    scanf("%d", &timer);
    while ((endMins - startMins) != timer)
    {
        t = time(NULL);
        ptr = localtime(&t);
        endMins = ptr->tm_min;
    }
    t = time(NULL);
    ptr = localtime(&t);
    endMins = ptr->tm_min;
    printf("%d\n", endMins);
}
void print_image(FILE *fptr)
{
    char read_string[256];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}
int draw()
{
    char *filename = "../assests/art.txt";
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
    draw();
    return 0;
}
