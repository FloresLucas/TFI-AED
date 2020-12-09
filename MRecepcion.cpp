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
void mostrarMascotas(FILE *Mascot, mascota reg);
void regMascotas(FILE *Mascot,mascota reg);

main()
{
    FILE *User;
    usuarios asist;
    
    FILE *Mascot;

    mascota reg;

    User=fopen("Asistentes.dat", "rb");

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
            fread(&asist,sizeof(usuarios),1,User);
            while (!feof(User))
            {
                if (strcmp(asist.usuario,auxus)==0)
                {
                    if (strcmp(asist.contrasenia,auxcont)==0)
                    {
                        system("cls");
                        printf("Se inicio sesion correctamente\n");
                        system("pause");
                        band=true;
                    }
                }
                
                fread(&asist,sizeof(usuarios),1,User);
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

            fclose(User);
        
        int opcion;
	do{
		system("cls");
		printf("\t      MENU DE OPCIONES\n");
        printf("\t================================");
		printf("\n\t1) Registrar Mascota\n");
		printf("\t2) Registrar Turno\n");
        printf("\t3) Listado de Atenciones por Veterinarios y Fecha\n");
		printf("\t0) Salir\n");
		printf("\n\tSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		

		switch(opcion){
			
			case 1:
                system("cls");
			    regMascotas(Mascot,reg);
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				// regAsist(User,asist);
				printf("\n");
				system("pause");
			break;
            case 3:
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
    
    remove("Mascotas.dat");
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

void regMascotas(FILE *Mascot,mascota reg)
{
    int r;

   Mascot=fopen("Mascotas.dat","a+b");
   
   printf("Ingrese el Apellido (Apellido del duenio) y Nombre de la Mascota: ");
   _flushall();
   gets(reg.apeynom);


   printf("\nIngrese el DNI del duenio de la Mascota: ");
   scanf("%d",&reg.dni);


   printf("\nIngrese la localidad del duenio de la Mascota: ");
   _flushall();
   gets(reg.localidad);

   printf("\nIngrese fecha de nacimiento: ");

   printf("\nDia: ");
   scanf("%d",&reg.edadNaci.dia);
    printf("Mes: ");
   scanf("%d",&reg.edadNaci.mes);
    printf("Anio: ");
   scanf("%d",&reg.edadNaci.anio);

    reg.edad = 2020-reg.edadNaci.anio;

    printf("Peso de la Mascota: ");
    scanf("%f",&reg.peso);

    fwrite(&reg,sizeof(mascota),1,Mascot);

    fclose(Mascot);

    printf("\nQuiere mostrar las mascotas ingresadas: \n");
    scanf("%d",&r);
    if (r==1)
    {
        mostrarMascotas(Mascot,reg);
    }
    
}

void mostrarMascotas(FILE *Mascot, mascota reg)
{
    Mascot=fopen("Mascotas.dat","rb");

     if(Mascot==NULL)
    {
        system("CLS");
        printf("\n\nNo existe el archivo todavia\n");
        printf("\nRegistrar previamente un usuario en el Modulo de Administracion\n");
        printf("\n\n\t");

    }
    else
    {
        system("cls");
        rewind(Mascot);
        fread(&reg,sizeof(mascota),1,Mascot);
        while (!feof(Mascot))
        {
            printf("Apellido y Nombre \t  D.N.I  \t Localidad  \t Edad \t Peso\n");
            printf("\n%s\t%d\t%s\t%d\t%0.2f",reg.apeynom,reg.dni,reg.localidad,reg.edad,reg.peso);
            fread(&reg,sizeof(mascota),1,Mascot);

        }
    }
    
}