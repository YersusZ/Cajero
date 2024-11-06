#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include "interfaz.hpp"
#include <cstdio>
using namespace std;
void segundos(int x,int y,int z)///FUNCION QUE SIRVE PARA ESPERAR X SEGUNDOS
{
    for(int i=z; i>0;i--)
    {
        gotoxy(x,y);
        cout<<i;
        Sleep(1000);
    }
}
void Menu_Principal();
//------------------------------------------------------------------
struct Cuentas///CREA LA BASE DE DATOS DENTRO DEL CODIGO
{
	char numcta[6];
	char nip[6];
	float saldo;
};
//------------------------------------------------------------------

Cuentas A[10];

void AbrirArchivo()///ABRE LA BASE DE DATOS Y DICE SI SE ABRIO EXISTOSAMENTE O NO
{
	ifstream Entrada;
	Entrada.open("Cuentas.txt");
	if (Entrada.good())
	{
	    color(7);
	    gotoxy(0,35);
		color(240);
		char Cadena[50];
		for (int i=0; i<10; i++)
		{
			Entrada>>Cadena;
			strcpy(A[i].numcta,Cadena);
			//cout<< A[i].numcta << "\t";
			Entrada>>Cadena;
			strcpy(A[i].nip,Cadena);
			//cout<< A[i].nip << "\t";
			Entrada>>Cadena;
			A[i].saldo=atof(Cadena);
			//cout << A[i].saldo << "\n";
		}
	}
	else
	{
	    color(7);
	    gotoxy(0,35);
		cout << "Hubo un error vuelva a intentar...";
	}
}

//------------------------------------------------------------------

int a;
int b;
void Inicio_de_sesion()///COMPARA LA BASE DE DATOS CON LOS DATOS INGRESADOS PARA PODER EJECUTAR EL MENU
{
    clean();
    color(240);
    a=0;
    char num_cuenta[6];
    gotoxy(5,4);
    cout << "Bienvenido!";
    gotoxy(5,6);
    cout << "Escriba su numero de cuenta: ";
    gets(num_cuenta);

    char NIP[6];
    gotoxy(5,8);
    cout <<"Escriba su NIP: ";
    gets(NIP);
    for (int i=0; i<10; i++)
    {
        if ((strcmp(num_cuenta,A[i].numcta) == 0) and (strcmp(NIP,A[i].nip) == 0))///CONDICIONAL EVALUA SI LOS DATOS INGRESADOS SON IGUALES A LOS DE LA BASE DATOS
        {
            a=1;
            b=i;
            break;
        }
    }
    if (a==1)///EN CASO DE QUE SI CONCUERDEN LOS DATOS
    {
        clean();
        Menu_Principal();
    }
    else///EN CASO DE QUE LOS DATOS INGRESADOS NO CONCUERDEN
    {
        gotoxy(5,10);
        cout << "ERROR. Ingrese datos validos.";
        gotoxy(5,11);
        system("pause");
        clean();
        Inicio_de_sesion();
    }
}

//------------------------------------------------------------------
void Ver_saldo();
void Retirar();
void Depositar();
int Billetes=500;
void Menu_Principal()///PROCEDIMIENTO EN EL QUE SE ABRE EL MENU PRINCIPAL
{
    clean();
    color(240);
    gotoxy(5,4);
    cout <<"MENU PRINCIPAL";
    gotoxy(5,6);
    cout << "1 - Ver mi saldo.";
    gotoxy(5,7);
    cout << "2 - Retirar efectivo.";
    gotoxy(5,8);
    cout << "3 - Depositar fondos.";
    gotoxy(5,9);
    cout << "4 - Salir.";
    int op;
    gotoxy(5,11);
    cout << "Seleccione una opcion (1-4): ";
    cin >> op;
    if (op == 1)
    {
        Ver_saldo();
        Menu_Principal();
    }
    if (op == 2)
    {
        if (Billetes == 0)
        {
            clean();
            gotoxy(5,4);
            cout << "No hay billetes en el cajero.";
            gotoxy(5,6);
            cout<<"Perdon las molestias, vuelva otro dia";
            gotoxy(5,8);
            system("pause");
            Menu_Principal();
        }
        else
        {
             Retirar();
             Menu_Principal();
        }
    }
    if (op == 3)
    {
        Depositar();
        Menu_Principal();
    }
    if (op == 4)
    {
        clean();
        gotoxy(5,4);
        cout << "Se ha cerrado su cuenta exitosamente";
        gotoxy(5,6);
        cout << "Se podra iniciar sesion nuevamente en: ";
        gotoxy(46,6);
        cout<<"segundos";
        segundos(44,6,9);
        getchar();
        Inicio_de_sesion();
    }
}

