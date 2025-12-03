#include "Book.hpp"

// Constructor
Book::Book(const std::string& bookID, const std::string& title, const std::string& author, const std::string& genre, int pages, bool availability)
    : bookID(bookID), title(title), author(author), genre(genre), pages(pages), availability(availability) {
}

// Getters
std::string Book::getBookID() const {
    return bookID;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getGenre() const {
    return genre;
}

int Book::getPages() const {
    return pages;
}

bool Book::getAvailability() const {
    return availability;
}

// Setters
void Book::setBookID(const std::string& newBookID) {
    bookID = newBookID;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void Book::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void Book::setPages(int newPages) {
    pages = newPages;
}

void Book::setAvailability(bool newAvailability) {
    availability = newAvailability;
}