//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
//#include"Box.h"
#include"Outline.h"
#include<time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
void movingright();
void movingleft();
void movingup();
void movingdown();
outline s;
void MouseClicked(int button, int state, int x, int y);
void MouseMoved(int, int);

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)


 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */



void disp(){


for(int i=0;i<s.getlen();i++){

//DrawSquare(  , s.boxes[i].gety() ,s.boxes[i].gets(),colors[RED]);

DrawRectangle(s.boxes[i].getx(), s.boxes[i].gety(), s.getlenx(),s.getleny(), colors[s.boxes[i].getstring()]);
}
if(s.getmoving()==true && s.getright()==true){
glutPostRedisplay();
glutIdleFunc(movingright);
}else 
if(s.getmoving()==true && s.getleft()==true){
glutPostRedisplay();
glutIdleFunc(movingleft);
}
else 
if(s.getmoving()==true&& s.getup()==true){
glutPostRedisplay();
glutIdleFunc(movingup);
}else 
if(s.getmoving()==true && s.getdown()==true){
glutPostRedisplay();
glutIdleFunc(movingdown);
}

glutPostRedisplay();
}

void GameDisplay()/**/{


//BOX s(20,20,100);

//static int i=0;
//i++;

//cout<<"i is = "<<i<<endl;
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
string score="SCORE = ";
score=score+to_string(s.user.getscore());
 if(s.Menu.getinmenu()==true && s.Menu.getsubmenu()==false){
s.Menu.settimetrial(false);
s.Menu.setnormal(false);
s.Menu.display();
glutPassiveMotionFunc(MouseMoved);
s.Menu.settimetrial(false);
s.Menu.setnormal(false);
}else if(s.Menu.getsubmenu()==true &&  ((s.Menu.getnormal()==false) || (s.Menu.gettimetrial()==false))){
	cout<<"dubmenu";
	static bool once=false;
	if(once==false){
		s.Menu.setnormal(false);
		s.Menu.settimetrial(false);
		once=true;
	}
	if(((s.Menu.getnormal()==true) || (s.Menu.gettimetrial()==true))){
s.Menu.setsubmenu(false);
	}
	s.Menu.dubmenu();
glutPassiveMotionFunc(MouseMoved);
}else if(s.Menu.getname()==true){
s.Menu.namemenu();
DrawString( 340, 480, s.user.getusername(), colors[BLACK]);
}else
if((s.Menu.getnormal()==true || (s.Menu.gettimetrial()==true)) &&  s.Menu.getname()==false && s.Menu.getexit()==false && s.Menu.getsaved()==false){
	if(s.Menu.gettimetrial()==false){
	s.user.leveldraw();
	}else{
		DrawString( 70, 750, "Time Elapsed = "+to_string(s.Menu.getcount()), colors[MISTY_ROSE]);
		DrawString( 350, 750, "Total Time = "+to_string(s.Menu.gettime()), colors[MISTY_ROSE]);
	}
	if(s.user.getlevel()>s.user.gettlevel()){
    s.user.settlevel(s.user.getlevel());
    s.makeoutline(s.user.getboxes());
}
disp();
DrawString( 700, 800, s.user.getusername(), colors[MISTY_ROSE]);
   DrawString( 700, 700, "LEVEL : "+to_string(s.user.getlevel()), colors[MISTY_ROSE]);
DrawString( 700, 750, score, colors[MISTY_ROSE]);
s.displayout();

}else if(s.Menu.getexit()==true){
s.Menu.displayexit();
}else if(s.user.getlshow()==true){
	s.user.leveld();
	s.displayout();
}else if(s.Menu.sethighscore()==true){
	s.Menu.dhighscore();
}else if(s.Menu.getsaved()==true){
	s.Menu.displaysavedgames();
}else if(s.Menu.gethelp()==true){
	s.Menu.helpd();
}




	//Fire Gun
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)


	
	DrawLine( 55 , 5 ,  55 , 860 , 5 , colors[MISTY_ROSE] );
	DrawLine( s.getii(), 5 ,  s.getii() , 860 , 5 , colors[MISTY_ROSE] );	
//DrawLine( 590, 5 ,  590 , 860 , 5 , colors[MISTY_ROSE] );	
	DrawLine( 55 , 840 ,  s.getii() , 840 , 5 , colors[MISTY_ROSE] );


	DrawLine( 55 , 5 ,  s.getii() , 5 , 5 , colors[MISTY_ROSE] );


	//DrawCircle(50,670,10,colors[RED]);

	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	glFlush();
	glutSwapBuffers(); // do not modify this line..

}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */



