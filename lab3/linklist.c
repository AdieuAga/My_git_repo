#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "linklist.h"

tDataNode* FindCmd(tDataNode *head, char *cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode *p = head;
    while (p != NULL)
    {
        if(strcmp(p -> cmd, cmd) == 0)
	{	
	    return p;
        }
        p = p -> next;
    }
    return NULL;
}

void ShowAllCmd(tDataNode *head)
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p ->cmd, p -> desc);
	p = p -> next;
    }
}


