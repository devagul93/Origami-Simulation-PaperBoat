//  main.cpp
//  vertex arrays
//  Created by devansh_himanshu on 01/05/15.
//  Copyright (c) 2015 pesit_bangalore_south_campus. All rights reserved.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

int displayFrontScreen = 1;
int idlestateangle =0;
int idlestate1 = 0, idlestate2 = 0, idlestate3 = 0;
int rotateonce =0;
int stage3_mode =0;
static int line_mid = 0, line_perp=0, line_perp1 = 0, turn1 = 0, turn2 =0;
float z= 0, x1 = 2.828, x2 = -2.828;
int j, depth = 0;
double lookatangle = 0;
int stage =1;
int state1 = 0, state2 = 0, state3= 0;
float valy = -2, valz = 0;
float transvalx = 0, transvaly = 2;
int xanglecount = 0;
int xangle =0;
int world_angles[] = {0,0,0};
int world_angles_true[] = {0,0,0};

float computeZ(float y){
    float temp = 4 - y*y;
    
    float z = sqrtf(temp);
    return z;
}

void triangle1_Stage3(){
    
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(-2, 0, 0);
    glVertex3f(0, 2, 0);
    glEnd();
    
}

void traingle2_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 2, 0);
    glVertex3f(2, 0, 0);
    
    glEnd();
    
}

void traingle3_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(0, valy, valz);
    glVertex3f(0, 0, 0);
    glEnd();
    
}

void traingle4_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, valy, valz);
    glVertex3f(-2, 0, 0);
    glVertex3f(0, 0, 0);
    glEnd();
}

void coneTriangleOne_Stage3(){
    
    glBegin(GL_TRIANGLES);
    glVertex3f(-2, 0, 0);   
    glVertex3f(-transvalx, transvaly, 0);
    glVertex3f(0, valy, valz);
    glEnd();    
}

void coneTriangleTwo_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(transvalx, transvaly, 0);
    glVertex3f(0, valy, valz);
    glEnd();
}

void conetraingaleThree_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(-2, 0, 0);    
    glVertex3f(-transvalx, transvaly, 0);
    glVertex3f(0, valy, -valz);
    glEnd();
}

void conetraingleFour_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(transvalx, transvaly, 0);
    glVertex3f(0, valy, -valz);
    glEnd();
}

void coneTriangle1()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, -2, z);
    glVertex3f(x2, -2,0);
    glVertex3f(0, 0,0);
    glEnd();
}

void coneTriangle2()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, -2, 0);
    glVertex3f(0, -2, z);
    glVertex3f(0, 0, 0);
    glEnd();
}

void conetraingale3()
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, -2, -z);
    glVertex3f(x2, -2,0);
    glVertex3f(0, 0,0);
    glEnd();
    glPopMatrix();
    
}

void conetraingle4()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, -2, 0);
    glVertex3f(0, -2, -z);
    glVertex3f(0, 0, 0);
    glEnd();
}

void drawtraingleone()
{
    if (depth ==1) {
        glColor3ub(63, 81, 181);
        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0, 0,-2);
        glVertex3f(-2, 0,0);
        glVertex3f(-2, 2,0);
        glEnd();
        glPopMatrix();
        
    }else{
    glColor3ub(63, 81, 181);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0, 0,0);
    glVertex3f(-2, 0,0);
    glVertex3f(-2, 2,0);
    glEnd();
    glPopMatrix();    
    }
}

void drawtriangletwo()
{
    if (depth ==1) {
        glColor3ub(86, 119, 252);
        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0, 0,2);
        glVertex3f(-2, 2,0);
        glVertex3f(0, 2,0);
        glEnd();
        glPopMatrix();
    }else{
    glColor3ub(86, 119, 252);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0, 0,0);
    glVertex3f(-2, 2,0);
    glVertex3f(0, 2,0);
    glEnd();
    glPopMatrix();
    }
}

void drawtrianglethree()
{
    if (depth ==1) {
        glColor3ub(0, 188, 212);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0,-2);
        glVertex3f(0, 2,0);
        glVertex3f(2, 2,0);
        glEnd();
        glPopMatrix();
    }
    glColor3ub(0, 188, 212);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0,0);
    glVertex3f(0, 2,0);
    glVertex3f(2, 2,0);
    glEnd();
    glPopMatrix();
}

