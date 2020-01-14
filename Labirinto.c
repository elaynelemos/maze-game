/*
*   Universidade Federal do Vale do São Francisco - Univasf
*   Colegiado de Engenharia de Computação
*   Orientador: Prof. Dr. Jorge Cavalcanti
*   Discentes: Elayne Lemos, elayne.l.lemos@gmail.com
*              Jônatas de Castro, jonatascastropassos@gmail.com
*   Atividade: implementação em OpenGL/GLUT de um "labirinto", ambiente com
*              diversos obstáculos em que o player possue 3 oportunidades de
*              ir do extremo inferior ao extremo superior da tela.
*   Controles: O player podera
    Movimentar:                     Setas do teclado
    Girar em torno de si mesmo:     PageUp e PageDown
    Mudar o formato:                Numéricos de 3 a 6 (Apenas na posição inicial)
    Trocar a cor dos obstáculos     Botão esquerdo do mouse
*/

#include "TADGeometry.c"

#define n_obstac 13
#define player_x0 50
#define player_y0 5
#define n_paletas 3


void Mouse(int,int,int,int); //Retorna ao início do jogo ao clicar no botão em Perdeu() e Venceu().

void DesenhaTextoStroke(void*, char*); //Recebe fonte e texto a ser impresso.

void Desenha(void); //display

void Inicializa (void); //cria o contexto com todos os objetos (player + obstáculos.

void Teclado (unsigned char,int,int);

void Perdeu(void);

void Venceu(void);

//Variáveis Globais
Geometry g[n_obstac];
int life = 3, playing=1;

Color paletas[n_paletas];   //Salva as opções de cores para os obstáculos
int paleta_i=0;             //Salva a paleta atual

Color paleta;       // Salva a cor base para os obstáculos
Color player_color; // Salva a configuração de cor do player


void Inicializa (void)
{
    int i;
    //FreeConsole(); //O audio não deixa ficar bom
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,100.0,0.0,100.0);

    //Criando paletas
    paletas[0]= COLORset(0.100,0.680,1.000);
    paletas[1]= COLORset(0.100,0.680,0.000);
    paletas[2]= COLORset(1.000,0.680,0.000);

    //Selecionando paleta
    paleta = paletas[paleta_i];
    player_color = COLORset(1.000000,0.000000,0.498000);




    for(i=0; i<n_obstac; i++)
    {
        g[i] = GEOset();
        GEOsetFill(g+i,COLORpaleta(paleta,i,n_obstac,3)); //preenche os obstáculos com escala monocromática.
        GEOsetStrokeP(g+i,1,1,1);
        g[i].stroke_width = 2;
    }

    //0 - Player
    GEOsetFill(g+0,player_color);
    GEOsetCenterP(g,player_x0,player_y0);
    g[0].radius = 5.0;
    g[0].sides = 6;

    //1
    GEOsetCenterP(g+1,30,20);
    g[1].radius = 8.0;
    g[1].sides = 6;

    //2
    GEOsetCenterP(g+2,50,50);
    g[2].radius = 15.0;
    g[2].sides = 5;

    //3
    GEOsetCenterP(g+3,10,70);
    g[3].radius = 10.0;
    g[3].sides = 7;

    //4
    GEOsetCenterP(g+4,70,30);
    g[4].radius = 8.0;
    g[4].sides = 3;

    //5
    GEOsetCenterP(g+5,80,80);
    g[5].radius = 6.0;
    g[5].sides = 3;

    //6
    GEOsetCenterP(g+6,40,80);
    g[6].radius = 8.0;
    g[6].sides = 6;

    //7
    GEOsetCenterP(g+7,90,50);
    g[7].radius = 5.0;
    g[7].sides = 8;

    //8
    GEOsetCenterP(g+8,10,40);
    g[8].radius = 5.0;
    g[8].sides = 8;

    //9
    GEOsetCenterP(g+9,80,15);
    g[9].radius = 4.0;
    g[9].sides = 9;

    //10
    GEOsetCenterP(g+10,60,90);
    g[10].radius = 7.0;
    g[10].sides = 8;

    //11
    GEOsetCenterP(g+11,20,95);
    g[11].radius = 5.0;
    g[11].sides = 5;

    //12
    GEOsetCenterP(g+12,30,55);
    g[12].radius = 4.0;
    g[12].sides = 3;
}

