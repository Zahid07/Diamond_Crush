#include "util.h"
#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"Box.h"
#include"user.h"
#include"menu.h"
#include"start.h"
#include<cmath>
#include <iostream>
#include <fstream> 
using namespace std;

class outline{
public:
User user;
BOX* boxes;
menu Menu;
tbox* boxes1;
private:
int color[6]={2,12,22,32,42,52};
bool once=false;
int lenx;
bool done=false;
bool moving =false;
int ii=0;
int iy;
bool right =false;
bool left =false;
string filename;
bool up=false;
bool down=false;
int ti;
int leny;
int len;
int ix;
int startx;
int starty;
string filen;
public:
int getcolor(int i){
   return color[i]; 
}

bool getonce(){
    return once;
}

void setonce(bool o){
once=o;
}

int getlenx(){
    return lenx;
}

void setlenx(int i){
    lenx=i;
}
bool getdone(){
    return done;
}

void setdone(bool m){
    done=m;
}

bool getmoving(){
    return moving;
}

void setmoving(bool m){
    moving=m;
}

void setii(int i){
    ii=i;
}
int getii(){
    return ii;
}
void setiy(int i){
    iy=i;
}
int getiy(){
    return iy;
}

bool getright(){
    return right;
}

void setright(bool m){
right=m;
}

bool getleft(){
    return left;
}

void setleft(bool m){
left=m;
}

bool getup(){
    return up;
}

void setup(bool m){
up=m;
}

bool getdown(){
    return down;
}

void setdown(bool m){
down=m;
}

void setti(int i){
    ti=i;
}
int getti(){
    return ti;
}

void setleny(int i){
    leny=i;
}
int getleny(){
    return leny;
}

void setix(int i){
    ix=i;
}
int getix(){
    return ix;
}


outline(){
boxes=NULL;
len=0;
filename="user";
filen="names";
startx=0;
starty=0;
}

void move(int i){

boxes[i].goright(5);
}

void checkdiv(int n){
int tempi=0;

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if((i*j)==n){
tempi=i;

if(i<=j){
lenx=500/i;
//cout<<"i is = "<<i<<" and lenx is = "<<lenx<<endl;
ix=i;
iy=j;
leny=700/j;

}
}
}
}
}





outline(int n){
srand(time(NULL));
int t=0;
int tx=0;
startx=65;
len=n;
starty=15;
bool once=false;
checkdiv(n);
boxes= new BOX[n];
boxes1= new tbox[n];
for(int i=0;i<n;i++){
boxes[i].setx(startx);
boxes[i].sety(starty);
//boxes[i].sets(100);
//cout<<"x is = "<<startx<<" y is = "<<starty<<endl;
//startx+=105;
startx=startx+lenx+5;
t=(rand()%6);
tx=(rand()%10);
boxes[i].setstring(color[t]);
boxes1[i].setstring(color[t]);
//cout<<"found is = "<<4*lenx+20<<endl;
if(startx>=(ix*(lenx+10))){
//starty+=105;
ii+=1;
starty=starty+leny+3;
//cout<<"in if"<<endl;
startx=65;
}


}
len=n;
//cout<<"len is = "<<((((ix+1)*lenx)))<<endl;
if((((ix+1)*lenx)+15)>590){
ii=590+((((ix+1)*lenx)+15)-590);
if(ii>590 && ii<593){
ii=595;
}
//cout<<"ii is = "<<ii<<endl;
}else if(((((ix+1)*lenx)))<590){
ii=600;
}else
{
ii=590;
}


t=0;
tx=0;
startx=65;
len=n;
starty=15;
once=false;
checkdiv(n);
for(int i=0;i<n;i++){
boxes1[i].setx(startx);
boxes1[i].sety(starty);
//boxes[i].sets(100);
//cout<<"x is = "<<startx<<" y is = "<<starty<<endl;
//startx+=105;
startx=startx+lenx+5;


//cout<<"found is = "<<4*lenx+20<<endl;
if(startx>=(ix*(lenx+10))){
//starty+=105;
ii+=1;
starty=starty+leny+3;
//cout<<"in if"<<endl;
startx=65;
}

}

}
void goright(int i){

//cout<<"Now x is = "<<boxes[i].getx();
//boxes1[i].getx();cout<<endl;

int ts=boxes[i].getstring();
boxes[i].setstring(boxes[i+1].getstring());
boxes[i+1].setstring(ts);
boxes[i].setx(boxes1[i].getx());
boxes[i+1].setx(boxes1[i+1].getx());
//cout<<"swapping"<<endl;
//boxes[i+1].setstring(boxes1[i].getstring());
//cout<<"string is = "<<boxes[i].getstring()<<endl;;
//boxes[i].setstring(boxes1[i+1].getstring());
equal();


}

