#include"player.h"
Player :: Player()
{
	this->jerseyNo = -1;
	strcpy(this->Name,"NULL");
	this->matches = -1;
	this->runs = -1;
	this->wickets = -1;
}
Player :: Player(int jn,char* nm,int mat,int run,int wick)
{
	this->jerseyNo = jn;
	strcpy(this->Name,nm);
	this->matches = mat;
	this->runs = run;
	this->wickets = wick;
}
void Player :: setJerseyNo(int jn)
{
	this->jerseyNo = jn;
}
void Player :: setName(char* nm)
{
	strcpy(this->Name,nm);
}
void Player :: setMatches(int mat)
{
	this->matches = mat;
}
void Player :: setRuns(int run)
{
	this->runs = run;
}
void Player :: setWickets(int wick)
{
	this->wickets = wick;
}
int Player :: getJerseyNo()
{
	return this->jerseyNo;
}
char* Player :: getName()
{
	return this->Name;
}
int Player :: getMatches()
{
	return this->matches;
}
int Player :: getRuns()
{
	return this->runs;
}
int Player :: getWickets()
{
	return this->wickets;
}
void Player :: displayPlayer()
{
	cout<<"\nJersey No.: "<<this->jerseyNo<<"\nPlayer Name: "<<this->Name<<"\nMatches played: "<<this->matches<<"\nRuns: "<<this->runs<<"\nWickets: "<<this->wickets<<"\n";
}