void drawtrianglefour()
{
    if (depth ==1) {
        glColor3ub(3, 169, 15);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0,-2);
        glVertex3f(2, 2,0);
        glVertex3f(2, 0,0);
        glEnd();
        glPopMatrix();
    }
    glColor3ub(3, 169, 15);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0,0);
    glVertex3f(2, 2,0);
    glVertex3f(2, 0,0);
    glEnd();
    glPopMatrix();
}

void drawsquareone(int flag)
{
    if (flag ==2) {
        glPushMatrix();
        drawtraingleone();
        glPushMatrix();
        glRotatef(turn1, -1, 1, 0);
        drawtriangletwo();
        glPopMatrix();
        glPopMatrix();
    }
    else{
    glPushMatrix();
    drawtraingleone();
    drawtriangletwo();
    glPopMatrix();
    }
}

void drawsquaretwo(int flag)
{
    if (flag ==1) {
        glPushMatrix();
        glPushMatrix();
        glRotatef(turn1, 1, 1, 0);
        drawtrianglethree();
        glPopMatrix();
        drawtrianglefour();
        glPopMatrix();

    }
    else{    
        glPushMatrix();
        drawtrianglethree();
        drawtrianglefour();
        glPopMatrix();
    }
    
}

void drawrectangletop(int flag)
{
    if (flag ==1) {
        glPushMatrix();
        glPushMatrix();
        glRotatef(turn1, 1, 1, 0);
        drawsquareone(0);
        glPopMatrix();
        drawsquaretwo(1);
        glPopMatrix();
    }
    else if(flag == 2){
        glPushMatrix();
        drawsquareone(2);
        glPushMatrix();
        glRotatef(turn1, -1, 1, 0);
        drawsquaretwo(0);
        glPopMatrix();
        glPopMatrix();

    }
    else{
    glPushMatrix();
    drawsquareone(0);
        glPushMatrix();
    drawsquaretwo(0);
        glPopMatrix();
    glPopMatrix();
    }
}

void drawrectanglebottom(int flag)
{
    if (flag ==2) {
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(0);
        glTranslated(4, 0, 0);
        drawsquareone(2);
        glPopMatrix();
    }
    else if (flag ==1) {
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(1);
        glTranslated(4, 0, 0);
        drawsquareone(0);
        glPopMatrix();
    }
    else{
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(0);
        glTranslated(4, 0, 0);
        drawsquareone(0);
        glPopMatrix();
    }
}

int i;

