#include<stdio.h>
#include<windows.h>
void menu();
void grid();
void start();
void draw();
void pos_x_y(int, char);
void window_size();
void gotoxy(int, int);
void comp_turn();
int posswin(char);
char p,com;
int board[]={0,0,0,0,0,0,0,0,0,0};
int c,co,turn=1;
int main()
{
	menu();
	int choice;
	printf("\tEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			p = 'X';
			com = 'O';
			grid();
		break;
		case 2 :
			p = 'O';
			com = 'X';
			grid();
		case 3 :
			exit(0);
		break;
	}
	getch();
 	return 0;
}
void menu()
{
	printf("\n\t-----------MENU----------\n");
	printf("\t1 : PLAY with X\n");
	printf("\t2 : PLAY with O\n");
	printf("\t3 : EXIT\n");
}
void grid()
{
	int j;

    for(j=10; j<18; j++)
    {
        gotoxy(10,j);
        printf("|        |");
    }
    gotoxy(5,12);
    printf("----------------------");
    gotoxy(5,15);
    printf("----------------------");
    if(p=='X')
		start();
	else
		comp_turn();	
}
void start()
{
	while(turn<=9)
	{
		if(posswin(com))
	{
		gotoxy(10,25);
		system("color 4");
		printf("COMPUTER WINS");
		getch();
		exit(0);
	}
		
		gotoxy(10,20);
		printf("\n\t Your Turn :> ");
		scanf("%d",&c);
		if(board[c]!=0)
			start();
		pos_x_y(c,p);
		turn++;
		draw();
		comp_turn();
		draw();
	}
}
void draw()
{
	gotoxy(10,23);
    if(turn > 9)
    {
        printf("Game Draws");
        getch();
        exit(0);
    }
}
void comp_turn()
{
	if(posswin(p))
	{
		gotoxy(10,25);
		system("color 3");
		printf("PLAYER WINS");
		getch();
		exit(0);
	}
	if(make2())
		co=make2();
	else
		co=make4();
	if(board[co]!=0)
		comp_turn();
	pos_x_y(co,com);
	turn++;
	start();
}
int make2()
{
	// p==X then X   p==O  then  O
    int i;
    int check_val,pos;

    if(p == 'X')
        check_val = 4;
    else
        check_val = 6;
	if(board[5] == 0)
        return 5;
    if(board[2] == 0)
        return 2;
    i = 1;
    while(i<=9)//row check
    {
        if(board[i] + board[i+1] + board[i+2] == check_val)
        {
            if(board[i] == 0)
                return i;
            if(board[i+1] == 0)
                return i+1;
            if(board[i+2] == 0)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] + board[i+3] + board[i+6] == check_val)
        {
            if(board[i] == 0)
                return i;
            if(board[i+3] == 0)
                return i+3;
            if(board[i+6] == 0)
                return i+6;
        }
        i++;
    }

    if(board[1] + board[5] + board[9] == check_val)
    {
        if(board[1] == 0)
            return 1;
        if(board[5] == 0)
            return 5;
        if(board[9] == 0)
            return 9;
    }

    if(board[3] + board[5] + board[7] == check_val)
    {
        if(board[3] == 0)
            return 3;
        if(board[5] == 0)
            return 5;
        if(board[7] == 0)
            return 7;
    }
    return 0;
}
int make4()
{
	// p==X then X   p==O  then  O
    int i;
    int check_val,pos;

    if(p == 'X')
        check_val = 6;
    else
        check_val = 4;
	if(board[5] == 0)
        return 5;
    if(board[2] == 0)
        return 2;
    i = 1;
    while(i<=9)//row check
    {
        if(board[i] + board[i+1] + board[i+2] == check_val)
        {
            if(board[i] == 0)
                return i;
            if(board[i+1] == 0)
                return i+1;
            if(board[i+2] == 0)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] + board[i+3] + board[i+6] == check_val)
        {
            if(board[i] == 0)
                return i;
            if(board[i+3] == 0)
                return i+3;
            if(board[i+6] == 0)
                return i+6;
        }
        i++;
    }

    if(board[1] + board[5] + board[9] == check_val)
    {
        if(board[1] == 0)
            return 1;
        if(board[5] == 0)
            return 5;
        if(board[9] == 0)
            return 9;
    }

    if(board[3] + board[5] + board[7] == check_val)
    {
        if(board[3] == 0)
            return 3;
        if(board[5] == 0)
            return 5;
        if(board[7] == 0)
            return 7;
    }
	return rand() % 9 -1;
}
void pos_x_y(int a,char ch)
{
	if(a==1)
	{
		gotoxy(7,11);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==2)
	{
		gotoxy(15,11);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==3)
	{
		gotoxy(23,11);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==4)
	{
		gotoxy(7,14);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==5)
	{
		gotoxy(15,14);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==6)
	{
		gotoxy(23,14);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==7)
	{
		gotoxy(7,17);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==8)
	{
		gotoxy(15,17);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else if(a==9)
	{
		gotoxy(23,17);
		putchar(ch);
		if(ch=='X')
			board[a]=2;
		else			//X=2, O=3
			board[a]=3;
	}
	else
		start();
}
int posswin(char p)
{
// p==X then X   p==O  then  O
    int i;
    int check_val,pos;

    if(p == 'X')
        check_val = 8;
    else
        check_val = 27;

    i = 1;
    while(i<=9)//row check
    {
        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            return i;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
              return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        return 1;
    }
    return 0;
}
void gotoxy(int x, int y)
{
	HANDLE h = NULL;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h,c);
}