//------------------------------------------------------------------

void Ver_saldo()///PROCEDIMIENTO QUE PERMITE VER EL SALDO DE LA BASE DE DATOS
{
    clean();
    color(240);
    gotoxy(5,4);
    cout << "Cuenta: " << A[b].numcta;
    gotoxy(5,6);
    cout << " Tiene un saldo de: " << A[b].saldo << " $";
    gotoxy(5,8);
    system("pause");
}

//------------------------------------------------------------------
void Retirar()///PROCEDIMIENTO PARA DISMINUIR SALDO EN BASE DE DATOS Y DISPENSAR EL DINERO
{
    clean();
    color(240);
    gotoxy(6,5);
    cout << "Opciones de retiro: " ;
    gotoxy(6,7);
    cout << "1 - 20$" ;
    gotoxy(6,8);
    cout << "2 - 40$" ;
    gotoxy(6,9);
    cout << "3 - 60$" ;
    gotoxy(30,7);
    cout << "4 - 100$";
    gotoxy(30,8);
    cout << "5 - 200$";
    gotoxy(30,9);
    cout << "6 - Cancelar transaccion";
    int op;
    gotoxy(6,11);
    cout << "Elija una opcion de retiro (1 - 6): ";
    cin >> op;
    if (op == 1)
    {
        if ((A[b].saldo < 20) or (Billetes < 1))
        {
            clean();
            gotoxy(5,4);
            cout << "El saldo es menor al monto a retirar o no hay billetes suficientes en el cajero.";
            gotoxy(5,6);
            cout<<"Por favor ingrese un monto mas pequeno";
            gotoxy(5,8);
            system("pause");
            Retirar();
        }
        else
        {
            ofstream escribir;
            escribir.open("Cuentas.txt");
            for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) - 20);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();
            Billetes-1;
            clean();
            gotoxy(5,4);
            cout << "ATENCION";
            gotoxy(5,6);
            cout << "Tome el dinero.";
            gotoxy(5,8);
            cout<<"Tiempo de retiro: ";
            gotoxy(25,8);
            cout<<"segundos";
            segundos(23,8,9);
        }
    }
     if (op == 2)
    {
        if ((A[b].saldo < 40) or (Billetes < 2))
        {
            clean();
            gotoxy(5,4);
            cout << "El saldo es menor al monto a retirar o no hay billetes suficientes en el cajero.";
            gotoxy(5,6);
            cout<<"Por favor ingrese un monto mas pequeno";
            gotoxy(5,8);
            system("pause");
            Retirar();
        }
        else
        {
            ofstream escribir;
            escribir.open("Cuentas.txt");
            for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) - 40);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();
            Billetes-2;
            clean();
            gotoxy(5,4);
            cout << "ATENCION";
            gotoxy(5,6);
            cout << "Tome el dinero.";
            gotoxy(5,8);
            cout<<"Tiempo de retiro: ";
            gotoxy(25,8);
            cout<<"segundos";
            segundos(23,8,5);
        }
    }
    if (op == 3)
    {
        if ((A[b].saldo < 60) or (Billetes < 3))
        {
            clean();
            gotoxy(5,4);
            cout << "El saldo es menor al monto a retirar o no hay billetes suficientes en el cajero.";
            gotoxy(5,6);
            cout<<"Por favor ingrese un monto mas pequeno";
            gotoxy(5,8);
            system("pause");
            Retirar();
        }
        else
        {
            ofstream escribir;
            escribir.open("Cuentas.txt");
            for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) - 60);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();
            Billetes-3;
            clean();
            gotoxy(5,4);
            cout << "ATENCION";
            gotoxy(5,6);
            cout << "Tome el dinero.";
            gotoxy(5,8);
            cout<<"Tiempo de retiro: ";
            gotoxy(25,8);
            cout<<"segundos";
            segundos(23,8,9);
        }
    }
    if (op == 4)
    {
        if ((A[b].saldo < 100) or (Billetes < 5))
        {
            clean();
            gotoxy(5,4);
            cout << "El saldo es menor al monto a retirar o no hay billetes suficientes en el cajero.";
            gotoxy(5,6);
            cout<<"Por favor ingrese un monto mas pequeno";
            gotoxy(5,8);
            system("pause");
            Retirar();
        }
        else
        {
            ofstream escribir;
            escribir.open("Cuentas.txt");
            for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) - 100);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();
            Billetes-5;
            clean();
            gotoxy(5,4);
            cout << "ATENCION";
            gotoxy(5,6);
            cout << "Tome el dinero.";
            gotoxy(5,8);
            cout<<"Tiempo de retiro: ";
            gotoxy(25,8);
            cout<<"segundos";
            segundos(23,8,9);
        }
    }
    if (op == 5)
    {
        if ((A[b].saldo < 200) or (Billetes < 10))
        {
            clean();
            gotoxy(5,4);
            cout << "El saldo es menor al monto a retirar o no hay billetes suficientes en el cajero.";
            gotoxy(5,6);
            cout<<"Por favor ingrese un monto mas pequeno";
            gotoxy(5,8);
            system("pause");
            Retirar();
        }
        else
        {
            ofstream escribir;
            escribir.open("Cuentas.txt");
            for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) - 200);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();
            Billetes-10;
            clean();
            gotoxy(5,4);
            cout << "ATENCION";
            gotoxy(5,6);
            cout << "Tome el dinero.";
            gotoxy(5,8);
            cout<<"Tiempo de retiro: ";
            gotoxy(25,8);
            cout<<"segundos";
            segundos(23,8,9);
        }
    }
    if (op == 6)
    {
        clean();
        gotoxy(5,4);
        cout << "Transaccion cancelada.";
        gotoxy(5,6);
        cout<<"Volvera al menu principal en: ";
        gotoxy(37,6);
        cout<<"segundos";
        segundos(35,6,5);
    }
}
//------------------------------------------------------------------

