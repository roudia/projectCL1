#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
/* ameliorated version test
{

    int occ=0,pre=0;
    for(int i=0;i<col->ls;i++)
    {
        if(col->data[i]>=val && occurences(col,col->data[i])==1)
        {
            occ++;
        }
        else if(col->data[i]>=val && occurences(col,col->data[i])!=1)
        {
            if (pre==0)
            {
                occ++;
            }
            pre++;
        }
    }
    return occ;
}*/

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
/* ameliorated version test
{
    int *pre =(int*)malloc(col->ls * sizeof(int));
    int occ=0,po=0,j=0;
    for(int i=0;i<col->ls;i++)
    {
        if(col->data[i]<=val && occurences(col,col->data[i])==1)
        {
            occ++;
        }
        else if(col->data[i]<=val && occurences(col,col->data[i])!=1)
        {
            do
            {
                j++;
                if(pre[j]==col->data[i])
                {
                    po++;
                }
            }
            while(pre[j]!=col->data[i]);
            if(po==0)
            {
                occ++;
            }
            pre++;
        }
    }
    return occ;
}*/


// Cdataframe part
//definition of a new type
typedef struct
{
    int ls;
    int ps;
    int rows;
    COLUMN *data;
}CDATAFRAME;

// initialisation of cdataframe
CDATAFRAME *createEmptyDataframe()
{
    CDATAFRAME * cd=(CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    cd->ls=0;
    cd->ps=REALOC_SIZE;
    cd->rows=0;
    cd->data=(COLUMN*)malloc(REALOC_SIZE * sizeof(COLUMN));
    return cd;
}

//place a column in the cdatatframe
int insert_column(CDATAFRAME *cd, COLUMN *list)
{
    if(cd->ls == cd->ps)
    {
        cd->ps+=REALOC_SIZE;
        cd->data = (COLUMN*)realloc(cd->data, cd->ps * sizeof(COLUMN));
        if(cd->data == NULL)
        {
            return 0;
        }
    }
    cd->data[cd->ls]=*list;
    cd->ls++;
    return 1;
}

void hardFillDataframe(CDATAFRAME *cd)
{
    int obj=0,value=0;
    char name[100];
    printf("how many column do you plan to put ?");
    scanf("%d",&obj);
    printf("With how many rows ?\n");
    scanf("%d",&cd->rows);
    for (int i = 0; i <obj; i++)
    {
        printf("what is the name of the column at the index %d ?\n",i+1);
        scanf("%s",name);
        COLUMN *col = create_column(name);
        insert_column(cd,col);
        printf("what are the %d values you want in the column ?",cd->rows);
        for(int j=0;j<cd->rows;j++)
        {
            scanf("%d",&value);
            insert_value(col,value);
        }
    }
}

void display_all_cdata(CDATAFRAME *cd)
{
    for(int i=0;i<cd->ls;i++)
    {
        printf("%s ",cd->data[i].name);
    }
    printf("\n");
    for(int k=0;k<cd->rows;k++)
    {
        for(int j=0;j<cd->ls;j++)
        {
            printf("%d\t ",cd->data[j].data[k]);
        }
        printf("\n");
    }
}

void display_part_rows(CDATAFRAME *cd, int start,int end)
{
    for(int i=0;i<cd->ls;i++)
    {
        printf("%s ",cd->data[i].name);
    }
    printf("\n");
    for(int k=start;k<end;k++)
    {
        for(int j=0;j<cd->ls;j++)
        {
            printf("%d\t ",cd->data[j].data[k]);
        }
        printf("\n");
    }
}

void display_part_col(CDATAFRAME *cd,int start,int end)
{
    for(int i=start;i<end;i++)
    {
        printf("%s ",cd->data[i].name);
    }
    printf("\n");
    for(int k=0;k<cd->rows;k++)
    {
        for(int j=start;j<end;j++)
        {
            printf("%d\t ",cd->data[j].data[k]);
        }
        printf("\n");
    }
}