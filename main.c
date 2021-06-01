#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int menu(void);
int pedirNum(void);
void imprimir(char * u);
void turno1(char * v);
void turno2(char * v);
int ganador(char * v);
int main(void)
{int op,i,j,y,a=0,b=0,z=0;
char matriz[3][3];
do{
op=menu();
switch(op){
		  case 1:z++;
		  		 for(i=0;i<3;i++)
		  				{for(j=0;j<3;j++)
		  						{matriz[i][j]='-';
		  						}
		  				}
		  		if(z==1)
		  			{printf("Instruciones: Es un juego triqui convencional, el usuario juega con la 'X' y la computadora con 'O', cuando sea el turno del usuario, este debera ingresar la posicion donde quiere jugar con dos numeros: el primero el numero de la fila(horizontal), y el segundo el numero de la columna(vertical)\n\n");
		  			sleep(2);
		  			printf("Si esta listo para jugar, ingrese un numero cualquiera ");
		  			y=pedirNum();
		  			}
		  		sleep(1);
		  		system("cls");	
		  		imprimir(&matriz[0][0]);
		  		for(;;)
		  		{turno1(&matriz[0][0]);
		  		if((ganador(&matriz[0][0]))==1)
		  			{a++;
		  			printf("¡Felicitaciones, has ganado el juego!\n");
		  			break;
		  			}
		  	 	if((ganador(&matriz[0][0]))==2)
		  	 		{printf("\n¡Empate!\n");
		  	 		break;
		  	 		}
		  		 turno2(&matriz[0][0]);
		  		 if((ganador(&matriz[0][0]))==1)
		  		 	{b++;
		  	 	printf("¡Perdiste el juego, la computadora ha ganado!\n");
		  		 	break;
		  		 	}
		  		 
		  		}
                break; 
          case 2: printf("\n *PUNTAJE FINAL* \n");  	
		     	  printf("Usuario: %d - Computadora: %d\n",a,b);
                break; 
          case 3: 
                break;
          default: printf("Ingrese por favor, un numero valido\n");
                break;
      	 }
}
while(op!=3);
system("pause");
return(0);
}
int pedirNum(void)
{int x;
scanf("%d",&x);
return(x);
}
int menu(void)
{int x;
printf("-MENU-\n");
printf("1-Jugar \n2-Puntaje \n3-Salir\n");
x=pedirNum();
return(x);
}
void imprimir(char * u)
{int i,j,h=1;
printf("    1   2   3  ");
printf("\n   ************\n");
printf("1*|");
for(i=0;i<3;i++)
	{for(j=0;j<3;j++)
		{printf(" %c |",*(u+((3*i)+j)));
		}
	h++;
	if(i!=2)
		{printf("\n%d*|",h);
		}
	}	
	printf("\n");	
}
void turno1(char * v)
{int m,n;	
printf("Es su turno, ingrese la direccion donde quiere jugar: (Fila) ");
scanf("%d",&m);
printf("(Columna) ");
scanf("%d",&n);
sleep(1);
if(((*(v+(3*(m-1)+(n-1))))=='-')&&(m<=3)&&(n<=3)&&(m>=1)&&(n>=1))
	{(*(v+((3*(m-1))+(n-1))))='X';
	}
	else
	{printf("Jugada invalida\n");
	turno1(v);
	}
system("cls");
imprimir(v);
sleep(1);
}
void turno2(char * v)//Turno de la maquina con inteligencia
{int i,j,z,m,x,k,a,b,c,h;
int n[3]={0,4,8};
char car;
srand(time(0));
m=rand()%9;
h=rand()%3;
if((*(v+n[h]))=='-')
	{m=n[h];
	}
for(a=0;a<2;a++)
{if(a==0)
	{car='X';
	}
	else
	{car='O';
	}
b=0,c=0;
for(i=0;i<3;i++)//Intenta bloquear el juego si al jhugador le falta una jugada para ganar en una fila
	{z=0;
	for(j=0;j<3;j++)
		{if((*(v+(3*i)+j))==car)
			{z++;
			}
			else
			{k=((3*i)+j);
			}
		}
	if(z==2)
		{if((*(v+k))=='-')
		m=k;
		break;
		}
	}
i=0;
j=0;
for(j=0;j<3;j++)//Intenta bloquear el juego si al jugador le falta una jugada para ganar en una columna
	{z=0;
	for(i=0;i<3;i++)
		{if((*(v+(3*i)+j))==car)
			{z++;
			}
			else
			{k=((3*i)+j);
			}
		}
	if(z==2)
		{if((*(v+k))=='-')
		m=k;
		break;
		}
	}
i=0;
for(i=0;i<9;i=i+4)
	{if((*(v+i))==car)
			{b++;
			}
			else
			{k=i;
			}
	}
if(b==2)
		{if((*(v+k))=='-')
		m=k;
		}	
i=0;
for(i=2;i<7;i=i+2)
	{if((*(v+i))==car)
			{c++;
			}
			else
			{k=i;
			}
	}
if(c==2)
	{if((*(v+k))=='-')
	m=k;
	}	
}
if((*(v+m))=='-')
	{*(v+m)='O';
	}
	else
	{
	turno2(v);
	}
system("cls");
imprimir(v);
sleep(3/4);
}
int ganador(char * v)
{char a,e;
int b=0,i,c,d,j;
if((*(v+4))!='-')
	{a=*(v+4);
	for(i=1;i<5;i++)
		{if(((*(v+(4-i)))==a)&&((*(v+(4+i)))==a))
			{b=1;
			}
		}
	}
for(c=0;c<3;c=c+2)
	{e=*(v+(3*c));
	if(e!='-')
		{if(((*(v+((3*c)+1)))==e)&&((*(v+((3*c)+2)))==e))
			{b=1;
			}
		}	
	}
c=0;
for(c=0;c<3;c=c+2)
	{e=*(v+c);
	if(e!='-')
		{if(((*(v+((3*1)+c)))==e)&&((*(v+((3*2)+c)))==e))
			{b=1;
			}
		}		
	}
if(b!=1)//Verficar que no hayan posiciones y que no haya ganador
	{b=2;
	for(j=0;j<9;j++)
		{if((*(v+j))=='-')
			{b=0;
			}
		}
	}
return(b);//Returna 0, si no ha pasado nada. Retorna 1, si hay un ganador, Retorna 2 si hay un empate
}




