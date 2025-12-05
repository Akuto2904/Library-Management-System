//main.cpp
#include "Book.hpp"
#include "Members.hpp"
#include "Library.hpp"

#include <iostream>
#include <string>

//Function declarations
void displayMenu();
void addBookMenu(Library& library);
void removeBookMenu(Library& library);
void searchBooksMenu(Library& library);
void displayAllBooksMenu(Library& library);
void displayAvailableBooksMenu(Library& library);
void addMemberMenu(Library& library);
void removeMemberMenu(Library& library);
void displayAllMembersMenu(Library& library);
void borrowBookMenu(Library& library);
void returnBookMenu(Library& library);
void saveBooksMenu(Library& library);
void loadBooksMenu(Library& library);
void saveMembersMenu(Library& library);
void loadMembersMenu(Library& library);
void saveLibraryMenu(Library& library);
void loadLibraryMenu(Library& library);
void hardCodedTests();

//Main function
int main() {
    //Create Library instance
    Library library;
    int choice = 0;
    
    std::cout << "\n===== Welcome to The Library Management System =====" << std::endl;
    
    //Main loop
    while (true) {
        //Display menu options and get user choice
        displayMenu();
        std::cout << "\nEnter your choice (1-18): ";
        
        //Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Error: Invalid input. Please enter a number between 1 and 18." << std::endl;
            continue;
        }
        
        std::cin.ignore(10000, '\n'); //Clear input buffer
        
        //Switch to get user choice and process
        switch (choice) {
    case 1:
        addBookMenu(library);
        break;
    case 2:
        removeBookMenu(library);
        break;
    case 3:
        searchBooksMenu(library);
        break;
    case 4:
        displayAvailableBooksMenu(library);  //Display available books only
        break;
    case 5:
        displayAllBooksMenu(library);  //Display all books (including borrowed)
        break;
    case 6:
        addMemberMenu(library);
        break;
    case 7:
        removeMemberMenu(library);
        break;
    case 8:
        displayAllMembersMenu(library);
        break;
    case 9:
        borrowBookMenu(library);
        break;
    case 10:
        returnBookMenu(library);
        break;
    case 11:
        saveBooksMenu(library);
        break;
    case 12:
        loadBooksMenu(library);
        break;
    case 13:
        saveMembersMenu(library);
        break;
    case 14:
        loadMembersMenu(library);
        break;
    case 15:
        saveLibraryMenu(library);
        break;
    case 16:
        loadLibraryMenu(library);
        break;
    case 17:
            hardCodedTests();
            break;
    case 18:
        std::cout << "\nThank you for using the Library Management System. Goodbye!" << std::endl;
        return 0;
    default:
        std::cout << "Error: Invalid choice. Please enter a number between 1 and 18." << std::endl;
        }
    }
    
    return 0;
}

//Dsiplay main menu options with all options
void displayMenu() {
    std::cout << "\n========== LIBRARY MANAGEMENT MENU ==========" << std::endl;
    std::cout << "1.  Add Book" << std::endl;
    std::cout << "2.  Remove Book" << std::endl;
    std::cout << "3.  Search Books" << std::endl;
    std::cout << "4.  Display Available Books" << std::endl;
    std::cout << "5.  Display All Books (Including Borrowed)" << std::endl;
    std::cout << "6.  Add Member" << std::endl;
    std::cout << "7.  Remove Member" << std::endl;
    std::cout << "8.  Display All Members" << std::endl;
    std::cout << "9.  Borrow Book" << std::endl;
    std::cout << "10. Return Book" << std::endl;
    std::cout << "11. Save Books to File" << std::endl;
    std::cout << "12. Load Books from File" << std::endl;
    std::cout << "13. Save Members to File" << std::endl;
    std::cout << "14. Load Members from File" << std::endl;
    std::cout << "15. Save Library to File" << std::endl;
    std::cout << "16. Load Library from File" << std::endl;
    std::cout << "17. Run Hard-Coded Tests" << std::endl;
    std::cout << "18. Exit" << std::endl;
    std::cout << "===========================================" << std::endl;
}


