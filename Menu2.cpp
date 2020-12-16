#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
void gotoxy(int x,int y); // Funcion para poder mover el Titulo en una posicion especifica//
void cuadro(int x1, int y1, int x2, int y2);
main()
{
	int opcion;
	do{
		system("cls");
		system("color 0E");
		gotoxy(55,2);
		printf("MENU PRINCIPAL");
        printf("\n\t-----------------------------------------------------------------------------------------------------------");
        printf("\n\t-----------------------------------------------------------------------------------------------------------");
		printf("\n\t1) Modulo Consultorio\n");
		printf("\t2) Modulo Recepcion\n");
		printf("\t3) Modulo Administracion\n");
		printf("\t0) Salir\n");
		printf("\n\tSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		

		switch(opcion){
			
			case 1:
				system("cls");
				system("MConsultorio.exe");//Llama al programa del Modulo de Consuktorio//
				
			break;
			case 2:
				system("cls");
				system("MRecepcion.exe");//Llama al programa del Modulo de Recepcion//

			break; 
			case 3:
				system("cls");
				system("MAdministacion.exe");//Llama al programa del Modulo de Administracion//
				
			break; 
			case 0:
			break; 
			default:
				system("cls");
				printf("Opcion Incorrecta\n");
				
			break;  
			
			
		}
	}
	while(opcion!=0);
 }
 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
void cuadro(int x1, int y1, int x2, int y2){
    int i;
    for (i=x1;i<x2;i++){	
		gotoxy(i,y1);printf("�") ; //linea horizontal superior 
		gotoxy(i,y2);printf("�") ; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){	
		gotoxy(x1,i);printf("�") ; //linea vertical izquierda
		gotoxy(x2,i);printf("�") ; //linea vertical derecha
    }
    
    gotoxy(x1,y1); printf("�"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("�");
    gotoxy(x2,y1); printf("�");
    gotoxy(x2,y2); printf("�");
}
