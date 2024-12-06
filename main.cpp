#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;
int menu();
int opt1(int opt);
int opt2(int opt);
int opt3(int opt);
int opt4(int opt);
int opt5(int opt);
int main();
int menu()
{
    int opt;
     system("cls");
    system("color 6");
    cout<<"1-Display Books"<<endl;
    cout<<"2-Add a new Book to Library"<<endl;
    cout<<"3-Borrow Book"<<endl;
    cout<<"4-Display Borrowed Books"<<endl;
    cout<<"5-Return a Book"<<endl;
    cout<<"\n Enter a number to select the option"<<endl;
    cin>>opt;
    while(opt<1 || opt>5)
    {
        cout<<"Wrong Option, Enter Again"<<endl;
        cin>>opt;
    }
    return opt;
}
int opt1(int opt)
{
    int exit;
    string book;
    if(opt==1)
    {
          system("cls");
          system("color F9");
      ifstream input("booksdisplay.txt");
      while(getline(input,book))
      {
       cout<<book<<endl;
      }
        cout<<"\n Press 0 and enter to return to menu"<<endl;
        cin>>exit;
        while(exit!=0)
        {
            cout<<"Press 0 to return"<<endl;
            cin>>exit;
        }
        if(exit==0)
        {

            main();
        }

     }
     return 0;
}

int opt2(int opt)
{
    int id, exit;
    string book, author;
    if (opt == 2)
    {
        system("cls");
        system("color F9");
        cin.ignore();
        cout << "Enter the Name of Book" << endl;
        getline(cin, book);
        cout << "Enter the Name of Author" << endl;
        getline(cin, author);
        ifstream in("id.txt");
        in >> id;
        id++;
        in.close();
        ofstream out("id.txt");
        out << id;
        out.close();
        ofstream output("booksdisplay.txt", ios::app);
        output << left << setw(6) << id << left << setw(30) << book << left << author << endl;

        cout << "Book added successfully with ID: " << id << endl;

        cout << "Enter 0 for menu" << endl;
        cout << "Enter 1 to add a new book" << endl;
        cin >> exit;

        if (exit == 0)
        {
            main();
        }
        else if (exit == 1)
        {
            opt2(opt);
        }
        else
        {
            while (exit != 0 && exit != 1)
            {
                cout << "Wrong input" << endl;
                cin >> exit;
                if (exit == 0)
                {
                    main();
                }
                else if (exit == 1)
                {
                    opt2(opt);
                }
            }
        }
    }
    return 0;
}
int opt3(int opt)
{
    int day, exit, i, id;
    string line, line2, name, month, borrowed;
    if (opt == 3)
    {
        system("cls");
        system("color F9");
        cout << "Enter the ID of the Book you want to borrow (or enter 0 to return and see your book ID in display)" << endl;
        cin >> id;
        if (id == 0)
        {
            main();
        }
        i = -2;
        ifstream input("booksdisplay.txt");
        while (getline(input, line))
        {
            i++;
            if (i == id)
            {
                ifstream in("borrowedbooks.txt");
                while (getline(in, line2))
                {
                    if (line == line2)
                    {
                        cout << "The book has already been borrowed return to menu and see option 4 for borrowed books" << endl;
                        break;
                    }
                }

                if (line != line2)
                {
                    ofstream output("borrowedbooks.txt", ios::app);
                    output << line << endl;

                    system("cls");
                    cout << "Enter your Name" << endl;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter the full name of month" << endl;
                    cin >> month;
                    cout << "Enter the day of month" << endl;
                    cin >> day;
                    system("cls");
                    cout << "ID    TITLE                         AUTHOR" << endl;
                    cout << line << endl;
                    cout << "\n THE BOOK HAS BEEN BORROWED BY " << name << " ON " << month << " " << day << endl;

                    cout << "\n press 0 to return" << endl;
                    cin >> exit;
                    while (exit != 0)
                    {
                        cout << "Press 0 to return" << endl;
                        cin >> exit;
                        if (exit == 0)
                        {
                            main();
                        }
                    }
                    if (exit == 0)
                    {
                        main();
                    }
                }
                cout << "\n press 0 to return" << endl;
                    cin >> exit;
                    while (exit != 0)
                    {
                        cout << "Press 0 to return" << endl;
                        cin >> exit;
                        if (exit == 0)
                        {
                            main();
                        }
                    }
                    if (exit == 0)
                    {
                        main();
                    }
                break;
            }
        }
    }
    return 0;
}
int opt4(int opt)
{
    int exit;
    string line;
    system("cls");
    system("color f9");
    ifstream input("borrowedbooks.txt");
    cout<<"THESE BOOKS HAVE ALREADY BEEN BORROWED"<<endl;
    cout << "ID    TITLE                         AUTHOR" << endl;
    while(getline(input,line))
    {
        cout<<line<<endl;
    }
    cout<<"\nPress 0 to exit"<<endl;
    cin>>exit;
    while(exit!=0)
    {
        cout<<"Wrong input"<<endl;
        cin>>exit;
        if(exit==0)
        {
            main();
        }
    }
    if(exit==0)
    {
        main();
    }
return 0;
}
int opt5(int opt)
{
    int exit, days;
    string returnedBook, line;

    system("cls");
    system("color F9");

    cout << "Enter the ID of the Book you want to return (or enter 0 to return to the menu)" << endl;
    cin >> returnedBook;

    if (returnedBook == "0")
    {
        main();
    }

    ifstream input("borrowedbooks.txt");
    ofstream temp("temp.txt");

    bool bookReturned = false;

    while (getline(input, line))
    {
        if (line.find(returnedBook) == string::npos)
        {
            temp << line << endl;
        }
        else
        {
            cout << "The book with ID " << returnedBook << " has been returned." << endl;
            cout << "How many days did you keep the book: ";
            cin >> days;
            if (days <= 7)
                cout << "No fine" << endl;
            else
                cout << "Fine is 20 rs per day after a week so your fine would be: " << (days - 7) * 20 << endl;
            bookReturned = true;
        }
    }

    input.close();
    temp.close();

    remove("borrowedbooks.txt");
    rename("temp.txt", "borrowedbooks.txt");

    if (!bookReturned)
    {
        cout << "The book with ID " << returnedBook << " was not found in the borrowed books list." << endl;
    }

    cout << "\nPress 0 to return to the menu" << endl;
    cin >> exit;

    while (exit != 0)
    {
        cout << "Wrong input" << endl;
        cin >> exit;
        if (exit == 0)
        {
            main();
        }
    }

    if (exit == 0)
    {
        main();
    }

    return 0;
}



int main()
{
    system("cls");
    system("color 07");
    int opt;
    opt = menu();

    if (opt == 1)
        opt1(opt);
    else if (opt == 2)
        opt2(opt);
    else if (opt == 3)
        opt3(opt);
    else if (opt == 4)
        opt4(opt);
    else if (opt == 5)
        opt5(opt);
    else
        cout << "Invalid option." << endl;
    if (opt != 0)
        main();
}


