#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"

#define REALOC_SIZE 256
// FIRST PART OF THE PROJECT
// creation of a struct

//initialisation of a column
COLUMN *create_column(char *title)
{
    COLUMN *col =(COLUMN*)malloc(sizeof(COLUMN));
    col->name = strdup(title);
    col->ls =0;
    col->ps = REALOC_SIZE;
    col->data =(int*)malloc(REALOC_SIZE * sizeof(int));
    return col;
};

//check the physical size and allocate a value
int insert_value(COLUMN *col, int value)
{
    if(col->ls == col->ps)
    {
        col->ps+=REALOC_SIZE;
        col->data = (int*)realloc(col->data, col->ps * sizeof(int));
    }
    col->data[col->ls]=value;
    col->ls++;
    return 1;
}


// free the allocated space of the collumn (delete it)
/*void delete_column(COLUMN **col)
{
    free((*col)->data);
    free(*col);
}*/

//print the value
void print_col(COLUMN *col)
{
    for(int i=0;i<col->ls;i++)
    {
        printf("[%d]  %d\n",i,col->data[i]);
    }
}

//supplementary function (4.1.5)
int occurences(COLUMN *col,int val)
{
    int occ=0;
    for(int i=0;i<col->ls;i++)
    {
        if(col->data[i]==val)
        {
            occ++;
        }
    }
    return occ;
}

int returnvalue(COLUMN *col,int ind)
{
    return col->data[ind];
}

int greatvalue(COLUMN *col,int val)
{
    int occ=0;
    for(int i=0;i<col->ls;i++)
    {
        if(col->data[i]>=val)
        {
            occ++;
        }
    }
    return occ;
}

int lessvalue(COLUMN *col,int val)
{
    int occ=0;
    for(int i=0;i<col->ls;i++)
    {
        if(col->data[i]<=val)
        {
            occ++;
        }
    }
    return occ;
}