void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	int k=key;
cout<<"key is = "<<k<<endl;
	if(s.Menu.getname()==true){
		 char name;
		name=key;
		
		if((name>=65 && name<=90)    ||  (name>=97 && name<=122) || name==32 || name==8){
			s.user.setusername(name);
		}


		glutPostRedisplay();
	}

	if (key == 27 && s.Menu.getinmenu()==false && s.Menu.getsubmenu()==false) {
		s.Menu.setexit(true);
	}

	if (key == 'b' || key == 'B' && s.Menu.getname()==false) //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
if(s.Menu.gettimetrial()==true && s.Menu.getexit()==false){
	if(s.Menu.getcount()>=s.Menu.gettime()){
		s.Menu.setsubmenu(true);
		s.Menu.setinmenu(false);
		s.Menu.setname(false);
		s.Menu.settimetrial(false);
	}
	s.Menu.setcount(1);
}
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void drawl(int i, int x , int y, int px, int py){
cout<<"here"<<endl;


DrawLine( px, py ,  x , y , 10 , colors[MISTY_ROSE] );
glutPostRedisplay();
}

void MousePressedAndMoved(int x, int y) {

if(s.getmoving()==true){

	if(((x) >= (s.boxes[s.getti()].getx()+(s.getlenx()/1.5)) )   &&  ((840-y) >= s.boxes[s.getti()].gety()-s.getleny()  &&  (840-y) <= s.boxes[s.getti()].gety()+s.getleny()) ){
//glutIdleFunc(movingright);
s.setonce(true);
s.setright(true);
s.setleft(false);
s.setup(false);
s.setdown(false);
cout<<"Herere"<<endl;
}

	if(((x) >= (s.boxes[s.getti()].getx())  &&  x<=(s.boxes[s.getti()].getx()+(s.getlenx()/2)) )   &&  ((840-y) >= s.boxes[s.getti()].gety()-s.getleny()  &&  (840-y) <= s.boxes[s.getti()].gety()+s.getleny()) ){
//glutIdleFunc(movingright);
s.setonce(true);;
s.setright(false);
s.setleft(true);
s.setup(false);
s.setdown(false);
cout<<"in left"<<endl;
}

	if(((x) >= (s.boxes[s.getti()].getx())  &&  x<=(s.boxes[s.getti()].getx()+(s.getlenx())) )   &&  ((840-y) >= s.boxes[s.getti()].gety()+(s.getleny()/2)&& (840-y) <= s.boxes[s.getti()].gety()+(s.getlenx())) ){
//glutIdleFunc(movingright);
s.setright(false);
s.setleft(false);
s.setup(true);
s.setdown(false);
cout<<"in up"<<endl;
}


	if(((x) >= (s.boxes[s.getti()].getx())  &&  x<=(s.boxes[s.getti()].getx()+(s.getlenx())) )   &&  ((840-y) <= s.boxes[s.getti()].gety()+(s.getleny()/2)) &&  ((840-y) <= s.boxes[s.getti()].gety()+(0))   ){
//glutIdleFunc(movingright);
s.setonce(true);;
s.setright(false);
s.setleft(false);
s.setup(false);
s.setdown(true);
cout<<"in down"<<endl;
}


}
	cout << x << " " <<y << endl;


glutSwapBuffers();

	glutPostRedisplay();
}


void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
if((x>=350 && x<=430)&&(y>=266 && y<=294)){
s.Menu.sethover(5,true);
}else
if((x>=350 && x<=430)&&(y>=500 && y<=600)){
s.Menu.sethover(4,true);
}else
if((x>=350 && x<=430)&&(y>=320 && y<=340)){
s.Menu.sethover(0,true);
}else if((x>=350 && x<=430)&&(y>=370 && y<=390)){
s.Menu.sethover(1,true);
}else if((x>=350 && x<=430)&&(y>=415 && y<=450)){
s.Menu.sethover(2,true);
}else if((x>=350 && x<=430)&&(y>=470 && y<=495)){
s.Menu.sethover(3,true);
}else{
for(int i=0;i<6;i++){
s.Menu.sethover(i,false);
}

}



//glutSwapBuffers();
	glutPostRedisplay();

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *s
 * */


void movingdown(){

if(s.getonce()){
//cout<<"len x is = "<<s.boxe<<endl;


if((s.boxes[s.getti()].gety()  !=  s.boxes1[s.getti()-(s.getix())].gety()) && s.getmoving()==true && s.getdown()==true){
		s.boxes[s.getti()-(s.getix())].goup(1);

		s.boxes[s.getti()].godown(1);
//cout<<"tbox x is = "<<s.boxes1[s.getti()+1].getx()<<endl;
cout<<"going down"<<endl;
disp();
		
			
}else
 {
s.setmoving(false);
s.setdone(true);
//s.checkboxesleft();
s.setonce(false);
if(s.getdown()==true){
s.godown(s.getti());
//s.getti()-=s.getix();
s.setti(s.getti()-s.getix());
s.checkboxeshorizontal();
;
s.check();
//}
s.setdown(false);
}

if(s.getright()==true){
s.goright(s.getti());
s.setright(false);
}

}
}




}



