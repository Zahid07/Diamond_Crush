#include "util.h"
#include <iostream>
#include<string>
#include<string.h>
#include<time.h>
#include<cmath>
#include <fstream>  

class menu {
int *hscores;
bool exitmenu;
int time;
bool inmenu;
 int count;
 bool help;
bool submenu;
bool name;
bool savedgames;
string *hnames;
string filename;
string filen;
bool highscore1;
bool hover[6];
bool normal;
bool timetrial;
public:
bool getnormal(){
    return normal;
}
void setnormal(bool m){
    normal=m;
}

bool gettimetrial(){
    return timetrial;
}
void settimetrial(bool m){
    timetrial=m;
}

bool gethover(int i){
    return hover[i];
}
void sethover(int i,bool m){
    hover[i]=m;
}




menu(){
inmenu=true;
time=30;
count=0;
help=false;
submenu=false;
savedgames=false;
name=false;
exitmenu=false;
normal=false;
filename="user";
 filen="names";
//back=false;
timetrial=false;

for(int i=0;i<6;i++){
hover[i]=false;
}
}
int gettime(){
return time;
}
void settime(int t){
time+=t;
}
int getcount(){
return count;
}
void setcount(int t){
count+=t;
}

int gethscore(int i){
    return hscores[i];
}
string gethname(int i){
    return hnames[i];
}
void sethelp(bool m){
    help=m;
}
bool gethelp(){
    return help;
}
void setsaved(bool m){
    savedgames=m;
}
bool getsaved(){
    return savedgames;
}
void sethighscore(bool m){
highscore1=m;
}
bool sethighscore(){
return highscore1;
}

void setname(bool m){
    name=m;
}
int getname(){
    return name;
}
bool getexit(){
    return exitmenu;
}
void setexit(bool m){
     exitmenu =m;
}



void displayexit(){
DrawRectangle(340, 480, 210,50, colors[MISTY_ROSE]);
DrawString( 345, 485, "EXIT MENU", colors[RED]);
DrawRectangle(160, 420, 210,50, colors[MISTY_ROSE]);
DrawString( 170, 425, "BACK <--", colors[RED]);
DrawRectangle(380, 420, 210,50, colors[MISTY_ROSE]);
DrawString( 400, 425, "SAVE AND EXIT", colors[RED]);
DrawRectangle(340, 360, 210,50, colors[MISTY_ROSE]);
DrawString( 345, 365, "NEW-GAME", colors[RED]);

}

void namemenu(){
DrawRectangle(340, 480, 210,50, colors[MISTY_ROSE]);
DrawRectangle(160, 420, 210,50, colors[MISTY_ROSE]);
DrawString( 170, 425, "BACK <--", colors[RED]);
DrawRectangle(380, 420, 210,50, colors[MISTY_ROSE]);
DrawString( 400, 425, "CONTINUE", colors[RED]);
}

void helpd(){
DrawString( 300, 700, "HELP", colors[MISTY_ROSE]);
DrawString( 60, 650, "In Main Menu you have many option.", colors[MISTY_ROSE]);
DrawString( 60, 600, "Option 1 shows the top 4 saved games according", colors[MISTY_ROSE]);
DrawString( 60, 570, "scores.", colors[MISTY_ROSE]);
DrawString( 60, 530, "Option 2 shows the Level modes.", colors[MISTY_ROSE]);
DrawString( 60, 500, "Option 3 shows Levels Completed.", colors[MISTY_ROSE]);
DrawString( 60, 470, "Option 4 shows top 4 saved highscores", colors[MISTY_ROSE]);
DrawString( 60, 430, "To make score, you have to drag the box to make ", colors[MISTY_ROSE]);
DrawString( 60, 400, "3 or more similar boxes.", colors[MISTY_ROSE]);

if(hover[4]==true){

DrawRectangle(340, 280, 130,50, colors[RED]);
}
DrawString( 350, 300, "BACK <--", colors[MISTY_ROSE]);

}

void dubmenu(){
if(hover[0]==true){
DrawRectangle(340, 480, 210,50, colors[RED]);
}
DrawString( 350, 500, "NORMAL MODE", colors[MISTY_ROSE]);
if(hover[1]==true){
DrawRectangle(340, 430, 170,50, colors[RED]);
}
DrawString( 350, 450,"TIME TRIAL", colors[MISTY_ROSE]);
if(hover[2]==true){
DrawRectangle(340, 380, 130,50, colors[RED]);
}
DrawString( 350, 400, "BACK  <--", colors[MISTY_ROSE]);
}

void display(){
if(hover[5]==true){
DrawRectangle(340, 530, 190,50, colors[RED]);
}
DrawString( 350, 550, "SAVED GAMES", colors[MISTY_ROSE]);
if(hover[0]==true){ 
DrawRectangle(340, 480, 190,50, colors[RED]);
}
DrawString( 350, 500, "LEVEL MODES", colors[MISTY_ROSE]);
if(hover[1]==true){
DrawRectangle(340, 430, 100,50, colors[RED]);
}
DrawString( 350, 450,"LEVEL", colors[MISTY_ROSE]);
if(hover[2]==true){
DrawRectangle(340, 380, 190,50, colors[RED]);
}
DrawString( 350, 400, "HIGH-SCORES", colors[MISTY_ROSE]);
if(hover[3]==true){
DrawRectangle(340, 330, 100,50, colors[RED]);
}
DrawString( 350, 350, "HELP", colors[MISTY_ROSE]);
if(hover[4]==true){
DrawRectangle(340, 280, 100,50, colors[RED]);
}
DrawString( 350, 300, "QUIT", colors[MISTY_ROSE]);
}

bool getinmenu(){
return inmenu;
}

bool getsubmenu(){
return submenu;
}

void setinmenu(bool m){
inmenu=m;
}

void setsubmenu(bool m){
submenu=m;
}
void highscores(){
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
    //cout<<file<<endl;
    //cout<<name<<endl;
    taken=true;
    i++;
    myfile.close();
    myfile1.close();
  }else {taken=false;}

}
 
