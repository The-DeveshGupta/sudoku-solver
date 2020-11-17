/************************************************************
Objective - A Program to solve sudoku
Programmer - Devesh Gupta (02715002716,MSIT,GGSIP University)
************************************************************/
#include<conio.h>
#include<stdio.h>
#define u 10
int s[u][u][u];
int a[u],b[u],c[u],i,j,k,l,p,q;
int c1=0,c2=0,c3,c4;
void assign()
	{
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			for(k=1;k<u;k++)
				{
				s[i][j][k]=k;
				}
			}
		}
	}
void enter()
	{
	printf("Enter Sudoku Entity\n");
	printf("Enter 0 when you dont know number\n");
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			printf("[%d][%d]=",i,j);
			scanf("%d",&s[i][j][0]);
			}
		}
	}
void show()
	{
	clrscr();
	printf("\t\t\t\tSudoku\n");
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			printf("%d\t",s[i][j][0]);
			}
		printf("\n");
		}
	}
void repair()
	{
	printf("Do you want to refill or repair sudoku entity\n");
	printf("1. Yes\n2. No\n");
	scanf("%d",&c1);
	if(c1==1)
		{
		do
			{
			printf("Enter entity number i,j");
			scanf("%d%d",&i,&j);
			printf("[%d][%d]=",i,j);
			scanf("%d",&s[i][j][0]);
			printf("Any other entity you want to repair");
			printf("\n1. Yes\n2. No\n");
			scanf("%d",&c2);
			}while(c2==1);
		clrscr();
		show();
		}
	else
		{
		clrscr();
		show();
		}
	}
void logic_1()
	{
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			if(s[i][j][0]!=0)
				{
				p=s[i][j][0];
				for(k=1;k<u;k++)
					s[i][j][k]=0;
				for(k=1;k<u;k++)
					{
					s[i][k][p]=0;
					s[k][j][p]=0;
					}


				}
			}
		}
	}