void repSound(char type, int number){
    switch(type){
    case 'd'://derrota
        switch(number){
        case 1:
            system("mp3\\mpg123.exe mp3\\d01.mp3 -q  && cls");
            break;
        case 2:
            system("mp3\\mpg123.exe mp3\\d02.mp3 -q  && cls");
            break;
        case 3:
            system("mp3\\mpg123.exe mp3\\d03.mp3 -q  && cls");
            break;
        case 4:
            system("mp3\\mpg123.exe mp3\\d04.mp3 -q  && cls");
            break;
        case 5:
            system("mp3\\mpg123.exe mp3\\d05.mp3 -q  && cls");
            break;
        case 6:
            system("mp3\\mpg123.exe mp3\\d06.mp3 -q  && cls");
            break;
        case 7:
            system("mp3\\mpg123.exe mp3\\d07.mp3 -q  && cls");
            break;
        }
        break;
    case 'i'://inicio
        switch(number){
        case 1:
            system("mp3\\mpg123.exe mp3\\i01.mp3 -q  && cls");
            break;
        case 2:
            system("mp3\\mpg123.exe mp3\\i02.mp3 -q  && cls");
            break;
        case 3:
            system("mp3\\mpg123.exe mp3\\i03.mp3 -q  && cls");
            break;
        case 4:
            system("mp3\\mpg123.exe mp3\\i04.mp3 -q  && cls");
            break;
        }
        break;
    case 'l'://menos uma vida
        switch(number){
        case 1:
            system("mp3\\mpg123.exe mp3\\l01.mp3 -q  && cls");
            break;
        }
        break;
    case 'v'://Vitoria
        switch(number){
        case 1:
            system("mp3\\mpg123.exe mp3\\v01.mp3 -q  && cls");
            break;
        case 2:
            system("mp3\\mpg123.exe mp3\\v02.mp3 -q  && cls");
            break;
        case 3:
            system("mp3\\mpg123.exe mp3\\v03.mp3 -q  && cls");
            break;
        case 4:
            system("mp3\\mpg123.exe mp3\\v04.mp3 -q  && cls");
            break;
        case 5:
            system("mp3\\mpg123.exe mp3\\v05.mp3 -q  && cls");
            break;
        case 6:
            system("mp3\\mpg123.exe mp3\\v06.mp3 -q  && cls");
            break;
        }
        break;
    }
}

void SomMenosVida(int i){
    repSound('l',1);
    if(life !=0 && life!=3)
            playing = 1;
}

void SomVitoria(int i){
    repSound('v',rand()%6+1);
}

void SomDerrota(int i){
    repSound('d',rand()%7+1);
}

void SomInicio(int i){
    repSound('i',rand()%4+1);
}

void Desenha(void)
{
    int i, j;
    GLint colised;
    Geometry lifes;

    glClear(GL_COLOR_BUFFER_BIT);

    for(i=1; i<n_obstac; i++)
    {
        GEOsetFill(g+i,COLORpaleta(paleta,i,n_obstac,3)); //preenche os obstáculos com escala monocromática.
        GEOdraw(g[i]);
    }
    GEOsetFill(g+0,player_color);
    GEOdraw(g[0]);


    //representação de quantas chances restam para o player no canto superior direito
    lifes = GEOset();
    GEOsetFill(&lifes,player_color);
    GEOsetStrokeP(&lifes,1,1,1);
    lifes.stroke_width = 1.5f;
    lifes.radius = 2.0f;
    lifes.sides = g[0].sides;
    lifes.center.y = 96.0f;
    lifes.center.x = 96.0f;
    for(j=0; j<life; j++)
    {
        GEOdraw(lifes);
        lifes.center.x-=4.5f;
    }

    colised = GEOmultiColision(g[0],g+1,n_obstac-1);
    if(colised+1)
    {
        GEOsetFillP(g+colised+1,0,0,0);
        GEOdraw(g[colised+1]);
        life--;

        playing = 0;
        glutTimerFunc(10,SomMenosVida,1);

        GEOsetFill(g+colised+1,COLORpaleta(paleta,colised+1,n_obstac,3));
        GEOsetCenterP(g+0,player_x0,player_y0);

        if(life<1 && g[0].center.y<95)
            Perdeu();
    }

    if(g[0].center.y >= 95)
        Venceu();

    glFlush();
}


void DesenhaTexto(void *font, char *string)
{
    // Exibe caractere a caractere
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
}


void DesenhaTextoStroke(void *font, char *string)
{
    // Exibe caractere a caractere
    while(*string)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}


void Mouse(int key, int state, int x, int y)
{

    if(key==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(!playing && 210<x && x<380 && 330<y && y<380)
        {
            GEOsetCenterP(g,player_x0,player_y0);
            playing=1;
            life = 3;
            g[0].sides = 6;
            g[0].phase = 0;
            paleta_i=0;
            paleta = paletas[paleta_i];

            glutTimerFunc(10,SomInicio,1);
        }
        else if(playing )
        {
            paleta_i = (paleta_i+1)%n_paletas;
            paleta = paletas[paleta_i];
        }

        Desenha();
    }
}


