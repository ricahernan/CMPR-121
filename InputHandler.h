#pragma once
#include <fstream>
#include <string>
#include "PersonType.h"
#include "CandidateList.h"

void createCandidateList(ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[NUM_OF_CAMPUSES];
	string fName, lName;

	infile >> ssn;

	while (ssn != -999)
	{
		CandidateType newCandidate;
		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);
		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByCampus(i, allVotes[i]);
		}
		candidateList.addCandidate(newCandidate);
		infile >> ssn;
	}
}

void readCandidateData(CandidateList& candidateList)
{
	ifstream infile;
	infile.open("Candidate_data.txt");
	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1);
	}

	int ssn;
	string firstName, lastName;
	int votes[NUM_OF_CAMPUSES];

	while (infile >> ssn >> firstName >> lastName)
	{
		CandidateType candidate;
		candidate.setPersonInfo(firstName, lastName, ssn);

		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> votes[i];
			candidate.updateVotesByCampus(i + 1, votes[i]);
		}

		candidateList.addCandidate(candidate);
	}

	infile.close();
}
