#include "node.cpp"

template <class T>
class LinkedList{
	Node<T>* start;
	
	public:
		LinkedList();
		void insertPos(int,T&);
		void display();
		void deletePos(int);
		int searchPlayerJersey(int);
		int searchPlayerName(char*);
		void updatePlayer(int);
		void sortJersey();
		void sortMatches();
		void sortRuns();
		void sortWickets();
		void writeToFile(const char*);
		void readFromFile(const char*);
		~LinkedList();
};
