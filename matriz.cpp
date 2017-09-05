#include <iostream>
#include <cstdlib>
#include <ctime>
int tablero[15][15];
int filabomba;
int columnabomba;
void ftablero();
void fbombas(int);
void fcontarbombas(int,int);
void fverceros(int,int);
int fganar();

int main(){
	srand(time(0));
	bool c, d;
	c=false;
	d=true;
	while(d==true){
	int bombas, fila, columna, puntos, i, j, num;
	for (int k=0; k<15; k++){
		for (int l=0; l<15; l++){
			tablero[k][l]=0;
		}
	}
	filabomba=0;
	columnabomba=0;
	puntos=0;
	while(true){
	std::cout<<"Ingrese la cantidad de bombas, entre 10 y 80: ";
	std::cin>>bombas;
	if (bombas<10 || bombas>80){
		std::cout<<"Solo numeros entre 10 y 80\n";
	}
	else{
		fbombas(bombas);
		for(i=0;i<15;i++){
			for(j=0;j<15;j++){
				if(tablero[i][j]!=9){
				fcontarbombas(i, j);
			}
			}
		}
		break;
	}
	}
	while(true){
	system("cls");
	ftablero();
	if(fganar()==0){
		std::cout<<"Ganaste!\n";
		break;
	}
	else{
		std::cout<<"Posiciones faltantes: "<<fganar()<<"\n";
	}
	if(c==true){
		std::cout<<"Ya ingresaste esa posicion.\n";
		c=false;
		puntos--;
	}
	fila=0;
	columna=0;
	std::cout<<"Ingrese fila: ";
	std::cin>>fila;
	std::cout<<"Ingrese columna: ";
	std::cin>>columna;
	
	if (fila<15 && columna<15 && fila>=0 && columna>=0){
		if(tablero[fila][columna]>=10){
			c=true;
		}
		if (tablero[fila][columna]==9){
			system("cls");
			tablero[fila][columna]=19;
			filabomba=fila;
			columnabomba=columna;
			ftablero();
			std::cout<<"Perdiste! Puntos: "<<puntos<<"\n";
			break;
		}
		else{
		if (tablero[fila][columna]<9){
			tablero[fila][columna]+=10;
		}
		puntos++;
		//fcontarbombas(fila, columna);
		system("cls");
		if(tablero[fila][columna]==10){
			//tablero[fila][columna]=10;
			fverceros(fila, columna);
		}
		ftablero();
		}	
	}
	else{
		std::cout<<"Ingrese una posicion valida del tablero.\n";
		system("PAUSE");
	}
	}
	std::cout<<"Para jugar otra partida ingrese 1, para salir ingrese otro numero.\n";
	std::cin>>num;
	if(num!=1){
		d=false;
	}
	}
	return 0;
}


void ftablero(){
	int i, j, ict, k;
	ict = 0;
	for(j=0;j<15;j++){          
		if(j==0){
			for(k=0;k<15;k++){
				if(k==0){
					std::cout<<"    ";
				}
				std::cout<<k;
				if(k>=10){
				std::cout<<" ";
				}
				else{
					std::cout<<"  ";
				}
			}
			std::cout<<"\n";
			std::cout<<"    ___________________________________________";
			std::cout<<"\n";
		}
		for(i=0;i<15;i++){
			if(i==0){
				std::cout<<i + ict;
				ict=ict+1;
				if(ict<=10){
					std::cout<<"  ";
				}
				else{
					std::cout<<" ";
				}
				std::cout<<"|";
			}
		if (tablero[filabomba][columnabomba]==19){
			if(tablero[j][i]==9){
				tablero[j][i]=19;
			}
		}
			if(tablero[j][i]>=0 && tablero[j][i]<10){
				std::cout<<'X';
			}
			else if(tablero[j][i]==19){
				std::cout<<'*';
			}
			else{
			std::cout<<tablero[j][i]-10;
			}
			std::cout<<"  ";	
		}
		std::cout<<"\n";
	}
	return;
}
void fbombas(int bombas){
	int rand1, rand2, i;
	for(i = bombas;i>0;i--){
		rand1 = rand() % 15;
		rand2 = rand() % 15;
		if(tablero[rand1][rand2]==9){
			i++;
		}
		else{
			tablero[rand1][rand2]=9;
		}
	}
	return;
}
void fcontarbombas(int fila, int columna){
	int i, j, contadorbombas, iniciofila, iniciocolumna, finfila, fincolumna;
	contadorbombas=0;
	if(fila==0){
		iniciofila=1;
		finfila=2;
	}
	else if(fila==14){
		finfila=1;
		iniciofila=0;
	}
	else{
		iniciofila=0;
		finfila=2;
	}
	if(columna==0){
		iniciocolumna=1;
		fincolumna=2;
	}
	else if(columna==14){
		fincolumna=1;
		iniciocolumna=0;
	}
	else{
		iniciocolumna=0;
		fincolumna=2;
	}
	for(i=iniciofila;i<=finfila;i++){
		for(j=iniciocolumna;j<=fincolumna;j++){
			if(tablero[fila-1+i][columna-1+j]==9){
				contadorbombas++;
			}
		}
		if(contadorbombas>0){
			tablero[fila][columna]=contadorbombas;
		}
	}
	return;
}
void fverceros(int fila, int columna){
	int i, j, iniciofila, iniciocolumna, finfila, fincolumna;
	if(fila==0){
		iniciofila=1;
		finfila=2;
	}
	else if(fila==14){
		finfila=1;
		iniciofila=0;
	}
	else{
		iniciofila=0;
		finfila=2;
	}
	if(columna==0){
		iniciocolumna=1;
		fincolumna=2;
	}
	else if(columna==14){
		fincolumna=1;
		iniciocolumna=0;
	}
	else{
		iniciocolumna=0;
		fincolumna=2;
	}
	for(i=iniciofila;i<=finfila;i++){
		for(j=iniciocolumna;j<=fincolumna;j++){
			if(tablero[fila-1+i][columna-1+j]==0){
				tablero[fila-1+i][columna-1+j]+=10;
				fverceros(fila-1+i, columna-1+j);
			}
			else if(tablero[fila-1+i][columna-1+j]<9){
				tablero[fila-1+i][columna-1+j]+=10;
			}
		}
	}
	return;
}
int fganar(){
	int i, j, cpos;
	cpos=0;
	for (i=0;i<15;i++){
		for(j=0;j<15;j++){
			if(tablero[i][j]<9){
				cpos++;
			}
		}
	}
	return cpos;
}