void displaytext(int x, int y,char const* s)
{
    int len;
    glRasterPos2d(x,y);
    len=strlen(s);
    for(i=0;i<len;i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
    glFlush();
    
}

void secondInit()
{
    glClearColor(0, 1, 0, 0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, 1, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -15);
}

void init()
{
    glClearColor(0, 1, 0, 0);
    glShadeModel(GL_SMOOTH);
    gluOrtho2D(0,100,0,100);
}

void message()
{
    glColor3f(0.0,0.0,0.0);
    displaytext(38,65,"Simulation of a Paper Boat");
}

void displayFirstScreen()
{    
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    displaytext(40,90,"COMPUTER GRAPHICS PROJECT");
    displaytext(40,80,"ORIGAMI 3D SIMULATION");
    message();
    glColor3f(1.0,1.0,1.0);
    displaytext(4,35,"DEVANSH GULHANE");
    displaytext(4,32,"1PE12CS045");
    displaytext(4,25,"HIMANSHU BANSAL");
    displaytext(4,22,"1PE12CS058");
    glColor3f(1.0,1.0,1.0);
    displaytext(4,15,"Press 'z' to move towards the Simulation");
    glutSwapBuffers();
    glPopMatrix();    
}

void displayStage1(){
    glPushMatrix();//origin at 0,0 at this point;first push; make changes and pop returns here
    if (turn2 ==1) {
        glRotatef(45, 0, 0, 1);
    }
    glPushMatrix();//push for rotate about xaxis;
    glRotatef(line_perp, 1, 0, 0);
    //top-left quadrant
    glPushMatrix();//push to draw the topleft;context = rotateabout x
    glTranslated(-2, 2, 0);
    drawrectangletop(state3);
    glTranslated(0, -2, 0);
    drawrectanglebottom(state3);
    //end
    glPopMatrix();//translation back to rotation about x
    glPopMatrix();//backto origin;
    //bottom-left quadrant
    glPushMatrix();//push to bottom -left
    glTranslated(-2, -2, 0);
    glRotatef(180, 0, 0, 1);
    glPushMatrix();
    drawrectangletop(2);
    glTranslated(0, -2, 0);
    drawrectanglebottom(2);
    //end
    glPopMatrix();//back to origin
    glPopMatrix();
    glPushMatrix();//push to change state for rotation ;all the stuff inside this context will by rotated by y =0.
    glRotatef(line_mid, 0, 1, 0);//rotate the entire right side
    glPushMatrix();//push to add rotate about x
    glRotatef(line_perp, 1, 0, 0);//rotation about x
    glPushMatrix();//current context, rotate; push to topright
    //top-right quadrant
    glTranslated(2, 2, 0);
    drawrectangletop(2);
    glTranslated(0, -2, 0);
    drawrectanglebottom(2);
    //end
    glPopMatrix();//back to rotation about x
    glPopMatrix();//back to roaton right
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslated(-4, 4, 0);
    //bottom-right quadrant
    glPushMatrix();//rotate, add translaton for bottom quad
    glTranslated(2, -2, 0);
    drawrectangletop(1);
    glTranslated(0, -2, 0);
    drawrectanglebottom(1);
    //end
    glPopMatrix();//return to rotate
    glPopMatrix();
    
    glPopMatrix();//rotate context over;context back t origin
    glPopMatrix();//extra context buffer    
}

void displayStage2()
{
    glPushMatrix();
    glColor3ub(86, 119, 252);
    coneTriangle1();
    coneTriangle2();
    coneTriangle1();
    coneTriangle2();
    conetraingale3();
    conetraingle4();
    conetraingale3();
    conetraingle4();
    glPopMatrix();
}

void displayStage3()
{
    if (stage3_mode == 1) {
    }
    if (!rotateonce) {
    }
    
    glPushMatrix();
    triangle1_Stage3();
    traingle2_Stage3();
    glPushMatrix();
    glRotated(180, 0, 1, 0);
    glColor3ub(86, 119, 252);
    traingle3_Stage3();
    traingle4_Stage3();
    glPopMatrix();
    glColor3f(1, 1, 1);
    traingle3_Stage3();
    traingle4_Stage3();
    glColor3ub(86, 119, 252);
    coneTriangleOne_Stage3();
    coneTriangleTwo_Stage3();
    conetraingaleThree_Stage3();
    conetraingleFour_Stage3();
    glPopMatrix();    
}

void rotateWorld(int mode)
{
    if (mode ==1) {
        glRotatef(world_angles[0], world_angles_true[0], 0, 0);
        glRotatef(world_angles[1], 0, world_angles_true[1], 0);
        glRotatef(world_angles[2], 0, 0, world_angles_true[2]);
    }
    
}

void idle(void){
    if (idlestate1) {
        
    }else if (idlestate2){
        
    }else if (idlestate3){
        
    }  
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_LINE);
    glColor3f(1.0, 1.0, 1.0);
    //if condition for the first screen
    if (displayFrontScreen) {
        // do something
        displayFirstScreen();
    }
    else
    {
        if(stage3_mode == 1)
        {
            rotateWorld(stage3_mode);            
        }
        if (stage == 1) {
            displayStage1();
        }else if (stage ==2){
            displayStage2();
        }else if (stage == 3){
            displayStage3();
        }
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2f(0, 0);
        glEnd();   
        glutSwapBuffers();
    }    
}

