#include<Library_management.h>

/**
 * @brief function to view all the books
 * 
 * @return test_merit
 */

test_merit ToViewBook()
{
    
    FILE *fp=NULL;
    fp=fopen("Booklibrary.dat","rb");
   
    if(fp==NULL)
    {
        printf("\nERROR:\n");
        return fail;
    }
    else{
        publication *book_to_view=(publication*)malloc(sizeof(publication));
    while(fread(book_to_view,sizeof(publication),1,fp)==1)
    {
        printf("\n%d\t\t\t%s\t\t\t%s",book_to_view->Book_Id,book_to_view->Book_Name,book_to_view->Author_Name);
    }
    fclose(fp);
    free(book_to_view);
    
    return pass;
    }
}





#include<iostream>
using namespace std;

struct atm {
char account_no[11];
char pin[4] ;

};
int main(){

cin.getline(atm.account_no, sizeof(atm.account_no));

cin.getline(atm.pin, sizeof(atm.pin));

return 0;
}

