#include <C:\\TC20\\include\\stdio.h>;
#include <C:\\TC20\\include\\stdlib.h>;
#include <C:\\TC20\\include\\conio.h>;
#include <C:\\TC20\\include\\dos.h>;
#include <C:\\TC20\\include\\string.h>;
#include "C:\\TC20\\repos\\Projects\\include\\TOOLS.H"

#define MAX_STRLN 256
#define enye 164
#define up 72
#define down 80
#define enter 13
#define blok 219

typedef struct
{
    string user;
    string password;
} accounts;

void Start(void);
void Menu(void);
void Exit(void);
void Exit_Option(void);
void Presentation(void);
void Recargas(void);
void ATM(void);
void Frame(int lineas);
float Dollar_Value(void);

/*void Date(int x1, int y1, int x2, int y2, int FirstColor, int SecondColor);*/

int RemainingAttemps = 3;
float Balance = 0, CurrentDolar_Value = 0;

accounts assigned;
bool isActive;

void main()
{
    assigned.user = "luis";
    assigned.password = "2602";
	CurrentDolar_Value = Dollar_Value();
    if (CurrentDolar_Value == 0)
    {
        isActive = false;
    }else
    {
        isActive = true;
    }
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
        gotoxy(19, 6);
        cprintf("Project Bank's Avanced Register - BAR :D");
        gotoxy(18, 7);

        textcolor(BLUE);
        gotoxy(32, 10);
        MinStrLn = 2;
        MaxStrLn = 7;
        isPassword = false;
        get_string("Usuario: ",c1.user);
        
        textcolor(BLUE);
        gotoxy(32, 14);
        MinStrLn = 3;
        MaxStrLn = 6;
        isPassword = true;
        get_string("Contra: ",c1.password);

        if (strcmp(c1.user, assigned.user) == 0 && strcmp(c1.password, assigned.password) == 0)
        {
            Menu();
        }
        else if (strcmp(c1.user, assigned.user) == 0 && strcmp(c1.password, assigned.password) != 0)
        {
            textcolor(WHITE);
            gotoxy(32, 17);
            cprintf("Contrase%ca Incorrecta", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(32, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && strcmp(c1.password, assigned.password) == 0)
        {
            textcolor(WHITE);
            gotoxy(32, 17);
            cprintf("Usuario Incorrecto");

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(32, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && strcmp(c1.password, assigned.password) != 0)
        {
            textcolor(WHITE);
            gotoxy(32, 17);
            cprintf("Usuario y Contrase%ca Incorrectos", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(32, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
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

        textcolor(RED);
        gotoxy(5,3);
        cprintf("Usuario : %s",assigned.user);
        gotoxy(5,4);
        cprintf("Saldo : C$ %0.2f",Balance);

		textcolor(BLUE);
        gotoxy(30,7);
        cprintf("MENU PRINCIPAL");

        for (i = 0; i < 4; i++)
        {
            textcolor(3+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i+1 == option ? 16 : 0, menu_options[i]);
        }

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

    getch();
    Menu();
}

void ATM(void)
{
    int i,opt,t = 0,option = 1, ex = 0;
    int Deposit = 0, Retirement = 0, PosY[4] = {10,12,14,16};
    char *Options[] = {"Ingresar Saldo","Retirar Saldo","Consultar Saldo","Atras","\0"}, M;

    /*Date(55,25,58,23,4,6);*/

    do
    {
        clrscr();
        Frame(1);

        textcolor(RED);
        gotoxy(5,3);
        cprintf("Usuario : %s",assigned.user);

        textcolor(4);
        gotoxy(28, 7);
        cprintf("BIENVENIDO A ATM-UNI");

        for (i = 0; i < 4; i++)
        {
            textcolor(5+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i + 1 == option ? 16 : 0,Options[i]);
        }

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
            Frame(1);

            textcolor(RED);
            gotoxy(25,10);
            cprintf("Elija la moneda a depositar");

            textcolor(BLUE);
            gotoxy(24,12);
            cprintf("C - Cordobas      D - Dolares");

            textcolor(GREEN);
            gotoxy(35,14);
            cprintf("Letra: ");

            gotoxy(42,14);
            scanf("%s",&M);

        }while (M != 'D' && M != 'd' && M != 'c' && M != 'C');

        if (strcmp(M,'D')==0 || strcmp(M,'d')==0 && isActive == true)
        {
            do
            {
                clrscr();      
                gotoxy(18,9);
                textcolor(CYAN);
                cprintf("Digite la cantidad a depositar en Dolares ($) netos");
				gotoxy(39,11);
                textcolor(BLUE);
                cprintf("$ ");
                gotoxy(41,11);
                scanf("%d", &Deposit);
			}while (Deposit <= 0 || Deposit > 2000);

            Balance = Balance + (Deposit * CurrentDolar_Value);

            gotoxy(14,14);
            textcolor(WHITE);
            cprintf("Se ha depositado correctamente la cantidad de $ %d netos",Deposit);

            gotoxy(19,16);
            textcolor(DARKGRAY);
            cprintf("Cambio Actual del Dolar a Cordobas : %f",CurrentDolar_Value);
        }else if (isActive == false)
        {
            gotoxy(28,16);
            printf("Error en precio de dolar");
        }

        if (strcmp(M,'C')==0 || strcmp(M,'c')==0)
        {
            do
            {
                clrscr();      
                gotoxy(18,9);
                textcolor(CYAN);
                cprintf("Digite la cantidad a depositar en cordobas (C$) netos");
                gotoxy(38,11);
                textcolor(BLUE);
                cprintf("C$ ");
                gotoxy(41,11);
                scanf("%d", &Deposit);
			}while (Deposit <= 0 || Deposit > 30000);

            Balance = Balance + Deposit;

            textcolor(WHITE);
            gotoxy(14,14);
            cprintf("Se ha depositado correctamente la cantidad de C$ %d netos",Deposit);
        }

        getch();
        ATM();
        break;
    case 2:
        if (Balance == 0)
        {
            clrscr();
            Frame(1);
            textcolor(BLUE);
            gotoxy(27,11);
            cprintf("No tiene saldo en la cuenta");
            gotoxy(24,13);
            cprintf("Intente Ingresar saldo a su cuenta");
        }else if ( Balance < 50 && Balance > 0)
        {
            clrscr();
            Frame(1);
            textcolor(BLUE);
            gotoxy(25,11);
            cprintf("No tiene saldo suficiente para retirar");
            gotoxy(24,13);
            cprintf("El saldo minimo a retirar es C$ 50  o  $1");
            gotoxy(27,15);
            cprintf("Su saldo actual es C$ %0.2f",Balance);
        }else
        {
            do
            {
                clrscr();
                Frame(1);
                textcolor(RED);
                gotoxy(25,10);
                cprintf("Elija la moneda a retirar\n\n");

                textcolor(BLUE);
                gotoxy(24,12);
                cprintf("C - Cordobas      D - Dolares");

                textcolor(GREEN);
                gotoxy(35,14);
                cprintf("Letra: ");

                gotoxy(42,14);
                scanf("%s",&M);
            }while (M != 'D' && M != 'd' && M != 'c' && M != 'C');

			if (strcmp(M,'D')==0 || strcmp(M,'d')==0 && isActive == true)
            {
                do
                {
                    clrscr();     
                    Frame(1); 
                    gotoxy(18,9);
                    textcolor(CYAN);
                    cprintf("Digite la cantidad a retirar en Dolares ($) netos");

                    gotoxy(39,11);
                    textcolor(BLUE);
                    cprintf("$ ");

					gotoxy(41,11);
                    scanf("%d", &Retirement);
				}while (Retirement <= 0 || Retirement > 2000 || Retirement > (Balance / CurrentDolar_Value));

				Balance = Balance - (Retirement * CurrentDolar_Value);

                gotoxy(14,14);
                textcolor(WHITE);
                cprintf("Se ha retirado correctamente la cantidad de $ %d netos",Retirement);

                gotoxy(19,16);
                textcolor(WHITE);
				cprintf("Cambio Actual del Dolar a Cordobas : %f",CurrentDolar_Value);
            }else if (isActive == false)
            {
                gotoxy(28,16);
                printf("Error en precio de dolar");
            }

            if (strcmp(M,'C')==0 || strcmp(M,'c')==0)
            {
                do
                {
                    clrscr();  
                    Frame(1);
                    gotoxy(18,9);
                    textcolor(CYAN);    
                    cprintf("Digite la cantidad a retirar en cordobas (C$) netos\n");

                    gotoxy(38,11);
                    textcolor(BLUE);
                    cprintf("C$ ");

                    gotoxy(41,11);
                    scanf("%d", &Retirement);
                }while (Retirement <= 0 || Retirement > 30000 || Retirement > Balance);

                Balance = Balance - Retirement;

                textcolor(WHITE);
                gotoxy(14,14);
                cprintf("Se ha retirado correctamente la cantidad de C$ %d netos",Retirement);
            }
        }
        getch();
        ATM();
        break;
    case 3:
        clrscr();
        Frame(2);
        textcolor(RED);
        gotoxy(36,9);
        cprintf("ATM - UNI");

        textcolor(BLUE);
        gotoxy(30,11);
        cprintf("Su saldo es C$ %0.2f", Balance);

        gotoxy(19,13);
		cprintf("Cambio Actual del Dolar a Cordobas : %f",CurrentDolar_Value);

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

    if (Balance == 0 || Balance < 10)
    {
        textcolor(BLUE);
        clrscr();
        cprintf("No tiene saldo en la cuenta o es menor a C$ 10");
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

        while(Amount_Entered == 0 || Amount_Entered < 10)
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
                printf("Su saldo actual es : C$ %0.2f",Balance);
                Amount_Entered = 0;
                getch();
            }else if (Amount_Entered <= 0)
            {
                clrscr();
                printf("La cantidad a recargar es negativa o nula\n");
                printf("Su saldo actual es : C$ %0.2f",Balance);
                Amount_Entered = 0;
                getch();
            }else if (Amount_Entered < 10 && Amount_Entered > 0)
            {
                clrscr();
                printf("La cantidad a recargar es menor a C$ 10\n");
                printf("Su saldo actual es : C$ %0.2f",Balance);
                Amount_Entered = 0;
                getch();
            }else
            {
                Balance = Balance - Amount_Entered;
                printf("\nSe ha realizado la recarga con exito de C$ %d al numero %li de la compa%cia %s",Amount_Entered,CellPhone_Number,enye,Company);
                getch();
            }
        }
    }
    Menu();
}

void Exit_Option(void)
{
    clrscr();
    textcolor(2);
    gotoxy(30,11);
    cprintf("Fue un placer atenderle...");

    textcolor(3);
    gotoxy(19,13);
    cprintf("Hacer su transaccion aqui es seguro, rapido y sencillo");

    textcolor(4);
    gotoxy(30,11);
    cprintf("Le esperamos nuevamente :D ");

    getch();
    exit(-1);
}

void Exit(void)
{
    clrscr();
    textcolor(BLUE);
    gotoxy(30,11);
    cprintf("Ha agotado sus 3 intentos");

    gotoxy(30,13);
    cprintf("-------------------------");

    gotoxy(30,15);
    cprintf("Estimado Usuario : %s",assigned.user);

    gotoxy(30,17);
    cprintf("Su cuenta sera bloqueada por 24 horas por motivos de seguridad");

	gotoxy(30,19);
    cprintf("Gracias por su comprension");
    getch();
    exit(-1);
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
}

float Dollar_Value(void)
{
    float Fixed_Dollar = 34.9380, NewPrice_Dollar = 0;
    float Monthly_Rise = 0.0795, Annual_Rise = 0.9541;
	int Fixed_Month = 2, Fixed_Year = 2021;
    int Current_Month = 0, Current_Year = 0, Month_Difference = 0, Year_Difference = 0;

    struct date d;
    struct time t;

    gettime(&t);
    getdate(&d);

    clrscr();

    Current_Month = d.da_mon;
    Current_Year = d.da_year;

    if (Current_Month >= Fixed_Month && Current_Year == Fixed_Year)
    {
        Month_Difference = Current_Month - Fixed_Month;
        NewPrice_Dollar = Fixed_Dollar + (Monthly_Rise * Month_Difference);
    }else if (Current_Month >= Fixed_Month && Current_Year > Fixed_Year)
    {
        Year_Difference = Current_Year - Fixed_Year;
        Month_Difference = Current_Month - Fixed_Month;
        NewPrice_Dollar = Fixed_Dollar + (Annual_Rise * Year_Difference) + (Monthly_Rise * Month_Difference);
        getch();
    }else
    {
        NewPrice_Dollar = 0;
    }

    return NewPrice_Dollar;
}

/*
void Date(int x1, int y1, int x2, int y2, int FirstColor, int SecondColor)
{
    struct date d;
    struct time t;
    int ejm = 0;

    while (ejm < 60)
    {
        gettime(&t);
        getdate(&d);

        clrscr();

        gotoxy(x1, y1);
        textcolor(FirstColor);
        cprintf("Fecha : %d / %02d / %d \n", d.da_day, d.da_mon,d.da_year);

        gotoxy(x2,y2);
        textcolor(SecondColor);
        cprintf("Hora : %d: %d: %d", t.ti_hour, t.ti_min, t.ti_sec);

        ejm = t.ti_sec;

        sleep(1);

        if (ejm == 59)
        {
            ejm = 0;
        }
    }
}*/