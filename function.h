//
// Created by Mac on 29/03/2024.
//
typedef struct
{
    char *name;
    int ls;
    int ps;
    int *data;
}COLUMN;

COLUMN *create_column(char *);
int insert_value(COLUMN *, int );
void delete_column(COLUMN **);
void print_col(COLUMN *);