void movingup(){

if(s.getonce()){
//cout<<"len x is = "<<s.boxe<<endl;


if((s.boxes[s.getti()].gety()  !=  s.boxes1[s.getti()+(s.getix())].gety()) && s.getmoving()==true && s.getup()==true){
		s.boxes[s.getti()+(s.getix())].godown(1);

		s.boxes[s.getti()].goup(1);
//cout<<"tbox x is = "<<s.boxes1[s.getti()+1].getx()<<endl;
//cout<<"box is = "<<s.boxes[s.getti()].gety()<<endl;
//cout<<"t box is = "<<s.boxes[s.getti()+s.getix()].gety()<<endl;
disp();
		
			
}else
 {
s.setmoving(false);
s.setdone(true);
//s.checkboxesleft();
s.setonce(false);
if(s.getup()==true){
s.goup(s.getti());
s.setti(s.getti()+s.getix());
//s.getti()+=s.getix();
s.checkboxeshorizontal();
;
s.check();
s.setup(false);
}

if(s.getright()==true){
s.goright(s.getti());
s.setright(false);
}

}
}




}

void movingleft(){
if(s.getonce()){
cout<<"len x is = "<<s.getix()<<endl;


if((s.boxes[s.getti()].getx()  !=  s.boxes1[s.getti()-1].getx()) && s.getmoving()==true && s.getleft()==true){
		s.boxes[s.getti()-1].goright(1);

		s.boxes[s.getti()].goleft(1);
//cout<<"tbox x is = "<<s.boxes1[s.getti()+1].getx()<<endl;
//cout<<"box is = "<<s.boxes[s.getti()].getx()<<endl;
disp();
		
	
		
}else
 {
s.setmoving(false);
s.setdone(true);
s.setonce(false);


if(s.getleft()==true){
s.goleft(s.getti());
s.setti(s.getti()-1);
//s.getti()-=1;
s.checkboxeshorizontal();
;
s.check();
s.setleft(false);
}

if(s.getright()==true){
s.goright(s.getti());
s.setright(false);
}
/*if(s.user.getscore()>100){
s.user.setboxes(56);
s.makeoutline(s.user.getboxes());
}*/

}
}





}

void movingright(){
if(s.getonce()){



if((s.boxes[s.getti()].getx()  !=  s.boxes1[s.getti()+1].getx()) && s.getmoving()==true && s.getright()==true){
		s.boxes[s.getti()].goright(1);

		s.boxes[s.getti()+1].goleft(1);
//cout<<"tbox x is = "<<s.boxes1[s.getti()+1].getx()<<endl;
//cout<<"box is = "<<s.boxes[s.getti()].getx()<<endl;
disp();
			
		
}else
 {
s.setmoving(false);
s.setdone(true);

s.setonce(false);
if(s.getleft()==true){
s.goleft(s.getti());

s.setleft(false);
}

if(s.getright()==true){
s.goright(s.getti());
s.setti(s.getti()+1);
//s.getti()+=1;
s.checkboxeshorizontal();
;
s.check();
//s.getti()-=2;
//s.checkboxeshorizontal();
s.setright(false);
}


}
}
}


void MouseClicked(int button, int state, int x, int y) {

if( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) &&(s.Menu.getnormal()==true || (s.Menu.gettimetrial()==true)) &&  s.Menu.getname()==false && s.Menu.getexit()==false && s.Menu.getsaved()==false){
if(x>=792 && x<=887  &&  y>=703 && y<= 817){
s.Menu.setexit(true);
}else if(x>=911 && x<=989  &&  y>=703 && y<= 817){ 
	if(s.user.gethint()>=0 &&  s.user.gethint()<=3){
	s.makeoutline(s.user.getboxes());
	s.user.sethint(1);
	}
}
}


	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.gethelp()==true){
if(s.Menu.gethover(4)==true){
	s.Menu.sethelp(false);
	s.Menu.setinmenu(true);
	for(int i=0;i<6;i++){
		s.Menu.sethover(i,false);
	}
}

	}
if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.getsaved()==true){
if(x>=178 && x<=530  &&  y>=303 && y<= 346){
s.getfile(s.Menu.gethname(0));
}else
if(x>=178 && x<=530  &&  y>=353 && y<= 400){
s.getfile(s.Menu.gethname(1));
}else
if(x>=178 && x<=530  &&  y>=403 && y<= 448){
s.getfile(s.Menu.gethname(2));
}else
if(x>=178 && x<=530  &&  y>=451 && y<=497){
s.getfile(s.Menu.gethname(3));
}


}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.sethighscore()==true){
      if((x>=346 &&  x<=445)  &&  (y>=606 &&  y<=644)){
		s.Menu.setinmenu(true);
		s.Menu.sethighscore(false);
		s.Menu.setsaved(false);
	  }
	}