void godown(int i){
int ts=boxes[i].getstring();
boxes[i].setstring(boxes[i-(ix)].getstring());
boxes[i-(ix)].setstring(ts);
boxes[i].sety(boxes1[i].gety());
boxes[i-(ix)].sety(boxes1[i-(ix)].gety());
//cout<<"swapping"<<endl;
//boxes[i+1].setstring(boxes1[i].getstring());
//cout<<"string is = "<<boxes[i].getstring()<<endl;;
//boxes[i].setstring(boxes1[i+1].getstring());
equal();


}

void goup(int i){
int ts=boxes[i].getstring();
boxes[i].setstring(boxes[i+(ix)].getstring());
boxes[i+(ix)].setstring(ts);
boxes[i].sety(boxes1[i].gety());
boxes[i+(ix)].sety(boxes1[i+(ix)].gety());
//cout<<"swapping"<<endl;
//boxes[i+1].setstring(boxes1[i].getstring());
//cout<<"string is = "<<boxes[i].getstring()<<endl;;
//boxes[i].setstring(boxes1[i+1].getstring());
equal();


}


void goleft(int i){

//cout<<"Now x is = "<<boxes[i].getx();
//boxes1[i].getx();cout<<endl;

int ts=boxes[i].getstring();
boxes[i].setstring(boxes[i-1].getstring());
boxes[i-1].setstring(ts);
boxes[i].setx(boxes1[i].getx());
boxes[i-1].setx(boxes1[i-1].getx());
//cout<<"swapping"<<endl;
//boxes[i+1].setstring(boxes1[i].getstring());
//cout<<"string is = "<<boxes[i].getstring()<<endl;;
//boxes[i].setstring(boxes1[i+1].getstring());
equal();


}

void increment_level(){
//user.setnum(1);
len+=8;
//makeoutline(len);

}
void makeoutline(int n){
srand(time(NULL));
int t=0;
int tx=0;
startx=65;
len=n;
starty=15;
bool once=false;
checkdiv(n);

boxes= new BOX[n];
boxes1= new tbox[n];
for(int i=0;i<n;i++){
boxes[i].setx(startx);
boxes[i].sety(starty);
//boxes[i].sets(100);
//cout<<"x is = "<<startx<<" y is = "<<starty<<endl;
//startx+=105;
startx=startx+lenx+5;
t=(rand()%6);
tx=(rand()%10);
boxes[i].setstring(color[t]);
boxes1[i].setstring(color[t]);
//cout<<"found is = "<<4*lenx+20<<endl;
if(startx>=(ix*(lenx+10))){
//starty+=105;
ii+=1;
starty=starty+leny+3;
//cout<<"in if"<<endl;
startx=65;
}


}
len=n;
//cout<<"len is = "<<((((ix+1)*lenx)))<<endl;
if((((ix+1)*lenx)+15)>590){
ii=590+((((ix+1)*lenx)+15)-590);
if(ii>590 && ii<593){
ii=595;
}
//cout<<"ii is = "<<ii<<endl;
}else if(((((ix+1)*lenx)))<590){
ii=600;
}else
{
ii=590;
}


t=0;
tx=0;
startx=65;
len=n;
starty=15;
once=false;
checkdiv(n);
for(int i=0;i<n;i++){
boxes1[i].setx(startx);
boxes1[i].sety(starty);
//boxes[i].sets(100);
//cout<<"x is = "<<startx<<" y is = "<<starty<<endl;
//startx+=105;
startx=startx+lenx+5;


//cout<<"found is = "<<4*lenx+20<<endl;
if(startx>=(ix*(lenx+10))){
//starty+=105;
ii+=1;
starty=starty+leny+3;
//cout<<"in if"<<endl;
startx=65;
}

}

check();
}

