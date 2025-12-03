#include "Library.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// Constructor
Library::Library() {
    // Initialization
}

// Book Management
void Library::addBook(const Book& book) {
    books.insert({book.getBookID(), book});
    std::cout << "Book '" << book.getTitle() << "' (ID: " << book.getBookID() << ") added to library." << std::endl;
}

void Library::removeBook(const std::string& bookID) {
    auto it = books.find(bookID);
    if (it != books.end()) {
        std::cout << "Book '" << it->second.getTitle() << "' (ID: " << bookID << ") removed from library." << std::endl;
        books.erase(it);
    } else {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
    }
}

void Library::searchBooks(const std::string& query) const {
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    
    std::vector<Book> results;
    
    // Convert query to lowercase for case-insensitive comparison
    std::string queryLower = query;
    std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);
    
    // Search through all books
    for (const auto& pair : books) {
        const Book& book = pair.second;
        bool match = false;
        
        // Check if query matches author
        std::string bookAuthor = book.getAuthor();
        std::transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        if (bookAuthor.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        // Check if query matches title
        std::string bookTitle = book.getTitle();
        std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
        if (bookTitle.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        // Check if query matches genre
        std::string bookGenre = book.getGenre();
        std::transform(bookGenre.begin(), bookGenre.end(), bookGenre.begin(), ::tolower);
        if (bookGenre.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        // Check if query matches book ID
        std::string bookID = book.getBookID();
        std::transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
        if (bookID.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        if (match) {
            results.push_back(book);
        }
    }
    
    // Display results
    if (results.empty()) {
        std::cout << "No books found matching \"" << query << "\"." << std::endl;
    } else {
        std::cout << "\n========== SEARCH RESULTS ==========" << std::endl;
        std::cout << "Search query: \"" << query << "\"" << std::endl;
        std::cout << "Found " << results.size() << " match(es)" << std::endl;
        std::cout << std::string(48, '-') << std::endl;
        
        for (const Book& book : results) {
            std::cout << "Book ID: " << book.getBookID() << std::endl;
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Pages: " << book.getPages() << std::endl;
            std::cout << "Status: " << (book.getAvailability() ? "Available" : "Borrowed") << std::endl;
            std::cout << std::string(48, '-') << std::endl;
        }
    }
}

// Function to display all books
void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    
    std::cout << "\n========== ALL BOOKS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(48, '-') << std::endl;
    int bookCount = 0;
    
    for (const auto& pair : books) {
        const Book& book = pair.second;
        bookCount++;
        
        std::cout << "Book ID: " << book.getBookID() << std::endl;
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "Pages: " << book.getPages() << std::endl;
        std::cout << "Status: " << (book.getAvailability() ? "Available" : "Borrowed") << std::endl;
        std::cout << std::string(48, '-') << std::endl;
    }
    
    std::cout << "Total Books in Library: " << bookCount << std::endl;
    std::cout << "===========================================" << std::endl;
}


//Function to display available books
void Library::displayAvailableBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }

    std::cout << "\n========== AVAILABLE BOOKS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(48, '-') << std::endl;
    
    int availableCount = 0;
    for (const auto& pair : books) {
        const Book& book = pair.second;
        
        if (book.getAvailability()) {
            availableCount++;
            std::cout << "Book ID: " << book.getBookID() << std::endl;
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Pages: " << book.getPages() << std::endl;
            std::cout << "Status: Available" << std::endl;
            std::cout << std::string(48, '-') << std::endl;
        }
    }
    
    if (availableCount == 0) {
        std::cout << "No available books at this time." << std::endl;
    } else {
        std::cout << "Total Available Books: " << availableCount << std::endl;
    }
}

// Member Management
void Library::addMember(const Members& member) {
    members.insert({member.getMemberID(), member});
    std::cout << "Member '" << member.getName() << "' (ID: " << member.getMemberID() << ") added to library." << std::endl;
}

