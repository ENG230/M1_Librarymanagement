/**
 * @file Library_management.h
 * @author Engile Arun Kumar 
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __LIBRARY_MANAGEMENT_H__
#define __LIBRARY_MANAGEMENT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



/**
 * @brief structure for Book Record
 * 
 */
typedef struct Bookshouse
{
    int Book_Id;
    char Book_Name[30];
    char Author_Name[20];
}publication;

/**
 * @brief return type for funtions for unit testing
 */

typedef enum test_merit {
    pass = 1,
    fail = 0
}test_merit;

/**
 * @brief function to find a book by its Number
 * @return test_merit 
 */
test_merit ToSearchingBook(int Id);

/**
 * @brief function to add new books to the library
 * 
 * @return test_merit 
 */
test_merit ToAddingBook(int Id,char Name[],char AuthorName[]);

/**
 * @brief funtion to denote discarded books
 * 
 * @param  
 * @return test_merit 
 */
test_merit ToDeletingBook(int Id);

/**
 * @brief function to view all the books
 * 
 * @return test_merit 
 */

test_merit ToViewBook(void);

#endif