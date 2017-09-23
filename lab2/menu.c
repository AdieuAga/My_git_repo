#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    char cmd[128];
    char word[128];
    char matter[128];
    while(1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "help") == 0)
        {
            printf("This is help cmd，What is the matter？\n");
            scanf("%s", matter);
            if(strcmp(matter, "time") == 0)
            {
                time_t timep;
                time (&timep);
                printf("%s", asctime(gmtime(&timep)));
            }
            else if(strcmp(matter, "read") == 0)
            {
                printf("The path is:\n");
                scanf("%s", word);
                if(access(word, R_OK) == 0)
                printf("This can be read\n");
                else
                printf("This can't be read\n");
            }
            else if(strcmp(matter, "currentdirectory") == 0)
            {
                char buf[80];
                getcwd(buf, sizeof(buf));
                printf("current working directory : %s\n", buf);
            }
            else if(strcmp(matter, "rand") == 0)
            {
                srand(time(0));
                printf("%d/n", ((rand()%100)+1));
            }
            else if(strcmp(matter, "length") == 0)
            {
                printf("The string is:\n");
                scanf("%s", word);
                printf("str length = %d\n", strlen(word));
            }
        }
        else if(strcmp(cmd, "quit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Wrong cmd!\n"); 
        }
    }
}


