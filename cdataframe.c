#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "cdataframe.h"

#define REALOC_SIZE 256
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

int get_int_input() {
    int value;
    while (scanf("%d", &value) != 1) {
        while (getchar() != '\n');  // Vider le tampon d'entrée
        printf("Invalid input. Please enter a number: ");
    }
    return value;
}

void hardFillDataframe(CDATAFRAME *cd)
{
    char name[100];
    printf("how many column do you plan to put ?\n");
    int obj =get_int_input();
    printf("With how many rows ?\n");
    cd->rows =get_int_input();
    for (int i = 0; i <obj; i++)
    {
        printf("what is the name of the column at the index %d ?\n",i+1);
        scanf("%s",name);
        COLUMN *col = create_column(name);
        insert_column(cd,col);
        printf("what are the %d values you want in the column ?\n",cd->rows);
        for(int j=0;j<cd->rows;j++)
        {
            printf("Value for row %d:", j + 1);
            int value = get_int_input();
            insert_value(col, value);
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
    int start=cd->rows;
    int value =0;
    for (int i = 0; i <cd->ls; i++)
    {
        printf("what are the %d new values you want in the column %d ?",num,i);
        for (int j = start; j < cd->rows+num; j++)
        {
            scanf("%d", &value);
            insert_value(&cd->data[i], value);
        }
    }
    cd->rows+=num;
}

void delete_rows_val(CDATAFRAME*cd,int ind)
{
    int temp=0;
    for(int i=ind;i<cd->rows;i++)
    {
        for (int j = 0; j < cd->ls; j++)
        {
            temp = cd->data[j].data[i];
            cd->data[j].data[i] = cd->data[j].data[i + 1];
            cd->data[j].data[i + 1] = temp;
        }
        ind++;
    }
    for(int k=cd->ls;k>0;k--)
    {
        free(&cd->data[k].data[cd->rows]);
    }
    cd->rows--;
}

void add_col_cdata(CDATAFRAME *cd,int num)
{
    int value =0, obj=(cd->ls)+num;
    char name[100];
    for (int i = cd->ls; i <obj; i++)
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

void delete_col_val(CDATAFRAME**cd,int ind)
{
    int temp=0;
    for(int i=ind;i<(*cd)->ls;i++)
    {
        for (int j = 0; j < (*cd)->rows; j++)
        {
            temp = (*cd)->data[i].data[j];
            (*cd)->data[i].data[j] = (*cd)->data[i+1].data[j];
            (*cd)->data[i+1].data[j] = temp;
        }
        ind++;
    }
    delete_column(&(*cd)->data[(*cd)->ls]);
    (*cd)->data = (COLUMN*)realloc((*cd)->data, ((*cd)->ls- 1) * sizeof(COLUMN));
    (*cd)->ls--;
}

int exist_val(CDATAFRAME*cd,int val)
{

    for(int i=0;i<cd->ls;i++)
    {
        for(int j=0;j<cd->rows;j++)
        {
            if(cd->data[i].data[j]==val)
            {
                return 1;
            }
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
    printf("%d\n",cd->rows);
}

void num_col(CDATAFRAME *cd)
{
    printf("%d\n",cd->ls);
}

void num_equal(CDATAFRAME*cd,int val)
{
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num += occurences(&cd->data[i],val);
    }
    printf("%d\n",num);
}

void num_great(CDATAFRAME*cd,int val)
{
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num +=greatvalue(&cd->data[i],val);
    }
    printf("%d\n",num);
}

void num_lower(CDATAFRAME*cd,int val)
{
    int num =0;
    for(int i=0;i<cd->ls;i++)
    {
        num +=lessvalue(&cd->data[i],val);
    }
    printf("%d\n",num);
}
