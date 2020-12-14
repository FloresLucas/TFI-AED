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
struct veterinario
{
    char usuario[11];
    char contrasenia[33];
    char apeynomV[60];
    int matri;
    int dniV;
    char telefo[25];
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
void regEV(turnos turno,char auxus[11]);
// void pasarTurnos(FILE *Turno,turnos turno);
void mostrarAtenciones(FILE *Atent,turnos turno);
// void mostrarMascotas(FILE *Mascot, char s[60]);

main()
{
    FILE *Vet;
    veterinario vet;
    turnos turno;
    char s[60];

   Vet=fopen("Veterinarios.dat", "rb");

    if(Vet==NULL)
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
            
            rewind(Vet);
            fread(&vet,sizeof(veterinario),1,Vet);
            while (!feof(Vet))
            {
                if (strcmp(vet.usuario,auxus)==0)
                {
                    if (strcmp(vet.contrasenia,auxcont)==0)
                    {
                        system("cls");
                        printf("Bienvenido %s\n",vet.apeynomV);
                        printf("\n");
                        system("pause");
                        band=true;

                    }
                }
                
                fread(&vet,sizeof(veterinario),1,Vet);
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
				regEV(turno,auxus);
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

    remove("Tempfile.dat");

    }
}


void listarTurnos(turnos turno)
{
    FILE *Turno;
    FILE *fileAux;
    FILE *EV;
    

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
        char s[60];
        int r;
        rewind(Turno);

        printf("Mascota \t  D.N.I  \t Fecha\n");
        fread(&turno,sizeof(turnos),1,Turno);
        while (!feof(Turno))
        {
            printf("\n%s \t %d\t %d/%d/%d\n",turno.apeynomM,turno.dniT,turno.tur.dia,turno.tur.mes,turno.tur.anio);
            
            fread(&turno,sizeof(turnos),1,Turno);
        }

        printf("\nIngrese el apellido y nombre a la mascota que atendera: ");
        _flushall();
        gets(s);
        _flushall();
        
        bool band=false;
        do
        {
            rewind(Turno);
            fread(&turno,sizeof(turnos),1,Turno);
            while (!feof(Turno))
            {
                if (strcmp(turno.apeynomM,s)==0)
                {
                    band=true;
                }

                fread(&turno,sizeof(turnos),1,Turno);
            }

            if (r=!1)
            {
                system("cls");
                printf("El apellido y nombre ingresado no se encuentra en la lista\n");
                system("pause");
            }
            

        } while (!band);
        
        fileAux=fopen("Tempfile.dat", "w+b");
        EV=fopen("Evolucion.dat","w+b");
         
        rewind(Turno);
        
        fread(&turno,sizeof(turnos),1,Turno);
        while (!feof(Turno))
        {
            if(strcmp(turno.apeynomM,s)==0)
            {
                fwrite(&turno,sizeof(turnos),1,EV);
            }
            else
            {
                fwrite(&turno,sizeof(turnos),1,fileAux);
            }
            
            fread(&turno,sizeof(turnos),1,Turno);
        }

            fclose(Turno);
            fclose(fileAux);
            fclose(EV);
    }
}


void regEV(turnos turno,char auxus[11])
{
    FILE *EV;
    FILE *Atent;
    FILE *Mascot;
    FILE *Vet;
    mascota reg;

    veterinario vet;
    char s[60];
    EV=fopen("Evolucion.dat","rb");

    if(EV==NULL)
    {
        system("CLS");
        printf("No existe el archivo todavia\n");
        printf("\nNo se encuentra ningun turno seleccionado para realziar\n");
        printf("\n\n\t");
    }
    else
    {
        bool band=false;
        bool band1=false;
        
        rewind(EV);
        fread(&turno,sizeof(turnos),1,EV);
        strcpy(s,turno.apeynomM);
        fclose(EV);

        
        mostrarMascotas(Mascot,s);

        Atent=fopen("Atenciones.dat","a+b");

        Mascot=fopen("Mascotas.dat","rb");

        rewind(Mascot);
        fread(&reg,sizeof(mascota),1,Mascot);
        while (!feof(Mascot))
        {
            if (strcmp(reg.apeynom,s)==0)
            { 
                turno.dniT=reg.dni;
                strcpy(turno.apeynomM,reg.apeynom);
            }
            fread(&reg,sizeof(mascota),1,Mascot);
        }
        fclose(Mascot);

        Vet=fopen("Veterinarios.dat","rb");

        rewind(Vet);
        fread(&vet,sizeof(veterinario),1,Vet);
        while (!feof(Vet))
        {
            if (strcmp(vet.usuario,auxus)==0)
            {
                turno.matri=vet.matri;
                strcpy(turno.apeynomVet,vet.apeynomV);
            }
            
            fread(&vet,sizeof(veterinario),1,Vet);
        }
        fclose(Vet);

        printf("\nIngrese la fecha de la Atencion: ");
                        
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
                }
                            
        } while (!band);
                        
        printf("Realize la evolucion de la Mascota: ");
        _flushall();
        gets(turno.atencion);
        _flushall();

        fwrite(&turno,sizeof(turnos),1,Atent);

        fclose(Atent);

        // mostrarAtenciones(Atent,turno);

        remove("Turnos.dat");
        rename("Tempfile.dat","Turnos.dat");
        remove("Evolucion.dat");
    }
    

}

void mostrarMascotas(FILE *Mascot, char s[60])
{
    Mascot=fopen("Mascotas.dat","rb");

    mascota reg;

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
       printf("Apellido y Nombre\tD.N.I\tLocalidad\tEdad\tPeso\n");
        while (!feof(Mascot))
        {
            if (strcmp(reg.apeynom,s)==0)
            {
                printf("\n%s\t%d\t%s\t%d\t%0.2f\n",reg.apeynom,reg.dni,reg.localidad,reg.edad,reg.peso);
            }
            
            fread(&reg,sizeof(mascota),1,Mascot);
        }
    }
    
}


// void mostrarAtenciones(FILE *Atent,turnos turno)
// {
//     Atent=fopen("Atenciones.dat","rb");

//      if(Atent==NULL)
//     {
//         system("CLS");
//         printf("\n\nNo existe el archivo todavia\n");
//         printf("\nRegistrar previamente un Turno en el Modulo de Recepcion\n");
//         printf("\n\n\t");

//     }
//     else
//     {
//         system("cls");
//         rewind(Atent);
//         fread(&turno,sizeof(turnos),1,Atent);
//         while (!feof(Atent))
//         {
//             printf("\tApellido y Nombre de la Mascota: %s\n",turno.apeynomM);
//             printf("\tD.N.I: %d\n",turno.dniT);
//             printf("\tApellido y Nombre del Veterinario: %s\n",turno.apeynomVet);
//             printf("\tMatricula: %d\n",turno.matri);
//             printf("\tAtencion:\n%s",turno.atencion);
//             printf("\n\n");
//         fread(&turno,sizeof(turnos),1,Atent);
//         }

//         fclose(Atent);
//     }
// }






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

