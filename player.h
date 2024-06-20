#include<iostream>
#include<string.h>
using namespace std;

class Player{
	int jerseyNo,matches,runs,wickets;
	char Name[25];
	
	public:
		Player();
		Player(int,char*,int,int,int);
		void setJerseyNo(int);
		void setName(char*);
		void setMatches(int);
		void setRuns(int);
		void setWickets(int);
		int getJerseyNo();
		char* getName();
		int getMatches();
		int getRuns();
		int getWickets();
		void displayPlayer();
};
