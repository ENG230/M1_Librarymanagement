/**
 * @file main.c
 * @author Engile Arun Kumar (engilearunkumar77@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"Library_management.h"

/**
 * @brief main function of the project
 * 
 * @return int 
 */

int main()
{

    int Id,option,success,pass,fail; 

    char Name[30],Authorname[20];



    printf("\n\t\t\t\t\t\t************** MAIN MENU ***************\n");
    printf("\n\t\t\t\t\t\t1.To Add Books");
    printf("\n\t\t\t\t\t\t2.To Delete Books");
    printf("\n\t\t\t\t\t\t3.To Search Books");
    printf("\n\t\t\t\t\t\t4.To View Books");
    printf("\n\t\t\t\t\t\t5.To Exit Application");
    printf("\n\t\t\t\t\t\t$**************************************$\n");
    printf("\n\t\t\t\t\t\tEnter your option: ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("\nBookId: ");
        scanf("%d",&Id);
        fflush(stdin);
        printf("\nEnter Book Name:");
        //gets(name);
	scanf("%19s",Name);
       printf("AuthorName: ");
        fflush(stdin);
        //gets(author);
	scanf("%19s",Authorname);
        success=ToAddingBook(Id,Name,Authorname);
        break;
        case 2:
        printf("\nBookId: ");
        scanf("%d",&Id);
        success=ToDeletingBook(Id);
        break;
        case 3:
        success=ToViewBook();
        break;
        case 4:
        printf("\nBookId:");
        scanf("%d",&Id);
        success=ToSearchingBook(Id);
        break;
        case 5:
        printf("\nBookId: ");
        scanf("%d",&Id);
        case 6:
        printf("\n\n\n");
        exit(1);
        default:
        printf("\n\t\t\t\t\t\tIncorrect option");
        break;
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