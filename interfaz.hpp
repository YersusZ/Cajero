#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;


/*Nombre Procedimiento: Gotoxy(int x, int y)
    Objetivo; Ubicar el cursor de l teclado en una posicion x, y en la pantalla
    Parametros: x --> indica la posicion en x en donde se ubicara el dato
                y --> indica la posicion en y en donde se ubicara el dato
    Ejemplo:    gotoxy(5,10)
                cout <<"Hola Mundo" //Muestra en pantalla "Hola mundo en la posicion 5,10"
*/
 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void LineaH(int x, int y, int tam, char tipo)
{
    for (int i=x; i<=x+tam;i++)
    {
        gotoxy(i,y);
        if(tipo=='s')
            cout<<(char)196;
        else
            cout<<(char)205;
    }

}

void LineaV(int x, int y, int tam,char tipo)
{

    for (int i=y; i<=y+tam;i++)
    {
        gotoxy(x,i);
        if(tipo=='s')
            cout<<(char)179;
        else
            cout<<(char)186;
    }
}

void Esquinas(int x1,int y1,int x2,int y2,char tipo)
{
    gotoxy(x1,y1);
    if(tipo=='s')
    {
        cout<<(char)218;
    }
    else if(tipo=='d')
    {
        cout<<(char)201;
    }

    gotoxy(x1,y2);
    if(tipo=='s')
    {
        cout<<(char)192;
    }
    else if(tipo=='d')
    {
        cout<<(char)200;
    }
    gotoxy(x2,y1);
    if(tipo=='s')
    {
        cout<<(char)191;
    }
    else if(tipo=='d')
    {
        cout<<(char)187;
    }
    gotoxy(x2,y2);
    if(tipo=='s')
    {
        cout<<(char)217;
    }
    else if(tipo=='d')
    {
        cout<<(char)188;
    }

}

//-------------------------------------------------------------
void cuadro(int x1, int y1, int x2, int y2,char tipo)
{
    LineaH(x1,y1,x2-x1,tipo);
    LineaH(x1,y2,x2-x1,tipo);
    LineaV(x1,y1,y2-y1,tipo);
    LineaV(x2,y1,y2-y1,tipo);
    Esquinas(x1,y1,x2,y2,tipo);
}
//-----------------------------------------------------------

void cuadradogrande()
{   //
    cuadro(1,1,90,33,'d');
    cout<<endl<<endl;
}
//#####################################################################3

void LineaHx(int x, int y, int tam,int tipo)
{
    int cont;
    for (int i=x; i<=x+tam;i++)
    {
        if (tipo==1)
        {
            gotoxy(i,y);
            cout<<(char)223;
        }
        else
        {
            gotoxy(i,y);
            cout<<(char)220;
        }
    }
}

void LineaVx(int x, int y, int tam)
{

    for (int i=y; i<=y+tam;i++)
    {
        gotoxy(x,i);
        cout<<(char)219;
    }
}
void cuadrox(int x1, int y1, int x2, int y2)
{
    LineaHx(x1,y1,x2-x1,1);
    LineaHx(x1,y2,x2-x1,2);
    LineaVx(x1,y1,y2-y1);
    LineaVx(x2,y1,y2-y1);
}
void cuadradopantalla()
{   //
    int x2,xy2;
    cuadrox(3,3,88,13);
    cout<<endl<<endl;
}
//#####################################################################3

void cuadradoteclado()
{   //
    int x2,xy2;
    cuadro(3,15,31,31,'d');
    cout<<endl<<endl;
}
//-----------------------------------------------------------

void cuadradoefectivo()
{   //
    int x2,xy2;
    cuadro(34,15,88,21,'d');
}
//-----------------------------------------------------------

