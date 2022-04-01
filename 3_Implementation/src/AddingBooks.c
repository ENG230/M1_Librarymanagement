#include<Library_management.h>

/**
 * @brief function to add new books to library
 * 
 * @return test_merit 
 */

test_merit ToAddingBook(int id,char name[],char author[])
{



    FILE *fp=NULL;
    fp=fopen("Booklibrary.dat","ab+");

    if(fp == NULL)
    {
        printf("\nError: while opening file\n");
        return fail;
    }
    else{

        publication *Newbook = NULL;
        Newbook = malloc(sizeof(publication));

        Newbook->Book_Id = Id;
        strcpy(Newbook->Book_Name,Name);



    strcpy(Newbook->Author_Name,Authorname);

    fwrite(Newbook,sizeof(publication),1,fp);
    fclose(fp);
    free(Newbook);


    return pass;
    }

}