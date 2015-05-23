#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "AddressBook.h"

int AddressBook::entryCnt_	= 0;
std::string AddressBook::filePath_ = "";

void AddressBook::SetFirstName(const std::string fName)
{
    firstName_ = fName;
}

void AddressBook::SetLastName(const std::string buff)
{
    lastName_ = buff;
}
/*
The methods SetStreetNum(string) and SetZipCode(string) convert from a numeric string to an integer
I learned that something about my environment I use (code::blocks compiling with gnu gcc) won't
compile any of the nice string to number functions (atoi() etc.) so stringstreams are used instead.
*/
void AddressBook::SetStreetNum(const std::string buff)
{
    int temp = 0;
    std::stringstream ss;
    ss << buff;
    ss >> temp;
    streetNum_ = temp;
}

void AddressBook::SetZipCode(const std::string buff)
{
    int temp = 0;
    std::stringstream ss;
    ss << buff;
    ss >> temp;
    zipCode_ = temp;
}

void AddressBook::SetStreetNum(int num)
{
    streetNum_ = num;
}

void AddressBook::SetStreetName(const std::string buff)
{
    streetName_ = buff;
}

void AddressBook::SetCity(const std::string buff)
{
    city_ = buff;
}

void AddressBook::SetState(const std::string buff)
{
    state_ = buff;
}

void AddressBook::SetZipCode(int zip)
{
    zipCode_ = zip;
}

void AddressBook::GetFirstName(char buff[], int sz) const
{
    strcpy(buff, firstName_.c_str());
}

void AddressBook::GetLastName(char buff[], int sz) const
{
    strcpy(buff, lastName_.c_str());
}

void AddressBook::AddEntryFromConsole()
{
    if(filePath_ == "")
    {
        std::cout << "No file opened, please first open an address book./n";
        return;
    }
    std::string usrBuf;
    int usrInt = 0;

    std::cout << "Enter the first name: ";
    std::cin >> usrBuf;
    AddressBook::SetFirstName(usrBuf);
    std::cout << "\nEnter the last name: ";
    std::cin >> usrBuf;
    AddressBook::SetLastName(usrBuf);
    std::cout << "\nEnter the street number: ";
    std::cin >> usrInt;
    AddressBook::SetStreetNum(usrInt);
    std::cout << "\nEnter the street name: ";
    std::cin >> usrBuf;
    AddressBook::SetStreetName(usrBuf);
    std::cout << "\nEnter the city: ";
    std::cin >> usrBuf;
    AddressBook::SetCity(usrBuf);
    std::cout << "\nEnter the state: ";
    std::cin >> usrBuf;
    AddressBook::SetState(usrBuf);
    std::cout << "\nEnter the zip code: ";
    std::cin >> usrInt;
    AddressBook::SetZipCode(usrInt);
}

void AddressBook::PrintToConsole()
{
    std::cout << firstName_ << "\n"
              << lastName_ << "\n"
              << streetNum_ << "\n"
              << streetName_ << "\n"
              << city_ << "\n"
              << state_ << "\n"
              << zipCode_ << "\n";
}

void AddressBook::AppendToFile()
{
    std::ofstream outFile;
    outFile.open(AddressBook::filePath_.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    outFile << "\n" << firstName_ << "\n"
                    << lastName_ << "\n"
                    << streetNum_ << "\n"
                    << streetName_ << "\n"
                    << city_ << "\n"
                    << state_ << "\n"
                    << zipCode_;
    outFile.close();
    outFile.clear(std::ios_base::goodbit);
}

void AddressBook::operator=(const AddressBook& obj)
{
    AddressBook::SetFirstName(obj.firstName_);
    AddressBook::SetLastName(obj.lastName_);
    AddressBook::SetStreetNum(obj.streetNum_);
    AddressBook::SetStreetName(obj.streetName_);
    AddressBook::SetCity(obj.city_);
    AddressBook::SetState(obj.state_);
    AddressBook::SetZipCode(obj.zipCode_);
    entryCnt_++;
    AppendToFile();
}

bool operator== (const AddressBook& obj1, const AddressBook& obj2)
{
    int sz = 128;
    char fName1[sz], fName2[sz], lName1[sz], lName2[sz];
    //Copies private variables into char arrays for comparison
    obj1.GetFirstName(fName1, sz);
    obj1.GetLastName(lName1, sz);
    obj2.GetFirstName(fName2, sz);
    obj2.GetLastName(lName2, sz);
    if((strcmp(fName1, fName2) == 0) && (strcmp(lName1, lName2) == 0))      //if first and last names are the same, entries are considered equal
    {
        return true;
    }
    else
    {
        return false;
    }

}
