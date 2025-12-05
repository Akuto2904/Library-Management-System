#ifndef MEMBERS_HPP
#define MEMBERS_HPP

#include <string>
#include <vector>

class Members {
    //Attributes
    private:
    std::string memberID;
    std::string name;
    std::vector<std::string> borrowed;

    public:
    //Constructor
    Members(const std::string& memberID, const std::string& name, const std::vector<std::string>& borrowed);
    
    //Getters
    std::string getMemberID() const;
    std::string getName() const;
    std::vector<std::string> getBorrowed() const;

    //Setters
    void setMemberID(const std::string& memberID);
    void setName(const std::string& name);
    void setBorrowed(const std::vector<std::string>& borrowed);

    //Functions
    void borrowBook(const std::string& bookID);
    void returnBook(const std::string& bookID);
};

#endif //MEMBERS_HPP