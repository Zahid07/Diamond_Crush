#include "util.h"
#include <iostream>
#include<string>
#include<string.h>
#include<time.h>
#include<cmath> 
using namespace std;

class tbox{
int x;
int y;
int color;

public:

void setx(int xx){
x=xx;

//cout<<"tx is = "<<tx<<endl;
}
void sety(int yy){
y=yy;
}

int getx(){
//cout<<"boxes x is = "<<x<<endl;
return x;
}
int gety(){
return y;
}

void setstring(int s){
color=s;
}
int getstring(){
return color;
}

};