cout<<"i is = "<<i<<endl;
if(i<4){
hscores=new int[4];
hnames=new string[4];
for(int j=0;j<4;j++){
    hnames[j]="N/A";
    hscores[j]=0;
}
}else{
    hscores=new int[i];
hnames=new string[i];
for(int j=0;j<i;j++){
    hnames[j]="N/A";
    hscores[j]=0;
}
}
int k=0;
for(int j=0;j<i;j++){
    k=1;
file=filename+to_string(j);
name=filen+to_string(j);
string item;
ifstream myfile (file);
ifstream myfile1 (name);
 while (getline(myfile,item)){
    //cout<<"item is = "<<item<<endl;
   
    if(k==3){
        hscores[j]=stoi(item);
        cout<<"item is = "<<item<<endl;
    }
     k+=1;
   
}
k=0;
 myfile.close();
while(getline(myfile1,item)){
    hnames[j]=item;
   cout<<"item is = "<<item<<endl;
    myfile1.close();
}

}


for(int j=0;j<i;j++){
for(int k=0;k<i-1;k++){
    cout<<"ordering"<<endl;
    if(hscores[k]<hscores[k+1]){
        int temp=hscores[k+1];
        hscores[k+1]=hscores[k];
        hscores[k]=temp;

        string temp1=hnames[k+1];
        hnames[k+1]=hnames[k];
        hnames[k]=temp1;
        
    }

}
}

//    DrawString( 350, 500, to_string(hscores[0]), colors[MISTY_ROSE]);
  //  DrawString( 350, 450, to_string(hscores[0]), colors[MISTY_ROSE]);
   // DrawString( 350, 400, to_string(hscores[0]), colors[MISTY_ROSE]);
    //DrawString( 350, 350, to_string(hscores[0]), colors[MISTY_ROSE]);
   




}
void dhighscore(){
    if(highscore1==true && savedgames==false){
    DrawRectangle(210, 600, 320,45, colors[MISTY_ROSE]);
    DrawString( 220, 610, "Displaying TOP 4 Highscores", colors[RED]);
    }else if(savedgames==true){
    DrawRectangle(210, 600, 350,45, colors[MISTY_ROSE]);
    DrawString( 220, 610, "Displaying TOP 4 Saved Games", colors[RED]);
    DrawRectangle(180, 495, 350,45, colors[RED]);
    DrawRectangle(180, 445, 350,45, colors[RED]);
    DrawRectangle(180, 395, 350,45, colors[RED]);
    DrawRectangle(180, 345, 350,45, colors[RED]);
    }
    

    DrawString( 200, 500,hnames[0], colors[MISTY_ROSE]);
    DrawString( 200, 450, (hnames[1]), colors[MISTY_ROSE]);
    DrawString( 200, 400, (hnames[2]), colors[MISTY_ROSE]);
    DrawString( 200, 350, (hnames[3]), colors[MISTY_ROSE]);

    DrawString( 350, 500, to_string(hscores[0]), colors[MISTY_ROSE]);
    DrawString( 350, 450, to_string(hscores[1]), colors[MISTY_ROSE]);
    DrawString( 350, 400, to_string(hscores[2]), colors[MISTY_ROSE]);
    DrawString( 350, 350, to_string(hscores[3]), colors[MISTY_ROSE]);
    DrawRectangle(345, 195, 150,40, colors[RED]);
    DrawString( 350, 200,"BACK <---", colors[MISTY_ROSE]);
    
}


void displaysavedgames(){
highscores();
highscore1=true;
dhighscore();


}



};
