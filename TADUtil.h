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

/** procedimento de compilacao normal
  * uso: COLORglColor(color);
  *
  * Solicita que uma cor seja enviada paa a máquina de estados para configurar a cor de fundo
  * Esta função serve para mascarar a função do openGL evitando chamadas longas e confusas
**/
void COLORglClearColor(Color color);

/** procedimento de compilacao normal
  * uso: COLORglColor(color);
  *
  * Solicita que uma cor seja enviada paa a máquina de estados
  * Esta função serve para mascarar a função do openGL evitando chamadas longas e confusas
**/
void COLORglColor(Color color);

/** procedimento de compilacao normal
  * uso: COORDglVertex(coord);
  *
  * Solicita que um vertice seja imprimido na máquna de estados
  * Esta função serve para mascarar a função do openGL evitando chamadas longas e confusas
**/
void COORDglVertex(Coord coord);

/** procedimento de compilacao normal
  * uso: COORDcopy(&a, b);
  *
  * a é um ponteiro para Color, e b é uma variável do tipo Coord;
  * Esta função tem como objetivo copiar os valores que estão na
  * cor b nos valores que estão na cor a
**/
void COLORcopy(Color *color1, Color color2);

/** procedimento de compilacao normal
  * uso: COLORparse(&color,r,g,b);
  *
  * a função recebe 3 valores flutuantes, referentes a cada atributo de uma cor
  * a função recebe o endereço da cor onde serão colocados os 3 parâmetros
**/
void COLORparse(Color *color, GLfloat r, GLfloat g,GLfloat b);

/** procedimento de compilacao normal
  * uso: COLORset(r,g,b);
  *
  * a função recebe 3 valores flutuantes, referentes a cada atributo de uma cor
  * A função returnará uma cor inicializada com os valores recebidos
**/
Color COLORset(GLfloat r, GLfloat g,GLfloat b);

/** procedimento de compilacao normal
  * uso: COORDcopy(&a, b);
  *
  * a é um ponteiro para Coord, e b é uma variável do tipo Coord;
  * Esta função tem como objetivo copiar os valores que estão na
  * coordenada b nos valores que estão na coordenada a
**/
void COORDcopy(Coord *coord1, Coord coord2);

/** procedimento de compilacao normal
  * uso: COLORrandom()
  *
  * Retornará uma cor calculada randomicamente
**/
Color COLORrandom();

/** procedimento de compilacao normal
  * uso: COORDdistance(a,b)
  *
  * a e b são variaveis do tipo Coord.
  * A distância euclidiana entre os pontos
**/
GLfloat COORDdistance(Coord a, Coord b);

/** procedimento de compilacao normal
  * uso: COORDangle(a,b)
  *
  * a e b são variaveis do tipo Coord.
  * esta função retorna o algulo que os pontos fazem
  * em relação ao norte, com orientação horária
  * O valor retornado estará em radianos
**/
GLfloat COORDangle(Coord a, Coord b);

/** procedimento de compilacao normal
  * uso: COLORpaleta(cor, indice, maximo, seletor)
  *
  * cor é uma variavel do tipo Color, e servira como tema base para a paleta
  * indice é um valor inteiro que deverá ser menor do que maximo, e representa a parcela de tom para cada um dos parametros da cor
  * Maximo é o valor que deseja-se estipular como topo da paleta, delimita a variavel indice
  * seletor é um valor inteiro que representa em binário as flags de cada uma das cores. A rigor os bits utilizados são apenas os 3 primeiros
  * 0 bit 2 em 1 significa que o parametro R da cor sofrerá alterações com a paleta.
  * O bit 1 em 1 significa que o parametro G da cor sofrerá alterações com a paleta.
  * O bit 0 em 1 significa que o parametro B da cor sofrerá alterações com a paleta.
  * Se algum dos bit for 0, o paramtro recebera uma copia do parametro da paleta correspondente.
**/
Color COLORpaleta(Color p, int i,int m,int s);

/** procedimento de compilacao normal
  * uso: COORDprint(coordenada)
  *
  * coordenada é uma variavel do tipo Coord e ao passar nessa função
  * Esta coordenada será imprimida na saída padrão formatada com seus parâmetros
**/
void COORDprint(Coord a);

/** procedimento de compilacao normal
  * uso: COLORprint(cor)
  *
  * cor é uma variavel do tipo Color e ao passar nessa função
  * Esta cor será imprimida na saída padrão formatada com seus parâmetros
**/
void COLORprint(Color a);


/** procedimento de compilacao normal
  * uso: pause(valor)
  *
  * valor eh um numero maior que zero podendo ser uma fracao.
  * eh o tempo em segundos de pausa no programa.
**/
void pause (float delay1) ;

#endif // TADUTIL_H
