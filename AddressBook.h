#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <string>

class AddressBook
{
private:
    std::string firstName_;
    std::string lastName_;
    int streetNum_;
    std::string streetName_;
    std::string city_;
    std::string state_;
    int zipCode_;

public:

    static int entryCnt_;
    static std::string filePath_;

    void SetFirstName(const std::string fName);
    void SetLastName(const std::string buff);
    void SetStreetNum(const std::string buff);
    void SetStreetNum(int num);
    void SetStreetName(const std::string buff);
    void SetCity(const std::string buff);
    void SetState(const std::string buff);
    void SetZipCode(const std::string buff);
    void SetZipCode(int zip);

    // Copies some properties into out arguments
    void GetFirstName(char buff[], int sz) const;
    void GetLastName(char buff[], int sz) const;

    void AddEntryFromConsole();
    void PrintToConsole();
    void AppendToFile();

    void operator=(const AddressBook& obj);
};

bool operator== (const AddressBook& obj1, const AddressBook& obj2); //STILL NEED TO DEFINE THIS, BUT WHERE?

#endif // ADDRESSBOOK_H