void reshape(int w, int h)
{
    glViewport(0, 0, GLsizei(w), GLsizei(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -15);
}

void keyboard(unsigned char key, int x, int y)
{
    if (stage == 1) {
        stage3_mode = 0;
        //to-do: all the stage one keyboard conditions go here
        switch (key) {
            case 'd':
                line_mid = (line_mid + 3) % 180;
                if (line_mid >170) {
                    state1 = 1;
                }
                if (state1 &&state2) {
                    state3 = 1;
                }
                glutPostRedisplay();
                break;
                
            case 'D':line_mid = (line_mid - 10) % 180;
                glutPostRedisplay();
                break;
            case 'p':
                line_perp = (line_perp + 3) % 180;
                line_perp1 = (line_perp1 - 3) % 180;
                if (line_perp >170) {
                    state2 = 1;
                }
                if (state1 &&state2) {
                    state3 = 1;
                }
                glutPostRedisplay();
                break;
                
            case 'P':line_perp = (line_perp - 10) % 180;
                line_perp1 = (line_perp1 + 3) % 180;
                glutPostRedisplay();
                break;
            default:
                break;
        }
        if (state3 > 0)
        {
            switch (key)
            {
                case 'y': turn1 = (turn1 + 5) % 180;
                    if (turn1>170) {                        
                        //change from one stage to another
                        stage =2;
                        idlestate2 = 1;
                        
                    }
                    glutPostRedisplay();
                    break;
                    
                case 'Y': turn1 = (turn1 -5)%360;
                    glutPostRedisplay();
                    break;
                default:
                    break;
            }
        }
    }
    else if (stage == 2){
        stage3_mode = 0;
        if (x1>0) {
            
            switch (key) {
                case 'd': z = z + 0.2;
                    x1 = x1 - 0.2;
                    x2 = x2 + 0.2;
                    glutPostRedisplay();
                    break;
                    
                case 'D':line_mid = (line_mid - 10) % 180;
                    glutPostRedisplay();
                    break;
                case 'p':
                    line_perp = (line_perp + 3) % 180;
                    line_perp1 = (line_perp1 - 3) % 180;
                    if (line_perp >170) {
                        state2 = 1;
                    }
                    if (state1 &&state2) {
                        state3 = 1;
                    }
                    glutPostRedisplay();
                    break;
                    
                case 'P':line_perp = (line_perp - 10) % 180;
                    line_perp1 = (line_perp1 + 3) % 180;
                    glutPostRedisplay();
                    break;
                default:
                    break;
            }
            
        }
        else if (x1 <= 0){
            
            if (key == 'p') {
                if(lookatangle<5){
                    lookatangle = lookatangle + .4;
                    stage =3;
                    glutPostRedisplay();
                    
                }            
            }
        }
        if (state3 > 0)
        {
            switch (key)
            {
                case 'y': turn1 = (turn1 + 5) % 180;
                    if (turn1>170) {
                        turn2 = 1;
                    }
                    glutPostRedisplay();
                    break;
                    
                case 'Y': turn1 = (turn1 -5)%360;
                    glutPostRedisplay();
                    break;
                default:
                    break;
            }
        }
    }
    else if (stage == 3){
        
        stage3_mode = 0;
        switch (key) {
            case 'd':
                
                xanglecount+= 2;
                xangle = xanglecount % 90;
                valy +=.2;
                valz = computeZ(valy);
                transvalx += .2;
                transvaly+= .007;
                
                glutPostRedisplay();
                break;
                
            default:
                break;
        }
    
    }
    
    switch (key) {
                    
            case 'i':
                        stage3_mode = 1;
                world_angles_true[0] = 1;
                world_angles[0] += 1;
                world_angles[0] % 360;
                glutPostRedisplay();
                break;
            case 'j':
                        stage3_mode = 1;
                world_angles_true[1] = 1;
                world_angles[1] += 1;
                world_angles[1] % 360;
                glutPostRedisplay();
                break;
            case 'k':
                        stage3_mode = 1;
                world_angles_true[2] = 1;
                world_angles[2] += 1;
                world_angles[2] % 360;
                glutPostRedisplay();
                break;
            case 'z':
            displayFrontScreen = 0;
            secondInit();
            glutPostRedisplay();
            glFlush();
            break;
            
                default: stage3_mode = 0;
                break;   
    }    
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Origami Simulation");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();    
return 0;
}