void Library::removeMember(const std::string& memberID) {
    auto it = members.find(memberID);
    if (it != members.end()) {
        std::cout << "Member '" << it->second.getName() << "' (ID: " << memberID << ") removed from library." << std::endl;
        members.erase(it);
    } else {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl;
    }
}

void Library::displayMembers() const {
    if (members.empty()) {
        std::cout << "No members in the library." << std::endl;
        return;
    }

    std::cout << "\n========== MEMBERS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    for (const auto& pair : members) {
        const Members& member = pair.second;
        std::cout << "Member ID: " << member.getMemberID() << std::endl;
        std::cout << "Name: " << member.getName() << std::endl;
        
        std::vector<std::string> borrowed = member.getBorrowed();
        std::cout << "Books Borrowed (" << borrowed.size() << "): ";
        
        if (borrowed.empty()) {
            std::cout << "None" << std::endl;
        } else {
            for (size_t i = 0; i < borrowed.size(); ++i) {
                std::cout << borrowed[i];
                if (i < borrowed.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::string(40, '-') << std::endl;
    }
}

// Borrowing and Returning
void Library::borrowBook(const std::string& memberID, const std::string& bookID) {
    // Find the member
    auto memberIt = members.find(memberID);
    if (memberIt == members.end()) {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl;
        return;
    }

    // Find the book
    auto bookIt = books.find(bookID);
    if (bookIt == books.end()) {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
        return;
    }

    // Check if book is available
    if (!bookIt->second.getAvailability()) {
        std::cout << "Error: Book '" << bookIt->second.getTitle() << "' (ID: " << bookID << ") is not available for borrowing." << std::endl;
        return;
    }

    // Check if member already borrowed this book
    const std::vector<std::string>& borrowed = memberIt->second.getBorrowed();
    if (std::find(borrowed.begin(), borrowed.end(), bookID) != borrowed.end()) {
        std::cout << "Error: Member '" << memberIt->second.getName() << "' has already borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
        return;
    }

    // Add book to member's borrowed list (make a copy, modify it, then set it back)
    std::vector<std::string> updatedBorrowed = borrowed;  // Create a copy
    updatedBorrowed.push_back(bookID);
    memberIt->second.setBorrowed(updatedBorrowed);

    // Update book availability to false
    bookIt->second.setAvailability(false);

    // Record the loan
    loans[memberID].push_back(bookID);

    std::cout << "Member '" << memberIt->second.getName() << "' successfully borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
}


void Library::returnBook(const std::string& memberID, const std::string& bookID) {
    // Find the member
    auto memberIt = members.find(memberID);
    if (memberIt == members.end()) {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl;
        return;
    }

    // Find the book
    auto bookIt = books.find(bookID);
    if (bookIt == books.end()) {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
        return;
    }

    // Check if member has borrowed this book
    const std::vector<std::string>& borrowed = memberIt->second.getBorrowed();
    if (std::find(borrowed.begin(), borrowed.end(), bookID) == borrowed.end()) {
        std::cout << "Error: Member '" << memberIt->second.getName() << "' has not borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
        return;
    }

    // Remove book from member's borrowed list
    std::vector<std::string> updatedBorrowed = borrowed;
    auto it = std::find(updatedBorrowed.begin(), updatedBorrowed.end(), bookID);
    updatedBorrowed.erase(it);
    memberIt->second.setBorrowed(updatedBorrowed);

    // Update book availability to true
    bookIt->second.setAvailability(true);

    // Record the return in loans
    auto loanIt = loans.find(memberID);
    if (loanIt != loans.end()) {
        auto bookInLoans = std::find(loanIt->second.begin(), loanIt->second.end(), bookID);
        if (bookInLoans != loanIt->second.end()) {
            loanIt->second.erase(bookInLoans);
        }
    }

    std::cout << "Member '" << memberIt->second.getName() << "' successfully returned book '" << bookIt->second.getTitle() << "'." << std::endl;
}


// File I/O
void Library::saveLibraryToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    
    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for writing." << std::endl;
        return;
    }
    
    // Write books to file
    outFile << "===== BOOKS =====" << std::endl;
    if (books.empty()) {
        outFile << "No books in library." << std::endl;
    } else {
        for (const auto& pair : books) {
            const Book& book = pair.second;
            outFile << book.getBookID() << "|"
                    << book.getTitle() << "|"
                    << book.getAuthor() << "|"
                    << book.getGenre() << "|"
                    << book.getPages() << "|"
                    << (book.getAvailability() ? "1" : "0") << std::endl;
        }
    }
    
    outFile << std::endl << "===== MEMBERS =====" << std::endl;
    
    // Write members to file
    if (members.empty()) {
        outFile << "No members in library." << std::endl;
    } else {
        for (const auto& pair : members) {
            const Members& member = pair.second;
            outFile << member.getMemberID() << "|"
                    << member.getName() << "|";
            
            // Write borrowed books
            const std::vector<std::string>& borrowed = member.getBorrowed();
            if (borrowed.empty()) {
                outFile << "None" << std::endl;
            } else {
                for (size_t i = 0; i < borrowed.size(); ++i) {
                    outFile << borrowed[i];
                    if (i < borrowed.size() - 1) {
                        outFile << ",";
                    }
                }
                outFile << std::endl;
            }
        }
    }
    
    outFile.close();
    std::cout << "Library successfully saved to '" << filename << "'." << std::endl;
}


