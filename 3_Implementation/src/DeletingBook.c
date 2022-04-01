#include"Library_managment.h"

/**
 * @brief function to remove the records of a book
 * 
 * @param Id 
 * @return test_merit 
 */

test_values ToDeletingBook(int Id)
{
    
    
    
    FILE *fp=NULL;
    FILE *ft=NULL;
    fp = fopen("Booklibrary.dat","rb");
    ft = fopen("temp.dat","wb");
    
    if(fp==NULL || ft==NULL)
        {
            printf("\nError: While opening file:\n");
            return fail;
        }
    else{
        repeat(fp);
        
        publication *removed_book = (publication*)malloc(sizeof(publication));
    while(fread(removed_book,sizeof(publication),1,fp)==1)
    {
        if(Id != removed_book->Book_Id)
        {
            
            fwrite(removed_book,sizeof(publication),1,ft);
            
            
        }
        
        
        

    }
    fclose(fp);
    fclose(ft);
    free(removed_book);
  
   remove("Booklibrary.dat");
    rename("temp.dat","Booklibrary.dat");
    
    return pass;
    
    
        }

}
