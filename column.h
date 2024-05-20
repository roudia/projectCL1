/* NAME:column.h
* AUTHORS: Annabelle Larvor and Judia Ouazari
 * ROLE :File that contains all the prototype of the function present in the column.c file
 * and make them work in the main.c .
 * */


typedef struct
{
    char *name;
    int ls;
    int ps;
    int *data;
}COLUMN;

COLUMN *create_column(char *);
int insert_value(COLUMN *, int );
void delete_column(COLUMN *);
void print_col(COLUMN *);
int occurences(COLUMN *,int );
int returnvalue(COLUMN *,int );
int greatvalue(COLUMN *,int );
int lessvalue(COLUMN *,int);

