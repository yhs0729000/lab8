#include <iostream>
#include<string>
#include<cstdio>
#include"time.h"
using namespace std;
char mapID[22][52],mapHP[22][52];
string to_string(int val){
	char str[10];
	sprintf(str,"%d",val);
	return string(str);
}
void update(){
	
	int sec,mana,one=1,two,three,four;
	char a;
    cin>>sec>>mana>>one>>two>>three>>four;
    for(int i=0;i<22;i++){
    	for(int j=0;j<52;j++)
    		cin.get(mapID[i][j]);
    	cin.get(a);
	}
	for(int i=0;i<22;i++){
		for(int j=0;j<52;j++)
			cin.get(mapHP[i][j]);
		cin.get(a);
	}
	
	cout<<string("1 ")+to_string(one)+ " 5 23"<<endl;
	cout<<string("2 ")+to_string(two)+ " 17 23"<<endl;
	/*cout<<string("1 ")+to_string(three)+ " 5 23"<<endl;
	cout<<string("1 ")+to_string(four)+ " 5 23"<<endl;*/
	cout<<0<<endl;
}
int main(){
	cout<<"3 4 7 1 8 6 2 5"<<endl;
	while(true){
		update();
	}
    //cin>>sec>>mana>>one>>two>>three>>four;

} 
		
