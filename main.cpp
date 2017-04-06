#include<iostream>
#include<cstdio>
#include<string>
#include "timer6.h"
using namespace std;
	char map1[22][52];

	char map2[22][52];
string to_string(int val){
	char str[10];
	sprintf(str,"%d",val);
	return string(str);
}

class draw{
    
public:

      void drawcard(){  cout<<"7 9 8 2 6 5 4 1"<<endl;}
};
//抽卡排序//





int main(){

draw drew;
drew.drawcard();

    while(true)
   {	
   
int sec,mana,one=1,two,three,four;
	char a;

	



	

	//讀map//
	cin>>sec>>mana>>one>>two>>three>>four;

	
		for(int i=0;i<22;i++)
		{
	         for(int j=0;j<52;j++)
			 
				 cin.get(map1[i][j]);
				 cin.get(a);
			
			 
		}

		for(int i=0;i<22;i++)
		{
	         for(int j=0;j<52;j++)
			 
				 cin.get(map2[i][j]);
                                 cin.get(a);
			 
		}
 
       cout<<string("1 ")+to_string(one)+ " 5 23"<<endl;
       cout<<string("2 ")+to_string(one)+ " 5 24"<<endl;
       cout<<string("3 ")+to_string(one)+ " 17 24"<<endl;
       cout<<string("4 ")+to_string(one)+ " 5 23"<<endl;

              cout<<0<<endl;


    }
}
		
