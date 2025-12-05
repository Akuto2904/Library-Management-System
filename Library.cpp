#include "Library.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

//Constructor
Library::Library() {
    //Initiate library as empty
}


//Functions


//Book Management

//Function to add a book
void Library::addBook(const Book& book) {
    //Insert book into books map
    books.insert({book.getBookID(), book});
    //Confirmation message
    std::cout << "Book '" << book.getTitle() << "' (ID: " << book.getBookID() << ") added to library." << std::endl;
}

//Function to remove a book
void Library::removeBook(const std::string& bookID) {
    //Find book in books map
    auto it = books.find(bookID);
    if (it != books.end()) {
        //Confirmation message
        std::cout << "Book '" << it->second.getTitle() << "' (ID: " << bookID << ") removed from library." << std::endl;
        books.erase(it);
    } else {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
    }
}

//Function to search books by title, author, genre, or book ID
void Library::searchBooks(const std::string& query) const {
    //Check if library is empty
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    
    //Vector to store search results
    std::vector<Book> results;
    
    //Convert query to lowercase for case-insensitive comparison
    std::string queryLower = query;
    std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);
    
    //Search through all books
    for (const auto& pair : books) {
        //Get book reference
        const Book& book = pair.second;
        bool match = false;
        
        //Check if query matches author
        std::string bookAuthor = book.getAuthor();
        std::transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        if (bookAuthor.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        //Check if query matches title
        std::string bookTitle = book.getTitle();
        std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
        if (bookTitle.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        //Check if query matches genre
        std::string bookGenre = book.getGenre();
        std::transform(bookGenre.begin(), bookGenre.end(), bookGenre.begin(), ::tolower);
        if (bookGenre.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        //Check if query matches book ID
        std::string bookID = book.getBookID();
        std::transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
        if (bookID.find(queryLower) != std::string::npos) {
            match = true;
        }
        
        //If any match found, add to results
        if (match) {
            results.push_back(book);
        }
    }
    
    //Display results
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

//Function to display all books
void Library::displayAllBooks() const {
    //Check if library is empty
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    
    //Function to display all books
    std::cout << "\n========== ALL BOOKS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(48, '-') << std::endl;
    int bookCount = 0;
    
    //Iterate through all books
    for (const auto& pair : books) {
        const Book& book = pair.second;
        bookCount++;

        //Display book details
        std::cout << "Book ID: " << book.getBookID() << std::endl;
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "Pages: " << book.getPages() << std::endl;
        std::cout << "Status: " << (book.getAvailability() ? "Available" : "Borrowed") << std::endl;
        std::cout << std::string(48, '-') << std::endl;
    }
    
    //Display total number of books
    std::cout << "Total Books in Library: " << bookCount << std::endl;
    std::cout << "===========================================" << std::endl;
}


//Function to display available books
void Library::displayAvailableBooks() const {
    //Check if library is empty
    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }

    //Display available books
    std::cout << "\n========== AVAILABLE BOOKS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(48, '-') << std::endl;
    
    //Counter for available books
    int availableCount = 0;
    //Iterate through all books
    for (const auto& pair : books) {
        const Book& book = pair.second;
        
        //If book is available, display its details
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
    
    //Display total number of available books (with message for none available)
    if (availableCount == 0) {
        std::cout << "No available books at this time." << std::endl;
    } else {
        std::cout << "Total Available Books: " << availableCount << std::endl;
    }
}

//Function to check if a book ID already exists
bool Library::bookExists(const std::string& bookID) const {
    return books.find(bookID) != books.end();
}


//Member Management


//Function to add a member
void Library::addMember(const Members& member) {
    members.insert({member.getMemberID(), member});
    std::cout << "Member '" << member.getName() << "' (ID: " << member.getMemberID() << ") added to library." << std::endl;
}

//Function to remove a member
void Library::removeMember(const std::string& memberID) {
    auto it = members.find(memberID);
    //Check if member exists
    if (it != members.end()) {
        std::cout << "Member '" << it->second.getName() << "' (ID: " << memberID << ") removed from library." << std::endl;
        members.erase(it);
    } else {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl; //No member found
    }
}

//Function to display all members
void Library::displayMembers() const {
    //Check if library has members
    if (members.empty()) {
        std::cout << "No members in the library." << std::endl;
        return;
    }

    //Display all members
    std::cout << "\n========== MEMBERS IN LIBRARY ==========" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    //Iterate through all members
    for (const auto& pair : members) {
        const Members& member = pair.second;
        //Display member details
        std::cout << "Member ID: " << member.getMemberID() << std::endl;
        std::cout << "Name: " << member.getName() << std::endl;
        
        std::vector<std::string> borrowed = member.getBorrowed();
        std::cout << "Books Borrowed (" << borrowed.size() << "): ";
        
        //Display borrowed books
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

//Function to check if a member ID already exists
bool Library::memberExists(const std::string& memberID) const {
    return members.find(memberID) != members.end();
}

//Borrowing and Returning
void Library::borrowBook(const std::string& memberID, const std::string& bookID) {
    //Find the member
    auto memberIt = members.find(memberID);
    //Check if member exists
    if (memberIt == members.end()) {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl;
        return;
    }

    //Find the book
    auto bookIt = books.find(bookID);
    //Check if book exists
    if (bookIt == books.end()) {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
        return;
    }

    //Check if book is available
    if (!bookIt->second.getAvailability()) {
        std::cout << "Error: Book '" << bookIt->second.getTitle() << "' (ID: " << bookID << ") is not available for borrowing." << std::endl;
        return;
    }

    //Check if member already borrowed this book
    const std::vector<std::string>& borrowed = memberIt->second.getBorrowed();
    if (std::find(borrowed.begin(), borrowed.end(), bookID) != borrowed.end()) {
        std::cout << "Error: Member '" << memberIt->second.getName() << "' has already borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
        return;
    }

    //Add book to member's borrowed list (make a copy, modify it, then set it back)
    std::vector<std::string> updatedBorrowed = borrowed;  //Create a copy
    updatedBorrowed.push_back(bookID);
    memberIt->second.setBorrowed(updatedBorrowed);

    //Update book availability to false
    bookIt->second.setAvailability(false);

    //Record the loan
    loans[memberID].push_back(bookID);

    //Confirmation message
    std::cout << "Member '" << memberIt->second.getName() << "' successfully borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
}

//Function to return a book
void Library::returnBook(const std::string& memberID, const std::string& bookID) {
    //Find the member
    auto memberIt = members.find(memberID);
    //Check if member exists
    if (memberIt == members.end()) {
        std::cout << "Error: Member with ID '" << memberID << "' not found in library." << std::endl;
        return;
    }

    //Find the book
    auto bookIt = books.find(bookID);
    //Check if book exists
    if (bookIt == books.end()) {
        std::cout << "Error: Book with ID '" << bookID << "' not found in library." << std::endl;
        return;
    }

    //Check if member has borrowed this book
    const std::vector<std::string>& borrowed = memberIt->second.getBorrowed();
    if (std::find(borrowed.begin(), borrowed.end(), bookID) == borrowed.end()) {
        std::cout << "Error: Member '" << memberIt->second.getName() << "' has not borrowed book '" << bookIt->second.getTitle() << "'." << std::endl;
        return;
    }

    //Remove book from member's borrowed list
    std::vector<std::string> updatedBorrowed = borrowed;
    auto it = std::find(updatedBorrowed.begin(), updatedBorrowed.end(), bookID);
    updatedBorrowed.erase(it);
    memberIt->second.setBorrowed(updatedBorrowed);

    //Update book availability to true
    bookIt->second.setAvailability(true);

    //Record the return in loans
    auto loanIt = loans.find(memberID);
    if (loanIt != loans.end()) {
        auto bookInLoans = std::find(loanIt->second.begin(), loanIt->second.end(), bookID);
        if (bookInLoans != loanIt->second.end()) {
            loanIt->second.erase(bookInLoans);
        }
    }

    //Confirmation message
    std::cout << "Member '" << memberIt->second.getName() << "' successfully returned book '" << bookIt->second.getTitle() << "'." << std::endl;
}


//File I/O

//Function: Save Books to Separate File
void Library::saveBooksToFile(const std::string& filename) const {
    //Open file for writing
    std::ofstream outFile(filename);
    
    //Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for writing." << std::endl;
        return;
    }
    
    if (books.empty()) {
        outFile << "No books in library." << std::endl;
    } else {
        for (const auto& pair : books) {
            const Book& book = pair.second;
            //Write book details in pipe-delimited format: ID|Title|Author|Genre|Pages|Availability
            outFile << book.getBookID() << "|"
                    << book.getTitle() << "|"
                    << book.getAuthor() << "|"
                    << book.getGenre() << "|"
                    << book.getPages() << "|"
                    << (book.getAvailability() ? "1" : "0") << std::endl;
        }
    }
    
    //Close file and display confirmation message
    outFile.close();
    std::cout << "Books successfully saved to '" << filename << "'." << std::endl;
}

//Function: Load Books from Separate File
void Library::loadBooksFromFile(const std::string& filename) {
    //Open file for reading
    std::ifstream inFile(filename);

    //Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return;
    }

    //Read file line by line
    std::string line;
    while (std::getline(inFile, line)) {
        //Skip empty lines
        if (line.empty()) {
            continue;
        }

        //Skip header line if present
        if (line.find("ID|Title|Author|Genre|Pages|Availability") != std::string::npos) {
            continue;
        }

        //Parse books directly (no headers)
        std::stringstream ss(line);
        std::string bookID, title, author, genre, pagesStr, availStr;

        //Parse pipe-delimited fields: ID|Title|Author|Genre|Pages|Availability
        if (std::getline(ss, bookID, '|') &&
            std::getline(ss, title, '|') &&
            std::getline(ss, author, '|') &&
            std::getline(ss, genre, '|') &&
            std::getline(ss, pagesStr, '|') &&
            std::getline(ss, availStr, '|')) {

            //Trim whitespace from availStr
            availStr.erase(0, availStr.find_first_not_of(" \t\r\n"));
            availStr.erase(availStr.find_last_not_of(" \t\r\n") + 1);

            try {
                int pages = std::stoi(pagesStr);
                bool availability = (availStr == "1" || availStr == "0");
                if (availStr != "0" && availStr != "1") {
                    std::cerr << "Warning: Invalid availability value '" << availStr << "' for book '" << bookID << "'" << std::endl;
                }
                availability = (availStr == "1");
                Book book(bookID, title, author, genre, pages, availability);
                books.insert({bookID, book});
                std::cout << "Book '" << title << "' loaded from file." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error parsing book data: " << e.what() << std::endl;
            }
        }
    }

    //Close file and display confirmation message
    inFile.close();
    std::cout << "Books successfully loaded from '" << filename << "'." << std::endl;
}

//Function: Save Members to Separate File
void Library::saveMembersToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    
    //Open file for writing
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for writing." << std::endl;
        return;
    }
    
    //Check if there are no members
    if (members.empty()) {
        outFile << "No members in library." << std::endl;
    } else {
        for (const auto& pair : members) {
            const Members& member = pair.second;
            outFile << member.getMemberID() << "|"
                    << member.getName() << "|";
            
            //Write borrowed books
            const std::vector<std::string>& borrowed = member.getBorrowed();
            //Check if there are no borrowed books
            if (borrowed.empty()) {
                outFile << "None" << std::endl;
            } else {
                //Write borrowed book IDs comma-separated
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
    
    //Close file and display confirmation message
    outFile.close();
    std::cout << "Members successfully saved to '" << filename << "'." << std::endl;
}

//Function: Load Members from Separate File
void Library::loadMembersFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    //Open file for reading
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return;
    }

    //Read file line by line
    std::string line;
    while (std::getline(inFile, line)) {
        //Skip empty lines
        if (line.empty()) {
            continue;
        }

        //Skip header line if present
        if (line.find("ID|Name|BorrowedBooks") != std::string::npos) {
            continue;
        }

        //Parse members directly (no headers)
        std::stringstream ss(line);
        std::string memberID, name, borrowedStr;

        //Parse pipe-delimited fields: ID|Name|BorrowedBooks (or ID|Name if no books)
        if (std::getline(ss, memberID, '|') &&
            std::getline(ss, name, '|')) {

            //Parse borrowed books (pipe-separated, not comma-separated)
            std::vector<std::string> borrowed;

            //Get remaining borrowed books
            while (std::getline(ss, borrowedStr, '|')) {
                //Trim whitespace from each book ID
                borrowedStr.erase(0, borrowedStr.find_first_not_of(" \t\r\n"));
                borrowedStr.erase(borrowedStr.find_last_not_of(" \t\r\n") + 1);
                
                if (!borrowedStr.empty()) {
                    borrowed.push_back(borrowedStr);
                }
            }

            //Create member and add to library
            Members member(memberID, name, borrowed);
            members.insert({memberID, member});
            std::cout << "Member '" << name << "' loaded from file." << std::endl;
        }
    }

    //Close file and display confirmation message
    inFile.close();
    std::cout << "Members successfully loaded from '" << filename << "'." << std::endl;
}


//Function to save library to a file
void Library::saveLibraryToFile(const std::string& filename) const {
    //Open file for writing
    std::ofstream outFile(filename);
    
    //Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for writing." << std::endl;
        return;
    }
    
    //Write books to file
    outFile << "===== BOOKS =====" << std::endl;
    //Check if there are no books
    if (books.empty()) {
        outFile << "No books in library." << std::endl;
    } else {
        for (const auto& pair : books) {
            const Book& book = pair.second;
            //Write book details in pipe-delimited format: ID|Title|Author|Genre|Pages|Availability
            outFile << book.getBookID() << "|"
                    << book.getTitle() << "|"
                    << book.getAuthor() << "|"
                    << book.getGenre() << "|"
                    << book.getPages() << "|"
                    << (book.getAvailability() ? "1" : "0") << std::endl;
        }
    }
    
    //Check if there are no members
    outFile << std::endl << "===== MEMBERS =====" << std::endl;
    
    //Write members to file

    //Check if there are no members
    if (members.empty()) {
        outFile << "No members in library." << std::endl;
    } else {
        for (const auto& pair : members) {
            const Members& member = pair.second;
            outFile << member.getMemberID() << "|"
                    << member.getName() << "|";
            
            //Write borrowed books
            const std::vector<std::string>& borrowed = member.getBorrowed();
            //Check if there are no borrowed books
            if (borrowed.empty()) {
                outFile << "None" << std::endl;
            } else {
                //Write borrowed book IDs comma-separated
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
    
    //Close the file
    outFile.close();
    //Confirmation message
    std::cout << "Library successfully saved to '" << filename << "'." << std::endl;
}

//Function to load library from a file
void Library::loadLibraryFromFile(const std::string& filename) {
    //Open file for reading
    std::ifstream inFile(filename);
    
    //Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return;
    }
    
    //Setup variables for reading
    std::string line;
    bool readingBooks = false;
    bool readingMembers = false;
    
    //Read file line by line
    while (std::getline(inFile, line)) {
        //Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        //Check for section headers
        if (line == "===== BOOKS =====") {
            readingBooks = true;
            readingMembers = false;
            continue;
        } else if (line == "===== MEMBERS =====") {
            readingBooks = false;
            readingMembers = true;
            continue;
        }
        
        //Skip section messages
        if (line == "No books in library." || line == "No members in library.") {
            continue;
        }
        
        //Parse books
        if (readingBooks) {
            std::stringstream ss(line);
            std::string bookID, title, author, genre, pagesStr, availStr;
            
            //Parse pipe-delimited fields: ID|Title|Author|Genre|Pages|Availability
            if (std::getline(ss, bookID, '|') &&
                std::getline(ss, title, '|') &&
                std::getline(ss, author, '|') &&
                std::getline(ss, genre, '|') &&
                std::getline(ss, pagesStr, '|') &&
                std::getline(ss, availStr, '|')) {
                
                    //Parse book details
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
        
        //Parse members
        if (readingMembers) {
            std::stringstream ss(line);
            std::string memberID, name, borrowedStr;
            
            //Parse pipe-delimited fields: ID|Name|BorrowedBooks
            if (std::getline(ss, memberID, '|') &&
                std::getline(ss, name, '|') &&
                std::getline(ss, borrowedStr, '|')) {
                
                //Parse borrowed books (comma-separated)
                std::vector<std::string> borrowed;
                //Check if there are no borrowed books
                if (borrowedStr != "None") {
                    std::stringstream borrowSS(borrowedStr);
                    std::string bookID;
                    //Parse each borrowed book ID
                    while (std::getline(borrowSS, bookID, ',')) {
                        borrowed.push_back(bookID);
                    }
                }
                //Create member object and add to members map
                Members member(memberID, name, borrowed);
                members.insert({memberID, member});
                std::cout << "Member '" << name << "' loaded from file." << std::endl;
            }
        }
    }
    
    //Close the file
    inFile.close();
    //Confirmation message
    std::cout << "Library successfully loaded from '" << filename << "'." << std::endl;
}