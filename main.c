
#include <stdio.h>
#include "function.h"
int main()
{
    /* TEST PREMIERE PARTIE

    char *title="newcol";
    COLUMN *col = create_column(title);

    insert_value(col, 10);
    insert_value(col, 20);
    insert_value(col, 10);
    insert_value(col, 30);

    print_col(col);

    printf("%d : %d : %d : %d\n",occurences(col,10),returnvalue(col,1),greatvalue(col,13),lessvalue(col,22));

    delete_column(&col);*/


    CDATAFRAME *df = createEmptyDataframe();

    // Hard fill DataFrame with user input
    hardFillDataframe(df);

    // Display DataFrame
    printf("\nDataFrame:\n");
    display_all_cdata(df);

    // Free allocated memory
    for (int i = 0; i < df->ls; i++) {
        delete_column(&(df->data[i]));
    }


    return 0;
}
