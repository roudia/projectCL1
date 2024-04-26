#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"
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


// Cdataframe part
//definition of a new type

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
    for(int k=start-1;k<end;k++)
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
    for(int k=0;k<cd->rows;k++)
    {
        for(int j=start-1;j<end;j++)
        {
            printf("%d\t ",cd->data[j].data[k]);
        }
        printf("\n");
    }
}

//supplementary function : USUAL OPERATIONS
void add_rows_val(CDATAFRAME *cd,int num)
{
    int fin=cd->rows+num+1;
    int value =0;
    for (int i = 0; i <cd->ls; i++)
    {
        printf("what are the %d new values you want in this column ?",num);
        for (int j = cd->rows; j < fin; j++)
        {
            scanf("%d", &value);
            insert_value(cd->data[i].data[j], value);
        }
    }
    cd->rows+=num;
}

void delete_rows_val(CDATAFRAME*cd,int ind)
{
    int start=ind,temp=0;
    for(int i=start;i<cd->rows;i++)
    {
        for (int j = 0; j < cd->ls; j++)
        {
            temp = cd->data[j].data[i];
            cd->data[j].data[i] = cd->data[j].data[i + 1];
            cd->data[j].data[i + 1] = temp;
        }
        ind++;
    }
    for(int k=0;k<cd->ls;k++)
    {
        free(cd->data[k].data[cd->rows]);
    }
    cd->rows--;
}

void add_col_cdata(CDATAFRAME *cd,int num)
{
    int value =0;
    char name[100];
    for (int i = cd->ls; i <(cd->ls)+num; i++)
    {
        printf("what is the name of the column at the index %d ?\n", i + 1);
        scanf("%s", name);
        COLUMN *col = create_column(name);
        insert_column(cd, col);
        printf("what are the %d values you want in the column ?", cd->rows);
        for (int j = 0; j < cd->rows; j++) {
            scanf("%d", &value);
            insert_value(col, value);
        }
    }
    cd->ls+=num;
}

void delete_col_val(CDATAFRAME*cd,int ind)
{
    int start=ind,temp=0;
    for(int i=start;i<cd->ls;i++)
    {
        for (int j = 0; j < cd->rows; j++)
        {
            temp = cd->data[i].data[j];
            cd->data[i].data[j] = cd->data[i+1].data[j];
            cd->data[i+1].data[j] = temp;
        }
        ind++;
    }
    delete_column(*cd->data[cd->ls].data);
    cd->ls--;
}

int exist_val(CDATAFRAME*cd,int val)
{
    for(int i=0;i<cd->ls;i++)
    {
        if(occurences(&cd->data[i],val)>=1)
        {
            return 1;
        }
    }
    return 0;
}

void access_cell(CDATAFRAME*cd,int ord,int abs)
{
    printf("the value at the row %d and col %d is %d",abs,ord,cd->data[ord].data[abs]);
}

void replace_cell(CDATAFRAME*cd,int ord,int abs)
{
    int num=0;
    printf("By which number do you want to change it ?\n ");
    scanf("%d",&num);
    cd->data[ord].data[abs]=num;
}

void rename_title(CDATAFRAME *cd,int ind)
{
    char title[100];
    printf("what is the new title of the column at the index %d ?\n",ind);
    scanf("%s",title);
    cd->data[ind].name=title;
}

void display_name(CDATAFRAME *cd)
{
    for(int i=0;i<cd->ls;i++)
    {
        printf("%s ",cd->data[i].name);
    }
    printf("\n");
}

//supplementary function :ANALYSIS AND STATISTICS
void num_rows(CDATAFRAME *cd)
{
    printf("%d",cd->rows);
}

void num_col(CDATAFRAME *cd)
{
    printf("%d",cd->ls);
}

void num_equal(CDATAFRAME*cd,int val)
{
    //occurences(COLUMN *col,int val)
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num += occurences(&cd->data[i],val);
    }
    printf("%d",num);
}

void num_great(CDATAFRAME*cd,int val)
{
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num +=greatvalue(&cd->data[i],val);
    }
    printf("%d",num);
}

void num_lower(CDATAFRAME*cd,int val)
{
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num +=lessvalue(&cd->data[i],val);
    }
    printf("%d",num);
}