void cuadradodeposito()
{   //
    int x2,xy2;
    cuadro(34,25,88,31,'d');
}
//-----------------------------------------------------------
void LineaHxd(int x, int y, int tam)
{
    for (int i=x; i<=x+tam;i++)
    {
        gotoxy(i,y);
        cout<<(char)220;
    }

}
//#################################################################
void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//#################################################################
void lineascajero()
{
    color(128);
    cuadradogrande();
    color(368);
    cuadradopantalla();
    color(112);
    cuadradoteclado();
    cuadradoefectivo();
    cuadradodeposito();
    LineaHxd(37,19,48);
    LineaHxd(46,29,29);
}
//######################################################################################################
//----------------------------------------------------------
void cuadrorelleno(int x1, int y1, int x2, int y2)
{
    for (int a=y1;a<=y2;a++)
    {
        for (int i=x1;i<=x2;i++)
        {
            gotoxy(i,a);
            cout<<(char)219;
        }
    }

}
//----------------------------------------------------------
void cuadradogrande2()
    {   //
        cuadrorelleno(1,1,90,33);
    }
//-----------------------------------------------------------
void cuadradopantalla2()
    {   //
        cuadrorelleno(3,3,88,13);
    }
//-----------------------------------------------------------
void cuadradoteclado2()
    {   //
        cuadrorelleno(3,15,31,31);
    }
//-----------------------------------------------------------
void cuadradoefectivo2()
    {   //
        cuadrorelleno(34,15,88,21);
    }
//-----------------------------------------------------------
void cuadradodeposito2()
    {   //
        cuadrorelleno(34,25,88,31);
    }
//__________________________________________________________
void colorcajero()
{
    color(136);
    cuadradogrande2();
    color(255);
    cuadradopantalla2();
    color(119);
    cuadradoteclado2();
    cuadradoefectivo2();
    cuadradodeposito2();
}
//######################################################################
void lineasnum(int x, int y, int tam)
{
    color(15);
    for (int i=y; i<=y+tam;i++)
    {
        gotoxy(x,i);
        cout<<i;
    }
}
//######################################################################
void letras()
{
    //efectivo
    color(112);
    gotoxy(50,16);
    cout<<"Tome aqui el efectivo";
    //deposito
    gotoxy(45,26);
    cout<<"Inserte aqui el sobre de deposito";
    //TECLADO
        color(143);
        //1
        gotoxy(9,17);
        cout<<"1";
        //2
        gotoxy(17,17);
        cout<<"2";
        //3
        gotoxy(25,17);
        cout<<"3";
        //4
        gotoxy(9,21);
        cout<<"4";
        //5
        gotoxy(17,21);
        cout<<"5";
        //6
        gotoxy(25,21);
        cout<<"6";
        //7
        gotoxy(9,25);
        cout<<"7";
        //8
        gotoxy(17,25);
        cout<<"8";
        //9
        gotoxy(25,25);
        cout<<"9";
        //0
        gotoxy(9,29);
        cout<<"0";
        //enter
        gotoxy(19,29);
        cout<<"ENTER";

}
//###############################################################################################
void letrascolor()
{
    color(136);
    cuadrorelleno(7,16,11,18);//1
    cuadrorelleno(15,16,19,18);//2
    cuadrorelleno(23,16,27,18);//3
    cuadrorelleno(7,20,11,22);//4
    cuadrorelleno(15,20,19,22);//5
    cuadrorelleno(23,20,27,22);//6
    cuadrorelleno(7,24,11,26);//7
    cuadrorelleno(15,24,19,26);//8
    cuadrorelleno(23,24,27,26);//9
    cuadrorelleno(7,28,11,30);//0
    cuadrorelleno(17,28,25,30);//ENTER
}
//###############################################################################################

void clean()
{
    color(255);
    cuadradopantalla2();
    color(368);
    cuadradopantalla();
    color(240);
}
//###############################################################################################
void menu()
{
    colorcajero();
    lineascajero();
    letrascolor();
    letras();
    //lineasnum(0,1,40);
    gotoxy(1,40);
}
