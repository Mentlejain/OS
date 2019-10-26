#include <iostream>
#include<conio.h>
using namespace std;
class MM
{
	private:
		int m;
		int p;
		int* M;
		int* P;
		int* A;
	public:
		void display();
		void input();
		int* bestfit();
		int* worstfit();
		int* firstfit();
};
void MM::input()
{
	cout<<"Enter number of Memory Chunks: ";
	cin>>m;
	M=new int[m];
	cout<<"Enter allocated memory"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<"M["<<i<<"]: ";
		cin>>M[i];
	}
	cout<<"Enter number of Processes: ";
	cin>>p;
	A=new int[p];
	P=new int[p];
	cout<<"Enter memory size"<<endl;
	for(int i=0;i<p;i++)
	{
		cout<<"P["<<i<<"]: ";
		cin>>P[i];
		A[i]=-1;
	}
	
}
void MM::display()
{
	for(int i=0;i<p;i++)
	{
		cout<<"P["<<i<<"]";
		if(A[i]!=-1)
			cout<<" allocated to M["<<A[i]<<"]"<<endl;
		else
			cout<<" not allocated"<<endl;
	}
}
int* MM::bestfit()
{
	int T[p];
	int t,n;
	for(int i=0;i<p;i++)
	{
		T[i]=M[i];
		A[i]=-1;
	}
	for(int i=0;i<p;i++)
	{
		n=-1;
		for(int j=0;j<m;j++)
		{
			if(T[j]>=P[i])
			{
				if(n==-1)
					n=j;
				else if(T[j]<T[n])
					n=j;
			}
		}
		if(n!=-1)
		{
			T[n]=T[n]-P[i];
			A[i]=n;
		}
	}	
	return A;
}
int* MM::worstfit()
{
	int T[p];
	int t,n;
	for(int i=0;i<m;i++)
	{
		T[i]=M[i];
		A[i]=-1;
	}
	for(int i=0;i<p;i++)
	{
		n=-1;
		for(int j=0;j<m;j++)
		{
			if(T[j]>=P[i])
			{
				if(n==-1)
					n=j;
				else if(T[j]>T[n])
					n=j;
			}
		}
		if(n!=-1)
		{
			T[n]=T[n]-P[i];
			A[i]=n;
		}
	}
	return A;
}
int* MM::firstfit()
{
	int T[p];
	for(int i=0;i<m;i++)
	{
		T[i]=M[i];
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(T[j]>=P[i])
			{
				T[j]=T[j]-P[i];
				A[i]=j;
				break;
			}
		}
	}
	return A;
}
int main()
{
	MM MGR;
	MGR.input();
	cout<<"1).Firstfit 2).Bestfit 3).Worstfit"<<endl;
	do
	{
		switch(getch()-48)
		{
			case 1:
			{
				MGR.firstfit();
				MGR.display();
				break;
			}
			case 2:
			{
				MGR.bestfit();
				MGR.display();
				break;
			}
			case 3:
			{
				MGR.worstfit();
				MGR.display();
				break;
			}
			default:
			{
				cout<<"Invalid Option"<<endl;
			}
		}
	}while(true);
	
}
