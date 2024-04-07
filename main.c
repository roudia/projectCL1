
#include <stdio.h>
#include "function.h"
int main()
{
    char *title="newcol";
    COLUMN *col = create_column(title);

    insert_value(col, 10);
    insert_value(col, 20);
    insert_value(col, 30);

    print_col(col);

    delete_column(&col);

    return 0;
}
