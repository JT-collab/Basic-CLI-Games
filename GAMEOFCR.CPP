#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
int count=0;
void game();
void play()
{
	for(int i=0;i<100;i++)
	{
	game();
	}
}
void again(int fs)
{
	fs=0;
	count=0;
	char ans[10];
	do{
	cout<<"Do you want to continue the game\n";
	gets(ans);
	if(strcmp(ans,"no")==fs)
	{
	exit(0);
	}
	else if(strcmp(ans,"yes")==0)
	{
	play();
	}
	else
	{
	cout<<"Enter proper answer in 'yes' or 'no'\n";
	}
	}while(1);
}
void line()
{
cout<<"--------------------------------------------------------------------------------";
}
void instr()
{
	char ans[15];
	cout<<"Instructions for game:\n";
	line();
	cout<<" 1.Player have to roll two dice.\n";
	cout<<" 2.Then if the sum of number of two dice is 7 and 11 in first attempt\n then you win\n ";
	cout<<"3.But in first attempt if the sum of two dice is 2,3 or 12 then the\n player loses the game\n ";
	cout<<"4.But if the sum of two dice comes to be 4,5,6,7,8,9 or 10 it becomes\n as point of player\n ";
	cout<<"5.On next throw player have to try to bring the same point number\n again inorder to win the game.\n";
	cout<<" 6.But if player gets 7 as sum of two dice in other attempt\n then player loses\n";
	line();
	getch();
	do{
	cout<<"Did you understood the game?\n";
	gets(ans);
	line();
	if(strcmp(ans,"no")==0)
	{
	cout<<"Lets see the some cases so that you can understand:\n";line();
	cout<<"Case 1: You tossed a 4\nYou tossed a 6\nYou tossed a 7\nYou LOST\n";line();
	cout<<"Case 2:You tossed a 8\nYou tossed a 3\nYou tossed a 6\nYou tossed a 3\nYou tossed a 8\nYou WON\n";line();
	cout<<"Case 3:You tossed a 7\nYou WON\n";line();getch();
	cout<<"Case 4:You tossed a 5\nYou tossed a 8\nYou tossed a 2\nYou tossed a 11\nYou tossed a 8\nYou tossed a 7\nYou LOST\n";line();
	cout<<"Case 5:You tossed a 12\nYou LOST\n";line();getch();
	break;
	}
	else if(strcmp(ans,"yes")==0)
	{
	break;
	}
	else
	{
	cout<<"Enter answer as 'yes' or 'no'\n";
	line();
	}
	}while(1);
}
int sum(int a,int b)
{
	return(a+b);
}

int* roll()
{
	int ans[2],r[2];
	long roll[2];
	for(int i=0;i<2;i++)
	{
		cout<<"Roll "<<i+1<<" die by pressing 1 or press any inorder to exit\n";
		cin>>ans[i];
		if(ans[i]==1)
		{
		line();
		roll[i]=time(NULL);
		srand(roll[i]);
		r[i]=rand()%6+1;
		cout<<"\tYou got "<<r[i]<<endl;
		line();
		}
		else
		{
		exit(0);
		}
	}
	return &r[0];
}
void test(int sum,int fsum)
{
	if(sum==7)
	{
	cout<<"\t\t\tYou got sum as 7\n";
	cout<<"\t\t\tYou LOSE\n";
	line();
	getch();
	again(fsum);
	}
	else if(sum==fsum)
	{
	cout<<"\t\t\tYou got sum as "<<sum<<endl;
	cout<<"\t\t\tYou WIN\n";
	line();
	getch();
	again(fsum);
	}
	else
	{
	cout<<"\t\t\tYou got sum as "<<sum<<endl;
	cout<<"\t\t\tAgain roll the dice\n";
	}
}
void game()
{
	int a,b,t;
	static int fs;
	int *ans;
	ans=roll();
	a=*ans;
	for(int i=0;i<1;i++)
	{
	ans++;
	b=*ans;
	}
	if(count==0)
	{
	fs=sum(a,b);
	if(fs==2 || fs==3 || fs==12)
	{
	cout<<"\t\t\tYou got sum as "<<fs<<endl;
	cout<<"\t\t\tYou LOSE\n";
	line();
	getch();
	again(fs);
	}
	else if(fs==7 || fs==11)
	{
	cout<<"\t\t\tYou got sum as "<<fs<<endl;
	cout<<"\t\t\tYou WIN\n";
	line();
	getch();
	again(fs);
	}
	else
	{
	cout<<"\t\t\tYou got sum as "<<fs<<endl;
	cout<<"\t\t\tAgain roll the dice\n";
	}
	count++;
	line();
	}
	else
	{
	t=sum(a,b);
	test(t,fs);
	}
}
void main()
{
	char name[15];
	clrscr();
	line();
	cout<<"\t\t\t  Welcome to the game of craps!!\n";
	line();
	cout<<"Enter your name\n";
	cin>>name;
	line();
	instr();
	cout<<"Lets begin our game "<<name<<endl;
	line();
	play();
	getch();
}

