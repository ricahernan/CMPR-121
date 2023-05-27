#include "CandidateList.h"

// adds a new candidate to the list and keeps track how many are in the list
void CandidateList::addCandidate(const CandidateType& candidate)
{
    Node* newNode = new Node(candidate, nullptr);

    if (first == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        last->setLink(newNode);
        last = newNode;
    }

    count++;
}

// finds and returns the SSN of candidate with highest total votes from list
int CandidateList::getWinner() const
{
    int maxVotes = first->getCandidate().getTotalVotes();
    int winnerSSN = first->getCandidate().getSSN();

    Node* current = first->getLink();

    while (current != nullptr)
    {
        int votes = current->getCandidate().getTotalVotes();
        if (votes > maxVotes)
        {
            maxVotes = votes;
            winnerSSN = current->getCandidate().getSSN();
        }
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return 0;
    }

    return winnerSSN;
}

// searches candidate with selected SSN. Returns true if found, false otherwise
bool CandidateList::searchCandidate(int ssn) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == ssn)
        {
            return true;
        }
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return false;
    }

    cout << "=> SSN not in the list" << endl;
    return false;
}

// searches candidate with selected SSN. If found, Prints first & last name
void CandidateList::printCandidateName(int ssn) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == ssn)
        {
            cout << current->getCandidate().getFirstName() << " " << current->getCandidate().getLastName() << endl;
            return;
        }
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return;
    }

    cout << "=> SSN not in the list" << endl;
}

// prints every candidates info from list
void CandidateList::printAllCandidates() const
{
    Node* current = first;

    while (current != nullptr)
    {
        current->getCandidate().printCandidateInfo();
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return;
    }
}

// searches candidate with selected SSN. If found, prints votes they got from each campus
void CandidateList::printCandidateCampusVotes(int ssn, int division) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == ssn)
        {
            cout << "Votes for campus " << division << ": " << current->getCandidate().getVotesByCampus(division) << endl;
            return;
        }
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return;
    }
}

// searches candidate with selected SSN. If found, prints their total votes from all campuses
void CandidateList::printCandidateTotalVotes(int ssn) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == ssn)
        {
            cout << "Total votes for candidate with SSN " << ssn << ": " << current->getCandidate().getTotalVotes() << endl;
            return;
        }
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return;
    }
}

// prints name & total votes from every candidate
void CandidateList::printFinalResults() const
{
    Node* current = first;

    while (current != nullptr)
    {
        cout << "Candidate: " << current->getCandidate().getFirstName() << " " << current->getCandidate().getLastName() << endl;
        cout << "Total votes: " << current->getCandidate().getTotalVotes() << endl;
        cout << "-------------------------" << endl;
        current = current->getLink();
    }

    if (first == nullptr)
    {
        cout << "=> List is empty" << endl;
        return;
    }

}

// deletes all nodes & resets pointers and count
void CandidateList::destroyList()
{
    Node* current = first;

    while (current != nullptr)
    {
        Node* temp = current;
        current = current->getLink();
        delete temp;
    }
    first = nullptr;
    last = nullptr;
    count = 0;
}

CandidateList::~CandidateList()
{
    destroyList();
}
