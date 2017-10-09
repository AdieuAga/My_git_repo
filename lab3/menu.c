#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "linklist.h"

void Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[] =
{
    {"help","This is a help cmd!",Help,&head[0]},
    {"version","This is Menu v1.0.",NULL,&head[1]},
    {"quit","Quit from the program.",Quit,NULL}
};

int Quit()
{
    exit(0);
}

void Help()
{
    ShowAllCmd(head);
}

int main()
{
    char cmd[CMD_MAX_LEN];
    Help();
    printf("\n");
    while(1)
    {
        printf("input a cmd: \n >>");
	scanf("%s", cmd);
	tDataNode *p = FindCmd(head, cmd);
	if(p == NULL)
	{
	    printf("Wrong cmd!\n");
	    continue;
	}
	printf("%s -%s\n", p -> cmd, p -> desc);
	if(p -> handler != NULL)
	    p -> handler();
	printf("\n");
    }
    return 0;
}