if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.getinmenu()==true){
if(s.Menu.gethover(5)==true){
s.Menu.setsaved(true);
s.Menu.setinmenu(false);
}else
if(s.Menu.gethover(0)==true){
s.Menu.setinmenu(false);
s.Menu.settimetrial(false);
s.Menu.setnormal(false);
s.Menu.setsubmenu(true);
s.Menu.setname(true);
for(int i=0;i<6;i++){
	s.Menu.sethover(i,false);
}
}else if(s.Menu.gethover(1)==true){
	s.Menu.setinmenu(false);
s.Menu.settimetrial(false);
s.Menu.setnormal(false);
s.user.setlshow(true);
}else if(s.Menu.gethover(2)==true){
	s.Menu.highscores();
s.Menu.sethighscore(true);
s.Menu.setinmenu(false);
}else if(s.Menu.gethover(3)==true){
	cout<<"Here=========------------"<<endl;
s.Menu.sethelp(true);
s.Menu.setinmenu(false);

}else if(s.Menu.gethover(4)==true){
exit(1);
}

}
if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.getsubmenu()==true &&s.Menu.getinmenu()==false ){

if(s.Menu.gethover(0)==true){
s.Menu.setnormal(true);
s.Menu.setname(true);
}else if(s.Menu.gethover(1)==true){
s.Menu.settimetrial(true);
s.Menu.setname(true);
}else if(s.Menu.gethover(2)==true){
s.Menu.setinmenu(true);
s.Menu.setsubmenu(false);
}


}
if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.getname()==true ){
	if((x>=158 && x<=369)  && (y>=375 && y<=419) ){
			s.Menu.setinmenu(true);
		s.Menu.setname(false);
		s.Menu.setnormal(false);
		s.Menu.settimetrial(false);
	}else if((x>=380 && x<=590)  && (y>=375 && y<=419) ){
		
		s.Menu.setname(false);
		
	}

}
if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.user.getlshow()==true){ 

if((x>=239 && x<=448)  && (y>=90 && y<=142) ){
s.user.setlshow(false);
s.Menu.setinmenu(true);
s.Menu.setsubmenu(false);
}
}

if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.Menu.getexit()==true ){
	if((x>=158 && x<=369)  && (y>=375 && y<=419) ){
		s.Menu.setexit(false);
	}else if((x>=380 && x<=590)  && (y>=375 && y<=419) ){
		s.savefile();
		exit(1);
		
	}else if((x>=338 && x<=550)  && (y>=434 && y<=482) ){
		s.Menu.setexit(false);
		s.Menu.setinmenu(true);
	}
}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && s.getmoving()==false && s.Menu.getinmenu()==false && s.Menu.getsubmenu()==false && s.Menu.sethighscore()==false && s.Menu.getname()==false && s.Menu.getsaved()==false) // dealing only with left button
			{
//cout<<"GDD"<<endl;
for(int i=0;i<s.getlen();i++){

if(((x) >= s.boxes[i].getx()-s.getlenx()  &&  (x) <= s.boxes[i].getx()+s.getlenx())   &&  ((840-y) >= s.boxes[i].gety()-s.getleny()  &&  (840-y) <= s.boxes[i].gety()+s.getleny()) ){

s.setti(i);
s.setdone(false);
s.setmoving(true);
cout<<"found it = "<<i<<endl;
state=0;
break;
}

}
cout<<"GLUT DOWN IS + "<<button<<"  state is = "<<state<<endl;

		//cout << x << " " << 840-y << endl;

	}
if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_UP)  &&  (s.getmoving()==true)){
if(s.getright()==false&&s.getleft()==false&&s.getup()==false&&s.getdown()==false){
	s.setmoving(false);
	s.setonce(false);
	s.setdone(true);
	//cout<<"colr is = "<<s.boxes[s.getti()].getstring()<<endl;
	//cout<<"FUCK OFF"<<endl;
}

}



 if ((button == GLUT_LEFT_BUTTON ) && (state == GLUT_UP)  &&  (s.getdone()==true))
		{	
	
if(s.getmoving()==false){
cout<<"It is false;"<<endl;
		s.setonce(false);
		//s.check();
//s.goright(s.getti());
}
			cout<<"Button up "<<endl;
			s.setti(-1);
		}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
int i=0;
s.makeoutline(s.user.getboxes());
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	cout<<"Here"<<endl;
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(idle); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	//glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);


//glutIdleFunc(MouseMoved);

	glutMouseFunc(MouseClicked);


//glutPassiveMotionFunc(MouseMoved); // Mouse

	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
