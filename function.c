#include <stdio.h>
#include <stdlib.h>
#define REALOC_SIZE 256
// FIRST PART OF THE PROJECT
// creation of a struct
typedef struct
{
    char *name;
    int ls;
    int ps;
    int *data;
}COLUMN;

//initialisation of a column
COLUMN *create_column(char *title)
{
    COLUMN *col =(COLUMN*)malloc(sizeof(COLUMN));
    col->name = title;
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
void delete_column(COLUMN **col)
{
    free((*col)->data);
    free(*col);
}

//print the value
void print_col(COLUMN *col)
{
    for(int i=0;i<col->ls;i++)
    {
        printf("%d : %d\n",i,col->data[i]);
    }
}