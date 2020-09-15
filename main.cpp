#include<conio.h>
#include<windows.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace std;

int a,d,w,s,l;//teclas
int xt = 25,yt = 11;//cordenadas de tanque
int dire = 0,diref = 0;//dereccion de tanque
int xt2 = 10,yt2 = 6;//cordenadas de tanque
int dire2 = 0,diref2 = 0;//dereccion de tanque
int xb = 0,yb = 0;//cordenadas de bala de tanque
int xb2 = 0,yb2 = 0;//cordenadas de bala de tanque
int xbn = 0,ybn = 0;//cordenadas de bala de enemigo1
int falb = 0;//actibador de bala
int falb2 = 0;//actibador de bala
int falbn = 0;//actibador de bala enemiga1
int xn = 5,yn = 18;//cordenadas de enemigo1
int diren = 0,direfn = 0;//direccion de enemigo1
int tine = 0;//tienpo en mover enemigo
int xvi = 0;//mover aleatorio
int falbn2 = 0;//actibador de bala enemigo2
int xn2 = 85,yn2 = 4;//cordenadas de enemigo2
int xbn2 = 0,ybn2 = 0;//cordenadas de balas de enemigo2
int diren2 = 0,direfn2 = 0;//direccion de enemigo2
int tanques = 0;//tanques destruidos
int ajetan = 5;//tanques para destruir
int vidas = 5;
int velo = 0;//velosidad de enemigos
int vibel = 1;
int aux=1; // contador para explosiones cada 7 segundos

//menu de inicio
int xp,yp;
int sal = 1;
int tecla;
int pos = 1;

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hcon,dwpos);
}

void ocultarCursor(){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hcon,&cci);
}

void inicio(){
	gotoxy(45,4); cout<<"UNIVERSIDAD NACIONAL MAYOR DE SAN MARCOS";
	gotoxy(59,6); cout<<"TANK WARS";
	gotoxy(61,8); cout<<"FIEE";
	gotoxy(37,14); cout<<"INICIAR PLAYER VS CPU";
	gotoxy(37,16); cout<<" SALIR";
	gotoxy(35,14); cout<<">";
	sal = 1;
	
	do {
		tecla = getch();	
			if (tecla == 'w' || tecla == 'W'){
				if(pos == 1){
					gotoxy(35,14);cout<<">";
					gotoxy(35,16);cout<<" ";
					pos = 1;
				}
				else if(pos == 2){
					gotoxy(35,14);cout<<">";
					gotoxy(35,16);cout<<" ";
					pos = 1;
				}
			}
			else{
				if(tecla == 's' || tecla == 'S' ){
					if(pos==1){
						gotoxy(35,16);cout<<">";
						gotoxy(35,14);cout<<" ";
						pos = 2;
					}
					else if(pos==2){
						gotoxy(35,16);cout<<">";
						gotoxy(35,14);cout<<" ";
						pos = 2;
					}
				}
			}
			// else{
				// if (tecla == 's' || tecla == 'S'){
				// 	gotoxy(35,14);cout<<" ";
				// 	gotoxy(35,16);cout<<">";
				// 	pos = 2;
				// }
			// }	
			if (tecla == 'l' || tecla == 'L'){
				if (pos == 1){
					sal = 2;
					vidas = 5;
				}
				else{
					if (pos == 2){
						sal = 5;
					}
					if(pos==0){
						sal = 0;
					}
				}
			}
	}while (sal == 1);
	system ("cls");
}

void nivel(){
	if (ajetan == tanques){
		tanques = 0;
		switch (vibel)
		{
		case 1:
			ajetan = 10;
			break;
		case 2:
			ajetan = 15;
			break;
		case 3:
			ajetan = 20;
			break;
		case 4:
			ajetan = 25;
			break;
		case 5:
			system("cls");
			gotoxy(50,14);
			cout<<"FELICIDADES! GRACIAS POR JUGAR..!"<<endl;
			system("pause");
			exit(0);
		default:
			break;
		}
		vibel ++;
		vidas ++;
	}
}

