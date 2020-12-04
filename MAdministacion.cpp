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
    int nn=0,i=0,l=0,p=0;
    // char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char temp;
    bool band=false;
    do{
        system("cls");
        printf("Ingrese un nuevo nombre de usuario: ");
        _flushall();
        gets(vet.usuario);

        nn=strlen(vet.usuario);

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
        }else
        {
            system("cls");
            printf("El nombre de usuario es incorrecto,debe tener la primera letra minuscula\n");
            printf("\n");
            system("pause");
            
        }
        if(p>=2)
        {
            printf("Nombre bien por ahora");
            printf("\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("El nombre de usuario es incorrecto, debe tener al menos dos mayusculas\n");
            printf("\n");
            system("pause");
            
        }
        
    }while(!band);
}