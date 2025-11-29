#include "Members.hpp"
#include "Book.hpp"
#include "Library.hpp"
#include <algorithm>
#include <iostream>

//borrowBook function implementation
void Members::borrowBook(const std::string& bookID, Book& book, Library& library) {
    
    //Check if book is available
    if (!book.getAvailability()) {
        std::cout << "Error, Book; " << bookID << " is not available for borrowing." << std::endl;
        return;
    }

    //Add BookID to borrowed list
    borrowed.push_back(bookID);

    //Update book availability
    book.setAvailability(false);

    //Update library records to reflect loaning book
    library.recordLoan(memberID, bookID);

    std::cout << "Book; " << bookID << " successfully borrowed by Member; " << memberID << "." << std::endl;
}

//returnBook function implementation
void Members::returnBook(const std::string& bookID, Book& book, Library& library) {
    
    //Search for book in member's borrowed vector
    auto it = std::find(borrowed.begin(), borrowed.end(), bookID);

    //Check if book was found in borrowed list
    if (it == borrowed.end()) {
        std::cout << "Error, Book; " << bookID << " not found in Member; " << memberID << "'s borrowed list." << std::endl;
        return;
    }

    //Remove Book from borrowed list
    borrowed.erase(it);

    //Update book availability
    book.setAvailability(true);

    //Update library records
    library.recordReturn(memberID, bookID);

    std::cout << "Book; " << bookID << " successfully returned by Member; " << memberID << "." << std::endl;
}