//Menu to add a new book with validation
void addBookMenu(Library& library) {
    std::cout << "\n========== ADD BOOK ==========" << std::endl;
    
    //Declare variables to hold book details
    std::string bookID, title, author, genre;
    int pages;
    
    //Get and validate book details from user
    std::cout << "Enter Book ID: ";
    std::getline(std::cin, bookID);
    if (bookID.empty() || library.bookExists(bookID)) {
        std::cout << "Error: Book ID cannot be empty or already exist." << std::endl;
        return;
    }
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    if (title.empty()) {
        std::cout << "Error: Title cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    if (author.empty()) {
        std::cout << "Error: Author cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);
    if (genre.empty()) {
        std::cout << "Error: Genre cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter Number of Pages: ";
    if (!(std::cin >> pages) || pages <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Error: Invalid page count. Please enter a positive number." << std::endl;
        return;
    }
    std::cin.ignore(10000, '\n');
    
    //Create Book instance and add to library
    Book newBook(bookID, title, author, genre, pages, true);
    library.addBook(newBook);
    
    //Confirmation message
    std::cout << "\n========== BOOK ADDED SUCCESSFULLY ==========" << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Pages: " << pages << std::endl;
    std::cout << "Status: Available" << std::endl;
    std::cout << "===========================================" << std::endl;
}

//Menu to remove a book with validation
void removeBookMenu(Library& library) {
    std::cout << "\n========== REMOVE BOOK ==========" << std::endl;
    
    //Get book ID to remove and validate
    std::string bookID;
    std::cout << "Enter Book ID to remove: ";
    std::getline(std::cin, bookID);
    if (bookID.empty()) {
        std::cout << "Error: Book ID cannot be empty." << std::endl;
        return;
    }
    
    //Remove book from library
    library.removeBook(bookID);
    std::cout << "===========================================" << std::endl;
}

//Menu to search books by title, author, genre, or book ID
void searchBooksMenu(Library& library) {
    std::cout << "\n========== SEARCH BOOKS ==========" << std::endl;
    
    //Getting search query from user and validate
    std::string query;
    std::cout << "Enter search query (Title, Author, Genre, or Book ID): ";
    std::getline(std::cin, query);
    
    if (query.empty()) {
        std::cout << "Error: Search query cannot be empty." << std::endl;
        return;
    }
    
    library.searchBooks(query);
    std::cout << "===========================================" << std::endl;
}


//Menu to display all books
void displayAllBooksMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL BOOKS ==========" << std::endl;
    library.displayAllBooks();
    std::cout << "===========================================" << std::endl;
}

//Menu to display all available books
void displayAvailableBooksMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL AVAILABLE BOOKS ==========" << std::endl;
    library.displayAvailableBooks();
    std::cout << "===========================================" << std::endl;
}

//Menu to add a new member with validation
void addMemberMenu(Library& library) {
    std::cout << "\n========== ADD MEMBER ==========" << std::endl;
    
    //Declare variables
    std::string memberID, name;
    
    //Get and validate member details from user
    std::cout << "Enter Member ID: ";
    std::getline(std::cin, memberID);
    if (memberID.empty() || library.memberExists(memberID)) {
        std::cout << "Error: Member ID cannot be empty or already exist." << std::endl;
        return;
    }
    std::cout << "Enter Member Name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Error: Member name cannot be empty." << std::endl;
        return;
    }
    
    //Create Members instance and add to library
    std::vector<std::string> borrowed;
    Members newMember(memberID, name, borrowed);
    library.addMember(newMember);
    
    //Confirmation message
    std::cout << "\n========== MEMBER ADDED SUCCESSFULLY ==========" << std::endl;
    std::cout << "Member ID: " << memberID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Books Borrowed: 0" << std::endl;
    std::cout << "===========================================" << std::endl;
}

//Menu to remove a member with validation
void removeMemberMenu(Library& library) {
    std::cout << "\n========== REMOVE MEMBER ==========" << std::endl;
    
    //Get member ID to remove and validate
    std::string memberID;
    std::cout << "Enter Member ID to remove: ";
    std::getline(std::cin, memberID);
    if (memberID.empty()) {
        std::cout << "Error: Member ID cannot be empty." << std::endl;
        return;
    }
    
    //Remove member from library
    library.removeMember(memberID);
    std::cout << "===========================================" << std::endl;
}