void Teclado (unsigned char key, int x, int y)
{
    Coord rect[2];
    int i = 0;


    if (key == 27) //no arquivo de definição glut.h alterou-se o código da tecla para 27 (esc).
        exit(0);

    if(playing && key>='3' && key <= '6' && (player_x0-2)<=g[0].center.x && g[0].center.x<=(player_x0+2) && g[0].center.y<=(player_y0+2))  //tipo do player (figura de de 3 a 9 lados); Só muda se o player estiver na posição inicial.
    {
        g[0].sides = key-'0';
        i=1;
    }

    if(i)
    {
        GEOboundingRect(rect,g[0]);

        if(rect[1].y>100.0)
            g[0].center.y -=rect[1].y-100.0;
        if(rect[0].y<0.0)
            g[0].center.y -=rect[0].y;
        if(rect[0].x<0.0)
            g[0].center.x -=rect[0].x;
        if(rect[1].x>100.0)
            g[0].center.x -=rect[1].x-100.0;

        Desenha();
    }


}


void TecladoEspecial (int key, int x, int y)
{
    Coord rect[2];
    int i = 0;

    if(playing)
    {
        if(key==GLUT_KEY_UP)  //controles de direção e sentido.
        {
            g[0].center.y += 2;
            i=1;
        }
        if(key==GLUT_KEY_DOWN)
        {
            g[0].center.y -= 2;
            i=1;
        }
        if(key==GLUT_KEY_LEFT)
        {
            g[0].center.x -= 2;
            i=1;
        }
        if(key==GLUT_KEY_RIGHT)
        {
            g[0].center.x += 2;
            i=1;
        }

        if(key==GLUT_KEY_PAGE_DOWN)  //rotação do player, sentido anti-horário.
        {
            g[0].phase += 18;
            i=1;
        }
        if(key==GLUT_KEY_PAGE_UP)  //rotação do player, sentido horário.
        {
            g[0].phase -= 18;
            i=1;
        }

        if(i)
        {
            GEOboundingRect(rect,g[0]);

            if(rect[1].y>100.0)
                g[0].center.y -=rect[1].y-100.0;
            if(rect[0].y<0.0)
                g[0].center.y -=rect[0].y;
            if(rect[0].x<0.0)
                g[0].center.x -=rect[0].x;
            if(rect[1].x>100.0)
                g[0].center.x -=rect[1].x-100.0;

            Desenha();
        }
    }
}


void Perdeu(void)
{
    int i;
    char *msg1 = "Game Over!", *msg2="TRY AGAIN";
    playing=0;
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.800000, 0.196100, 0.196100);
    glBegin(GL_QUADS);
    glVertex2d(35.0f,35.0f);
    glVertex2d(35.0f,45.0f);
    glVertex2d(65.0f,45.0f);
    glVertex2d(65.0f,35.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(32,50,0);
    glScalef(0.05,0.05, 0.05);
    glLineWidth(4); // Define a espessura da linha
    glColor3f(0.800000, 0.196100, 0.196100);
    DesenhaTextoStroke(GLUT_STROKE_ROMAN,msg1);
    glPopMatrix();

    glColor3f(1,1,1);
    glRasterPos2f(39,39);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,msg2);

    glutTimerFunc(10,SomDerrota,1);

    g[0].sides = 6;
    GEOsetCenterP(g,player_x0,player_y0);
    life = 3;
}


void Venceu(void)
{
    int i;
    char *msg1 = "You're a WINNER!", *msg2="PLAY AGAIN";
    playing=0;
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.439200, 0.576500, 0.858800);
    glBegin(GL_QUADS);
    glVertex2d(35.0f,35.0f);
    glVertex2d(35.0f,45.0f);
    glVertex2d(65.0f,45.0f);
    glVertex2d(65.0f,35.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(22,50,0);
    glScalef(0.05,0.05, 0.05);
    glLineWidth(4); // Define a espessura da linha
    glColor3f(0.439200, 0.576500, 0.858800);
    DesenhaTextoStroke(GLUT_STROKE_ROMAN,msg1);
    glPopMatrix();

    glColor3f(1,1,1);
    glRasterPos2f(38,38);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,msg2);

    glutTimerFunc(10,SomVitoria,1);

    g[0].sides = 6;
    GEOsetCenterP(g,player_x0,player_y0);
    life = 3;
}


int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600,600);

    glutCreateWindow("Labirinto");

    glutDisplayFunc(Desenha);
    glutKeyboardFunc (Teclado);
    glutSpecialFunc(TecladoEspecial);
    glutMouseFunc(Mouse);

    Inicializa();
    Desenha();

    glutTimerFunc(10,SomInicio,1);

    glutMainLoop();
}
