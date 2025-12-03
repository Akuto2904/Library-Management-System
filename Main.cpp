// main.cpp
#include "Book.hpp"
#include "Members.hpp"
#include "Library.hpp"

#include <iostream>
#include <string>

// Function prototypes
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
void saveLibraryMenu(Library& library);
void loadLibraryMenu(Library& library);

int main() {
    Library library;
    int choice = 0;
    
    std::cout << "\n===== Welcome to Library Management System =====" << std::endl;
    
    while (true) {
        displayMenu();
        std::cout << "\nEnter your choice (1-13): ";
        
        // Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Error: Invalid input. Please enter a number between 1 and 13." << std::endl;
            continue;
        }
        
        std::cin.ignore(10000, '\n'); // Clear input buffer
        
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
        displayAvailableBooksMenu(library);  // Display available books only
        break;
    case 5:
        displayAllBooksMenu(library);  // Display all books (including borrowed)
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
        saveLibraryMenu(library);
        break;
    case 12:
        loadLibraryMenu(library);
        break;
    case 13:
        std::cout << "\nThank you for using the Library Management System. Goodbye!" << std::endl;
        return 0;
    default:
        std::cout << "Error: Invalid choice. Please enter a number between 1 and 13." << std::endl;
        }
    }
    
    return 0;
}

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
    std::cout << "11. Save Library to File" << std::endl;
    std::cout << "12. Load Library from File" << std::endl;
    std::cout << "13. Exit" << std::endl;
    std::cout << "===========================================" << std::endl;
}


void addBookMenu(Library& library) {
    std::cout << "\n========== ADD BOOK ==========" << std::endl;
    
    std::string bookID, title, author, genre;
    int pages;
    
    std::cout << "Enter Book ID: ";
    std::getline(std::cin, bookID);
    if (bookID.empty()) {
        std::cout << "Error: Book ID cannot be empty." << std::endl;
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
    
    Book newBook(bookID, title, author, genre, pages, true);
    library.addBook(newBook);
    
    std::cout << "\n========== BOOK ADDED SUCCESSFULLY ==========" << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Pages: " << pages << std::endl;
    std::cout << "Status: Available" << std::endl;
    std::cout << "===========================================" << std::endl;
}

void removeBookMenu(Library& library) {
    std::cout << "\n========== REMOVE BOOK ==========" << std::endl;
    
    std::string bookID;
    std::cout << "Enter Book ID to remove: ";
    std::getline(std::cin, bookID);
    
    if (bookID.empty()) {
        std::cout << "Error: Book ID cannot be empty." << std::endl;
        return;
    }
    
    library.removeBook(bookID);
    std::cout << "===========================================" << std::endl;
}

void searchBooksMenu(Library& library) {
    std::cout << "\n========== SEARCH BOOKS ==========" << std::endl;
    
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

void displayAllBooksMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL BOOKS ==========" << std::endl;
    library.displayAllBooks();
    std::cout << "===========================================" << std::endl;
}

void displayAvailableBooksMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL AVAILABLE BOOKS ==========" << std::endl;
    library.displayAvailableBooks();
    std::cout << "===========================================" << std::endl;
}

void addMemberMenu(Library& library) {
    std::cout << "\n========== ADD MEMBER ==========" << std::endl;
    
    std::string memberID, name;
    
    std::cout << "Enter Member ID: ";
    std::getline(std::cin, memberID);
    if (memberID.empty()) {
        std::cout << "Error: Member ID cannot be empty." << std::endl;
        return;
    }
    
    std::cout << "Enter Member Name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Error: Member name cannot be empty." << std::endl;
        return;
    }
    
    std::vector<std::string> borrowed;
    Members newMember(memberID, name, borrowed);
    library.addMember(newMember);
    
    std::cout << "\n========== MEMBER ADDED SUCCESSFULLY ==========" << std::endl;
    std::cout << "Member ID: " << memberID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Books Borrowed: 0" << std::endl;
    std::cout << "===========================================" << std::endl;
}

void removeMemberMenu(Library& library) {
    std::cout << "\n========== REMOVE MEMBER ==========" << std::endl;
    
    std::string memberID;
    std::cout << "Enter Member ID to remove: ";
    std::getline(std::cin, memberID);
    
    if (memberID.empty()) {
        std::cout << "Error: Member ID cannot be empty." << std::endl;
        return;
    }
    
    library.removeMember(memberID);
    std::cout << "===========================================" << std::endl;
}

void displayAllMembersMenu(Library& library) {
    std::cout << "\n========== DISPLAYING ALL MEMBERS ==========" << std::endl;
    library.displayMembers();
    std::cout << "===========================================" << std::endl;
}

void borrowBookMenu(Library& library) {
    std::cout << "\n========== BORROW BOOK ==========" << std::endl;
    
    std::string memberID, bookID;
    
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
    
    library.borrowBook(memberID, bookID);
    std::cout << "===========================================" << std::endl;
}

void returnBookMenu(Library& library) {
    std::cout << "\n========== RETURN BOOK ==========" << std::endl;
    
    std::string memberID, bookID;
    
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
    
    library.returnBook(memberID, bookID);
    std::cout << "===========================================" << std::endl;
}

void saveLibraryMenu(Library& library) {
    std::cout << "\n========== SAVE LIBRARY ==========" << std::endl;
    
    std::string filename;
    std::cout << "Enter filename to save to (default: library_backup.txt): ";
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "library_backup.txt";
    }
    
    library.saveLibraryToFile(filename);
    std::cout << "===========================================" << std::endl;
}

void loadLibraryMenu(Library& library) {
    std::cout << "\n========== LOAD LIBRARY ==========" << std::endl;
    
    std::string filename;
    std::cout << "Enter filename to load from (default: library_backup.txt): ";
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "library_backup.txt";
    }
    
    library.loadLibraryFromFile(filename);
    std::cout << "===========================================" << std::endl;
}