void logic_2()
	{
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			if(s[i][j][0]!=0)
				{
				p=s[i][j][0];
				if(i>=1&&i<=3)
					{
					if(j>=1&&j<=3)
						{
						for(k=1;k<=3;k++)
							{
							for(l=1;l<=3;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=4&&j<=6)
						{
						for(k=1;k<=3;k++)
							{
							for(l=4;l<=6;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=7&&j<=9)
						{
						for(k=1;k<=3;k++)
							{
							for(l=7;l<=9;l++)
								s[k][l][p]=0;
							}
						}
					}
				else if(i>=4&&i<=6)
					{
					if(j>=1&&j<=3)
						{
						for(k=4;k<=6;k++)
							{
							for(l=1;l<=3;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=4&&j<=6)
						{
						for(k=4;k<=6;k++)
							{
							for(l=4;l<=6;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=7&&j<=9)
						{
						for(k=4;k<=6;k++)
							{
							for(l=7;l<=9;l++)
								s[k][l][p]=0;
							}
						}
					}
				else if(i>=7&&i<=9)
					{
					if(j>=1&&j<=3)
						{
						for(k=7;k<=9;k++)
							{
							for(l=1;l<=3;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=4&&j<=6)
						{
						for(k=7;k<=9;k++)
							{
							for(l=4;l<=6;l++)
								s[k][l][p]=0;
							}
						}
					else if(j>=7&&j<=9)
						{
						for(k=7;k<=9;k++)
							{
							for(l=7;l<=9;l++)
								s[k][l][p]=0;
							}
						}
					}
				}
			}
		}
	}
void filling_row()
	{
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			int count_row=0;
			a[0]=0;b[0]=0;c[0]=0;
			for(k=1;k<u;k++)
				{
				if(s[j][k][i]!=0)
					{
					a[0]=j;b[0]=k;c[0]=i;
					count_row++;
					}
				}
			if(count_row==1)
				s[a[0]][b[0]][0]=c[0];
			}
		}
	}
void filling_col()
	{
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			int count_col=0;
			a[0]=0;b[0]=0;c[0]=0;
			for(k=1;k<u;k++)
				{
				if(s[k][j][i]!=0)
					{
					a[0]=k;b[0]=j;c[0]=i;
					count_col++;
					}
				}
			if(count_col==1)
				s[a[0]][b[0]][0]=c[0];
			}
		}
	}
void filling_box()
	{
	int count_box[u][u];
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			count_box[i][j]=0;
		}
	for(i=1;i<u;i++)
		{
		for(j=1;j<u;j++)
			{
			for(k=1;k<u;k++)
				{
				if(j>=1&&j<=3)
					{
					if(k>=1&&k<=3)
						{
						if(s[j][k][i]!=0)
							{
							count_box[1][i]++;
							a[1]=j;b[1]=k;c[1]=i;
							}
						}
					if(k>=4&&k<=6)
						{
						if(s[j][k][i]!=0)
							{
							count_box[2][i]++;
							a[2]=j;b[2]=k;c[2]=i;
							}
						}
					if(k>=7&&k<=9)
						{
						if(s[j][k][i]!=0)
							{
							count_box[3][i]++;
							a[3]=j;b[3]=k;c[3]=i;
							}
						}
					}
				if(j>=4&&j<=6)
					{
					if(k>=1&&k<=3)
						{
						if(s[j][k][i]!=0)
							{
							count_box[4][i]++;
							a[4]=j;b[4]=k;c[4]=i;
							}
						}
					if(k>=4&&k<=6)
						{
						if(s[j][k][i]!=0)
							{
							count_box[5][i]++;
							a[5]=j;b[5]=k;c[5]=i;
							}
						}
					if(k>=7&&k<=9)
						{
						if(s[j][k][i]!=0)
							{
							count_box[6][i]++;
							a[6]=j;b[6]=k;c[6]=i;
							}
						}
					}
				if(j>=1&&j<=3)
					{
					if(k>=1&&k<=3)
						{
						if(s[j][k][i]!=0)
							{
							count_box[7][i]++;
							a[7]=j;b[7]=k;c[7]=i;
							}
						}
					if(k>=4&&k<=6)
						{
						if(s[j][k][i]!=0)
							{
							count_box[8][i]++;
							a[8]=j;b[8]=k;c[8]=i;
							}
						}
					if(k>=7&&k<=9)
						{
						if(s[j][k][i]!=0)
							{
							count_box[9][i]++;
							a[9]=j;b[9]=k;c[9]=i;
							}
						}
					}
				}
			}
		for(l=1;l<u;l++)
			{
			if(count_box[l][i]==1)
				s[a[l]][b[l]][0]=c[l];
			}
		}
	}
void check()
	{
	int flag=1;
	int sum_row=0,sum_col=0;
	for(j=1;j<u;j++)
		{
		for(k=1;k<u;k++)
			{
			sum_row+=s[j][k][0];
			sum_col+=s[k][j][0];
			}
		if(sum_row!=45||sum_col!=45)
			flag=0;
		}
	if(flag==0)
		printf("\nSudoku Solved is Incorrect");
	}
void show_plate()
	{
	printf("\t\t\t\tPlates\n");
	for(i=0;i<u;i++)
		{
		printf("Plate %d\n",i);
		for(j=1;j<u;j++)
			{
			for(k=1;k<u;k++)
				printf("%d\t",s[j][k][i]);
			printf("\n");
			}
		printf("Want to see others (y/n=1/0)");
		scanf("%d",&c3);
		if(c3==0)
			break;
		}
	}
void main()
	{
	clrscr();
	assign();
	/*
	//Sample Sudoku(Easy):
	s[1][3][0]=9;s[1][4][0]=2;s[1][7][0]=1;s[1][9][0]=5;
	s[2][2][0]=4;s[2][5][0]=6;s[2][9][0]=3;
	s[3][1][0]=5;s[3][3][0]=2;
	s[4][2][0]=5;s[4][4][0]=9;s[4][6][0]=4;s[4][7][0]=7;

	s[6][3][0]=7;s[6][4][0]=3;s[6][6][0]=2;s[6][8][0]=9;
	s[7][7][0]=5;s[7][9][0]=8;
	s[8][1][0]=7;s[8][5][0]=8;s[8][8][0]=6;
	s[9][1][0]=6;s[9][3][0]=4;s[9][6][0]=9;s[9][7][0]=2;
	*/
	/*
	//Sample sudoku(Hard):
	s[1][3][0]=7;s[1][7][0]=2;s[1][9][0]=3;
	s[2][4][0]=9;s[2][7][0]=8;
	s[3][1][0]=1;s[3][4][0]=3;s[3][6][0]=7;s[3][9][0]=9;
	s[4][5][0]=4;s[4][6][0]=9;
	s[5][2][0]=5;s[5][4][0]=7;s[5][6][0]=2;s[5][8][0]=1;
	s[6][4][0]=5;s[6][5][0]=6;
	s[7][1][0]=9;s[7][4][0]=2;s[7][6][0]=3;s[7][9][0]=8;
	s[8][3][0]=4;s[8][6][0]=8;
	s[9][1][0]=6;s[9][3][0]=5;s[9][7][0]=7;
	*/
	enter();
	show();
	repair();
	logic_1();
	logic_2();
	for(q=1;q<=20;q++)
	{
		filling_row();
		filling_col();
		filling_box();
		logic_1();
		logic_2();
		show();
		printf("\nLevel %d logic applied:",q);
		printf("\nSolve Again (y/n)=(1/0):");
		scanf("%d",&c4);
		if(c4==0)
			break;
	}
	//show_plate();
	//check();
	show();
	getch();
	}
