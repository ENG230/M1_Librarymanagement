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


#include<iostream>

#include<fstream>

#include<cstdio>

#include<string>

using namespace std;

struct member {

    int id;

    char name[20];

    char address[100];

    char ph_no[11];

};

struct book {

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

int menu()

{

    system("clear");

    cout << "\n1. Add Book";

    cout << "\n2. View Book";

    cout << "\n3. Delete Book";

    cout << "\n4. Update Book";

    cout << "\n5. Add Member";

    cout << "\n6. View Member";

    cout << "\n7. Delete Member";

    cout << "\n8. Update Member";

    cout << "\n9. Exit";

    cout << "\n\nEnter Your Choice: ";

    int c;

    cin >> c;

    cin.ignore(); // Ignore the newline character after reading the choice

    switch (c)

    {

        case 1:

            add_book();

            break;

        case 2:

            see_book();

            break;

        case 3:

            delete_book();

            break;

        case 4:

            update_book();

            break;

        case 5:

            add_member();

            break;

        case 6:

            see_member();

            break;

        case 7:

            delete_member();

            break;

        case 8:

            update_member();

            break;

        default:

            exit(0);

    }

}

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

int calculate_book_id()

{

    fstream f;

    f.open("books.txt", ios::in | ios::ate | ios::out);

    int s = f.tellg() / sizeof(book);

    f.close();

    return ++s;

}

void see_book()

{

    system("clear");

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

    system("clear");

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

        else

        {

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

    system("clear");

    cout << "Enter Id: ";

    int temp;

    cin >> temp;

    cin.ignore(); // Ignore the newline character after reading the id

    book s;

    fstream f;

    f.open("books.txt", ios::in | ios::out | ios::binary);

    while (!f.eof())

    {

        long pos = f.tellg();

        f.read((char*)&s, sizeof(s));

        if (temp == s.bookid)

        {

            cout << "Add new Details for Id: " << s.bookid;

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

    system("clear");

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

int calculate_member_id()

{

    fstream f;

    f.open("members.txt", ios::in | ios::ate | ios::out | ios::binary);

    int s = f.tellg() / sizeof(member);

    f.close();

    return ++s;

}

void see_member()

{

    system("clear");

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

    system("clear");

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

        else

        {

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

    system("clear");

    cout << "Enter Id: ";

    int temp;

    cin >> temp;

    cin.ignore(); // Ignore the newline character after reading the id

    member s;

    fstream f;

    f.open("members.txt", ios::in | ios::out | ios::binary);

    while (!f.eof())

    {

        long pos = f.tellg();

        f.read((char*)&s, sizeof(s));

        if (temp == s.id)

        {

            cout << "Add new Details for Id: " << s.id;

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

int main()

{

    menu();

    return 0;

}