int getlen(){
return len;
}

int getstartx(){
return startx;
}

int getstarty(){
return starty;
}

void equal(){
for(int i=0;i<len;i++){

boxes1[i].setx(boxes[i].getx());

}
}

bool checksame(){
    for(int l=0;l<len;l++){
        ti=l;
   bool found=true;
    bool found1=true;
    int upperboundry=0;
  int lowerboundry=0;
  int upperboundry1=0;
  int lowerboundry1=0;
int count=0;
int same=0;
int same1=0;
int i=0;

    i=ti;

srand(time(NULL));
  for(;;i--){
      if(i%ix==0){
               if(boxes[ti].getstring()==boxes[i].getstring()){     
                  // same+=1; 
      }else if(boxes[ti].getstring()!=boxes[i].getstring()){
          i+=1; 
      }
          lowerboundry=i;
          break;
      }
          if(boxes[ti].getstring()==boxes[i].getstring()){
          
         
      }else{ 
         i+=1;
         lowerboundry=i;
          break;}
        
      
  }
  
  i=ti;
   for(;;i-=ix){
        if(i>=0 && i<=(ix-1)){
               if(boxes[ti].getstring()==boxes[i].getstring()){  
                   //same+=1;    
                 }else{
                    i+=ix;
                             }
          lowerboundry1=i;
          break;
      }
          if(boxes[ti].getstring()==boxes[i].getstring()){
         
         
      }else{ 
         i+=ix;
         lowerboundry1=i;
          break;}
       
      
  }
  
 for(i=lowerboundry1;;i+=ix){
        if(boxes[ti].getstring()==boxes[i].getstring()){
          same1+=1;
      }else
      if(boxes[ti].getstring()!=boxes[i].getstring()){
         i-=ix;
          upperboundry1=i;
          break;
      }      
      count+=1;
       if(i>=(len-ix)&& i<=(len-1)){

          upperboundry1=i;
          break;
          
      }
  }
 
  for(i=lowerboundry;;i++){

     if((i+1)%ix==0){
           //i-=1;
            if(boxes[ti].getstring()!=boxes[i].getstring()){
               i-=1;
           }else if(boxes[ti].getstring()==boxes[i].getstring()){
             same+=1;
               
           }
  upperboundry=i;
      
          break;
          break;
          break;
          break;
      }
      if(boxes[ti].getstring()==boxes[i].getstring()){
          same+=1;
      }else
      if(boxes[ti].getstring()!=boxes[i].getstring()){
         i-=1;
          upperboundry=i;
          break;
      }      
      count+=1;
      
  }
     if(same1>2){
    return true;
}


if(same>2){
   return true;
}




    }
return false;

}