//Menu to display all members
void displayAllMembersMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL MEMBERS ==========" << std::endl;
    library.displayMembers();
    std::cout << "===========================================" << std::endl;
}

//Menu to borrow a book with validation
void borrowBookMenu(Library& library) {
    std::cout << "\n========== BORROW BOOK ==========" << std::endl;
    
    //Declare variables
    std::string memberID, bookID;
    
    //Get and validate book details from user
    std::cout << "Enter Member ID: ";
    std::getline(std::cin, memberID);
    if (memberID.empty()) {
        std::cout << "Error: Member ID cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter Book ID: ";
    std::getline(std::cin, bookID);
    if (bookID.empty()) {
        std::cout << "Error: Book ID cannot be empty." << std::endl;
        return;
    }
    
    //Borrow book from library
    library.borrowBook(memberID, bookID);
    std::cout << "===========================================" << std::endl;
}

//Menu to return a book with validation
void returnBookMenu(Library& library) {
    std::cout << "\n========== RETURN BOOK ==========" << std::endl;
    
    //Declare variables
    std::string memberID, bookID;
    
    //Get and validate book details from user
    std::cout << "Enter Member ID: ";
    std::getline(std::cin, memberID);
    if (memberID.empty()) {
        std::cout << "Error: Member ID cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter Book ID: ";
    std::getline(std::cin, bookID);
    if (bookID.empty()) {
        std::cout << "Error: Book ID cannot be empty." << std::endl;
        return;
    }
    
    //Return book to library
    library.returnBook(memberID, bookID);
    std::cout << "===========================================" << std::endl;
}

//Menu to save books to a file
void saveBooksMenu(Library& library) {
    std::cout << "\n========== SAVE BOOKS ==========" << std::endl;
    
    //Get filename to save to and use default if empty
    std::string filename;
    std::cout << "Enter filename to save books to (default: books.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "books.txt";
    }
    
    //Save books to file
    library.saveBooksToFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Menu to load books from a file
void loadBooksMenu(Library& library) {
    std::cout << "\n========== LOAD BOOKS ==========" << std::endl;
    
    //Get filename to load from and use default if empty
    std::string filename;
    std::cout << "Enter filename to load books from (default: books.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "books.txt";
    }
    
    //Load books from file
    library.loadBooksFromFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Menu to save members to a file
void saveMembersMenu(Library& library) {
    std::cout << "\n========== SAVE MEMBERS ==========" << std::endl;
    
    //Get filename to save to and use default if empty
    std::string filename;
    std::cout << "Enter filename to save members to (default: members.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "members.txt";
    }
    
    //Save members to file
    library.saveMembersToFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Menu to load members from a file
void loadMembersMenu(Library& library) {
    std::cout << "\n========== LOAD MEMBERS ==========" << std::endl;
    
    //Get filename to load from and use default if empty
    std::string filename;
    std::cout << "Enter filename to load members from (default: members.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "members.txt";
    }
    
    //Load members from file
    library.loadMembersFromFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Menu to save library to a file
void saveLibraryMenu(Library& library) {
    std::cout << "\n========== SAVE LIBRARY ==========" << std::endl;
    
    //Get filename to save to and use default if empty
    std::string filename;
    std::cout << "Enter filename to save to (default: library_backup.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "library_backup.txt";
    }
    
    //Save library to file
    library.saveLibraryToFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Menu to load library from a file
void loadLibraryMenu(Library& library) {
    std::cout << "\n========== LOAD LIBRARY ==========" << std::endl;
    
    //Get filename to load from and use default if empty
    std::string filename;
    std::cout << "Enter filename to load from (default: library_backup.txt): ";
    std::getline(std::cin, filename);

    //Use default filename if none provided
    if (filename.empty()) {
        filename = "library_backup.txt";
    }
    
    //Load library from file
    library.loadLibraryFromFile(filename);
    std::cout << "===========================================" << std::endl;
}

//Function to run hard-coded tests
void hardCodedTests() {
    std::cout << "\n========== RUNNING HARD-CODED TESTS ==========\n" << std::endl;
    
    Library testLibrary;
    
    // ===== TEST 1: Load Sample Data Files (SEPARATELY) =====
    std::cout << "\n[TEST 1] Loading sample data files (books.txt and members.txt)..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    testLibrary.loadBooksFromFile("books.txt");
    testLibrary.loadMembersFromFile("members.txt");
    
    // ===== TEST 2: Add a New Book =====
    std::cout << "\n[TEST 2] Adding a new book to the library..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Book Details:" << std::endl;
    std::cout << "Title: The Power of Positive Thinking" << std::endl;
    std::cout << "Author: Norman Vincent Peale" << std::endl;
    std::cout << "Genre: Motivational, spiritual" << std::endl;
    std::cout << "Pages: 240" << std::endl;
    
    Book newBook("B200", "The Power of Positive Thinking", "Norman Vincent Peale", 
                 "Motivational, spiritual", 240, true);
    testLibrary.addBook(newBook);
    std::cout << "Book added successfully with ID: B200" << std::endl;
    
    // ===== TEST 3: Add a New Member Named "Jane" =====
    std::cout << "\n[TEST 3] Adding a new member named 'Jane'..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::vector<std::string> janeEmpty;
    Members newMember("M110", "Jane", janeEmpty);
    testLibrary.addMember(newMember);
    std::cout << "Member 'Jane' added successfully with ID: M110" << std::endl;
    
    // ===== TEST 4: Member Ben Borrows Book B106 =====
    std::cout << "\n[TEST 4] Member 'Ben' borrows book with ID 'B106'..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "Attempting to borrow book B106 for member Ben (ID: M106)..." << std::endl;
    testLibrary.borrowBook("M106", "B106");
    std::cout << "Borrow transaction completed" << std::endl;
    
    // ===== TEST 5: Member Ben Returns Book B106 =====
    std::cout << "\n[TEST 5] Member 'Ben' returns book with ID 'B106'..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "Attempting to return book B106 from member Ben (ID: M106)..." << std::endl;
    testLibrary.returnBook("M106", "B106");
    std::cout << "Return transaction completed" << std::endl;
    
    // ===== TEST 6: Search for Specific Book =====
    std::cout << "\n[TEST 6] Searching for book with title 'Awaken the Giant Within', and author 'Tony Robbins'" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "Performing search for 'Awaken the Giant Within'..." << std::endl;
    testLibrary.searchBooks("Awaken the Giant Within");
    
    std::cout << "\nPerforming search for 'Tony Robbins'..." << std::endl;
    testLibrary.searchBooks("Tony Robbins");
    std::cout << "Search operations completed" << std::endl;
    
    // ===== TEST 7: Member Chen Borrows Book B109 =====
    std::cout << "\n[TEST 7] Member 'Chen' borrows book with ID 'B109'..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "Attempting to borrow book B109 for member Chen (ID: M109)..." << std::endl;
    testLibrary.borrowBook("M109", "B109");
    std::cout << "Borrow transaction completed" << std::endl;
    
    // ===== TEST 8: Export Current Data to Separate Files =====
    std::cout << "\n[TEST 8] Exporting current library data to separate files..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "Saving updated books to 'books_updated.txt'..." << std::endl;
    testLibrary.saveBooksToFile("books_updated.txt");
    std::cout << "Successfully saved to books_updated.txt" << std::endl;
    
    std::cout << "\nSaving updated members to 'members_updated.txt'..." << std::endl;
    testLibrary.saveMembersToFile("members_updated.txt");
    std::cout << "Successfully saved to members_updated.txt" << std::endl;
    
    // ===== TEST SUMMARY =====
    std::cout << "\n========== TEST SUMMARY ==========\n" << std::endl;
    std::cout << "All hard-coded tests have been executed successfully!" << std::endl;
    std::cout << "\nTest Coverage:" << std::endl;
    std::cout << "File I/O: Loading sample data files (books.txt, members.txt)" << std::endl;
    std::cout << "Book Management: Adding new books to library" << std::endl;
    std::cout << "Member Management: Adding new members" << std::endl;
    std::cout << "Borrowing Operations: Member borrowing books" << std::endl;
    std::cout << "Return Operations: Member returning books" << std::endl;
    std::cout << "Search Operations: Finding books by title and author" << std::endl;
    std::cout << "File Export: Saving updated data to separate output files" << std::endl;
    std::cout << "\n==================================\n" << std::endl;
}