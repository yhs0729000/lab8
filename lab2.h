#include<iostream>
#include<math.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

class score{


public:
	void score1(double a,double b){ Ra=a; Rb=b;}
	double down1(){dd=(Rb-Ra)/400; return dd;}
	double down2(){ss=(Ra-Rb)/400; return ss;}
	double opcount1(){Ea=1/(1+(pow(10,dd)));   return Ea;}
	double opcount2(){Eb=1/(1+(pow(10,ss)));   return Eb;}
	double multi1(double k){Ua=k-Ea;  return Ua;}
	double multi2(double e){Ub=e-Eb;  return Ub;}
	double calculate(){Sa=Ra+(32*Ua);    return Sa;}
	double calculate1(){Sb=Rb+(32*Ub);    return Sb;}

private:
	double Ra;
	double Rb;
	double Ea;
	double Eb;
	double Sa;
	double Sb;
	double Ua;
	double Ub;
	double dd;
	double ss;
};
