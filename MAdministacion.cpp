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
    char usuario[11];
    char contrasenia[33];
    char apeynomV[60];
    int matri;
    int dniV;
    char telefo[25];
    int contA;
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


void regVet(FILE *Vet,veterinario vet);
int sonConsecutivos(int prim, int segund);
int usercheck(FILE *Vet,char auxuser[11],veterinario vet);
int usercheckasi(FILE *User,char auxuser[11],usuarios asist);
void regAsist(FILE *User,usuarios asist);
void mostrarAtenciones(turnos turno);
void ranKatent(veterinario vet);
// void mostrarVet(FILE *Vet, veterinario vet);

main()
{
    FILE *User;
    FILE *Vet;
    veterinario vet;
    usuarios asist;
    turnos turno;
    
    int opcion;
	do{
		system("cls");
		printf("\t      MENU DE OPCIONES\n");
        printf("\t================================");
		printf("\n\t1) Registrar Veterinario\n");
		printf("\t2) Registrar Usuario Asistente\n");
		printf("\t3) Atenciones por Veterinario\n");
		printf("\t4) Ranking de Veterinarios por Atenciones\n");
		printf("\t0) Salir\n");
		printf("\n\tSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		

		switch(opcion){
            
			case 1:
				regVet(Vet,vet); //Funcion para registrar a un Veterinario encargados del Modulo de Consultorio 
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				regAsist(User,asist); //Funcion para registrar a un asistente encargados del Modulo de Recpcion
				printf("\n");
				system("pause");
			break; 
			case 3:
				system("cls");
				mostrarAtenciones(turno); //Funcion pra mostrar las atenciones registradas
				printf("\n");
				system("pause");
			break; 
			case 4:
				system("cls"); 
				ranKatent(vet); //Funcion que muestra al Veterinario con mas atenciones
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

void regVet(FILE *Vet,veterinario vet)
{
    int nn=0,i=0,l=0,p=0,t=0;
    char temp;
    bool band=false;
    do{
        system("cls");
        printf("Ingrese un nuevo nombre de usuario: ");
        _flushall();
        gets(vet.usuario);

        nn=strlen(vet.usuario);
    

    if (nn>=6 && nn<=10)
    {
        l=0;
        switch(vet.usuario[0]) // Veficica que el usuario empiece con minuscula 
            {
                case 'a': l++; break;
                case 'e': l++; break;
                case 'i': l++; break;
                case 'o': l++; break;
                case 'u': l++; break;
                case 'b': l++; break;
                case 'c': l++; break;
                case 'd': l++; break;
                case 'f': l++; break;
                case 'g': l++; break;
                case 'h': l++; break;
                case 'j': l++; break;
                case 'k': l++; break;
                case 'l': l++; break;
                case 'm': l++; break;
                case 'n': l++; break;
                case 'p': l++; break;
                case 'q': l++; break;
                case 'r': l++; break;
                case 's': l++; break;
                case 't': l++; break;
                case 'v': l++; break;
                case 'w': l++; break;
                case 'x': l++; break;
                case 'y': l++; break;
                case 'z': l++; break;
            }

        printf("\n%d\n",l);
        if(l>=1)
        {
            p=0;
            for(i=0;i<nn;i++)
            {
                
                switch(vet.usuario[i]) // Verifica que tenga al menos dos mayusculas
                {
                    case 'A': p++; break;
                    case 'E': p++; break;
                    case 'I': p++; break;
                    case 'O': p++; break;
                    case 'U': p++; break;
                    case 'B': p++; break;
                    case 'C': p++; break;
                    case 'D': p++; break;
                    case 'F': p++; break;
                    case 'G': p++; break;
                    case 'H': p++; break;
                    case 'J': p++; break;
                    case 'K': p++; break;
                    case 'L': p++; break;
                    case 'M': p++; break;
                    case 'N': p++; break;
                    case 'P': p++; break;
                    case 'Q': p++; break;
                    case 'R': p++; break;
                    case 'S': p++; break;
                    case 'T': p++; break;
                    case 'V': p++; break;
                    case 'W': p++; break;
                    case 'X': p++; break;
                    case 'Y': p++; break;
                   case 'Z': p++; break;
                }
            }
            if(p>=2)
            {
                t=0;
                for(i=0;i<nn;i++)
                {
                    switch(vet.usuario[i]) //Verifica que no tenga 3 numero seguidos
                    {
                        case '1': t++; break;
                        case '2': t++; break;
                        case '3': t++; break;
                        case '4': t++; break;
                        case '5': t++; break;
                        case '6': t++; break;
                        case '7': t++; break;
                        case '8': t++; break;
                        case '9': t++; break;
                        case '0': t++; break;	
                    }
                }
                if (t>3)
                {
                    system("cls");
                    printf("El nombre de usuario es incorrecto, debe tener debe tener como maximo 3 digitos\n");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    int h;
                    char auxuser[11];
                    strcpy(auxuser,vet.usuario);

                    h=usercheck(Vet, auxuser, vet);
                    if (h==1)
                    {
                        system("cls");
                        printf("El nombre de usuario es incorrecto, nombre de usuario no disponible\n");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Nombre de usuario registrado correctamente\n");
                        printf("\n");
                        system("pause");
                        band=true;
                    } 
                }
            }
            else
            {
                system("cls");
                printf("El nombre de usuario es incorrecto, debe tener al menos dos  mayusculas\n");
                printf("\n");
                system("pause");
                
            }
        }
        else
        {
            system("cls");
            printf("El nombre de usuario es incorrecto, debe empezar con misucula\n");
            printf("\n");
            system("pause");
                
        }
    }
    else
    {
        system("cls");
        printf("El nombre de usuario es incorrecto, debe entre 6 y 10 caracteres\n");
        printf("\n");
        system("pause");
    }
      
    }while(!band);

    bool band1=false;
    do
    {
        nn=0;
        int f=0,k=0,v=0,o=0,z=0;
        system("cls");
        printf("Ingrese una contrasenia para el nuevo usuario: ");
        _flushall();
        gets(vet.contrasenia);

        nn=strlen(vet.contrasenia);

        if (nn>=6 && nn<=32)
        {
            f=0;
            for(i=0;i<nn;i++)
            {
                switch(vet.contrasenia[i]) //Verfica quenotenga 3 numeros seguidos
                {
                    case '1': f++; break;
                    case '2': f++; break;
                    case '3': f++; break;
                    case '4': f++; break;
                    case '5': f++; break;
                    case '6': f++; break;
                    case '7': f++; break;
                    case '8': f++; break;
                    case '9': f++; break;
                    case '0': f++; break;
                    default: f=0;  break;
                   	
                }
                if(f>=3)
                {
                    k=1;
                }
            }
            if(f==0)
            {
                system("cls");
                printf("La contrasenia es incorrecta\n");
                printf("\n");
                system("pause");
            }
            else
            {
                if(k==1)
                {
                    system("cls");
                    printf("La contrasenia es incorrecta\n");
                    printf("\n");
                    system("pause");  
                }
                else
                {
                    
                    for(i=0;i<nn;i++)
                    {
                        switch(vet.contrasenia[i]) //Verifica que no tenga otros caracteres mas que los listados
                        {
                            case '1': o++; break;
                            case '2': o++; break;
                            case '3': o++; break;
                            case '4': o++; break;
                            case '5': o++; break;
                            case '6': o++; break;
                            case '7': o++; break;
                            case '8': o++; break;
                            case '9': o++; break;
                            case '0': o++; break;
                            case 'A': o++; break;
                            case 'E': o++; break;
                            case 'I': o++; break;
                            case 'O': o++; break;
                            case 'U': o++; break;
                            case 'B': o++; break;
                            case 'C': o++; break;
                            case 'D': o++; break;
                            case 'F': o++; break;
                            case 'G': o++; break;
                            case 'H': o++; break;
                            case 'J': o++; break;
                            case 'K': o++; break;
                            case 'L': o++; break;
                            case 'M': o++; break;
                            case 'N': o++; break;
                            case 'P': o++; break;
                            case 'Q': o++; break;
                            case 'R': o++; break;
                            case 'S': o++; break;
                            case 'T': o++; break;
                            case 'V': o++; break;
                            case 'W': o++; break;
                            case 'X': o++; break;
                            case 'Y': o++; break;
                            case 'Z': o++; break;
                            case 'a': o++; break;
                            case 'e': o++; break;
                            case 'i': o++; break;
                            case 'o': o++; break;
                            case 'u': o++; break;
                            case 'b': o++; break;
                            case 'c': o++; break;
                            case 'd': o++; break;
                            case 'f': o++; break;
                            case 'g': o++; break;
                            case 'h': o++; break;
                            case 'j': o++; break;
                            case 'k': o++; break;
                            case 'l': o++; break;
                            case 'm': o++; break;
                            case 'n': o++; break;
                            case 'p': o++; break;
                            case 'q': o++; break;
                            case 'r': o++; break;
                            case 's': o++; break;
                            case 't': o++; break;
                            case 'v': o++; break;
                            case 'w': o++; break;
                            case 'x': o++; break;
                            case 'y': o++; break;
                            case 'z': o++; break;
                            default: v=1;  break;
                        }
                    }
                    if (v==1)
                    {
                        system("cls");
                        printf("La contrasenia es incorrecta\n");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        if (o>=3)
                        {
                            for(i=0;i<nn;i++)
                            {
                                int prim = vet.contrasenia[i];
                                int segund = vet.contrasenia[i+1];
                                int dir=sonConsecutivos(prim,segund);  //Verifica que los carateres ingresados no sean consiguiente
                                if (dir==1)
                                {
                                    z++;
                                }
                                
                            }
                            if (z>0)
                            {
                                system("cls");
                                printf("La contrasenia es incorrecta,1\n");
                                printf("\n");
                                system("pause");
                            }
                            else
                            {
                                system("cls");
                                printf("Nueva contrasenia registrada correctamente\n");
                                printf("\n");
                                band1=true;
                            } 
                            
                        }
                        else
                        {
                            system("cls");
                            printf("La contrasenia es incorrecta\n");
                            printf("\n");
                            system("pause");
                        }
                        
                        
                    }
                }
            }  
        }
        else
        {
            system("cls");
            printf("La contrasenia es incorrecta\n");
            printf("\n");
            system("pause");
        }

    }while(!band1);
    
    
    Vet=fopen("Veterinarios.dat", "a+b");

    vet.usuario;
    vet.contrasenia;

    printf("\nUsuario veterinario registrado correctamente"); //Se ingresan los datos de los veterinarios a continuacion
    printf("\n\n");
    system("pause");
    system("cls");

    
    printf("Ingrese los datos del Veterinario\n");


    printf("\nIngrese Apellido y Nombre: ");
    _flushall();
    gets(vet.apeynomV);
    _flushall();

    printf("\nIngrese la matricula: ");
    scanf("%d",&vet.matri);

    printf("\nIngrese el D.N.I: ");
    scanf("%d",&vet.dniV);

    printf("\nIngrese el telefono: ");
    _flushall();
    gets(vet.telefo);
    _flushall();


    fwrite(&vet,sizeof(veterinario),1,Vet);

    fclose(Vet);
    
    // mostrarVet(Vet,vet);
    printf("\n");
    


}

void regAsist(FILE *User,usuarios asist)
{
  int nn=0,i=0,l=0,p=0,t=0;
  
    char temp;
    bool band=false;
    do{
        
        system("cls");
        printf("Ingrese un nuevo nombre de usuario: ");
        _flushall();
        gets(asist.usuario);

        nn=strlen(asist.usuario);
    

    if (nn>=6 && nn<=10)
    {
        switch(asist.usuario[0])
            {
                case 'a': l++; break;
                case 'e': l++; break;
                case 'i': l++; break;
                case 'o': l++; break;
                case 'u': l++; break;
                case 'b': l++; break;
                case 'c': l++; break;
                case 'd': l++; break;
                case 'f': l++; break;
                case 'g': l++; break;
                case 'h': l++; break;
                case 'j': l++; break;
                case 'k': l++; break;
                case 'l': l++; break;
                case 'm': l++; break;
                case 'n': l++; break;
                case 'p': l++; break;
                case 'q': l++; break;
                case 'r': l++; break;
                case 's': l++; break;
                case 't': l++; break;
                case 'v': l++; break;
                case 'w': l++; break;
                case 'x': l++; break;
                case 'y': l++; break;
                case 'z': l++; break;
            }

        printf("\n%d\n",l);
        if(l>=1)
        {   
            p=0;
            for(i=0;i<nn;i++)
            {
                
                switch(asist.usuario[i])
                {
                    case 'A': p++; break;
                    case 'E': p++; break;
                    case 'I': p++; break;
                    case 'O': p++; break;
                    case 'U': p++; break;
                    case 'B': p++; break;
                    case 'C': p++; break;
                    case 'D': p++; break;
                    case 'F': p++; break;
                    case 'G': p++; break;
                    case 'H': p++; break;
                    case 'J': p++; break;
                    case 'K': p++; break;
                    case 'L': p++; break;
                    case 'M': p++; break;
                    case 'N': p++; break;
                    case 'P': p++; break;
                    case 'Q': p++; break;
                    case 'R': p++; break;
                    case 'S': p++; break;
                    case 'T': p++; break;
                    case 'V': p++; break;
                    case 'W': p++; break;
                    case 'X': p++; break;
                    case 'Y': p++; break;
                   case 'Z': p++; break;
                }
            }
            if(p>=2)
            {   
                t=0;
                for(i=0;i<nn;i++)
                {
                    switch(asist.usuario[i])
                    {
                        case '1': t++; break;
                        case '2': t++; break;
                        case '3': t++; break;
                        case '4': t++; break;
                        case '5': t++; break;
                        case '6': t++; break;
                        case '7': t++; break;
                        case '8': t++; break;
                        case '9': t++; break;
                        case '0': t++; break;	
                    }
                }
                if (t>3)
                {
                    system("cls");
                    printf("El nombre de usuario es incorrecto, debe tener debe tener como maximo 3 digitos\n");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    int h;
                    char auxuser[11];
                    strcpy(auxuser,asist.usuario);

                    h=usercheckasi( User, auxuser, asist);
                    if (h==1)
                    {
                        system("cls");
                        printf("El nombre de usuario es incorrecto, nombre de usuario no disponible\n");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Nombre de usuario registrado correctamente\n");
                        printf("\n");
                        system("pause");
                        band=true;
                    } 
                }
            }
            else
            {
                system("cls");
                printf("El nombre de usuario es incorrecto, debe tener al menos dos  mayusculas\n");
                printf("\n");
                system("pause");
                
            }
        }
        else
        {
            system("cls");
            printf("El nombre de usuario es incorrecto, debe empezar con misucula\n");
            printf("\n");
            system("pause");
                
        }
    }
    else
    {
        system("cls");
        printf("El nombre de usuario es incorrecto, debe entre 6 y 10 caracteres\n");
        printf("\n");
        system("pause");
    }
      
    }while(!band);

    bool band1=false;
    do
    {
        nn=0;
        int f=0,k=0,v=0,o=0,z=0;
        system("cls");
        printf("Ingrese una contrasenia para el nuevo usuario: ");
        _flushall();
        gets(asist.contrasenia);

        nn=strlen(asist.contrasenia);

        if (nn>=6 && nn<=32)
        {
            f=0;
            for(i=0;i<nn;i++)
            {
                switch(asist.contrasenia[i])
                {
                    case '1': f++; break;
                    case '2': f++; break;
                    case '3': f++; break;
                    case '4': f++; break;
                    case '5': f++; break;
                    case '6': f++; break;
                    case '7': f++; break;
                    case '8': f++; break;
                    case '9': f++; break;
                    case '0': f++; break;
                    default: f=0;  break;
                    if(f>=3)
                    {
                        k=1;
                    }	
                }
            }
            if(k==1)
            {
                system("cls");
                printf("La contrasenia es incorrecta\n");
                printf("\n");
                system("pause");  
            }
            else
            {
                
                 for(i=0;i<nn;i++)
                {
                    switch(asist.contrasenia[i])
                    {
                        case '1': o++; break;
                        case '2': o++; break;
                        case '3': o++; break;
                        case '4': o++; break;
                        case '5': o++; break;
                        case '6': o++; break;
                        case '7': o++; break;
                        case '8': o++; break;
                        case '9': o++; break;
                        case '0': o++; break;
                        case 'A': o++; break;
                        case 'E': o++; break;
                        case 'I': o++; break;
                        case 'O': o++; break;
                        case 'U': o++; break;
                        case 'B': o++; break;
                        case 'C': o++; break;
                        case 'D': o++; break;
                        case 'F': o++; break;
                        case 'G': o++; break;
                        case 'H': o++; break;
                        case 'J': o++; break;
                        case 'K': o++; break;
                        case 'L': o++; break;
                        case 'M': o++; break;
                        case 'N': o++; break;
                        case 'P': o++; break;
                        case 'Q': o++; break;
                        case 'R': o++; break;
                        case 'S': o++; break;
                        case 'T': o++; break;
                        case 'V': o++; break;
                        case 'W': o++; break;
                        case 'X': o++; break;
                        case 'Y': o++; break;
                        case 'Z': o++; break;
                        case 'a': o++; break;
                        case 'e': o++; break;
                        case 'i': o++; break;
                        case 'o': o++; break;
                        case 'u': o++; break;
                        case 'b': o++; break;
                        case 'c': o++; break;
                        case 'd': o++; break;
                        case 'f': o++; break;
                        case 'g': o++; break;
                        case 'h': o++; break;
                        case 'j': o++; break;
                        case 'k': o++; break;
                        case 'l': o++; break;
                        case 'm': o++; break;
                        case 'n': o++; break;
                        case 'p': o++; break;
                        case 'q': o++; break;
                        case 'r': o++; break;
                        case 's': o++; break;
                        case 't': o++; break;
                        case 'v': o++; break;
                        case 'w': o++; break;
                        case 'x': o++; break;
                        case 'y': o++; break;
                        case 'z': o++; break;
                        default: v=1;  break;
                    }
                }
                if (v==1)
                {
                    system("cls");
                    printf("La contrasenia es incorrecta\n");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    z=0;
                    if (o>=3)
                    {
                        for(i=0;i<nn;i++)
                        {
        
                            int prim = asist.contrasenia[i];
                            int segund = asist.contrasenia[i+1];
                            int dir=sonConsecutivos(prim,segund);
                            if (dir==1)
                            {
                                z++;
                            }
                            
                        }    
                        if (z>0)
                        {
                            system("cls");
                            printf("La contrasenia es incorrecta\n");
                            printf("\n");
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            printf("Nueva contrasenia registrada correctamente\n");
                            printf("\n");
                            system("pause");
                            band1=true;
                        } 
                        
                    }
                    else
                    {
                        system("cls");
                        printf("La contrasenia es incorrecta\n");
                        printf("\n");
                        system("pause");
                    }
                    
                    
                }
                
            }
        }
        else
        {
            system("cls");
            printf("La contrasenia es incorrecta\n");
            printf("\n");
            system("pause");
        }

    }while(!band1);
    
    User=fopen("Asistentes.dat", "a+b");

    asist.usuario;
    asist.contrasenia;

    system("cls");
    printf("Ingrese el Apellido y Nombre del usuario %s: ",asist.usuario);
    _flushall();
    gets(asist.ApeyNom);
    _flushall();
    
    fwrite(&asist,sizeof(usuarios),1,User);

    system("cls");
    printf("Usuario registrado correctamente");
    printf("\n");
    fclose(User);  
}

     
int sonConsecutivos(int prim, int segund)
{
    if (prim<65)
    {
        return 0;
    }
    else
    {
        int result = (segund == prim + 1 || segund == prim + 33 || segund == prim - 31) ? 1 : 0;
        return result;
    }
}

int usercheck(FILE *Vet,char auxuser[11],veterinario vet) //CHekea que el nombre de usuario de un Veterinario no se encuentre tomado                   
{   
    Vet=fopen("Vetererinario", "a+b");
    int h; 
    rewind(Vet);
    fread(&vet,sizeof(veterinario),1,Vet);
    while (!feof(Vet)) 
    {
        if (strcmp(auxuser,vet.usuario)==0)
        {
            h=1;    
        }
        fread(&vet,sizeof(veterinario),1,Vet);
    }
     
    fclose(Vet);

    return h;
} 

int usercheckasi(FILE *User,char auxuser[11],usuarios asist) //Chekea que el nombre de usuario de un Asistente no se encuentre tomado                  
{   
    User=fopen("Asistentes.dat", "a+b");
    int h; 
    rewind(User);
    fread(&asist,sizeof(usuarios),1,User);
    while (!feof(User)) 
    {
        if (strcmp(auxuser,asist.usuario)==0)
        {
            h=1;    
        }
        fread(&asist,sizeof(usuarios),1,User);
    }
     
    fclose(User);

    return h;
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


void ranKatent(veterinario vet)
{
    FILE *Vet;
    FILE *Atent;
    int aux=0;
    char s[60];
   
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
        Vet=fopen("Veterinarios.dat","rb");

        rewind(Vet);
        fread(&vet,sizeof(veterinario),1,Vet);
        while (!feof(Vet))
        {
            if (vet.contA>aux)
            {
                aux=vet.contA;
                strcpy(s,vet.apeynomV);
            }
            fread(&vet,sizeof(veterinario),1,Vet);
        }
        printf("El Veterinario con mas Atenciones es: %s\n\n",s);
        fclose(Vet);
    }
}


// void mostrarVet(FILE *Vet, veterinario vet)
// {
//     Vet=fopen("Veterinarios.dat","rb");
    
//     if(Vet==NULL)
//     {
//         system("CLS");
//         printf("\n\nNo existe el archivo todavia\n");
//         printf("\nRegistrar previamente un usuario en el Modulo de Administracion\n");
//         printf("\n\n\t");

//     }
//     else
//     {
//         rewind(Vet);

//         printf("Usuario \t Contraseña \tApellido y Nombre \t  Matricula  \t D.N.I  \t Telefono\n");
//         fread(&vet,sizeof(veterinario),1,Vet);
//         while (!feof(Vet))
//         {
//             printf("\n%s\t%s\t%s\t%d\t%d\t%s\n",vet.usuario,vet.contrasenia,vet.apeynomV,vet.matri,vet.dniV,vet.telefo);
//             fread(&vet,sizeof(veterinario),1,Vet);

//         }

//     fclose(Vet);
//     }
    
    
// }