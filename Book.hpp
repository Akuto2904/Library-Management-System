#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book() {
    //Attributes
    private:
    std::string bookID;
    std::string title;
    std::string author;
    std::string genre;
    std::int pages;
    std::bool availability;

    public:
    //Constructor
    Book(const std::string& bookID, const std::string& title, const std::string& author, const std::string& genre, std::int pages,
        std::bool availability);
    
    //Getters
    std::string getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    std::int getPages() const;
    std::bool getAvailability() const;

    //Setters
    void setBookID(const std::string& bookID);
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setGenre(const std::string& genre);
    void setPages(std::int pages);
    void setAvailability(std::bool availability);
};

#endif // BOOK_HPP