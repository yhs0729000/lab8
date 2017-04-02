#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;


//抽卡排序//
class drawcard{



public:
	char set(){

		for(int i=0;i<8;i++)
		{	card[i]=i+1;}

		
	}
	void printcard(){ cout<<card[6]<<card[4]<<card[3]<<card[1]<<card[5]<<card[0]<<card[2]<<card[7]<<endl; }


private:
	char card[8];




};




int main(){

	char sec,mana,one,two,three,four,a;




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


		drawcard draw();
		return 0;




}
