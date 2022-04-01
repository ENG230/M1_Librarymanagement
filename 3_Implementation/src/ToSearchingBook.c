#include<Library_managment.h>

/**
 * @brief function to find the details about a book
 * 
 * @param Id 
 * @return test_merit
 */

test_merit ToSearchingBook(int Id)
{
    
    FILE *fp=NULL;
    fp = fopen("bookLibrary.dat","rb");
    if(fp==NULL)
    {
        printf("\nError while opening file in search area\n");
        return fail;
    }
    else{
    
    publication *book_to_search=(publication*)malloc(sizeof(publication));
    while(fread(book_to_search,sizeof(publication),1,fp))
    {
        if(book_to_search->Book_Id==Id)
        {
            
            printf("\nBook_Id: %d\t\tBook_Name: %s\t\tBook_Authorname: %s",book_to_search->Book_Id,book_to_search->Book_Name,book_to_search->Author_Name);
            fclose(fp);
            free(book_to_search);
            return pass;
        }
    }
    
    fclose(fp);
    free(book_to_search);
    printf("\nThis Specified Book is not found\n");
    
    return fail;
    }
}