void Depositar()///PROCEDIMIENTO QUE AUMENTA EL SALDO EN LA BASE DE DATOS
{
    float depositocentavos;
    float depositodolares;
    clean();
    color(240);
    gotoxy(5,4);
    cout<<"Inserte el dinero en la ranura(en centavos): ";
    cin >> depositocentavos;
    gotoxy(5,6);
    cout<<"Espere la comprobacion del deposito: ";
    gotoxy(44,6);
    cout<<"segundos";
    segundos(42,6,5);
    if (depositocentavos == 0)
    {
        clean();
        gotoxy(5,4);
        cout << "Deposito cancelado";
        gotoxy(5,6);
        cout<<"Volvera al menu principal en: ";
        gotoxy(37,6);
        cout<<"segundos";
        segundos(35,6,5);
        Menu_Principal();
    }
    else
    {
        depositodolares=depositocentavos/100;
        ofstream escribir;
        escribir.open("Cuentas.txt");
        for (int i=0; i<10; i++)
            {
                 if (i==b)
                {
                    escribir<< (A[i].numcta);
                    escribir<< (char)9;
                    escribir<< (A[i].nip);
                    escribir<< (char)9;
                    escribir<< ((A[i].saldo) + depositodolares);
                    escribir<< (char)10;
                    i++;
                }
                escribir<< (A[i].numcta);
                escribir<< (char)9;
                escribir<< (A[i].nip);
                escribir<< (char)9;
                escribir<< (A[i].saldo);
                escribir<< (char)10;
            }
            escribir.close();
            AbrirArchivo();

            clean();
            gotoxy(5,4);
            cout << "El deposito fue realizado con exito";
            gotoxy(5,6);
            cout<<"Volvera al menu principal en: ";
            gotoxy(37,6);
            cout<<"segundos";
            segundos(35,6,5);
            Menu_Principal();
    }
}

//------------------------------------------------------------------

void menubasedatos()///FUNCIONES PRIMARIAS
{
	AbrirArchivo();
	Inicio_de_sesion();
}


int main()
{
    menu();///LLAMADO interfaz cajero
    color(240);///COLOR QUE SE MANEJA EN LA PANTALLA
    menubasedatos();///LLAMADO AL CODIGO EN PANTALLA
    color(7);
    gotoxy(0,35);
}
