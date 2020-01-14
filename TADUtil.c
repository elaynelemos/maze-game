/*
*   Universidade Federal do Vale do São Francisco - Univasf
*   Colegiado de Engenharia de Computação
*   Orientador: Prof. Dr. Jorge Cavalcanti
*   Discentes: Elayne Lemos, elayne.l.lemos@gmail.com
*              Jônatas de Castro, jonatascastropassos@gmail.com
*   Implementação:
*   Este código implementa duas estruturas básicas : Cores e Coordenadas
*   A ideia é mascarar algumas operações e simplificar a utilização dos recursos
*/

#ifndef TADUTIL_H
#define TADUTIL_H

#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <stdio.h>
#include <time.h>

void pause (float); //recebe um valor com ponto flutuante dado em segundos e faz o delay.

typedef struct tcolor{
    GLfloat r;
    GLfloat g;
    GLfloat b;
}Color;

typedef struct tcoord{
    GLfloat x;
    GLfloat y;
}Coord;

void COLORglClearColor(Color color);
void COLORglColor(Color color);
void COORDglVertex(Coord coord);
void COLORcopy(Color *color1, Color color2);
void COLORparse(Color *color, GLfloat r, GLfloat g,GLfloat b);
Color COLORset(GLfloat r, GLfloat g,GLfloat b);
void COORDcopy(Coord *coord1, Coord coord2);
Color COLORrandom();
GLfloat COORDdistance(Coord a, Coord b);
GLfloat COORDangle(Coord a, Coord b);
Color COLORpaleta(Color p, int i,int m,int s);
void COORDprint(Coord a);
void COLORprint(Color a);

void COLORglClearColor(Color color){
    glClearColor(color.r, color.g, color.b, 1.0f);
}

void COLORglColor(Color color){
    glColor3f(color.r, color.g, color.b);
}

void COORDglVertex(Coord coord){
    glVertex2f(coord.x,coord.y);
}

void COLORcopy(Color *color1, Color color2){
    if(color1){
        color1->r = color2.r;
        color1->g = color2.g;
        color1->b = color2.b;
    }
}

void COLORparse(Color *color, GLfloat r, GLfloat g,GLfloat b){
    color->r = r;
    color->g = g;
    color->b = b;
}

Color COLORset(GLfloat r, GLfloat g,GLfloat b){
    Color ret;
    ret.r = r;
    ret.g = g;
    ret.b = b;
    return ret;
}

void COORDcopy(Coord *coord1, Coord coord2){
    if(coord1){
        coord1->x = coord2.x;
        coord1->y = coord2.y;
    }
}

Color COLORrandom(){
    Color color;

    color.r = rand()%100/100.0f;
    color.g = rand()%100/100.0f;
    color.b = rand()%100/100.0f;

    return color;
}

GLfloat COORDdistance(Coord a, Coord b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

GLfloat COORDangle(Coord a, Coord b){
    GLfloat ret = M_PI_2;//90º
    if(a.y!=b.y){//Garantindo divisão por não nulo
        ret = atan((b.x-a.x)/(b.y-a.y));

        ret = ret<0             ?ret+M_PI:ret;//4º para 2º
        ret = b.x<a.x           ?ret+M_PI:ret;//1,2 para 3,4
        ret = ret==0&&b.y<a.y   ?ret+M_PI:ret;//180º


    }else if(b.x<a.x){
        ret += M_PI;//270º
    }
    return ret;
}

Color COLORpaleta(Color p, int i,int m,int s){
    Color ret;
    ret.r = s&4?p.r*(1-i/(m+1.0)):p.r;
    ret.g = s&2?p.g*(1-i/(m+1.0)):p.g;
    ret.b = s&1?p.b*(1-i/(m+1.0)):p.b;
    return ret;
}

void COORDprint(Coord a){
    printf("Coord [ %.1f x %.1f ]\n",a.x,a.y);
}

void COLORprint(Color a){
    printf("Color [ %.1f %.1f %.1f ]\n",a.r,a.g,a.b);
}

void pause (float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

   return;

}

#endif // TADUTIL_H
