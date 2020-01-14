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

Geometry * GEOnew();
Geometry GEOset();
Geometry GEOreset(Geometry geo);
void GEOdrop(Geometry *geo);

void GEOprint(Geometry geo);
void GEOsetCenterP(Geometry *geo, GLfloat x,GLfloat y);
void GEOsetCenter(Geometry *geo,Coord coord);
void GEOsetStrokeP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b);
void GEOsetStroke(Geometry *geo,Color color);
void GEOsetFillP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b);
void GEOsetFill(Geometry *geo,Color color);
void GEOglVertex(Geometry geo);
void GEOdraw(Geometry geo);
void GEOprintSides(Geometry geo);
GLfloat GEOapotema(Geometry g);
GLfloat GEOapotemaRel(Geometry g, GLfloat alfa);
GLfloat GEOcentralAngle(Geometry g);
GLfloat GEOxi(Geometry g, GLint i);
GLfloat GEOyi(Geometry g, GLint i);
void GEOboundingRect(Coord rect[],Geometry g);
GLint GEOcutEdge(Geometry g, GLfloat angle);
GLint GEOnotColisionCircle(Geometry a,Geometry b);
GLint GEOnotColisionRect(Geometry a,Geometry b);
GLint GEOcolisionApotema(Geometry a,Geometry b);
GLint GEOcolision(Geometry a,Geometry b);
GLint GEOcolision(Geometry a,Geometry b);
GLint GEOmultiColision(Geometry a,Geometry b[],GLint n);

Geometry GEOset(){
    Geometry geo;
    geo.fill = NULL;
    geo.stroke = NULL;
    geo.center.x = 0;
    geo.center.y = 0;
    geo.radius = 0;
    geo.sides = 3;
    geo.phase = 0;

    return geo;
}

Geometry * GEOnew(){
    Geometry * geo = (Geometry*)malloc(sizeof(Geometry));
    *geo = GEOset();
    return geo;
}

Geometry GEOreset(Geometry geo){
    free(geo.fill);
    free(geo.stroke);
    geo = GEOset();
    return geo;
}

void GEOdrop(Geometry *geo){
    GEOreset(*geo);
    free(geo);
}

void GEOsetFill(Geometry *geo,Color color){
    geo->fill = (Color *)malloc(sizeof(Color));
    COLORcopy(geo->fill,color);
}

void GEOsetFillP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b){
    geo->fill = (Color *)malloc(sizeof(Color));
    geo->fill->r = r;
    geo->fill->g = g;
    geo->fill->b = b;
}

void GEOsetStroke(Geometry *geo,Color color){
    geo->stroke = (Color *)malloc(sizeof(Color));
    COLORcopy(geo->stroke,color);
}

void GEOsetStrokeP(Geometry *geo, GLfloat r,GLfloat g,GLfloat b){
    geo->stroke = (Color *)malloc(sizeof(Color));
    geo->stroke->r = r;
    geo->stroke->g = g;
    geo->stroke->b = b;
}

void GEOsetCenter(Geometry *geo,Coord coord){
    COORDcopy(&(geo->center),coord);
}

void GEOsetCenterP(Geometry *geo, GLfloat x,GLfloat y){
    geo->center.x = x;
    geo->center.y = y;
}

void GEOprint(Geometry geo){
    printf("Geometry [ center: %.1f x %.1f , raio: %.1f , sides: %d , phase: %.1fº, fill: %s, stroke: %s]\n",
           geo.center.x, geo.center.y, geo.radius, geo.sides, geo.phase, geo.fill!=NULL?"Color":"none",geo.stroke!=NULL?"Color":"none");
}



void GEOprintSides(Geometry geo){
    int i;
    for(i=0;i<geo.sides;i++){
        printf("[ %5.1f x %5.1f ]\n",GEOxi(geo,i),GEOyi(geo,i));
    }
}

void GEOdraw(Geometry geo){
    if(geo.fill!= NULL){
        COLORglColor(*geo.fill);
        glBegin(GL_POLYGON);
            GEOglVertex(geo);
        glEnd();
    }
    if(geo.stroke!=NULL){
        int i;
        geo.radius-=geo.stroke_width/12;
        COLORglColor(*geo.stroke);
        glLineWidth(geo.stroke_width);
        glBegin(GL_LINE_LOOP);
            GEOglVertex(geo);
        glEnd();

        /*glLineWidth(geo.stroke_width/2);
        glBegin(GL_LINES);
            for(i=0;i<geo.sides;i++){
                glVertex2f(geo.center.x + geo.radius*sin(i*M_PI*2/geo.sides + geo.phase*M_PI/180 + M_PI/geo.sides),
                           geo.center.y + geo.radius*cos(i*M_PI*2/geo.sides +geo.phase*M_PI/180 + M_PI/geo.sides));
                COORDglVertex(geo.center);
            }
        glEnd();*/

        geo.radius+=geo.stroke_width/12;
    }
}

void GEOglVertex(Geometry geo){
    int i;
    for(i=0;i<geo.sides;i++){
            glVertex2f(GEOxi(geo,i),GEOyi(geo,i));
    }
}

GLfloat GEOcentralAngle(Geometry g){
    return 2*M_PI/g.sides;
}

GLfloat GEOapotema(Geometry g){
    return g.radius*cos(M_PI/g.sides);
}

