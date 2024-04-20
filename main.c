
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

    //TEST DEUXIEME PARTIE
    CDATAFRAME *df = createEmptyDataframe();

    // Hard fill DataFrame with user input
    hardFillDataframe(df);

    // Display DataFrame
    printf("\nDataFrame:\n");
    display_name(df);
    display_all_cdata(df);

    //adding a row and a col
    add_rows_val(df,2);
    add_col_cdata(df,1);

    //check if a value exist ,change a number and a title
    if (exist_val(df,3)==1){
        printf("The value 3 is in the dataframe");
        replace_cell(df,2,2);
    }
    else{
        printf("not in the dataframe");
    }

    rename_title(df,2);

    // Free allocated memory
    for (int i = 0; i < df->ls; i++) {
        delete_column(&(df->data[i]));
    }


    return 0;
}
