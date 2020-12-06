#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


struct usuarios
{
    char usuario[11];
    char contrasenia[33];
};


void regVet(usuarios vet);
int oralfa(int prim,int segund);

main()
{
    usuarios vet;
    
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
				regVet(vet);
				printf("\n");
                system("pause");
				
			break;
			case 2:
				system("cls");
				// ventmes(archvent,reg);
				printf("\n");
				system("pause");
			break; 
			case 3:
				system("cls");
				// mostrar(archvent,reg);
				printf("\n");
				system("pause");
			break; 
			case 4:
				system("cls"); 
				// contcred(archvent,reg);
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

void regVet(usuarios vet)
{
    int nn=0,i=0,l=0,p=0,t=0;
    // char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
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
                    system("cls");
                    printf("\nNombre de usuario registrado correctamente\n");
                    printf("\n");
                    system("pause");
                    band=true;
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
        int f=0,k=0,v=0,o=0,z;
        system("cls");
        printf("Ingrese una contrasenia para el nuevo usuario: ");
        _flushall();
        gets(vet.contrasenia);

        nn=strlen(vet.contrasenia);

        if (nn>=6 && nn<=32)
        {
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
                            int segund = vet.contrasenia[i++];
                            int dir=oralfa(prim,segund);
                            if(dir==1)
                            {
                               z++; 
                            }
                            else
                            {
                                z=0;
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
                            printf("\nNueva contraseña registrada correctamente\n");
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

    system("cls");
    printf("El usurario se a registrado correctamente\n");
    printf("\n");
}
 
     
 
 


int oralfa(int prim,int segund)
{
    int i,p,s;
    if (prim + segund<180)
    {
        printf("\nAmbos caractenes minuscula\n");
        
        if (segund == prim + 1)
        {
            printf("\nSon consecutivos\n");
            i=1;

        }
        else
        {
            printf("\nNo son consecutivos\n");
            i=2;
        }
        
        
    }
    else
    {
        if (prim>90)
        {
            printf("\nPrimero mayuscula\n");
            p=1;
        }
        else
        {
            printf("\nPrimero minuscula\n");
            p=0;
        }
        if (segund>90)
        {
            printf("\nSegundo mayuscula\n");
            s=1;
        }
        else
        {
            printf("\nSegundo minuscula\n");
            s=0;
        }
        
        if (p==1 && s==0)
        {
            if (segund = prim + 33)
            {
                printf("\nSon consecutivos\n");
                i=1;
            }
            else
            {
                printf("\nNo son consecutivos\n");
                i=2;
            }
            
            
        }
        
        if (p==0 && s==1)
        {
            if (segund = prim - 31)
            {
                printf("Son consecutivos");
                i=1;
            }
            else
            {
                printf("\nNo son consecutivos\n");
                i=2;
            }
            
            
        }
        
        if (p==1 && s==1)
        {
            printf("Ambos mayuscula");
            if (segund = prim + 1)
            {
                printf("Son consecutivos");
                i=1;
            }
            else
            {
                printf("\nNo son consecutivos\n");
                i=2;
            }
            
        }
        
    }
    
    
   return i; 
}
