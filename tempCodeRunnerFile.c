#include<stdio.h>
#include<stdlib.h>


/**
 * @brief main function of the project
 * 
 * @return int 
 */

int main()
{
    
    int id,choice,success,pass,fail;
    
    
    
    char name[20],authorname[20];
    
        

    printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
    printf("\n\t\t\t\t\t\t1.To Adding Books");
    printf("\n\t\t\t\t\t\t2.To Deleting books");
    printf("\n\t\t\t\t\t\t3.To View Books");
    printf("\n\t\t\t\t\t\t4.To Searching book");
    printf("\n\t\t\t\t\t\t5.To Issuing books");
    printf("\n\t\t\t\t\t\t6.To Close the Application");
    printf("\n\t\t\t\t\t\t******************************************\n");
    printf("\n\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nBookId: ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\nBook name: ");
        //gets(name);
	scanf("%19s",name);
       printf("Authorname: ");
        fflush(stdin);
        //gets(author);
	scanf("%19s",authorname);
    
        
     }
     if(success == pass)
    {
        printf("Successful\n");
    }
    else if(success==fail)
    {
        printf("Unsuccessful\n");
    }
    else{
        printf("Error\n");
    }
return 0;
}
    


