#include "Members.hpp"

#include <algorithm>
#include <iostream>

// Constructor
Members::Members(const std::string& memberID, const std::string& name, const std::vector<std::string>& borrowed)
    : memberID(memberID), name(name), borrowed(borrowed) {
}

// Getters
std::string Members::getMemberID() const {
    return memberID;
}

std::string Members::getName() const {
    return name;
}

std::vector<std::string> Members::getBorrowed() const {
    return borrowed;
}

// Setters
void Members::setMemberID(const std::string& newMemberID) {
    memberID = newMemberID;
}

void Members::setName(const std::string& newName) {
    name = newName;
}

void Members::setBorrowed(const std::vector<std::string>& newBorrowed) {
    borrowed = newBorrowed;
}

// Functions
void Members::borrowBook(const std::string& bookID) {
    // Check if book is already borrowed by this member
    if (std::find(borrowed.begin(), borrowed.end(), bookID) != borrowed.end()) {
        std::cout << "Error: Member '" << name << "' has already borrowed book '" << bookID << "'." << std::endl;
        return;
    }

    // Add book to borrowed list
    borrowed.push_back(bookID);
    std::cout << "Book '" << bookID << "' added to Member '" << name << "'s borrowed list." << std::endl;
}

void Members::returnBook(const std::string& bookID) {
    // Find the book in the borrowed list
    auto it = std::find(borrowed.begin(), borrowed.end(), bookID);
    
    if (it == borrowed.end()) {
        std::cout << "Error: Member '" << name << "' has not borrowed book '" << bookID << "'." << std::endl;
        return;
    }

    // Remove the book from borrowed list
    borrowed.erase(it);
    std::cout << "Book '" << bookID << "' has been returned by member '" << name << "'." << std::endl;
}