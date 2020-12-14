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

struct turnos
{
    char apeynomM[100];
    char apeynomVet[100];
    int matri;
    fecha tur;
    int dniT;
    char atencion[380];
};



void clave(char auxcont[33]);
void regMascotas(FILE *Mascot,mascota reg);
void regTurnos(FILE *Mascot, mascota reg);
void mostrarAtenciones(turnos turno);

main()
{
    FILE *User;
    FILE *Mascot;
    usuarios asist;
    mascota reg;
    turnos turno;

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
                        system("cls");
                        printf("Bienvenido %s\n",asist.ApeyNom);
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
                printf("Mascota registrada\n");
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				regTurnos(Mascot,reg);
				printf("\n");
				system("pause");
			break;
            case 3:
                system("cls");
				mostrarAtenciones(turno);
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

void regMascotas(FILE *Mascot,mascota reg)
{
    int r;
    bool band=false;

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

    do
    {
        printf("\nDia: ");
        scanf("%d",&reg.edadNaci.dia);
        if (reg.edadNaci.dia>0 && reg.edadNaci.dia<32);
        {
            band=true;
        }
                    
    } while (!band);

    band=false;
    do
    {
        printf("Mes: ");
        scanf("%d",&reg.edadNaci.mes);
        if (reg.edadNaci.mes>0 && reg.edadNaci.mes<13)
        {
            band=true;
        }
                    
    } while (!band);
                
    band=false;
    do
    {
        printf("Anio: ");
        scanf("%d",&reg.edadNaci.anio);
        if (reg.edadNaci.anio>1000)
        {
            band=true;
        }
                    
    } while (!band);

    reg.edad = 2020-reg.edadNaci.anio;

    printf("Peso de la Mascota: ");
    scanf("%f",&reg.peso);

    fwrite(&reg,sizeof(mascota),1,Mascot);

    fclose(Mascot);


    // printf("\nQuiere mostrar las mascotas ingresadas: \n");
    // scanf("%d",&r);
    // if (r==1)
    // {
    //     mostrarMascotas(Mascot,reg);
    // }
    
}


void regTurnos(FILE *Mascot, mascota reg)
{
    FILE *Turnos;
    turnos turno;
    char auxApeNom[100];

    Mascot=fopen("Mascotas.dat","r+b");

    if(Mascot==NULL)
    {
        system("CLS");
        printf("No existe el archivo todavia\n");
        printf("\nRegistrar previamente una mascota en la opcion Registrar Mascota\n");
        printf("\n\n\t");

    }
    else
    {
        bool band=false;
        bool band1=false;
        
        do
        {
           printf("Ingrese el Apellido y Nombre de la mascota a registrar turno: ");
            _flushall();
            gets(auxApeNom);
            _flushall();
        
            rewind(Mascot);
            fread(&reg,sizeof(mascota),1,Mascot);
             Turnos=fopen("Turnos.dat","a+b");
            while (!feof(Mascot))
            {
                if (strcmp(reg.apeynom,auxApeNom)==0)
                {
                    strcpy(turno.apeynomM,reg.apeynom);
                    turno.dniT=reg.dni;

                    printf("Ingrese la fecha del dia: ");
                        
                    do
                    {
                        printf("\nDia: ");
                        scanf("%d",&turno.tur.dia);
                        if (turno.tur.dia>0 && turno.tur.dia<32);
                        {
                            band=true;
                        }
                            
                    } while (!band);

                    band=false;
                    do
                    {
                        printf("Mes: ");
                        scanf("%d",&turno.tur.mes);
                        if (turno.tur.mes>0 && turno.tur.mes<13)
                        {
                            band=true;
                        }
                            
                    } while (!band);
                        
                    band=false;
                    do
                    {
                        printf("Anio: ");
                        scanf("%d",&turno.tur.anio);
                        if (turno.tur.anio>1000)
                        {
                            band=true;
                            band1=true;
                        }
                            
                    } while (!band);
                        
                    fwrite(&turno,sizeof(turnos),1,Turnos);
                    }

                fread(&reg,sizeof(mascota),1,Mascot);

                }
            fclose(Mascot);
            fclose(Turnos);
        } while (!band1);

        system("cls");
        printf("Turno registrado correctamente\n");
    }
    

}


void mostrarAtenciones(turnos turno)
{
   FILE *Atent;
   
    Atent=fopen("Atenciones.dat","rb");

     if(Atent==NULL)
    {
        system("CLS");
        printf("\n\nNo existe el archivo todavia\n");
        printf("\nRegistrar previamente Atenciones Modulo de Consultorio\n");
        printf("\n\n\t");

    }
    else
    {
        system("cls");
        rewind(Atent);
        fread(&turno,sizeof(turnos),1,Atent);
        while (!feof(Atent))
        {
            printf("\tApellido y Nombre de la Mascota: %s\n",turno.apeynomM);
            printf("\tD.N.I: %d\n",turno.dniT);
            printf("\tApellido y Nombre del Veterinario: %s\n",turno.apeynomVet);
            printf("\tMatricula: %d\n",turno.matri);
            printf("\tFecha: %d/%d/%d\n",turno.tur.dia,turno.tur.mes,turno.tur.anio);
            printf("\tAtencion:\n\t%s",turno.atencion);
            printf("\n\n");
            fread(&turno,sizeof(turnos),1,Atent);
        }

        fclose(Atent);
    }
}


















// void mostrarMascotas(FILE *Mascot, mascota reg)
// {
//     Mascot=fopen("Mascotas.dat","rb");

//      if(Mascot==NULL)
//     {
//         system("CLS");
//         printf("\n\nNo existe el archivo todavia\n");
//         printf("\nRegistrar previamente un usuario en el Modulo de Administracion\n");
//         printf("\n\n\t");

//     }
//     else
//     {
//         system("cls");
//         rewind(Mascot);
//         fread(&reg,sizeof(mascota),1,Mascot);
//         while (!feof(Mascot))
//         {
//             printf("Apellido y Nombre \t  D.N.I  \t Localidad  \t Edad \t Peso\n");
//             printf("\n%s\t%d\t%s\t%d\t%0.2f",reg.apeynom,reg.dni,reg.localidad,reg.edad,reg.peso);
//             fread(&reg,sizeof(mascota),1,Mascot);

//         }
//     }
    
// }