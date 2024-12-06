# Library_management_System
Project: Library Management System with Fine Calculation in C++
Features:
1) The program contains a user interface in which different options can be selected, and each option brings the user to a new screen with a new console color.
2) The project is based on file handling all the data is stored and processed in the form of files for data persistence. Three text files are being used for this project which are booksdisplay.txt,borrowedbooks.txt, and id.txt.
3) There are 6 functions in the program. One function is used to show the menu and select the option. Rest of the 5 functions each represents an option.
4) In the main, system commands are used to clear the screen and select color which would be used in all of the functions. After that menu is shown and the user is asked to select an option.
5) If the user selects option 1 a list of books is shown which is already written inside the booksdisplay.txt file. It diplays author, id and book name.
6) If the user selects option 2 an id is automatically assigned and the user is asked to enter book name and author name. Then this data is stored in the same booksdisplay.txt file so that it can be displayed later.
7) If the user selects option 3 the user is asked to enter the id of the book that the user wants to borrow. The record of that book is written in a seperate file borrowedbooks.txt.
8) If the user selects option 4  the user the content from borrowedbooks.txt is showed which shows all the books that have been borrowed.
9) If the user selects option 5 the user can return a book using the id . Once the book is returned it is removed from borrowedbooks.txt and a fine calculation is also implemented.There is no fine for the first week but after 7 days there is 20 Rs fine each day.
