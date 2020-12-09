#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


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



void regVet(FILE *User,usuarios vet);
int sonConsecutivos(int prim, int segund);
int usercheck(FILE *User,char auxuser[11],usuarios vet);
int usercheckasi(FILE *User,char auxuser[11],usuarios asist);
void regAsist(FILE *User,usuarios asist);
// void mostrarVet(FILE *Vet, veterinario reg);

main()
{
    FILE *User;
    usuarios vet;
    usuarios asist;
    
    int opcion;
	do{
		system("cls");
		printf("\t      MENU DE OPCIONES\n");
        printf("\t================================");
		printf("\n\t1) Registrar Veterinario\n");
		printf("\t2) Registrar Usuario Asistente\n");
		printf("\t3) Registro de atenciones por Veterinario\n");
		printf("\t4) Ranking de Veterinarios por Atenciones\n");
		printf("\t0) Salir\n");
		printf("\n\tSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		

		switch(opcion){
			
			case 1:
				regVet(User,vet);
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				regAsist(User,asist);
				printf("\n");
				system("pause");
			break; 
			case 3:
				system("cls");
				// mostrar(User,reg);
				printf("\n");
				system("pause");
			break; 
			case 4:
				system("cls"); 
				// contcred(User,reg);
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

void regVet(FILE *User,usuarios vet)
{
    int nn=0,i=0,l=0,p=0,t=0;
    // char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char temp;
    bool band=false;
    FILE *Vet;
    veterinario reg;
    do{
        system("cls");
        printf("Ingrese un nuevo nombre de usuario: ");
        _flushall();
        gets(vet.usuario);

        nn=strlen(vet.usuario);
    

    if (nn>=6 && nn<=10)
    {
        l=0;
        switch(vet.usuario[0])
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
                
                switch(vet.usuario[i])
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
                    switch(vet.usuario[i])
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

                    h=usercheck( User, auxuser, vet);
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
                        printf("\nNombre de usuario registrado correctamente\n");
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
                switch(vet.contrasenia[i])
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
                    switch(vet.contrasenia[i])
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
                            int dir=sonConsecutivos(prim,segund);
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
                            printf("\nNueva contrasenia registrada correctamente\n");
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
        else
        {
            system("cls");
            printf("La contrasenia es incorrecta\n");
            printf("\n");
            system("pause");
        }

    }while(!band1);
    
    User=fopen("Usuarios.dat", "a+b");

    vet.usuario;
    vet.contrasenia;
    
    fwrite(&vet,sizeof(usuarios),1,User);


    printf("\nUsuario registrado correctamente");
    printf("\n\n");
    system("pause");
    system("cls");

    Vet=fopen("Veterinarios.dat","a+b");
    
    printf("Ingrese los datos del Veterinario\n");

    printf("\nIngrese Apellido y Nombre: ");
    _flushall();
    gets(reg.apeynomV);
    _flushall();

    printf("\nIngrese la matricula: ");
    scanf("%d",&reg.matri);

    printf("\nIngrese el D.N.I: ");
    scanf("%d",&reg.dniV);

    printf("\nIngrese el telefono: ");
    _flushall();
   gets(reg.telefo);
    _flushall();


    fwrite(&reg,sizeof(veterinario),1,Vet);

    fclose(Vet);
    
    // mostrarVet(Vet,reg);
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
                        printf("\nNombre de usuario registrado correctamente");
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
                            printf("\nNueva contrasenia registrada correctamente\n");
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
    
    printf("Ingrese el Apellido y Nombre del usuario %s: ",asist.usuario);
    _flushall();
    scanf("%s",asist.ApeyNom);
    _flushall();
    
    fwrite(&asist,sizeof(usuarios),1,User);

    // rewind(User);
    // fread(&asist,sizeof(usuarios),1,User);
    // while (!feof(User)) 
    // {
    //     printf("Usuario: %s\n",asist.usuario);
    //     printf("Contrasenia: %s\n",asist.contrasenia);
    //     printf("\n");
    //     fread(&asist,sizeof(usuarios),1,User);
    // }
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

int usercheck(FILE *User,char auxuser[11],usuarios vet)                   
{   
    User=fopen("Usuarios.dat", "a+b");
    int h; 
    rewind(User);
    fread(&vet,sizeof(usuarios),1,User);
    while (!feof(User)) 
    {
        if (strcmp(auxuser,vet.usuario)==0)
        {
            h=1;    
        }
        fread(&vet,sizeof(usuarios),1,User);
    }
     
    fclose(User);

    return h;
} 

int usercheckasi(FILE *User,char auxuser[11],usuarios asist)                   
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

// void mostrarVet(FILE *Vet, veterinario reg)
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

//     printf("Apellido y Nombre \t  Matricula  \t D.N.I  \t Telefono\n");
//     fread(&reg,sizeof(veterinario),1,Vet);
//         while (!feof(Vet))
//         {
//             printf("\n%s\t%d\t%d\t%s\n",reg.apeynomV,reg.matri,reg.dniV,reg.telefo);
//             fread(&reg,sizeof(veterinario),1,Vet);

//         }

//     fclose(Vet);
//     }
    
    
// }