void checkboxeshorizontal(){
    bool found=true;
    bool found1=true;
   //while(found==true && found1==true){
  int upperboundry=0;
  int lowerboundry=0;
  int upperboundry1=0;
  int lowerboundry1=0;
int count=0;
int same=0;
int same1=0;
int i=0;


    i=ti;
//cout<<"ti is = "<<ti<<endl;
   

//cout<<"In horizontal check"<<endl;
srand(time(NULL));
  for(;;i--){
      if(i%ix==0){
               if(boxes[ti].getstring()==boxes[i].getstring()){     
                  // same+=1; 
      }else if(boxes[ti].getstring()!=boxes[i].getstring()){
          i+=1; 
      }
          lowerboundry=i;
          break;
      }
          if(boxes[ti].getstring()==boxes[i].getstring()){
          //cout<<"in if"<<endl;
         
      }else{ 
         i+=1;
         lowerboundry=i;
          break;}
        
      
  }
  //cout<<"Lower boundry is = =================== = "<<lowerboundry<<endl;
  i=ti;
   for(;;i-=ix){
        if(i>=0 && i<=(ix-1)){
               if(boxes[ti].getstring()==boxes[i].getstring()){  
                   //same+=1;    
                 }else{
                    i+=ix;
                             }
          lowerboundry1=i;
          break;
      }
          if(boxes[ti].getstring()==boxes[i].getstring()){
          //cout<<"in if"<<endl;
         
      }else{ 
         i+=ix;
         lowerboundry1=i;
          break;}
       
      
  }
  //cout<<"lower boundry 1 is = =================== = "<<lowerboundry1<<endl;
  //Now do for upperboundry 1.from len-ix to len
//cout<<"lower boundry 1 is = "<<lowerboundry1<<endl;
//cout<<"Len is = "<<len<<endl;
 for(i=lowerboundry1;;i+=ix){
     //   cout<<"i in upper is = "<<i<<endl;
       // cout<<"Check color is = "<<boxes[ti].getstring()<<endl;
        //cout<<"color is = "<<boxes[i].getstring()<<endl;
      if(boxes[ti].getstring()==boxes[i].getstring()){
          same1+=1;
      }else
      if(boxes[ti].getstring()!=boxes[i].getstring()){
         i-=ix;
          upperboundry1=i;
          break;
      }      
      count+=1;
       if(i>=(len-ix)&& i<=(len-1)){
           //i-=1;
          // cout<<"Breaking"<<endl;
          upperboundry1=i;
          break;
          
      }
  }
  //cout<<"upper boundry 1 is = =================== = "<<upperboundry1<<endl;
  //cout<<"upper boundry 1 is = "<<upperboundry1<<endl;
  for(i=lowerboundry;;i++){
  //    cout<<"i is = "<<i<<endl;
 // cout<<"Check color is = "<<boxes[ti].getstring()<<endl;
    //  cout<<"color is = "<<boxes[i].getstring()<<endl;
     if((i+1)%ix==0){
           //i-=1;
           if(boxes[ti].getstring()!=boxes[i].getstring()){
               i-=1;
           }else if(boxes[ti].getstring()==boxes[i].getstring()){
             same+=1;
                 
           }
upperboundry=i;
      
          break;
          break;
      }
      if(boxes[ti].getstring()==boxes[i].getstring()){
          same+=1;
      }else
      if(boxes[ti].getstring()!=boxes[i].getstring()){
         i-=1;
          upperboundry=i;
          break;
      }      
      count+=1;
      
  }
  //cout<<"lower boundry  is = =================== = "<<lowerboundry<<endl;
  //cout<<"upper boundry  is = =================== = "<<upperboundry<<endl;
  same=(upperboundry-lowerboundry)+1;
  //same1=((upperboundry1-lowerboundry1)+1)/ix;
 // cout<<"same is = "<<same<<endl;;
  //cout<<"same1 is = "<<same1<<endl;;
 // cout<<"lower boundry is = "<<lowerboundry<<endl;
 // cout<<"upper boundry is = "<<upperboundry<<endl;
   if(same1>2){
       if(Menu.gettimetrial()==false){
user.setscore(same);
       }else{
           Menu.settime(1);
       }
       
for( i=lowerboundry1;i<=upperboundry1;i+=ix){
    int t=rand()%6;
    while(t==boxes[i].getstring()){
        t=rand()%6;
    }
    //cout<<"boundey is = "<<i<<endl;
    boxes[i].setstring(color[t]);
    boxes1[i].setstring(color[t]);
}

}else{
    found1=false;
}
cout<<endl<<endl;

if(same>2){
    if(Menu.gettimetrial()==false){
user.setscore(same);
       }else{
           Menu.settime(1);
       }
      
      
for( i=lowerboundry;i<=upperboundry;i++){
    int t=rand()%6;
    while(t==boxes[i].getstring()){
        t=rand()%6;
    }
    //cout<<"boundey is = "<<i<<endl;
    
    boxes[i].setstring(color[t]);
    boxes1[i].setstring(color[t]);
    
}

}else{
    found=false;
}

if(found==false && found1==false){
   // break;
}

//}


}
void displayout(){

 
DrawRectangle(650, 200, 350,400, colors[RED]);
DrawString( 850, 570, "MAKE ' EM", colors[MISTY_ROSE]);
DrawString( 670, 540, "MADE BY : ", colors[MISTY_ROSE]);
DrawString( 800, 520, "M.ZAHID", colors[MISTY_ROSE]);
DrawString( 670, 480, "ROLL NO: ", colors[MISTY_ROSE]);
DrawString( 800, 450, "19I-0469", colors[MISTY_ROSE]);
DrawString( 670, 420, "CS-D ", colors[MISTY_ROSE]);

DrawRectangle(650, 15, 350,130, colors[DARK_SLATE_GRAY]);
DrawRectangle(670, 20, 100,120, colors[BLACK]);
DrawRectangle(790, 20, 100,120, colors[BLACK]);
DrawRectangle(910, 20, 80,120, colors[BLACK]);
DrawString( 710, 70, "?", colors[MISTY_ROSE]);
DrawString( 830, 70, "P", colors[MISTY_ROSE]);
DrawString( 950, 70, "R", colors[MISTY_ROSE]);
}

