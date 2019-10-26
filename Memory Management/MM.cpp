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
	cout<<"Process \tSize \t Memory Block"<<endl;
	for(int i=0;i<p;i++)
	{	
		cout<<"P["<<i<<"] \t\t"<<P[i]<<" \t ";
		if(A[i]!=-1)
			cout<<"M["<<A[i]<<"]"<<endl;
		else
			cout<<"Not allocated"<<endl;
	}
}
int* MM::bestfit()
{
	int T[p];
	int t,n;
	for(int i=0;i<m;i++)
	{
		T[i]=M[i];
	}
	for(int i=0;i<p;i++)
	{
		A[i]=-1;
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
	}
	for(int i=0;i<p;i++)
	{
		A[i]=-1;
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
		A[i]=-1;
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
	cout<<"1).Firstfit 2).Bestfit ";
	cout<<"3).Worstfit 4).Exit"<<endl;
	do
	{
		switch(getch()-48)
		{
			case 1:
			{
				cout<<"First fit"<<endl;
				MGR.firstfit();
				MGR.display();
				break;
			}
			case 2:
			{
				cout<<"Best fit"<<endl;
				MGR.bestfit();
				MGR.display();
				break;
			}
			case 3:
			{
				cout<<"Worst fit"<<endl;
				MGR.worstfit();
				MGR.display();
				break;
			}
			case 4:
			{
				return 1337;
			}
			default:
			{
				cout<<"Invalid Option"<<endl;
			}
		}
	}while(true);
}
