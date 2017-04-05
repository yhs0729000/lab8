#include<iostream>

#include<string>
#include<cstdio>
#include "timer6.h"
using namespace std;


//抽卡排序//





int main(){

  
      cout<<"3 4 7 1 8 6 2 5"<<endl;

while(true)
{	char sec,mana,one,two,three,four,a;
       

	const int row =25;
 	const int column = 55;

	char map1[row][column];

	char map2[row][column];

	

	//讀map//
	cin>>sec>>mana>>one>>two>>three>>four;

	int i,j;
		for(i=0;i<22;i++)
		{
	         for(j=0;j<52;j++)
			 {
				 cin.get(map1[i][j]);
				 
			
			 }
		}

		for(i=0;i<22;i++)
		{
	         for(j=0;j<52;j++)
			 {
				 cin.get(map2[i][j]);
			 }
		}

               cout<<string("1 ")<<" 5 23"<<endl;
               cout<<0<<endl;
		
		

}
}
		
