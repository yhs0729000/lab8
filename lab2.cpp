#include<iostream>
#include<math.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include "lab2.h"
using namespace std;


int main(){
	double KK=0;double K1=0.5;double K2=0.5;double K3=0;double K4=0;double K5=0;
	double Qa=0;double Q1=0;double Q2=0;double Q3=0;double Q4=0;double Q5=0;
	double Qb=0;double Q6=0;double Q7=0;double Q8=0;double Q9=0;double Q10=0;
	double N=1;double N1=0.5;double N2=0.5;double N3=1;double N4=1;double N5=1;
	
	double i=0;
	string headline;
	score lab2;
	ifstream inFile("filein.txt",ios::in);
	if(!inFile)
		{
			cout<<"file opened failed"<<endl;
			exit(1);
		}
	ofstream outFile("outfile", ios::out);
	if(!outFile) {
 cerr << "Failed opening" << endl;
 exit(1);
 }

			if(inFile>>i>>Qa>>Qb)
			{
				
				lab2.score1(Qa,Qb);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(KK);
				lab2.multi2(N);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;
				
			}
						Q1=lab2.calculate();
		    Q2=lab2.calculate1();
			
	lab2.score1(Q1,Q2);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(K1);
				lab2.multi2(N1);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;

				Q3=lab2.calculate();
		    Q4=lab2.calculate1();
			
	lab2.score1(Q3,Q4);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(K2);
				lab2.multi2(N2);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;

				Q5=lab2.calculate();
		    Q6=lab2.calculate1();
			
	lab2.score1(Q5,Q6);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(K3);
				lab2.multi2(N3);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;

				Q7=lab2.calculate();
		    Q8=lab2.calculate1();
			
	lab2.score1(Q7,Q8);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(K4);
				lab2.multi2(N4);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;

				Q9=lab2.calculate();
		    Q10=lab2.calculate1();
			
	lab2.score1(Q9,Q10);
				lab2.down1();
				lab2.down2();
				lab2.opcount1();
				lab2.opcount2();
				lab2.multi1(K5);
				lab2.multi2(N5);
				lab2.calculate();
				lab2.calculate1();
				outFile<<lab2.calculate()<<"\t"<<lab2.calculate1()<<endl;
		
	
				return 0;
}