void checabala(){
	if (xb == xn && yb == yn+1 || xb == xn+2 && yb == yn+1 || xb == xn+3 && yb == yn+1 || xb == xn+4 && yb == yn+1 || xb+1 == xn+3 && yb == yn+2 || xb+1 == xn+3 && yb == yn){
		tanques ++;	
		if (yn > 11 && yt > 11){
			gotoxy(xn,yn); cout<<"     ";
			gotoxy(xn,yn+1); cout<<"     ";
			gotoxy(xn,yn+2); cout<<"     ";
			xn = 5;
			yn = 5;
			xb = 0;
			yb = 0;
			gotoxy(xn,yn); cout<<" ***";
			gotoxy(xn,yn+1); cout<<"  *** ";
			gotoxy(xn,yn+2); cout<<" ***";	
		}
			else{
				if(yn < 11 && yt < 11){
					gotoxy(xn,yn); cout<<"     ";
					gotoxy(xn,yn+1); cout<<"     ";
					gotoxy(xn,yn+2); cout<<"     ";
					xn = 5;
					yn = 18;
					xb = 0;
					yb = 0;
					gotoxy(xn,yn); cout<<" ***";
					gotoxy(xn,yn+1); cout<<"  *** ";
					gotoxy(xn,yn+2); cout<<" ***";	
				}
	
			}
	}
	if (xb == xn2 && yb == yn2+1 || xb == xn2+2 && yb == yn2+1 || xb == xn2+3 && yb == yn2+1 || xb == xn2+4 && yb == yn2+1 || xb+1 == xn2+3 && yb == yn2+2 || xb+1 == xn2+3 && yb == yn2){
		tanques ++;	
		if (yn2 > 11 && yt > 11){
		gotoxy(xn2,yn2); cout<<"     ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"     ";
		xn2 = 85;
		yn2 = 4;
		xb = 0;
		yb = 0;
		gotoxy(xn2,yn2); cout<<" ***";
		gotoxy(xn2,yn2+1); cout<<"*** ";
		gotoxy(xn2,yn2+2); cout<<" ***";
		}
		else{
		gotoxy(xn2,yn2); cout<<"     ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"     ";
		xn2 = 85;
		yn2 = 18;
		xb = 0;
		yb = 0;
		gotoxy(xn2,yn2); cout<<" ***";
		gotoxy(xn2,yn2+1); cout<<"*** ";
		gotoxy(xn2,yn2+2); cout<<" ***";	
		}
	}
	if (xb == xbn && yb == ybn){
		gotoxy(xb,yb);cout<<" ";
		xb = 0;
		yb = 0;
		xbn = 0;
		ybn = 0;
	}
	else{
		if (xb == xbn2 && yb == ybn2){
		gotoxy(xb,yb);cout<<" ";
		xb = 0;
		yb = 0;
		xbn2 = 0;
		ybn2 = 0;
		}	
	}
	if (xbn == xt && ybn == yt+1 || xbn == xt+2 && ybn == yt+1 || xbn == xt+3 && ybn == yt+1 || xbn == xt+4 && ybn == yt+1 || xbn+1 == xt+3 && ybn == yt+2 || xbn+1 == xt+3 && ybn == yt){
		gotoxy(xt,yt); cout<<"     ";
		gotoxy(xt,yt+1); cout<<"     ";
		gotoxy(xt,yt+2); cout<<"     ";
		xt = 45;
		yt = 11;
		gotoxy(xt,yt); cout<<" ***";
		gotoxy(xt,yt+1); cout<<" ****";
		gotoxy(xt,yt+2); cout<<" ***";
		vidas --;
		xbn = 0;
		ybn = 0;
	}
	else{
		if (xbn2 == xt && ybn2 == yt+1 || xbn2 == xt+2 && ybn2 == yt+1 || xbn2 == xt+3 && ybn2 == yt+1 || xbn2 == xt+4 && ybn2 == yt+1 || xbn2+1 == xt+3 && ybn2 == yt+2 || xbn2+1 == xt+3 && ybn2 == yt){
		gotoxy(xt,yt); cout<<"     ";
		gotoxy(xt,yt+1); cout<<"     ";
		gotoxy(xt,yt+2); cout<<"     ";
		xt = 45;
		yt = 11;
		gotoxy(xt,yt); cout<<" ***";
		gotoxy(xt,yt+1); cout<<" ****";
		gotoxy(xt,yt+2); cout<<" ***";
		vidas --;
		xbn2 = 0;
		ybn2 = 0;
		}
	}
}

void marcador(){
	gotoxy(100,2);cout<<"TANQUES DESTRUIDOS";
	gotoxy(100,3);cout<<tanques<<"/"<<ajetan<<"    ";
	gotoxy(100,5);cout<<"VIDAS";
	gotoxy(100,6);cout<<vidas;
	gotoxy(100,8);cout<<"NIVEL";
	gotoxy(100,9);cout<<vibel;
}

