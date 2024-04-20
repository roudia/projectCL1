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
int occurences(COLUMN *,int );
int returnvalue(COLUMN *,int );
int greatvalue(COLUMN *,int );
int lessvalue(COLUMN *,int);

typedef struct
{
    int ls;
    int ps;
    int rows;
    COLUMN *data;
}CDATAFRAME;

CDATAFRAME *createEmptyDataframe();
int insert_column(CDATAFRAME *, COLUMN *);
void hardFillDataframe(CDATAFRAME *);
void display_all_cdata(CDATAFRAME *);
void display_part_rows(CDATAFRAME *,int ,int);
void display_part_col(CDATAFRAME *,int,int);

void add_rows_val(CDATAFRAME *,int);
void delete_rows_val(CDATAFRAME*,int);
void add_col_cdata(CDATAFRAME *,int);
void delete_col_val(CDATAFRAME*,int);
int exist_val(CDATAFRAME*,int );
void access_cell(CDATAFRAME*,int ,int );
void replace_cell(CDATAFRAME*,int ,int );
void rename_title(CDATAFRAME *,int);

void display_name(CDATAFRAME *);
void num_rows(CDATAFRAME *);
void num_col(CDATAFRAME *);
void num_equal(CDATAFRAME*,int );
void num_great(CDATAFRAME*,int );
void num_lower(CDATAFRAME*,int );