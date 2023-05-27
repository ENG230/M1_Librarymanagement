#include"Library_management.h"

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




#include<iostream>

#include<fstream>

#include <cstdio>

#include<string>

using namespace std;

struct member{

    int id;

    char name[20];

    char address[100];

    char ph_no[11];

};

struct book{

    int bookid;

    char name[30];

    char author[30];

    char type[20];

};

int menu();

void add_book();

int calculate_book_id();

void see_book();

void delete_book();

void update_book();

void add_member();

int calculate_member_id();

void see_member();

void delete_member();

void update_member();

void add_book()

{

    //system("clear");

    book temp;

    cout << "Enter Book Name: ";

    cin.getline(temp.name, sizeof(temp.name));

    cout << "Enter Author's Name: ";

    cin.getline(temp.author, sizeof(temp.author));

    cout << "Enter Type: ";

    cin.getline(temp.type, sizeof(temp.type));

    temp.bookid = calculate_book_id();

    cout << "Id: " << temp.bookid;

    ofstream f;

    f.open("books.txt", ios::app);

    f.write((char*)&temp, sizeof(temp));

    f.close();

    cin.ignore();

    menu();

}

void see_book()

{

    //system("clear");

    book tem;

    int temp;

    cout << "Enter Id: ";

    cin >> temp;

    fstream f;

    f.open("books.txt", ios::in | ios::binary);

    while (f.read((char*)&tem, sizeof(tem)))

    {

        if (temp == tem.bookid)

        {

            cout << "Book Name: " << tem.name << endl;

            cout << "Author: " << tem.author << endl;

            cout << "Type: " << tem.type << endl;

            break;

        }

    }

    f.close();

    cin.ignore();

    menu();

}

void delete_book()

{

    //system("clear");

    int temp;

    cout << "Enter Id: ";

    cin >> temp;

    book s;

    fstream f, f1;

    f1.open("tempbook.txt", ios::out | ios::app);

    f.open("books.txt", ios::in | ios::out | ios::binary);

    while (f.read((char*)&s, sizeof(s)))

    {

        if (s.bookid != temp)

        {

            f1.write((char*)&s, sizeof(s));

        }

        else {

            cout << "\nBook deleted: " << s.name;

        }

    }

    f1.close();

    f.close();

    remove("books.txt");

    rename("tempbook.txt", "books.txt");

    cin.ignore();

    menu();

}

void update_book()

{

    //system("clear");

    cout << "Enter Id: ";

    int temp;

    cin >> temp;

    cin.ignore(); // Ignore the newline character after reading the ID

    book s;

    fstream f;

    f.open("books.txt", ios::in | ios::out | ios::binary);

    while (!f.eof())

    {

        long pos = f.tellg();

        f.read((char*)&s, sizeof(s));

        if (temp == s.bookid)

        {

            cout << "Add new details for Id: " << s.bookid;

            cout << "\nEnter Book Name: ";

            cin.getline(s.name, sizeof(s.name));

            cout << "Enter Author's Name: ";

            cin.getline(s.author, sizeof(s.author));

            cout << "Enter Type: ";

            cin.getline(s.type, sizeof(s.type));

            f.seekg(pos);

            f.write((char*)&s, sizeof(s));

            cout << "\nData Modified";

            break;

        }

    }

    f.close();

    cin.ignore();

    menu();

}

void add_member()

{

    //system("clear");

    member temp;

    cout << "Enter Name: ";

    cin.getline(temp.name, sizeof(temp.name));

    cout << "Enter Address: ";

    cin.getline(temp.address, sizeof(temp.address));

    cout << "Enter Phone No.: ";

    cin.getline(temp.ph_no, sizeof(temp.ph_no));

    temp.id = calculate_member_id();

    cout << "Id: " << temp.id;

    ofstream f;

    f.open("members.txt", ios::app | ios::binary);

    f.write((char*)&temp, sizeof(temp));

    f.close();

    cin.ignore();

    menu();

}

void see_member()

{

    //system("clear");

    member tem;

    int temp;

    cout << "Enter Id: ";

    cin >> temp;

    fstream f;

    f.open("members.txt", ios::in | ios::binary);

    while (f.read((char*)&tem, sizeof(tem)))

    {

        if (temp == tem.id)

        {

            cout << "Name: " << tem.name << endl;

            cout << "Address: " << tem.address << endl;

            cout << "Phone No.: " << tem.ph_no << endl;

            break;

        }

    }

    f.close();

    cin.ignore();

    menu();

}

void delete_member()

{

    //system("clear");

    int temp;

    cout << "Enter Id: ";

    cin >> temp;

    member s;

    fstream f, f1;

    f1.open("tempmem.txt", ios::out | ios::app | ios::binary);

    f.open("members.txt", ios::in | ios::out | ios::binary);

    while (f.read((char*)&s, sizeof(s)))

    {

        if (s.id != temp)

        {

            f1.write((char*)&s, sizeof(s));

        }

        else {

            cout << "\nMember deleted: " << s.name;

        }

    }

    f1.close();

    f.close();

    remove("members.txt");

    rename("tempmem.txt", "members.txt");

    cin.ignore();

    menu();

}

void update_member()

{

    //system("clear");

    cout << "Enter Id: ";

    int temp;

    cin >> temp;

    cin.ignore(); // Ignore the newline character after reading the ID

    member s;

    fstream f;

    f.open("members.txt", ios::in | ios::out | ios::binary);

    while (!f.eof())

    {

        long pos = f.tellg();

        f.read((char*)&s, sizeof(s));

        if (temp == s.id)

        {

            cout << "Add new details for Id: " << s.id;

            cout << "\nEnter Name: ";

            cin.getline(s.name, sizeof(s.name));

            cout << "Enter Address: ";

            cin.getline(s.address, sizeof(s.address));

            cout << "Enter Phone No.: ";

            cin.getline(s.ph_no, sizeof(s.ph_no));

            f.seekg(pos);

            f.write((char*)&s, sizeof(s));

            cout << "\nData Modified";

            break;

        }

    }

    f.close();

    cin.ignore();

    menu();

}

int calculate_book_id()

{

    fstream f;

    f.open("books.txt", ios::in | ios::ate | ios::out | ios::binary);

    int s = f.tellg() / sizeof(book);

    f.close();

    return ++s;

}

int calculate_member_id()

{

    fstream f;

    f.open("members.txt", ios::in | ios::ate | ios::out | ios::binary);

    int s = f.tellg() / sizeof(member);

    f.close();

    return ++s;

}

int main()

{

    system("clear");

    //int gd=DETECT,gp;

    //initgraph(&gd,&gp,"C:\\TURBOC3\\BGI");

    //setbkcolor(RED);

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t****WELCOME****";

    cout << "\n\t\t           Library Management System";

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tMade by-";

    cout << "\n\t\t\t\t\t\t\t\tARUN KUMAR ENGLE";

    cout << "\n\t\t\t\t\t\t\t\tID:40032324";

    cout << "\n\t\t\t\t\t\t\t\tOfc:LTTS";

    //delay(2000);

    //closegraph();

    menu();

    cin.ignore();

    return 0;

}
