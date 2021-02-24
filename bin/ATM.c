#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <dos.h>;
#include <string.h>;
/*#include "C:\TC20\REM\Projects\include\TOOLS.H"*/

/*Arreglar el ingresar saldo ATM_UNI*/

#define MAX_STRLN 256
#define enye 164
#define up 72
#define down 80
#define enter 13
#define blok 219

typedef struct
{
    char user[MAX_STRLN];
    int password;
} accounts;

void Start(void);
void Menu(void);
void Exit(void);
void Exit_Option(void);
void Presentation(void);
void Recargas(void);
void ATM(void);
void Remove_Cursor(int x, int y);
void Frame(int lineas);

int RemainingAttemps = 3, Balance = 0;

accounts assigned;

void main()
{
    strcpy(assigned.user, "luis");
    assigned.password = 2302;
    Start();
}

void Start(void)
{
    accounts c1;

    clrscr();

    if (RemainingAttemps == 0)
    {
        Exit();
    }
    else
    {
        Frame(1);

        textcolor(RED);
        gotoxy(18, 6);
        cprintf("Project IDEDIM - Inspirado DEl DIno de la Mitch :D");

        textcolor(BLUE);
        gotoxy(24, 10);
        cprintf("Usuario : ");
        textcolor(WHITE);
        scanf("%s", &c1.user);

        textcolor(BLUE);
        gotoxy(24, 14);
        cprintf("Contrase%ca : ", enye);
        textcolor(WHITE);
        scanf("%d", &c1.password);

        if (strcmp(c1.user, assigned.user) == 0 && c1.password == assigned.password)
        {
            Menu();
        }
        else if (strcmp(c1.user, assigned.user) == 0 && c1.password != assigned.password)
        {
            gotoxy(24, 17);
            printf("Contrase%ca Incorrecta", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            printf("Le restan %d intentos", RemainingAttemps);
            Remove_Cursor(4,4);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password == assigned.password)
        {
            gotoxy(24, 17);
            printf("Usuario Incorrecto");

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            printf("Le restan %d intentos", RemainingAttemps);
            Remove_Cursor(4,4);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password != assigned.password)
        {
            gotoxy(24, 17);
            printf("Usuario y Contrase%ca Incorrectos", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            printf("Le restan %d intentos", RemainingAttemps);
            Remove_Cursor(4,4);
            getch();
            Start();
        }
    }
}

void Menu(void)
{
    int i, opc, tecla = 0, option = 1, exit = 0;
    char *menu_options[] = {"Presentacion", "Cajero ATM-UNI", "Recargas Tigo-Claro", "Salir", "\0"};
    int PosY[4] = {10,12,14,16}; 
    do
    {
        clrscr();
        Frame(1);
		textcolor(BLUE);
        gotoxy(30,7);
        cprintf("MENU PRINCIPAL");

        for (i = 0; i < 4; i++)
        {
            textcolor(3+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i+1 == option ? 16 : 0, menu_options[i]);
        }

        Remove_Cursor(4,4);

        do
        {
            tecla = getch();
        } while (tecla != enter && tecla != up && tecla != down);

        switch (tecla)
        {
            case up:
                option--;
                if (option < 1) 
                    option = 4;
                break;
            case down:
                option++;
                if (option > 4) 
                    option = 1;
                break;
            case enter:
                exit = 1;
            default:
                break;
        }
    } while (exit == 0);

    opc = option;

    switch (opc)
    {
    case 1:
        Presentation();
        break;
    case 2:
        ATM();
        break;
    case 3:
        Recargas();
        break;
    case 4:
        Exit_Option();
        break;
    default:
        break;
    }
}

void Presentation(void)
{
    int i,j = 0;
    char *Presentation_Elements[] = {"NOMBRE  :", "FECHA   :", "GRUPO   :", "PROFE   :", "CARRERA :","\0"};
    char *Presentation_Complements[] = {"Luis Joseph","26/02/2021", "2M1-CO", "Alejandro Ortiz - Aliz","Ing. Computacion","\0"};

    clrscr();
    Frame(2);
    textcolor(BLUE);
    gotoxy(20,4);
    cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA - UNI");

    for (i = 0; i < 5; i++)
    {
        textcolor(BLUE);
        gotoxy(25, 8 + j);
        cprintf("%s",Presentation_Elements[i]);
        textcolor(CYAN);
        gotoxy(35, 8 + j);
        cprintf("%s",Presentation_Complements[i]);
        j = j + 3;
    }

    Remove_Cursor(4,4);

    getch();
    Menu();
}

void ATM(void)
{
    int i,opt,t = 0,option = 1, ex = 0;
    int Deposit = 0, Retirement = 0, PosY[4] = {10,12,14,16};
    char *Options[] = {"Ingresar Saldo","Retirar Saldo","Consultar Saldo","Atras","\0"};

    do
    {
        clrscr();
        Frame(1);
        textcolor(4);
        gotoxy(28, 7);
        cprintf("BIENVENIDO A ATM-UNI");

        for (i = 0; i < 4; i++)
        {
            textcolor(5+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i + 1 == option ? 16 : 0,Options[i]);
        }
        
        Remove_Cursor(4,4);

        do
        {
            t = getch();
        } while (t != up && t != down && t != enter);
        
        switch (t)
        {
        case up:
            option--;
            if (option < 1) 
                option = 4;
            break;
        case down:
            option++;
            if (option > 4)
                option = 1;
            break;
        case enter:
            ex = 1;
        default:
            break;
        }
    } while (ex == 0);
    
    opt = option;

    switch (opt)
    {
    case 1:
        do
        {
            clrscr();
            fflush(stdin);
            printf("Digite la cantidad a Depositar\n");
            printf("C$ ");
            scanf("%d", &Deposit);
        } while (Deposit <= 0 || Deposit > 30000);

        Balance = Balance + Deposit;

        printf("Se ha depositado correctamente la cantidad de C$ %d netos",Deposit);
        getch();
        ATM();
        break;
    case 2:
        if (Balance == 0)
        {
            clrscr();
            printf("No tiene saldo en la cuenta");
        }else
        {
            do 
            {
                clrscr();
                fflush(stdin);
                printf("Digite la cantidad a Retirar\n");
                printf("C$ ");
                scanf("%d", &Retirement);
			}while (Retirement <= 0 || Retirement > Balance);

            Balance = Balance - Retirement;

            printf("\nSe ha retirado correctamente la cantidad de C$ %d netos",Retirement);
        }
        getch();
        ATM();
        break;
    case 3:
        clrscr();
        printf("Su saldo es C$ %d", Balance);
        getch();
        ATM();
        break;
    case 4:
        Menu();
    default:
        break;
    }}

void Recargas(void)
{
    int Amount_Entered = 0;
    long int CellPhone_Number = 0;
    float Four_Numbers = 0;
    char Company[MAX_STRLN];

    if (Balance == 0)
    {
        clrscr();
        printf("No tiene saldo en la cuenta");
        getch();
    }else
    {
        clrscr();
        fflush(stdin);
        printf("Ingrese su numero telefonico\n");
        scanf("%ld",&CellPhone_Number);

        Four_Numbers = CellPhone_Number / 10000;

        if (Four_Numbers > 5500 && Four_Numbers < 5999)
        {
            strcpy(Company,"Claro");
            printf("Su numero %ld es %s",CellPhone_Number,Company);
            getch();
        }else if (Four_Numbers > 7700 && Four_Numbers < 8700)
        {
            strcpy(Company,"Tigo");
            printf("Su numero %ld es %s",CellPhone_Number,Company);
            getch();
        }else
        {
            printf("\nNumero no encontrado");
            getch();
            Recargas();
        }

        while(Amount_Entered == 0)
        {
            clrscr();
            fflush(stdin);
            printf("Ingrese la cantidad a recargar\n");
            printf("C$ ");
            scanf("%d",&Amount_Entered);

            if (Amount_Entered > Balance)
            {
                clrscr();
                printf("La cantidad a recargar supera el saldo actual\n");
                printf("Su saldo actual es : C$ %d",Balance);
                Amount_Entered = 0;
                getch();
            }else if (Amount_Entered <= 0)
            {
                clrscr();
                printf("La cantidad a recargar es negativa o nula\n");
                printf("Su saldo actual es : C$ %d",Balance);
                Amount_Entered = 0;
                getch();
            }else
            {
                Balance = Balance - Amount_Entered;
                printf("\nSe ha realizado la recarga con exito al numero %li de la compa%cia %s",CellPhone_Number,enye,Company);
                getch();
            }
        }
    }
    Menu();
}

void Exit_Option(void)
{
    clrscr();
    printf("Fue un placer atenderle...\n");
    printf("Hacer su transaccion aqui es seguro, rapido y sencillo\n");
    printf("Le esperamos nuevamente :D "),
    getch();
}

void Exit(void)
{
    clrscr();
    printf("Ha agotado sus 3 intentos\n\n");
    printf("-------------------------\n\n");
    printf("Estimado Usuario : %s\n\n",assigned.user);
    printf("Su cuenta sera bloqueada por 24 horas por motivos de seguridad\n\n");
    printf("Gracias por su comprension");
    getch();
}

void Remove_Cursor(int x, int y)
{
    textcolor(BLACK);
    gotoxy(x,y);
    cprintf("%c",blok);
    gotoxy(x,y);
}

void Frame(int lineas)
{
    int i;
    char lineaH=196, lineaV=179, esquinaNW=218, esquinaNE=191, esquinaSW=192, esquinaSE=217;

    if(lineas!=1)
    {
        lineaH = 205;
        lineaV = 286;
        esquinaNW = 201;
        esquinaNE = 187;
        esquinaSW = 200;
        esquinaSE = 188;
    }

    textcolor(CYAN);
    for(i=2;i<=79;i++)
    {
        gotoxy(i,1);
        if(i!=2&&i!=79)
            cprintf("%c",lineaH);
        else if(i==2)
            cprintf("%c",esquinaNW);
        else
            cprintf("%c",esquinaNE);
        
        gotoxy(i,25);
        if(i!=2&&i!=79)
            cprintf("%c",lineaH);
        else if(i==2)
            cprintf("%c",esquinaSW);
        else
            cprintf("%c",esquinaSE);
        
        if(i>=2&&i<=24)
        {
            gotoxy(2,i);
            cprintf("%c",lineaV);
            
            gotoxy(79,i);
            cprintf("%c",lineaV);
        }
    }
}