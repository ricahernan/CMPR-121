#include "PersonType.h"

PersonType::PersonType() {
    SSN = 0;
}

PersonType::PersonType(string fName, string lName, int SocialSN) {
    firstName = fName;
    lastName = lName;
    SSN = SocialSN;
}

void PersonType::setPersonInfo(string fName, string lName, int SocialSN) {
    firstName = fName;
    lastName = lName;
    SSN = SocialSN;
}

string PersonType::getFirstName() const {
    return firstName;
}

string PersonType::getLastName() const {
    return lastName;
}

int PersonType::getSSN() const {
    return SSN;
}

string PersonType::printName() const {
    return lastName + ", " + firstName;
}

void PersonType::printPersonInfo() {
    cout << printSSN() << " " << firstName << " " << lastName << endl;
}

string PersonType::printSSN() {
    string formattedSSN = to_string(SSN);
    formattedSSN.insert(3, "-");
    formattedSSN.insert(6, "-");

    return formattedSSN;
}

PersonType::~PersonType() {
    // Empty
}
