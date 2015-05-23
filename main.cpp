/*
Author: Connor McCloskey
Date: 4/22/2015
Assignment: assignment 2
description: Uses user defined AddressBook class to mimic an address book, loads information from a text file
             prints data back and allows user to add entries to the address book, which will then be appended
             to the file
sourced: cplusplus.com, stackoverflow.com
*/

#include "AddressBook.h"
#include <iostream>
#include <fstream>

using namespace std;

const int ADDR_BOOK_SZ 	= 1000;
AddressBook addrBook[ADDR_BOOK_SZ];

void clearAddr()    //Clears any data previously written in addrBook
{
    for(int i = 0; i < AddressBook::entryCnt_; i++)
    {
        addrBook[i].SetFirstName("");
        addrBook[i].SetLastName("");
        addrBook[i].SetStreetNum(0);
        addrBook[i].SetStreetName("");
        addrBook[i].SetCity("");
        addrBook[i].SetState("");
        addrBook[i].SetZipCode(0);
    }
    AddressBook::entryCnt_ = 0;
    AddressBook::filePath_ = "";
}

void loadFromFile()     //loads data from txt file
{
    string inBuf;
    ifstream inFile;
    int counter = 0;       //used to assign data to appropriate member
    clearAddr();           //clears any data already in addrBook
    cout << "Please enter the full file path: ";
    cin >> AddressBook::filePath_;
    inFile.open(AddressBook::filePath_.c_str());
    while(getline(inFile, inBuf))
    {
        switch(counter%7)      //counter gives line number mod 7 which determines which member to write data to
        {
            case 0:
                addrBook[AddressBook::entryCnt_].SetFirstName(inBuf);
                break;
            case 1:
                addrBook[AddressBook::entryCnt_].SetLastName(inBuf);
                break;
            case 2:
                addrBook[AddressBook::entryCnt_].SetStreetNum(inBuf);
                break;
            case 3:
                addrBook[AddressBook::entryCnt_].SetStreetName(inBuf);
                break;
            case 4:
                addrBook[AddressBook::entryCnt_].SetCity(inBuf);
                break;
            case 5:
                addrBook[AddressBook::entryCnt_].SetState(inBuf);
                break;
            case 6:
                addrBook[AddressBook::entryCnt_].SetZipCode(inBuf);
                AddressBook::entryCnt_++;   //Writing ZipCode means we've hit the end of the entry and should advance to the next
                break;
        }
        counter++;
    }
    inFile.close();
    inFile.clear(std::ios_base::goodbit);
    cout << "Loaded " << AddressBook::entryCnt_ << " files.\n";
}

void addEntry()     //Manually add entry to addrBook
{
    AddressBook tempBook;       //Temporary AddressBook object to store entry while duplication checking occurs
    tempBook.AddEntryFromConsole();
    for(int i = 0; i < AddressBook::entryCnt_; i++)
    {
        if (tempBook == addrBook[i])        //Check for a previous entry with same names
        {
            cout << "Duplicate entry, action aborted.\n";
            return;         // returns to main preventing assignment of a duplicate
        }
    }
    addrBook[AddressBook::entryCnt_] = tempBook;
}

int main()
{
    bool endProg = false;
    char usrIn = ' ';

    while(!endProg)
    {
        cout << "\na) Open an address book file.\nb) Add a new address book entry.\nc) Print the contents of current address book.\nd) Quit.\n";
        cin >> usrIn;
        usrIn = tolower(usrIn);
        switch(usrIn)
        {
            case 'a':       //Load entries from text file
                loadFromFile();
                break;
            case 'b':
                addEntry();        //manually add entry
                break;
            case 'c':           //print all entries to terminal
                for(int i = 0; i < AddressBook::entryCnt_; i++)
                {
                    addrBook[i].PrintToConsole();
                    cout << "\n";
                }
                cout << "\nShowing " << AddressBook::entryCnt_ << " entries.\n";
                break;
            case 'd':           //quit
                endProg = true;
                break;
            default:
                cout << "Please make a valid selection.\n";
        }
    }
    return 0;
}
