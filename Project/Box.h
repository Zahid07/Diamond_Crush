#include "util.h"
#include <iostream>
#include<string>
#include<string.h>
#include<time.h>
#include<cmath> 
using namespace std;

class BOX{
int x;
int y;

int size;
int color;
int tx;
public:

int ty;
BOX(){
x=0;
y=0;
size=0;

} 

BOX(int xx, int yy, int s){
x=xx;
y=yy;
tx=xx;
ty=yy;
size=s;
} 
void setstring(int s){
color=s;
}
int getstring(){
return color;
}
void setx(int xx){
x=xx;
tx=xx;

}
void sety(int yy){
y=yy;
ty=yy;
}
void sets(int s){
size=s;
}
int gettx(){
return tx;
}

int getx(){
return x;
}
int gety(){
return y;
}
int gets(){
return size;
}

void goup(int s){
y+=s;
}

void godown(int s){
y-=s;
}

void goright(int s){
x+=s;

glutPostRedisplay();
}

void goleft(int s){
x-=s;
}
void draw(){

DrawSquare( x , y ,size,colors[GREEN]); 

}
};
















































