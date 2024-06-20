#include "linkedList.h"
#include<fstream>

template <class T>
LinkedList<T> :: LinkedList()
{
	start = NULL;
	this->readFromFile("Player.txt");
}

template <class T>
void LinkedList<T> :: insertPos(int pos,T& data)
{
	Node<T>* temp = new Node<T>(data);
	if(start == NULL)
	{
		start = temp;
		cout<<"\nInsertion Successfully";
		return;
	}
	if(pos == 1)
	{
		temp->setNext(start);
		start = temp;
		cout<<"\nInsertion Successfully";
		return;
	}
	int i = 1;
	Node<T>* p = start;
	while(i < pos-1 && p->getNext() != NULL)
	{
		i++;
		p = p->getNext();
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
	cout<<"\nInsertion successfully";	
}

template <class T>
void LinkedList<T> :: display()
{
	if(start == NULL)
	{
		cout<<"\nNo any record do display";
	}
	else
	{
		Node<T>* p = start;
		while(p != NULL)	
		{
			p->getData().displayPlayer();
			p = p->getNext();
		}		
	}
}

template <class T>
void LinkedList<T> :: deletePos(int pos)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to delete";
		return;
	}
	Node<T>* p = start;
	if(pos == 1)
	{
		start = start->getNext();
		p->getData().displayPlayer();
		cout<<"\n--------------deleted successfully";
		delete p;
		return;
	}
	int i = 1;
	while(i < pos-1 && p->getNext() != NULL)
	{
		i++;
		p = p->getNext();
	}
	if(i == pos-1)
	{
		Node<T>* q = p->getNext();
		p->setNext(q->getNext());
		q->getData().displayPlayer();
		cout<<"\n--------------deleted successfully";
		delete q;
		return;
	}
	cout<<"\nInvalid Position";		
}

template <class T>
int LinkedList<T> :: searchPlayerJersey(int jn)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return -1;
	}
	Node<T>* p = start;
	int i = 1;
	while(p != NULL)
	{
		if((p->getData().getJerseyNo()) == jn)
		return i;
		p = p->getNext();
		i++;
	}
	return -1;
}

template <class T>
int LinkedList<T> :: searchPlayerName(char* nm)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return -1;
	}
	Node<T>* p = start;
	int i = 1;
	while(p != NULL)
	{
		if(strncasecmp(p->getData().getName(),nm,strlen(nm)) == 0)
			return i;
			i++;
			p = p->getNext();
	}
	return -1;
}

template <class T>
void LinkedList<T> :: updatePlayer(int jn)
{
	if(start == NULL)
	{
		cout<<"\nNo any record to search";
		return;
	}
	int flag = 0;
	Node<T>* p = start;
	int i = 1;
	while(p != NULL)
	{
		if(p->getData().getJerseyNo() == jn)
		{
			int mat,r,w;
			cout<<"\nEnter how many matches you want to add: ";
			cin>>mat;
			cout<<"\nEnter how many runs you want to add: ";
			cin>>r;
			cout<<"\nEnter how many wickets you want to add: ";
			cin>>w;

			T& player = p->getData();
			player.setMatches(player.getMatches() + mat);
			player.setRuns(player.getRuns() + r);
			player.setWickets(player.getWickets() + w);
			cout<<"\nRecord updated successfully";
			flag = 1;		
			return;
		}
		else
		{
			i++;
			p = p->getNext();	
		}
	}
	if(flag == 0)
	cout<<"\nNo record found of jersey Number "<<jn;
}

template <class T>
void LinkedList<T> :: sortJersey()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getJerseyNo() > q->getData().getJerseyNo())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: sortMatches()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getMatches() > q->getData().getMatches())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: sortRuns()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getRuns() > q->getData().getRuns())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: sortWickets()
{
	for(Node<T>* p = start; p != NULL; p = p->getNext())
	{
		for(Node<T>* q = p->getNext(); q != NULL; q = q->getNext())
		{
			if(p->getData().getWickets() > q->getData().getWickets())
			{
				T temp = p->getData();
				p->setData(q->getData());
				q->setData(temp);
			}
		}
	}
	display();
}

template <class T>
void LinkedList<T> :: writeToFile(const char* file)
{
	std::ofstream outfile(file, ios::binary);
	Node<T>* p = start;
	while(p != NULL)
	{
		outfile.write(reinterpret_cast<char*>(&p->getData()),sizeof(T));
		p = p->getNext();
	} 
	outfile.close();
}

template <class T>
void LinkedList<T> :: readFromFile(const char* file)
{
	std::ifstream infile(file, ios::binary);
	T pl;
	while(infile.read(reinterpret_cast<char*>(&pl), sizeof(T)))
	{
		this->insertPos(1,pl);	
	}	
	infile.close();
}
		
template <class T>
LinkedList<T> :: ~LinkedList()
{
	this->writeToFile("Player.txt");
	while(start != NULL)
	{
		Node<T>* p = start;
		start = p->getNext();
		delete p;
	}
}