void movern2(){
	velo ++;
	if (xvi > 30  && xvi < 40 && xn2 < 87 && velo == 5){
		//borrar
		gotoxy(xn2,yn2); cout<<"    ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"    ";
		xn2 ++;
		diren2 = 0;
		//divijar
		gotoxy(xn2,yn2); cout<<" ***";
		gotoxy(xn2,yn2+1); cout<<"  ***";
		gotoxy(xn2,yn2+2); cout<<" ***";
	}
	if (xvi > 20 && xvi < 30 && xn2 > 3 && velo == 5){	
		//borrar
		gotoxy(xn2,yn2);   cout<<"    ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"    ";
		xn2 --;
		diren2 = 1;
		//divijar
		gotoxy(xn2,yn2); cout<<" ***";
		gotoxy(xn2,yn2+1); cout<<"*** ";
		gotoxy(xn2,yn2+2); cout<<" ***";	
		}
	if (xvi > 10 && xvi < 19 && yn2 < 24 && velo == 5){
		//borrar
		gotoxy(xn2,yn2);   cout<<"    ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"    ";
		yn2 ++;
		diren2 = 2;
		//divijar
		gotoxy(xn2,yn2); cout<<" * *";
		gotoxy(xn2,yn2+1); cout<<" ***";
		gotoxy(xn2,yn2+2); cout<<"  * ";
	}
	if (xvi > 41 && xvi < 51 && yn2 > 4 && velo == 5){
		//borrar
		gotoxy(xn2,yn2);   cout<<"    ";
		gotoxy(xn2,yn2+1); cout<<"     ";
		gotoxy(xn2,yn2+2); cout<<"    ";
		yn2 --;
		diren2 = 3;
		//divijar
		gotoxy(xn2,yn2); cout<<"  * ";
		gotoxy(xn2,yn2+1); cout<<" ***";
		gotoxy(xn2,yn2+2); cout<<" * *";
	}
		if (falbn2 == 0){
				if (diren2 == 0){
					xbn2 = xn2+5;
					ybn2 = yn2+1;		
				}
				else{
					if (diren2 == 1){
					xbn2 = xn2-1;
					ybn2 = yn2+1;	
				
					}	
				}
				if (diren == 2){
					xbn2 = xn2+2;
					ybn2 = yn2+3;
				}
				else{
					if (diren2 == 3){
						xbn2 = xn2+2;
				    	ybn2 = yn2-1;	
					}
				}	
		falbn2 = 1;
		direfn2 = diren2;
	}
	if (velo == 5){
		velo = 0;
	}	
}

void divut(){
	gotoxy(xt,yt);   cout<<" ***";
	gotoxy(xt,yt+1); cout<<" ****";
	gotoxy(xt,yt+2); cout<<" ***";
	gotoxy(xn,yn);   cout<<" ***";
	gotoxy(xn,yn+1); cout<<"*** ";
	gotoxy(xn,yn+2); cout<<" ***";
	if(vibel >= 2){
		gotoxy(xn2,yn2); cout<<" ***";
		gotoxy(xn2,yn2+1); cout<<"  ***";
		gotoxy(xn2,yn2+2); cout<<" ***";	
	}	
}

void balan(){
	gotoxy(xbn,ybn);cout<<" ";
	if (falbn == 1 && xbn < 93 && xbn > 3 && ybn > 4 && ybn < 27){
		if (direfn == 0){
			xbn --;
		}
		else{
			if (direfn == 1){
				xbn ++;
			}
		}
		if (direfn == 2){
			ybn --;
		}
		else{
			if (direfn == 3){
				ybn --;
			}
		}
	gotoxy(xbn,ybn); cout<<"*";
	}	
	else{
		falbn = 0;
	}		
	if (xbn == xbn2 && ybn-1 == ybn2 || xbn == xbn2 && ybn+1 == ybn2 || xbn == xbn2 && ybn == ybn2){
		gotoxy(xbn,ybn);cout<<" ";
		xbn = 0;
		ybn = 0;
		xbn2 = 0;
		ybn2 = 0;
	}
}

void balan2(){
	gotoxy(xbn2,ybn2);cout<<" ";
	if (falbn2 == 1 && xbn2 <93  && xbn2 > 3 && ybn2 > 4 && ybn2 < 27){
		if (direfn2 == 0){
			xbn2 ++;
		}
		else{
			if (direfn2 == 1){
				xbn2 --;
			}
		}
		if (direfn2 == 2){
			ybn2 ++;
		}
		else{
			if (direfn2 == 3){
				ybn2 --;
			}
		}
	gotoxy(xbn2,ybn2);cout<<"*";
	}	
	else{
		falbn2 = 0;
	}
}

