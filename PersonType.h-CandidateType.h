#pragma once
#ifndef PersonType_H
#define PersonType_H

#include <iostream>
#include <string>

using namespace std;

class PersonType
{
private:

    string firstName;
    string lastName;
    int SSN;    // Social Security Number

public:

    PersonType();
    PersonType(string firstName, string lastName, int SSN);
    void setPersonInfo(string firstName, string lastName, int SSN);
    string getFirstName() const; // returns the person's first name
    string getLastName() const; // returns the person's last name
    int getSSN() const; // returns the person's soical security number
    string printName() const; // prints the person's last and first name
    void printPersonInfo(); // prints formattedSSN, first name, and last name
    string printSSN(); // Formats SSN to ###-##-#### & prints
    ~PersonType();
};

const int NUM_OF_CAMPUSES = 4;

class CandidateType : public PersonType
{
private:

    int totalVotes;
    int campuses[NUM_OF_CAMPUSES];

public:

    CandidateType();
    void updateVotesByCampus(int campusNum, int votes);
    int getTotalVotes() const;
    int getVotesByCampus(int campusNum) const;
    void printCandidateInfo() const;
    void printCandidateTotalVotes() const;
    void printCandidateCampusVotes(int campusNum) const;
    ~CandidateType();

};

#endif