GLfloat GEOapotemaRel(Geometry g, GLfloat alfa){
    alfa *= M_PI/180;
    if(alfa>=0 && alfa <= GEOcentralAngle(g)/2)
        return GEOapotema(g)/cos(alfa);
    else{
        printf("Alfa fora do intervalo\n");
        return 0;
    }
}

GLfloat GEOxi(Geometry g, GLint i){
    return g.center.x + g.radius * sin((i*2.0f/g.sides + g.phase/180.0f)*M_PI);
}

GLfloat GEOyi(Geometry g, GLint i){
    return g.center.y + g.radius * cos((i*2.0f/g.sides + g.phase/180.0f)*M_PI);
}

Coord GEOvi(Geometry g, GLint i){
    Coord ret;
    ret.x = GEOxi(g,i);
    ret.y = GEOyi(g,i);
    return ret;
}

void GEOboundingRect(Coord rect[],Geometry g){
    GLint i;
    Coord temp;
    rect[0] = g.center;
    rect[1] = g.center;
    for(i=0;i<g.sides;i++){
        temp.x = GEOxi(g,i);
        temp.y = GEOyi(g,i);
        rect[1].x = temp.x > rect[1].x ? temp.x : rect[1].x;
        rect[0].x = temp.x < rect[0].x ? temp.x : rect[0].x;
        rect[1].y = temp.y > rect[1].y ? temp.y : rect[1].y;
        rect[0].y = temp.y < rect[0].y ? temp.y : rect[0].y;
    }
}

GLint GEOcutEdge(Geometry g, GLfloat angle){
    GLint a = (int)(angle*180/M_PI);

    //Normalize angle
    a = a%360;
    //Normalize phase
    g.phase = g.phase%360;

    //Compensando phase
    a-=g.phase;
    a = a<0?a+360:a;

    return a/(360/g.sides);
}

GLint GEOalfaIn(Geometry g, GLfloat angle){
    GLint a = (int)(angle*180/M_PI);

    //Normalize angle
    a = a%360;
    //Normalize phase
    g.phase = g.phase%360;

    //Compensando phase
    a-=g.phase;
    a = a<0?a+360:a;

    if((a/(180/g.sides))%2)
        return a%(180/g.sides);
    else
        return 180/g.sides - a%(180/g.sides);
}


//Primeiro algoritmo de colisao
GLint GEOnotColisionCircle(Geometry a,Geometry b){
    return COORDdistance(a.center,b.center)>(a.radius+b.radius);
}

//Segundo algoritmo de colisao
GLint GEOnotColisionRect(Geometry a,Geometry b){
    Coord ra[2],rb[2];
    GEOboundingRect(ra,a);
    GEOboundingRect(rb,b);
    return !(
             ra[0].x<=rb[0].x && rb[0].x<=ra[1].x && ( ra[0].y<=rb[0].y && rb[0].y <= ra[1].y ||
                                                       rb[0].y<=ra[0].y && ra[0].y <= rb[1].y) ||
             rb[0].x<=ra[0].x && ra[0].x<=rb[1].x && ( ra[0].y<=rb[0].y && rb[0].y <= ra[1].y ||
                                                       rb[0].y<=ra[0].y && ra[0].y <= rb[1].y)
             );
}/**Pode não ser vantajoso utilizar este método, já que a maior parte das figuras serão eliminadas pelo primeiro algoritmo, que é muito mais simples que este
    Todavia pode ser vantagem já que este não utiliza algoritmos com ponto flutuante, apenas comparações(mas ainda as faz com pontos flutuantes, retornando o mesmo problema)*/

GLint GEOcolisionVertexApotema(Geometry g, Coord c){
    GLfloat distance = COORDdistance(c,g.center);//distancia entre o vertice e o centro da outra figura

    if(distance < g.radius){//Distancia menor que o raio pode haver colisao
        if(distance < GEOapotema(g) || //Distancia menor que a apotema ou
                distance < GEOapotemaRel(g,GEOalfaIn(g,COORDangle(g.center,c)))){ //Distancia menor que a apotema relativa
            return 1;//houve colisao
        }
    }

    return 0; //Não Houve
}

GLint GEOcolisionApotema(Geometry a,Geometry b){
    //a->b
    GLfloat angle = COORDangle(a.center,b.center);//Angulo da reta formada pelos pontos centrais

    GLint v = GEOcutEdge(a,angle);// Indice do vertice antes do corte

    Coord vert1 = GEOvi(a,v),//Vertice antes do corte
          vert2 = GEOvi(a,v+1);//Vertice depois do corte

    if(GEOcolisionVertexApotema(b,vert1) || GEOcolisionVertexApotema(b,vert2)){
        return 1;
    }

    //b->a
    angle = COORDangle(b.center, a.center);
    v = GEOcutEdge(b,angle);
    vert1 = GEOvi(b,v);
    vert2 = GEOvi(b,v+1);
    if(GEOcolisionVertexApotema(a,vert1) || GEOcolisionVertexApotema(a,vert2)){
        return 2;
    }

    return 0;// Então não houve colisão
}

GLint GEOcolision(Geometry a,Geometry b){
    if(GEOnotColisionCircle(a,b)){//GEOnotColisionCircle(a,b) ||
        return 0;
    }
    return GEOcolisionApotema(a,b);
}

GLint GEOmultiColision(Geometry a,Geometry b[],GLint n){
    int i;
    for(i=0;i<n;i++){
        if(GEOcolision(a,b[i]))
            return i;
    }
    return -1;
}

#endif // GEOMETRY_H
