
#include <stdio.h>
#include "cdataframe.h"

int main()
{
    char ques="";
    printf("========== MENU ========== \nWelcome in our project.\n");
    printf("Here are the possible functionnality that you can access: \n");
    printf("-Enter a :hardfile a Cdataframe\n-Enter A :display the dataframe\n");
    printf("-Enter b :manipulate the names of the columns\n-Enter B :display a part of the cdataframe\n");
    printf("-Enter c :add something to the cdataframe\n-Enter C :access to a certain cell\n");
    printf("-Enter d :specific information\n-Enter D :delete part of the Cdataframe\n");
    printf("-Enter e :finish with the Cdataframe created\n========== END ===========\n");

    CDATAFRAME *df = createEmptyDataframe();
    do {
        printf("what do you want to do ?");
        scanf("%c",&ques);
        if(ques == 'a'){
            hardFillDataframe(df);
        }
        else if(ques == 'A'){
            int nim;
            printf("do you want to display also the name?(1=yes and 0=no)");
            scanf("%d",&nim);
            if(nim == 1){
                printf("\nDataFrame:\n");
                display_name(df);
                display_all_cdata(df);
            }
            else{
                printf("\nDataFrame:\n");
                display_all_cdata(df);
            }
        }
        else if(ques =='b')
        {
            int nname,ncol;
            printf("Do you want to display all names (1),one name in particular(2) or change a name(3)?");
            scanf("%d",&nname);
            if(nname == 1)
                display_name(df);
            else if(nname == 2){
                printf("which column do you want to display the names ?");
                scanf("%d",&ncol);
                printf("%s\n",df->data[ncol].name);
            }
            else if(nname == 3) {
                printf("which column do you want to change the name ?");
                do {
                    scanf("%d",&ncol);
                }
                while(ncol>df->ls);
                rename_title(df,ncol);
            }
        }
        else if(ques=='B') {
            int num,x,y;
            printf("do you want to display a part of the columns (1) or a part of the rows (2)?");
            scanf("%d",&num);
            if(num ==1) {
                printf("from which to which column ?");
                scanf("%d %d",&x,&y);
                display_part_col(df,x,y);
            }
            if(num ==2) {
                printf("from which to which row ?");
                scanf("%d %d",&x,&y);
                display_part_rows(df,x,y);
            }
        }
        else if(ques=='c') {
            int num,plus;
            printf("do you want to add columns (1) or add rows (2)?");
            scanf("%d",&num);
            if(num ==1) {
                printf("how many column do you want to add ?");
                scanf("%d",&plus);
                add_col_cdata(df,plus);
            }
            if(num ==2) {
                printf("how many row do you want to add?");
                scanf("%d",&plus);
                add_rows_val(df,plus);
            }
        }
        else if(ques=='C') {
            int num,cell,x,y;
            printf("do you want to check if a value exist (1),access to a cell(2) or replace a value of a cell(3)?");
            scanf("%d",&num);
            if(num ==1) {
                printf("which value do you want to check?");
                scanf("%d",&cell);
                exist_val(df,cell);
            }
            if(num ==2) {
                printf("which cell do you want to know the value?");
                scanf("%d %d",&x,&y);
                access_cell(df,x,y);
            }
            if(num ==3) {
                printf("which cell do you want to replace the value?");
                scanf("%d %d",&x,&y);
                replace_cell(df,x,y);
            }
        }
        else if(ques=='d') {
            int num,choix,x;
            printf("do you want an information about the cdataframe (1)or compare a value to all of the cdataframe(2)?");
            scanf("%d",&num);
            if(num ==1) {
                printf("do you want to know the number of rows(1) or column (2)?");
                scanf("%d",&choix);
                if(choix ==1) {
                    num_rows(df);
                }
                if(choix ==2) {
                    num_col(df);
                }
            }
            if(num ==2) {
                printf("to which value do you want to compare?");
                scanf("%d",&x);
                printf("do you want to find the number of equivalent value(1),greater value(2) or the lower value (3)");
                scanf("%d",choix);
                if(choix ==1) {
                    num_equal(df,x);
                }
                if(choix ==2) {
                    num_great(df,x);
                }
                if(choix ==3) {
                    num_lower(df,x);
                }
            }
        }
        else if(ques =='D') {
            int choix,ind;
            printf("Do you want to delete a column(1) or a row(2) ?");
            scanf("%d",&choix);
            if(choix ==1) {
                printf("Which column?");
                scanf("%d",&ind);
                delete_col_val(&df,ind);
            }
            if(choix ==2) {
                printf("Which row?");
                scanf("%d",&ind);
                delete_rows_val(df,ind);
            }
        }
        else if(ques=='e')
        {
            int i;
            for(i=df->ls;i>=0;i--);
            {
                delete_column(&df->data[i]);
            }
        }
    }while(ques!='e');
    return 0;
}
