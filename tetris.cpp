 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include "genMino.h"
 using namespace std;
 int main()
 {
 Mino * mino_ptr;
 double *ptr[50];


 srandom(time(NULL));
try{
 for(int i=0;i<500;++i)
 {
 mino_ptr = genMino();
 mino_ptr->paint();
ptr[i] = new double[50000000];
 }
}catch(bad_alloc &memoryAlloc){
 cerr << "Exception: " <<
 memoryAlloc.what() << endl;}
 return 0;
 }

