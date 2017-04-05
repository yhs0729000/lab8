#include<iostream>
#include<stdio.h>
#include<string>
#include "timer6.h"
using namespace std;

string to_string(int val){
	char str[10];
	sprintf(str,"%d",val);
	return string(str);
}
//抽卡排序//
class drawcard{



public:

	void printcard(){ cout<<"3 4 7 1 8 6 2 5"<<endl; }




};

      void u(){
int sec,mana,one,two,three,four;


	

	char map1[22][52];

	char map2[22][52];

	

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
 
               cout<<string("1 ")+to_string(one)+ " 5 23"<<endl;
               cout<<0<<endl;


}



int main(){


        drawcard draw;

        draw.printcard();

while(true)
{	
   u();
}
}
		
