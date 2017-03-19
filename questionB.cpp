#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	
	int x;
	
	cout<<"key in number"<<endl;
	cin>>x;
	while(x>0)
	{
		if(x%2==0)
		{
			x=x/2;
			
			
		}
		else if(x%2!=0 && x!=1)
		{
			x=(3*x)+1;
	
			
		}
		else if(x==1)
		{
			break;
		}
		cout<<x<<""<<endl;
	
	}
		
	return 0;

	
}
