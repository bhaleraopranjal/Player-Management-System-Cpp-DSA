#include "linkedList.cpp"

int main() 
{
	cout<<"\n+------------------------------------------------------------------------+";
	cout<<"\n+                        Player Management System                        +";
	cout<<"\n+------------------------------------------------------------------------+";
	LinkedList<Player> PLL;
//	PLL.readFromFile("Player.txt");
	int ch = 0;
	while(ch != 7)
	{
		cout<<"\n\t\t\t1.Insert Record of Player \n\t\t\t2.Display Records of Players \n\t\t\t3.Delete Player record \n\t\t\t4.Search Player \n\t\t\t5.Update Player \n\t\t\t6.Sort Player \n\t\t\t7.Exit \nEnter youe choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:{
				int pos,jn,matches,runs,wickets;
				char name[25];
				cout<<"\nEnter position where you want to insert record: ";
				cin>>pos;
				cout<<"\nEnter Player Jersey Number: ";
				cin>>jn;
				cout<<"\nEnter Player Name: ";
				cin.ignore();
				cin.getline(name,25);
				cout<<"\nEnter Mateches played by Player: ";
				cin>>matches;
				cout<<"\nEnter total Runs done by Player: ";
				cin>>runs;
				cout<<"\nEnter total Wickets taken by Player: ";
				cin>>wickets;
				
				Player p1(jn,name,matches,runs,wickets);							
				PLL.insertPos(pos,p1);
				break;
			}
			case 2:{
				PLL.display();
				break;
			}
			case 3:{
				int pos;
				cout<<"\nEnter position where's record you want to delete: ";
				cin>>pos;
				
				PLL.deletePos(pos);
				break;
			}
			case 4:{
				int ch;
				cout<<"\n\t\t\t1.Search by Jersey Number \n\t\t\t2.Search by Name of Player \nEnter your choice: ";
				cin>>ch;
				
				if(ch == 1)
				{
					int jn;
					cout<<"\nEnter jersey number you want to serch: ";
					cin>>jn;
					
					int i = PLL.searchPlayerJersey(jn);
					(i == -1)?cout<<"\nPlayer not found":cout<<"\nPlayer found at "<<i<<" position";
				}
				else if(ch == 2)
				{
					char nm[20];
					cout<<"\nEnter name you want to search: ";
					cin.ignore();
					cin.getline(nm,20);
					
					int i = PLL.searchPlayerName(nm);
					(i == -1)?cout<<"\nPlayer not found":cout<<"\nPlayer found at "<<i<<" position";
				}
				break;
			}
			case 5:{
				int jn;
				cout<<"\nEnter jersey number whose record you want to update: ";
				cin>>jn;
				
				PLL.updatePlayer(jn);
				break;
			}
			case 6:{
				int choice;
				cout<<"\n\t\t\t1.Sort by Jersey Number \n\t\t\t2.Sort by Matches Played \n\t\t\t3.Sort by Runs \n\t\t\t4.Sort by Wickets taken \nEnter your choice: ";
				cin>>choice;
				
				if(choice == 1)
				{
					PLL.sortJersey();
				}
				else if(choice == 2)
				{
					PLL.sortMatches();
				}
				else if(choice == 3)
				{
					PLL.sortRuns();
				}
				else if(choice == 4)
				{
					PLL.sortWickets();	
				}
				else
				{
					cout<<"\nInvalid choice";
				}
				break;
			}
			case 7:{
//				PLL.writeToFile("Player.txt");
				cout<<"\n-----------------End of Program---------------------\n";
				break;
			}
			default:{
				cout<<"\nInvalid choice";
				break;
			}
		}
	}
	return 0;
}
