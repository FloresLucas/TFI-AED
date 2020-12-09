#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct fecha
{
	int dia;
	int mes;
	int anio;
};
struct usuarios
{
    char usuario[11];
    char contrasenia[33];
    char ApeyNom[60];
};

struct veterinario
{
    char apeynomV[60];
    int matri;
    int dniV;
    char telefo[25];
};
struct turnos
{
    char apeynomM[100];
    int matri;
    fecha tur;
    int dniT;
    char atencion[380];
};
struct mascota
{
    char apeynom[100];
    int dni;
    char localidad[50];
    fecha edadNaci;
    int edad;
    fecha fec;
    float peso;
};

void clave(char auxcont[33]);
void listarTurnos(turnos turno);

main()
{
    FILE *User;
    usuarios vet;
    turnos turno;

    User=fopen("Usuarios.dat", "rb");

    if(User==NULL)
    {
        system("CLS");
        printf("\n\nNo existe el archivo todavia\n");
        printf("\nRegistrar previamente un usuario en el Modulo de Administracion\n");
        printf("\n\n\t");

    }
    else
    {
        system("cls");
        printf("Iniciar Sesion\n");
        system("pause");
        system("cls");

        char auxus[11];
        char auxcont[33];
        bool band=false;
        do
        {
            printf("Usuario: ");
            _flushall();
            gets(auxus);
            printf("Contrasenia: ");
            _flushall();
            clave(auxcont);

            rewind(User);
            fread(&vet,sizeof(usuarios),1,User);
            while (!feof(User))
            {
                if (strcmp(vet.usuario,auxus)==0)
                {
                    if (strcmp(vet.contrasenia,auxcont)==0)
                    {
                        system("cls");
                        printf("Se inicio sesion correctamente\n");
                        system("pause");
                        band=true;
                    }
                }
                
                fread(&vet,sizeof(usuarios),1,User);
            }
            if (band==false)
            {
                system("cls");
                printf("Nombre de usuario o contrasenia incorrectos\n");
                system("pause");
                system("cls");
            }
            else
            {
            } 
            } while (!band);

        
        int opcion;
	do{
		system("cls");
		printf("\t      MENU DE OPCIONES\n");
        printf("\t================================");
		printf("\n\t1) Mostrar Lista de Espera de Turnos\n");
		printf("\t2) Registrar Evolucion de la Mascota\n");
		printf("\t0) Salir\n");
		printf("\n\tSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		

		switch(opcion){
			
			case 1:
				system("cls");
                listarTurnos(turno);
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				// regAsist(User,asist);
				printf("\n");
				system("pause");
			break;  
			case 0:
			break; 
			default:
				system("cls");
				printf("Opcion Incorrecta\n");
				system("pause");
			break;  
			
			
		}
	}
	while(opcion!=0);
    }
}

void clave(char auxcont[33])
{
	int i = 0;	/* Indica la posici�n del caracter le�do en la cadena */
	char caracter;
	while (caracter = getch()) 
    {
		if(caracter  == 13)
        {
            auxcont[i] = '\0';
            break;
        }
        else if (caracter == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                if (i < 33)
                {
                    printf("*");
                    auxcont[i] = caracter;
		            i++;
                }
                
            }
            
    }
        
}

void listarTurnos(turnos turno)
{
    FILE *Turno;
    int r;

    Turno=fopen("Turnos.dat","rb");
    if(Turno==NULL)
    {
        system("CLS");
        printf("No existe el archivo todavia\n");
        printf("\nRegistrar previamente un turno en el modulo Recepcion\n");
        printf("\n\n\t");

    }
    else
    {
        rewind(Turno);

        printf("Mascota \t  D.N.I  \t Fecha\n");
        fread(&turno,sizeof(turnos),1,Turno);
        while (!feof(Turno))
        {
            printf("\n%s \t %d\t %d/%d/%d\n",turno.apeynomM,turno.dniT,turno.tur.dia,turno.tur.mes,turno.tur.anio);
            
            fread(&turno,sizeof(turnos),1,Turno);
        }

        printf("\nIngrese 1 si desea tomar el turno: ");
        scanf("%d",&r);

        if (r==1)
        {
            system("cls");
            printf("Turno tomado\n");
            
        }
        
        
    }
}
	







    //     rewind(User);
    //     fread(&vet,sizeof(usuarios),1,User);
    //     while (!feof(User)) 
    //     {
    //         printf("Usuario: %s\n",vet.usuario);
    //         printf("Contrasenia: %s\n",vet.contrasenia);
    //         printf("\n");
    //         fread(&vet,sizeof(usuarios),1,User);
    //     }
    // }