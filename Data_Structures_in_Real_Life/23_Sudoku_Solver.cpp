#include<iostream>
#include<cmath>
using namespace std;
bool canplace(int a[9][9],int i,int j,int n,int k)
{
	for(int s=0;s<n;s++)
	{
		if(a[i][s]==k || a[s][j]==k)
		{
			return false;
		}
	}
	int rn=sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	for(int m=sx;m<sx+rn;m++)
	{
		for(int n=sy;n<sy+rn;n++)
		{
			if(a[m][n]==k)
			{
				return false;
			}
		}
	}
	return true;
}
bool sudsol(int a[9][9],int i,int j,int n)
{
	if(i==n)
	{
		cout<<"The solution of the given sudoku is:"<<endl<<endl;
		for(int i=0;i<n;i++)
		{   
			for(int j=0;j<n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;	
	}

	if(j==n)
	{
		return sudsol(a,i+1,0,n);
	}

	if(a[i][j] != 0)
	{
		return sudsol(a,i,j+1,n);
	}

	for(int k=1;k<=9;k++) 
	{
		if(canplace(a,i,j,n,k))
		{
			a[i][j]=k;

			bool couldwesolve = sudsol(a,i,j+1,n);
			if(couldwesolve==true)
			{
				return true;
			}
		}
		// a[i][j]=0;
	}
	// Backtracking Step
	a[i][j]=0;         
	return false;  
}

int main()
{
	int a[9][9];
	cout<<"Enter the sudoku to solve: "<<endl<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>a[i][j];
		}
	}
	// for(int i=0;i<9;i++)
	// {   
	// 	for(int j=0;j<9;j++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<endl;

	sudsol(a,0,0,9);
	return 0;
}
// 0 0 6 0 0 0 0 0 0 
// 5 2 0 0 0 0 0 0 0 
// 0 8 0 0 0 0 0 3 1 
// 0 0 3 0 0 0 0 8 0 
// 9 0 0 0 0 3 0 0 5 
// 0 5 0 0 0 0 0 0 0 
// 1 3 0 0 0 0 2 5 0 
// 0 0 0 0 0 0 0 7 4 
// 0 0 0 0 0 6 3 0 0


// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 0 0 0 0 0

// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9