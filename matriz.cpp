#include <iostream>
#include <cstdlib>
#include <ctime>
int tablero[15][15] = {0};
int filabomba=0;
int columnabomba=0;
void ftablero();
void fbombas(int);
void fcontarbombas(int,int);

int main(){
	srand(time(0));
	int bombas;
	while(true){
	std::cout<<"Ingrese la cantidad de bombas, entre 10 y 80: ";
	std::cin>>bombas;
	if (bombas<10 || bombas>80){
		std::cout<<"Solo numeros entre 10 y 80\n";
	}
	else{
		fbombas(bombas);
		break;
	}
	}
	while(true){
	system("cls");
	ftablero();
	int fila, columna;
	fila=0;
	columna=0;
	std::cout<<"Ingrese fila: ";
	std::cin>>fila;
	std::cout<<"Ingrese columna: ";
	std::cin>>columna;
	if (tablero[fila][columna]==9){
		system("cls");
		tablero[fila][columna]=10;
		filabomba=fila;
		columnabomba=columna;
		ftablero();
		std::cout<<"Perdiste!";
		break;
	}
	fcontarbombas(fila, columna);
	system("cls");
	if(tablero[fila][columna]==0){
		tablero[fila][columna]=11;
	}
	ftablero();
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
		if (tablero[filabomba][columnabomba]==10){
			if(tablero[j][i]==9){
				tablero[j][i]=10;
			}
		}
			if(tablero[j][i]==0 || tablero[j][i]==9){
				std::cout<<'X';
			}
			else if(tablero[j][i]==10){
				std::cout<<'*';
			}
			else if(tablero[j][i]==11){
				std::cout<<"0";
			}
			else{
			std::cout<<tablero[j][i];
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
	tablero[fila][columna]=contadorbombas;
	}
}
