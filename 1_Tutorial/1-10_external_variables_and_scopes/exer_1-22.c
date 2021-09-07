#include <stdio.h>

#define WRAP 80
#define MAXLINE 1000

int my_getline(void);
char line[MAXLINE];
int main(void)
{
    int i, len;
    int location, spaceholder;
    while ((len = my_getline()) > 0)
    {
        if (len < WRAP)
        {
        }
        else
        {
            i = 0;
            location = 0;
            while (i < len)
            {
                if (line[i] == ' ')
                    spaceholder = i;
                if (location == WRAP)
                {
                    line[spaceholder] = '\n';
                    location = 0;
                }
                ++location;
                ++i;
            }
        }
        printf("%s\n", line);
    }
    return 0;
}
int my_getline(void)
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
