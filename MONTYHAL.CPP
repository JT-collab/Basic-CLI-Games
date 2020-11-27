#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void option();
void line()
{
cout<<"------------------------------------------------------------------------------\n";
}
void instr()
{
cout<<"INSTRUCTIONS\n";
line();
cout<<"1.There will be three doors displayed out of which 1 door contain a car and\n other two doors will be containing goats\n";
cout<<"2.Player have to select one of the door from those three but\n door won't be opened\n";
cout<<"3.After that one of the door which contain goat will be displayed\n";
cout<<"4.Then player will have two options wheather player want to stay with the\n door choosen or want to switch to other door\n";
cout<<"5.Finally they will shown the results according to their selection\n";
line();
}
void again()
{
	char ans[15];
	do{
	cout<<"Do you want to play again?\n";
	cin>>ans;
	if(strcmp(ans,"yes")==0)
	{
	option();
	}
	else if(strcmp(ans,"no")==0)
	{
	exit(0);
	}
	else
	{
	cout<<"Enter proper answer in 'yes' or 'no'\n";
	}
	}while(1);
}
void game(int d)
{
	int ans,i,te=1,fn;
	long no[2];
	int dno[2];
	do
	{
		for(i=0;i<2;i++)
		{
		no[i]=time(NULL);
		srand(no[i]);
		dno[i]=rand()%3+1;
		}
	}while(dno[0]==dno[1]);
	//cout<<"dno[0] "<<dno[0]<<" dno[1] "<<dno[1]<<endl;
	cout<<"\t\tYou have selected DOOR NO "<<d<<endl;
	line();
	getch();
	if(dno[0]!=d)
	{
	te--;
	cout<<"\t\tDOOR which contain goat is, DOOR NO "<<dno[0]<<endl;
	}
	else if(dno[1]!=d)
	{
	te++;
	cout<<"\t\tDOOR which contain goat is, DOOR NO "<<dno[1]<<endl;
	}
	line();
	getch();
	cout<<"Do you want to switch or stay with your door\n1.Stay\n2.Switch\n";
	line();
	cin>>ans;
	line();
	if(ans==1)
	{
		cout<<"You are staying with DOOR NO "<<d<<endl;
		line();
		getch();
		for(i=0;i<2;i++)
		{
			if(dno[i]==d)
			{
			cout<<"You got a GOAT\n";
			line();
			getch();
			again();
			}
		}
		cout<<"You got a CAR\n";
		line();
		getch();
		again();
	}
	else if(ans==2)
	{
		if(te==0)
		{
		cout<<"Door you have switched to "<<dno[1]<<endl;
		fn=dno[1];
		}
		else if(te==2)
		{
			for(i=1;i<=3;i++)
			{
				if(dno[0]!=i && dno[1]!=i)
				{
				cout<<"Door you have switched to "<<i<<endl;
				fn=i;
				}
			}
		}
		getch();
		if(fn==dno[0] || fn==dno[1])
		{
		line();
		cout<<"You got a GOAT\n";
		line();
		getch();
		again();
		}
		else
		{
		line();
		cout<<"You got a CAR\n";
		line();
		getch();
		again();
		}
	}
}
void door()
{
	int dno;
	line();
	cout<<"Let's begin THE MONTY HALL GAME "<<endl;
	cout<<"SELECT THE DOOR NO:\n";
	line();
	cout<<"\t\t\tDOOR 1\t DOOR 2\t DOOR 3\n";
	line();
	cin>>dno;
	game(dno);
}
void option()
{
	int gs;
	line();
	cout<<"\n\t\tSelect option from the following:\n\n";
	line();
	cout<<"\t\t\t1.Instructions\n";
	line();
	cout<<"\t\t\t2.Play Game\n";
	line();
	cout<<"\t\t\t3.Instructions and Game\n";
	line();
	cout<<"\t\t\t4.Exit\n";
	line();
	cin>>gs;
	line();
	if(gs==1)
	{
	instr();
	line();
	again();
	}
	else if(gs==2)
	{
	door();
	}
	else if(gs==3)
	{
	instr();
	getch();
	door();
	}
	else
	{
	exit(0);
	}
}
int main()
{
	char name[15];
	int dno;
	clrscr();
	line();
	cout<<"\t\t\tWelcome to MONTY HALL GAME!!\n";
	line();
	cout<<"Please enter your name\n";
	gets(name);
	option();
	getch();
	return 0;
}
