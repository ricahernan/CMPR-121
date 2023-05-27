#pragma once
#pragma once
#ifndef Candidate_H
#define Candidate_H
#include "PersonType.h"
#include "Node.h"

class CandidateList
{
private:

    // Member variables
    Node* first; // Pointer to the first node
    Node* last;  // Pointer to the last node
    int count;   // Number of nodes in the list

public:

    // Default constructor
    CandidateList() : first(nullptr), last(nullptr), count(0) {}

    // Member functions
    void addCandidate(const CandidateType& candidate);
    int getWinner() const;
    bool searchCandidate(int ssn) const;
    void printCandidateName(int ssn) const;
    void printAllCandidates() const;
    void printCandidateCampusVotes(int ssn, int division) const;
    void printCandidateTotalVotes(int ssn) const;
    void printFinalResults() const;
    void destroyList();
    ~CandidateList();
};

#endif
