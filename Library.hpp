#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Members.hpp"
#include "Book.hpp"

#include <string>
#include <map>
#include <vector>
#include <memory>


class Library {
    //Attributes
    private:
    //Store members by their ID
    std::map<std::string, Members> members;

    //Store books by their ID
    std::map<std::string, Book> books;

    //Track loans
    std::map<std::string, std::vector<std::string>> loans;

    public:
    //Constructor
    Library();

    //Book Management
    void addBook(const Book& book);
    void removeBook(const std::string& bookID);
    void searchBooks(const std::string& query) const;
    void displayAllBooks() const;
    void displayAvailableBooks() const;

    //Member Management
    void addMember(const Members& member);
    void removeMember(const std::string& memberID);
    void displayMembers() const;

    //Borrowing and Returning
    void borrowBook(const std::string& memberID, const std::string& bookID);
    void returnBook(const std::string& memberID, const std::string& bookID);

    //File I/O
    void saveLibraryToFile(const std::string& filename) const;
    void loadLibraryFromFile(const std::string& filename);
};

#endif // LIBRARY_HPP