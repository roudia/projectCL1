
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

