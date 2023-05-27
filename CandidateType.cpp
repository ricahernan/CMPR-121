#include "PersonType.h"

// Sets totalVotes & Array elements to 0
CandidateType::CandidateType() : PersonType()
{
    totalVotes = 0;
    for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
        campuses[i] = 0;
    }
}

// updates total number of votes & number of votes for specified campus
void CandidateType::updateVotesByCampus(int campusNum, int votes)
{
    totalVotes += votes;
    campuses[campusNum - 1] += votes;
}

int CandidateType::getTotalVotes() const {
    return totalVotes;
}

int CandidateType::getVotesByCampus(int campusNum) const
{
    return campuses[campusNum - 1];
}

void CandidateType::printCandidateInfo() const
{
    cout << getSSN() << " - " << getLastName() << ", " << getFirstName() << endl << endl;
}

void CandidateType::printCandidateTotalVotes() const
{
    cout << getLastName() << ", " << getFirstName() << endl;
    cout << "Total Votes (all campuses): " << totalVotes << endl << endl;
}

void CandidateType::printCandidateCampusVotes(int campusNum) const
{
    cout << getLastName() << ", " << getFirstName() << endl;
    cout << "Campus " << campusNum << " total votes: " << campuses[campusNum - 1] << endl << endl;
}

CandidateType::~CandidateType()
{
    // Empty
}