void movern(){
	int posi = 0;//para donde moverme 
	tine ++; 
	if (tine > 10){
		tine = 0;
		xvi = (rand () % 70) +6;
	}
	velo ++;
	if (xvi > 30  && xvi < 40 && xn > 5 && velo == 5){
		//borrar
		gotoxy(xn,yn); cout<<"    ";
		gotoxy(xn,yn+1); cout<<"     ";
		gotoxy(xn,yn+2); cout<<"    ";
		xn --;
		diren = 0;
		//divijar
		gotoxy(xn,yn); cout<<" ***";
		gotoxy(xn,yn+1); cout<<"*** ";
		gotoxy(xn,yn+2); cout<<" ***";
	}
	if (xvi > 20 && xvi < 30 && xn < 93 && velo == 5){	
		//borrar
		gotoxy(xn,yn);   cout<<"    ";
		gotoxy(xn,yn+1); cout<<"     ";
		gotoxy(xn,yn+2); cout<<"    ";
		xn ++;
		diren = 1;
		//divijar
		gotoxy(xn,yn); cout<<" ***";
		gotoxy(xn,yn+1); cout<<"  ***";
		gotoxy(xn,yn+2); cout<<" ***";	
		}
	if (xvi > 10 && xvi < 19 && yn > 4 && velo == 5){
		//borrar
		gotoxy(xn,yn);   cout<<"    ";
		gotoxy(xn,yn+1); cout<<"     ";
		gotoxy(xn,yn+2); cout<<"    ";
		yn --;
		diren = 2;
		//divijar
		gotoxy(xn,yn); cout<<"  * ";
		gotoxy(xn,yn+1); cout<<" ***";
		gotoxy(xn,yn+2); cout<<" * *";
	}
	if (xvi > 41 && xvi < 51 && yn < 24 && velo == 5){
		//borrar
		gotoxy(xn,yn);   cout<<"    ";
		gotoxy(xn,yn+1); cout<<"     ";
		gotoxy(xn,yn+2); cout<<"    ";
		yn ++;
		diren = 3;
		//divijar
		gotoxy(xn,yn); cout<<" * *";
		gotoxy(xn,yn+1); cout<<" ***";
		gotoxy(xn,yn+2); cout<<"  * ";
	}
		if (falbn == 0){
				if (diren == 0){
					xbn = xn-2;
					ybn = yn+1;		
				}
				else{
					if (diren == 1){
					xbn = xn+5;
					ybn = yn+1;	
				
					}	
				}
				if (diren == 2){
					xbn = xn+2;
					ybn = yn-1;
				}
				else{
					if (diren == 3){
						xbn = xn+2;
				    	ybn = yn+3;	
					}
				}	
		falbn = 1;
		direfn = diren;
	}	
	if (velo == 5){
		velo = 0;
	}
}

void bala(){
	
	gotoxy(xb,yb);cout<<" ";
	if (falb == 1 && xb < 93 && xb > 3 && yb > 3 && yb < 27){
		if (diref == 0){
			xb ++;
		}
		else{
			if (diref == 1){
				xb --;
			}
		}
		if (diref == 2){
			yb --;
		}
		else{
			if (diref == 3){
				yb ++;
			}
		}
    	gotoxy(xb,yb);cout<<"*";	
	}
	else{
		falb = 0;
	}	
}

