#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
char playx[15],playo[15];
int count=1;
/*
Sequence of functions
void line();
void instr();
void write(int val,int tst);
int search(int num[],int q,int n);
int win_check(int n[],int t);
void ask();
void assign(char n1[], char n2[]);
void frame(); */
void option();
void line()
{
cout<<"-----------------------------------------------------------------------------\n";
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
void instr()
{
char a=4;
cout<<a<<" Instruction for the game:\n";
line();
cout<<"1.There will be two players playing the game and they can\n have either 'X' or '0'"<<endl;
cout<<"2.Player with 'X' will start first.\n";
cout<<"3.Player who succeeds in placing three of their marks in horizontal, \nvertical, or diagonal row wins the game\n";
line();
cout<<"\t\t\t\t 1 | 2 | 3 \n";
cout<<"\t\t\t\t-----------\n";
cout<<"\t\t\t\t 4 | 5 | 6 \n";
cout<<"\t\t\t\t-----------\n";
cout<<"\t\t\t\t 7 | 8 | 9 \n";
line();
getch();
option();
}
void write(int val,int tst)
{
	char ins[1];
	if(tst)
	ins[0]='X';
	else
	ins[0]='0';
		if(val==1)
		{
		outtextxy(445,140,ins);
		}
		else if(val==2)
		{
		outtextxy(510,140,ins);
		}
		else if(val==3)
		{
		outtextxy(570,140,ins);
		}
		else if(val==4)
		{
		outtextxy(445,205,ins);
		}
		else if(val==5)
		{
		outtextxy(510,205,ins);
		}
		else if(val==6)
		{
		outtextxy(570,205,ins);
		}
		else if(val==7)
		{
		outtextxy(445,265,ins);
		}
		else if(val==8)
		{
		outtextxy(510,265,ins);
		}
		else if(val==9)
		{
		outtextxy(570,265,ins);
		}
}
int search(int num[],int q,int n)
{
		//cout<<q<<"-"<<n<<" "; 	testing purpose
		int i;
		for(i=0;i<q;i++)
		{
			if(num[i]==n)
			{
				return 1;
			}
		}
		return 0;
}
int win_check(int n[],int t)
{
	int q;
	if(t)
		q=5;
	else
		q=4;
	int res,res1,res2,res3;
	res1=search(n,q,5);
	res2=search(n,q,1);
	res3=search(n,q,9);
	if(res1)
	{
		int r1,r2,r3,r4;
		r1=search(n,q,1);
		r2=search(n,q,2);
		r3=search(n,q,3);
		r4=search(n,q,4);
		if(r1)
		{       res=search(n,q,9);
			if(res)
			return 1;
		}
		if(r2)
		{
			res=search(n,q,8);
			if(res)
			return 1;
		}
		if(r3)
		{
			res=search(n,q,7);
			if(res)
			return 1;
		}
		if(r4)
		{
			res=search(n,q,6);
			if(res)
			return 1;
		}
	}
	else if(res2)
	{
		int r1,r2;
		r1=search(n,q,2);
		r2=search(n,q,4);
		if(r1)
		{
			res=search(n,q,3);
			if(res)
			return 1;
		}
		if(r2)
		{
			res=search(n,q,7);
			if(res)
			return 1;
		}
	}
	else if(res3)
	{
		int r1,r2;
		r1=search(n,q,8);
		r2=search(n,q,6);
		if(r1)
		{
			res=search(n,q,7);
			if(res)
			return 1;
		}
		if(r2)
		{
			res=search(n,q,3);
			if(res)
			return 1;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}
void ask()
{
	int x[5]={0},o[4]={0},xo[9];
	int res;
	int counx=0,couno=0;
	int t,a=0,b=0,j=0,chk=1; //i=0
	do{
	/*Above do loop is for X input and also it helps the to
	take input of X and 0 simultaneosly*/
	here:
	cout<<playx<<" where you want to add 'X'\n";
	cin>>x[a];
	xo[j]=x[a];
	/* This loop checks whether the input entered by user is
	not matching the previous input as it will lead to overlapping*/
		for(int k=0;k<j;k++)
		{
			if(xo[k]==x[a])
			{
			cout<<"Invalid input\n";
			chk=0;
			break;
			}
			chk=1;
		}
	j++;
	/*Below if statement checks with the help of above loop that there
	is no repetition of numbers*/
	if(chk)
	{
	/*Below if statement checks that the user input is between 1-9*/
		if(x[a]<=9 && x[a]>0)
		{
			t=1;
			write(x[a],t);
			a++;
			counx++;
			if(counx>2)
			{
				res=win_check(x,t);
				if(res==1)
				{
					cout<<playx<<" won\n";
					getch();
					closegraph();
					again();
				}
			}
			/*Below if statement states that X input must be
			taken 5 times so when it is done it has to goto
			to end the do loop*/
			if(a==5)
			{
			goto enddo2;
			}
		}
		else
		{
		cout<<"Enter number between 1-9\n";
		goto here;
		}
	}
	/*If there is repetition of input number then the goto statement
	will help the program to make the user input again*/
	else
	{
		goto here;
	}
	do{
	/*Above do loop is for taking 0 input. This do loop is similar
	to above do loop.*/
	there:
	cout<<playo<<" where you want to add '0'\n";
	cin>>o[b];
	xo[j]=o[b];
		for(k=0;k<j;k++)
		{
			if(xo[k]==o[b])
			{
				cout<<"Invalid input\n";
				chk=0;
				break;
			}
			chk=1;
		}
	j++;
	if(chk)
	{
		if(o[b]<=9 && o[b]>0)
		{
			t=0;
			write(o[b],t);
			b++;
			couno++;
			if(couno>=2)
			{
			res=win_check(o,t);
				if(res==1)
				{
				cout<<playo<<" won\n";
				getch();
				closegraph();
				again();
				}
			}
			if(b==4)
			{
			goto enddo1;
			}
			else
			{
			goto here;
			}
		}
		else
		{
		cout<<"Enter number between 1-9\n";
		goto there;
		}
	}
	else
	{
		goto there;
	}
	enddo1:
	}while(b!=4);
	enddo2:
	}while(a!=5);
	cout<<"Game is draw\n";
}
//	This function is to assign X and 0 to the players
void assign(char n1[], char n2[])
{
	int pnx,pno;
	unsigned m;
	m=time(NULL);
	srand(m);
	pnx=rand()%2+1;
	if(pnx==1)
	{
	fflush(stdin);
	strcpy(playx,n1);
	strcpy(playo,n2);
	pno=pnx;
	++pno;
	}
	else
	{
	fflush(stdin);
	strcpy(playx,n2);
	strcpy(playo,n1);
	pno=pnx;
	--pno;
	}
}
void frame()
{
	int maxx,maxy;
	int gd=DETECT;
	int gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	outtextxy(470,80,"TIC TAC TOE");
	maxx=getmaxx();
	maxy=getmaxy();
	line(maxx/2,0,maxx/2,maxy);
	line(480,120,480,300);
	line(545,120,545,300);
	line(420,175,600,175);
	line(420,240,600,240);
	ask();
	getch();
	closegraph();
}
void option()
{
	char n1[15],n2[15];
	int cho;
	cout<<"\n";
	line();
	cout<<"\t\t\tWhat would you like to do?\n";
	cout<<"1.Instructions\n\n";
	cout<<"2.Play game\n\n";
	cout<<"3.Exit\n";
	line();
	cin>>cho;
	switch(cho)
	{
	case 1:
		line();
		instr();
		getch();
		break;
	case 2:
		char n1[15],n2[15];
		cout<<"Player 1: Enter your name\n";
		gets(n1);
		cout<<"Player 2: Enter your name\n";
		gets(n2);
		line();
		cout<<"OK, so let's get started...\n";
		line();
		assign(n1,n2);
		line();
		frame();
		getch();
		again();
		break;
	case 3:
		exit(0);
	default:
		cout<<"Enter proper input\n";
	}
}
void main()
{
	clrscr();
	line();
	cout<<"\t\t\tWelcome to the TIC TAC TOE game\n";
	line();
	int inp;
	cout<<"How would you like to play?\n1.Computer\n2.Human\n";
	cin>>inp;
	switch(inp)
	{
		case 1:
			cout<<"Work in progress!!\n";
			getch();
			break;
		case 2:
			option();
			break;
	}
}