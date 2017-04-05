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

	void printcard(){ cout<<"7 5 4 1 6 3 8 2"<<endl; }




};




int main(){
while(true)
{	char sec,mana,one,two,three,four,a;
        drawcard draw;

        draw.printcard();


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

               cout<<string("1")+to_string(one)+ " 6 22"<<endl;

		
		return 0;

}
}
		