void mover(){                                        
	if (kbhit()){	
		unsigned char tecla = getch();		
			if ((tecla == 'a' || tecla == 'A' )&& xt > 3){
				//borrar
				gotoxy(xt,yt); cout<<"    ";
				gotoxy(xt,yt+1); cout<<"     ";
				gotoxy(xt,yt+2); cout<<"    ";
				xt --;
				dire = 1;
				//divijar
				gotoxy(xt,yt); cout<<" ***";
				gotoxy(xt,yt+1); cout<<"****";
				gotoxy(xt,yt+2); cout<<" ***";
			}
			else{
				if ((tecla == 'd'|| tecla == 'D' )&& xt < 89){
				gotoxy(xt,yt); cout<<"    ";
				gotoxy(xt,yt+1); cout<<"     ";
				gotoxy(xt,yt+2); cout<<"    ";
				xt ++;
				dire = 0;
				//divijar
				gotoxy(xt,yt); cout<<" ***";
				gotoxy(xt,yt+1); cout<<" ****";
				gotoxy(xt,yt+2); cout<<" ***";	
				}
			}

			if ((tecla == 'w'|| tecla == 'W' )&& yt > 3){
				gotoxy(xt,yt); cout<<"    ";
				gotoxy(xt,yt+1); cout<<"     ";
				gotoxy(xt,yt+2); cout<<"    ";
				yt --;
				dire = 2;
				//divijar
				gotoxy(xt,yt); cout<<"  * ";
				gotoxy(xt,yt+1); cout<<" ***";
				gotoxy(xt,yt+2); cout<<" ***";	
			}	
			else{
				if ((tecla == 's' || tecla == 'S' )&& yt < 25){
				gotoxy(xt,yt); cout<<"    ";
				gotoxy(xt,yt+1); cout<<"     ";
				gotoxy(xt,yt+2); cout<<"    ";
				yt ++;
				dire = 3;
				//divijar
				gotoxy(xt,yt); cout<<" ***";
				gotoxy(xt,yt+1); cout<<" ***";
				gotoxy(xt,yt+2); cout<<"  * ";
				}
			}
			if ((tecla == 'l' || tecla == 'L')&& falb == 0){
				if (dire == 0){
					xb = xt+5;
					yb = yt+1;	
				}
				else{
					if (dire == 1){
						xb = xt-1;
						yb = yt+1;
					}	
				}
				if (dire == 2){
					xb = xt+2;
					yb = yt-1;
				}
				else{
					if (dire == 3){
						xb = xt+2;
				    	yb = yt+3;	
					}
				}
				falb = 1; 
				diref = dire;
			}
		}//fin if
}

void pintar(){
int v = 2;

	for(int i = 2 ; i < 95 ; i++){
		v ++;
		//pintar horizontal
		gotoxy(i,2);cout<<char(219);
		gotoxy(i,28);cout<<char(219);
		//pintar vertical
		if (v < 28){
			gotoxy(2,v);cout<<char(219);
		    gotoxy(94,v);cout<<char(219);	
		}
	}
	gotoxy(2,2);cout<<char(219);
	gotoxy(2,28);cout<<char(219);
	gotoxy(94,2);cout<<char(219);
	gotoxy(94,28);cout<<char(219);
}

void pintarMarcoInicio(){
int v = 2;

	for(int i = 2 ; i < 115 ; i++){
		v ++;
		//pintar horizontal
		gotoxy(i,2);cout<<char(219);
		gotoxy(i,28);cout<<char(219);
		//pintar vertical
		if (v < 28){
			gotoxy(2,v);cout<<char(219);
		    gotoxy(115,v);cout<<char(219);	
		}
	}
	gotoxy(2,2);cout<<char(219);
	gotoxy(2,28);cout<<char(219);
	gotoxy(115,2);cout<<char(219);
	gotoxy(115,28);cout<<char(219);
}

void explosionMina(){
	srand(time(NULL));
	int x,y;
	x = 10 + rand()%70;
	y = 8 + rand()%14;

	gotoxy(x,y); cout<<"     ";
	gotoxy(x,y+1); cout<<"     ";
	gotoxy(x,y+2); cout<<"     ";
	Sleep(100);
	gotoxy(x,y);   cout<<" ** ";
	gotoxy(x,y+1); cout<<"****";
	gotoxy(x,y+2); cout<<" ** ";
	Sleep(100);
	gotoxy(x,y); cout<<"     ";
	gotoxy(x,y+1); cout<<"     ";
	gotoxy(x,y+2); cout<<"     ";
	Sleep(100);
	gotoxy(x,y);   cout<<" ** ";
	gotoxy(x,y+1); cout<<"****";
	gotoxy(x,y+2); cout<<" ** ";
	gotoxy(x,y); cout<<"     ";
	gotoxy(x,y+1); cout<<"     ";
	gotoxy(x,y+2); cout<<"     ";
	// vidas--;
}


int main(){
while (sal != 5){
		system ("cls");
		system("color 9");
		ocultarCursor();
		system("audioJuego.wav"); //Sirve para reproducir la musica, debe encontrarse el audio en la misma carpeta del juego
		pintarMarcoInicio();
	    inicio();
		system ("color A");
		while (sal == 2){	
			system("audioJuego.wav");
			divut();
			pintar();
			while (vidas > 0){
			nivel();
			checabala();
			marcador();
			xvi -= 3;
			movern();
			if(vibel >= 2){
				movern2();
				balan2();
			}
			mover();
			balan();
			bala();	
			if(vibel>=3){			
				aux++;
				if(aux%37==0){
					explosionMina();
				}
			}
			Sleep(40);
				if (vidas == 0){
					sal = 1;
				}	
			}
		}		
	}		
}  
