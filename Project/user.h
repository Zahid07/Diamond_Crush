#include "util.h"
#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<string.h> 
#include<cmath> 
using namespace std;

class User{
private:
string username;
int userlevel;
int hint;
int userscore;
bool showlevel;
int increment;
int inc;
int x;
int y;
int tscore;
bool reverse;
int levels[10];
int count;
int tlevel;
int noofboxes;
public:


int gettlevel(){
    return tlevel;
}

void settlevel(int t){
    tlevel=t;
}

User(){
username="\0";
userlevel=1;
userscore=0;
hint=3;
showlevel=false;
for(int i=0;i<10;i++){
    levels[i]=1;
}
noofboxes=48;
tscore=0;
tlevel=1;
count=1;
increment=1000;
x=70;
reverse=false;
y=750;
inc=increment/500;;

}
bool getlshow(){
    return showlevel;
}
int gethint()
{
    return hint;
}

void sethint(int h){
hint-=h;
}
void setlshow(bool m){
    showlevel=m;
}
void setusername(string um){
    username=um;
}

void setusername(char um){
    if(um==8){
int len=username.length();
//cout<<"backspace entered"<<endl;
string name=username.substr(0,len-1);
//for(int i=0;i<len;i++){
//name[i]=username[i];
//}
username=name;
    }else{
username=username+um;
    }
}
string getusername(){
    return username;
}
int getlevel(){
return userlevel;
}

int getscore(){
return userscore;
}

void setlevel(int i){
userlevel+=i;
if(reverse==false){
//cout<<"reverse is true------------------------------------------------ "<<endl;
    if(count==1){
noofboxes=noofboxes+8;
count+=1;
    }else if(count==2){
        noofboxes=noofboxes+4;
        count+=1;
    }

}
if(count==3 && reverse==false){
    count=1;
    reverse=true;
}

if(reverse==true){
 if(count==1){
noofboxes=noofboxes+4;
count+=1;
    }else if(count==2){
        noofboxes=noofboxes+8;
        count+=1;
    }

}

if(count==3 && reverse==true){
    count=1;
    reverse=false;
}


}

void setscore(int i){
if(i==3){
userscore+=20;
tscore+=20;
int t=(500*20)/increment;
inc+=t;
}else{
userscore+=40;
tscore+=40;
int t=(500*20)/increment;
inc+=t;
}
if(tscore>=50){
    inc+=increment/500;
    tscore=0;
}
if(userscore>increment){
    increment+=increment;
    setlevel(1);
    inc=increment/500;
    
}

}

int setboxes(int i){
 noofboxes=i;
}

int getboxes(){
return noofboxes;
}

void leveldraw(){    
DrawRectangle(x, y, inc,50, colors[RED]);
}

void leveld(){
for(int i=0;i<userlevel;i++){
    levels[i]=5;
}


DrawRectangle(90, 20, 130,130, colors[levels[9]]);
DrawRectangle(240, 20, 130,130, colors[levels[8]]);
DrawRectangle(400, 20, 130,130, colors[levels[7]]);

DrawRectangle(90, 200, 130,130, colors[levels[6]]);
DrawRectangle(240, 200, 130,130, colors[levels[5]]);
DrawRectangle(400, 200, 130,130, colors[levels[4]]);


DrawRectangle(90, 380, 130,130, colors[levels[3]]);
DrawRectangle(240, 380, 130,130, colors[levels[2]]);
DrawRectangle(400, 380, 130,130, colors[levels[1]]);


DrawRectangle(240, 560, 130,130, colors[levels[0]]);

DrawRectangle(240, 700, 210,50, colors[MISTY_ROSE]);
DrawString( 250, 710, "BACK <--", colors[RED]);

}



};
