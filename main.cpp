#include<iostream>
#include<stdio.h>
#include<string>
#include "timer6.h"
using namespace std;


//抽卡排序//
class drawcard{



public:

	void printcard(){ cout<<7<<""<<5<<""<<4<<""<<1<<""<<6<<""<<3<<""<<8<<""<<2<<endl; }




};




int main(){

	char sec,mana,one,two,three,four,a;
        drawcard draw;

        draw.printcard();


	const int row =22;
 	const int column = 52;

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
				 cin.get(a);
			
			 }
		}

		for(i=0;i<22;i++)
		{
	         for(j=0;j<52;j++)
			 {
				 cin.get(map2[i][j]);
				  cin.get(a);
			 }
		}


		
		return 0;




}