void check(){
    
    right =false;
    left =false;
    up=false;
    down=false;
    //cout<<"Checking boxes"<<endl;
   while(checksame()){
     //  cout<<"HEHEHEHEHEHEHEH"<<endl;
for(int i=0;i<len;i++){
    ti=i;
    checkboxeshorizontal();
    
}

   }
}

void savefile(){
   // cout<<"in file - ----------------"<<endl;
    bool taken=true;
    int i=0;
    string file;
    string name;
    while(taken==true){
    file=filename+to_string(i);
    name=filen+to_string(i);
ifstream myfile (file);
ifstream myfile1 (name);
  if (myfile.is_open() && myfile1.is_open())
  {
      //cout<<"file is open = "<<endl;
    taken=true;
    i++;
    myfile.close();
    myfile1.close();
  }else {taken=false;}

}
if(taken==false){
//cout<<"file ready is = "<<file<<endl;
ofstream myfile (file);
ofstream myfile1 (name);
  if (myfile.is_open() && myfile1.is_open())
  {
    myfile1 << user.getusername()<<endl;
    if(Menu.gettimetrial()==true){
   // myfile1<<"timetrial"<<endl;        
    }else if(Menu.getnormal()==true){
        myfile1<<"normal"<<endl;
    }

    myfile << user.getboxes()<<endl;
    myfile << user.getlevel()<<endl;
    myfile << user.getscore()<<endl;
    
    for(int i=0;i<len;i++){
        myfile<<boxes[i].getx()<<endl;
    }
    for(int i=0;i<len;i++){
        myfile<<boxes[i].gety()<<endl;
    }
      for(int i=0;i<len;i++){
        myfile<<boxes[i].getstring()<<endl;
    }

    myfile.close();
  }
}





}

void getfile(string nametosearch){
  bool taken=true;
    int i=0;
    string file;
    string name;
    while(taken==true){
    file=filename+to_string(i);
    name=filen+to_string(i);
ifstream myfile (file);
ifstream myfile1 (name);
  if (myfile.is_open() && myfile.is_open())
  {
    //cout<<file<<endl;
    //cout<<name<<endl;
    taken=true;
    i++;
    myfile.close();
  }else {taken=false;}

}
string item;
int items;
bool found=false;
//cout<<"i is---------------------------- = "<<i<<endl;
for(int j=0;j<i;j++){
file=filename+to_string(j);
name=filen+to_string(j);
ifstream myfile1 (name);
ifstream myfile (file);
while (getline(myfile1,item)){
    //cout<<"item is = "<<item<<endl;
    if(item==nametosearch){
       // cout<<"founf item  = "<<endl;
        //cout<<"file is = "<<name<<endl;
       found=true; 
       break;
    }
    myfile1.close();
}


myfile.close();
myfile1.close();
 if(item==nametosearch){
            found=true; 
       break;
    }

}
//cout<<"Here name to search is = "<<nametosearch<<endl;;
ifstream myfile1 (name);
ifstream myfile (file);
int k=0;
while (getline(myfile,item)){
    items=stoi(item);
    //cout<<"k is = "<<k <<" item is = "<<item<<endl;
    //user.setboxes(items);
    //user.setlevel(items);
    //user.setscore(items);
    k++;   
    
}


}


};
