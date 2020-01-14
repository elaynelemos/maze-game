/*
*   Universidade Federal do Vale do S�o Francisco - Univasf
*   Colegiado de Engenharia de Computa��o
*   Orientador: Prof. Dr. Jorge Cavalcanti
*   Discentes: Elayne Lemos, elayne.l.lemos@gmail.com
*              J�natas de Castro, jonatascastropassos@gmail.com
*   Implementa��o:
*   Este c�digo parametriza figuras geom�tricas convexas regulares
*   Apenas utilizando os parametros Centro, Raio, Numero de lados e fase, � possivel descrever totalmente a figura
*   Os outros par�metros definem os comportamentos gr�ficos como cor de preenchimento, cor de linha e espessura de linha
*
*   As fun��es mascaram a utiliza��o do OpenGL para desenhar as figuras e implementam todas as informa��es necess�rias para
*   determinar a colis�o entre objetos
*/


#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "TADUtil.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tGeometry{
    Color *fill;        //Cor do preenchimento
    Color *stroke;      //Cor da linha
    GLfloat stroke_width; //Tamanho da linha
    Coord center;       //Centro
    GLfloat radius;     //Raio de Inscri��o
    GLint sides;        //Numero de lados
    GLint phase;      //Giro da forma partindo do eixo vertical
}Geometry;

Geometry GEOset();

Geometry * GEOnew();

Geometry GEOreset(Geometry geo);

void GEOdrop(Geometry *geo);

void GEOsetFill(Geometry *geo,Color color);

void GEOsetFillP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b);

void GEOsetStroke(Geometry *geo,Color color);

void GEOsetStrokeP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b);

void GEOsetCenter(Geometry *geo,Coord coord);

void GEOsetCenterP(Geometry *geo, GLfloat x,GLfloat y);

void GEOprint(Geometry geo);



void GEOprintSides(Geometry geo);

void GEOdraw(Geometry geo);

void GEOglVertex(Geometry geo);

GLfloat GEOcentralAngle(Geometry g);

GLfloat GEOapotema(Geometry g);

GLfloat GEOapotemaRel(Geometry g, GLfloat alfa);

GLfloat GEOxi(Geometry g, GLint i);

GLfloat GEOyi(Geometry g, GLint i);

Coord GEOvi(Geometry g, GLint i);

void GEOboundingRect(Coord rect[],Geometry g);

GLint GEOcutEdge(Geometry g, GLfloat angle);

GLint GEOalfaIn(Geometry g, GLfloat angle);

//Primeiro algoritmo de colisao
GLint GEOnotColisionCircle(Geometry a,Geometry b);

//Segundo algoritmo de colisao
GLint GEOnotColisionRect(Geometry a,Geometry b);
/**Pode n�o ser vantajoso utilizar este m�todo, j� que a maior parte das figuras ser�o eliminadas pelo primeiro algoritmo, que � muito mais simples que este
    Todavia pode ser vantagem j� que este n�o utiliza algoritmos com ponto flutuante, apenas compara��es(mas ainda as faz com pontos flutuantes, retornando o mesmo problema)*/

GLint GEOcolisionVertexApotema(Geometry g, Coord c);

GLint GEOcolisionApotema(Geometry a,Geometry b);

GLint GEOcolision(Geometry a,Geometry b);

GLint GEOmultiColision(Geometry a,Geometry b[],GLint n);

#endif // GEOMETRY_H
