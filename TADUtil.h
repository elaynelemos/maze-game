/*
*   Universidade Federal do Vale do S�o Francisco - Univasf
*   Colegiado de Engenharia de Computa��o
*   Orientador: Prof. Dr. Jorge Cavalcanti
*   Discentes: Elayne Lemos, elayne.l.lemos@gmail.com
*              J�natas de Castro, jonatascastropassos@gmail.com
*   Implementa��o:
*   Este c�digo implementa duas estruturas b�sicas : Cores e Coordenadas
*   A ideia � mascarar algumas opera��es e simplificar a utiliza��o dos recursos
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
  * Solicita que uma cor seja enviada paa a m�quina de estados para configurar a cor de fundo
  * Esta fun��o serve para mascarar a fun��o do openGL evitando chamadas longas e confusas
**/
void COLORglClearColor(Color color);

/** procedimento de compilacao normal
  * uso: COLORglColor(color);
  *
  * Solicita que uma cor seja enviada paa a m�quina de estados
  * Esta fun��o serve para mascarar a fun��o do openGL evitando chamadas longas e confusas
**/
void COLORglColor(Color color);

/** procedimento de compilacao normal
  * uso: COORDglVertex(coord);
  *
  * Solicita que um vertice seja imprimido na m�quna de estados
  * Esta fun��o serve para mascarar a fun��o do openGL evitando chamadas longas e confusas
**/
void COORDglVertex(Coord coord);

/** procedimento de compilacao normal
  * uso: COORDcopy(&a, b);
  *
  * a � um ponteiro para Color, e b � uma vari�vel do tipo Coord;
  * Esta fun��o tem como objetivo copiar os valores que est�o na
  * cor b nos valores que est�o na cor a
**/
void COLORcopy(Color *color1, Color color2);

/** procedimento de compilacao normal
  * uso: COLORparse(&color,r,g,b);
  *
  * a fun��o recebe 3 valores flutuantes, referentes a cada atributo de uma cor
  * a fun��o recebe o endere�o da cor onde ser�o colocados os 3 par�metros
**/
void COLORparse(Color *color, GLfloat r, GLfloat g,GLfloat b);

/** procedimento de compilacao normal
  * uso: COLORset(r,g,b);
  *
  * a fun��o recebe 3 valores flutuantes, referentes a cada atributo de uma cor
  * A fun��o returnar� uma cor inicializada com os valores recebidos
**/
Color COLORset(GLfloat r, GLfloat g,GLfloat b);

/** procedimento de compilacao normal
  * uso: COORDcopy(&a, b);
  *
  * a � um ponteiro para Coord, e b � uma vari�vel do tipo Coord;
  * Esta fun��o tem como objetivo copiar os valores que est�o na
  * coordenada b nos valores que est�o na coordenada a
**/
void COORDcopy(Coord *coord1, Coord coord2);

/** procedimento de compilacao normal
  * uso: COLORrandom()
  *
  * Retornar� uma cor calculada randomicamente
**/
Color COLORrandom();

/** procedimento de compilacao normal
  * uso: COORDdistance(a,b)
  *
  * a e b s�o variaveis do tipo Coord.
  * A dist�ncia euclidiana entre os pontos
**/
GLfloat COORDdistance(Coord a, Coord b);

/** procedimento de compilacao normal
  * uso: COORDangle(a,b)
  *
  * a e b s�o variaveis do tipo Coord.
  * esta fun��o retorna o algulo que os pontos fazem
  * em rela��o ao norte, com orienta��o hor�ria
  * O valor retornado estar� em radianos
**/
GLfloat COORDangle(Coord a, Coord b);

/** procedimento de compilacao normal
  * uso: COLORpaleta(cor, indice, maximo, seletor)
  *
  * cor � uma variavel do tipo Color, e servira como tema base para a paleta
  * indice � um valor inteiro que dever� ser menor do que maximo, e representa a parcela de tom para cada um dos parametros da cor
  * Maximo � o valor que deseja-se estipular como topo da paleta, delimita a variavel indice
  * seletor � um valor inteiro que representa em bin�rio as flags de cada uma das cores. A rigor os bits utilizados s�o apenas os 3 primeiros
  * 0 bit 2 em 1 significa que o parametro R da cor sofrer� altera��es com a paleta.
  * O bit 1 em 1 significa que o parametro G da cor sofrer� altera��es com a paleta.
  * O bit 0 em 1 significa que o parametro B da cor sofrer� altera��es com a paleta.
  * Se algum dos bit for 0, o paramtro recebera uma copia do parametro da paleta correspondente.
**/
Color COLORpaleta(Color p, int i,int m,int s);

/** procedimento de compilacao normal
  * uso: COORDprint(coordenada)
  *
  * coordenada � uma variavel do tipo Coord e ao passar nessa fun��o
  * Esta coordenada ser� imprimida na sa�da padr�o formatada com seus par�metros
**/
void COORDprint(Coord a);

/** procedimento de compilacao normal
  * uso: COLORprint(cor)
  *
  * cor � uma variavel do tipo Color e ao passar nessa fun��o
  * Esta cor ser� imprimida na sa�da padr�o formatada com seus par�metros
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