void Library::loadLibraryFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return;
    }
    
    std::string line;
    bool readingBooks = false;
    bool readingMembers = false;
    
    while (std::getline(inFile, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Check for section headers
        if (line == "===== BOOKS =====") {
            readingBooks = true;
            readingMembers = false;
            continue;
        } else if (line == "===== MEMBERS =====") {
            readingBooks = false;
            readingMembers = true;
            continue;
        }
        
        // Skip section messages
        if (line == "No books in library." || line == "No members in library.") {
            continue;
        }
        
        // Parse books
        if (readingBooks) {
            std::stringstream ss(line);
            std::string bookID, title, author, genre, pagesStr, availStr;
            
            // Parse pipe-delimited fields: ID|Title|Author|Genre|Pages|Availability
            if (std::getline(ss, bookID, '|') &&
                std::getline(ss, title, '|') &&
                std::getline(ss, author, '|') &&
                std::getline(ss, genre, '|') &&
                std::getline(ss, pagesStr, '|') &&
                std::getline(ss, availStr, '|')) {
                
                try {
                    int pages = std::stoi(pagesStr);
                    bool availability = (availStr == "1");
                    
                    Book book(bookID, title, author, genre, pages, availability);
                    books.insert({bookID, book});
                    std::cout << "Book '" << title << "' loaded from file." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Error parsing book data: " << e.what() << std::endl;
                }
            }
        }
        
        // Parse members
        if (readingMembers) {
            std::stringstream ss(line);
            std::string memberID, name, borrowedStr;
            
            // Parse pipe-delimited fields: ID|Name|BorrowedBooks
            if (std::getline(ss, memberID, '|') &&
                std::getline(ss, name, '|') &&
                std::getline(ss, borrowedStr, '|')) {
                
                // Parse borrowed books (comma-separated)
                std::vector<std::string> borrowed;
                if (borrowedStr != "None") {
                    std::stringstream borrowSS(borrowedStr);
                    std::string bookID;
                    
                    while (std::getline(borrowSS, bookID, ',')) {
                        borrowed.push_back(bookID);
                    }
                }
                
                Members member(memberID, name, borrowed);
                members.insert({memberID, member});
                std::cout << "Member '" << name << "' loaded from file." << std::endl;
            }
        }
    }
    
    inFile.close();
    std::cout << "Library successfully loaded from '" << filename << "'." << std::endl;
}