/*
*   Universidade Federal do Vale do São Francisco - Univasf
*   Colegiado de Engenharia de Computação
*   Orientador: Prof. Dr. Jorge Cavalcanti
*   Discentes: Elayne Lemos, elayne.l.lemos@gmail.com
*              Jônatas de Castro, jonatascastropassos@gmail.com
*   Implementação:
*   Este código parametriza figuras geométricas convexas regulares
*   Apenas utilizando os parametros Centro, Raio, Numero de lados e fase, é possivel descrever totalmente a figura
*   Os outros parâmetros definem os comportamentos gráficos como cor de preenchimento, cor de linha e espessura de linha
*
*   As funções mascaram a utilização do OpenGL para desenhar as figuras e implementam todas as informações necessárias para
*   determinar a colisão entre objetos
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
    GLfloat radius;     //Raio de Inscrição
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
/**Pode não ser vantajoso utilizar este método, já que a maior parte das figuras serão eliminadas pelo primeiro algoritmo, que é muito mais simples que este
    Todavia pode ser vantagem já que este não utiliza algoritmos com ponto flutuante, apenas comparações(mas ainda as faz com pontos flutuantes, retornando o mesmo problema)*/

GLint GEOcolisionVertexApotema(Geometry g, Coord c);

GLint GEOcolisionApotema(Geometry a,Geometry b);

GLint GEOcolision(Geometry a,Geometry b);

GLint GEOmultiColision(Geometry a,Geometry b[],GLint n);

#endif // GEOMETRY_H
