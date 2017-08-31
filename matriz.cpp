#include <iostream>
#include <cstdlib>
#include <ctime>
int tablero[15][15] = {0};
void ftablero();
void frand(int);
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
	//frand(bombas);
	//std::cout<<"\n";
	system("cls");
	ftablero();
	int fila, columna;
	fila=0;
	columna=0;
	std::cout<<"Ingrese fila: ";
	std::cin>>fila;
	std::cout<<"Ingrese columna: ";
	std::cin>>columna;
	if (tablero[fila][columna]==7){
		std::cout<<"Perdiste!";
		break;
	}
	fcontarbombas(fila, columna);
	system("cls");
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
			std::cout<<tablero[j][i];
			std::cout<<"  ";	
		}
		std::cout<<"\n";
	}
	return;
}
void frand(int bombas){
	int num1, num2;
	num1=rand() % bombas + 1;
	std::cout<<num1<<"\n";
	num2=rand() % bombas + 1;
	std::cout<<num2;
	return;
}
void fbombas(int bombas){
	int rand1, rand2, i;
	for(i = bombas;i>0;i--){
		rand1 = rand() % 15;
		rand2 = rand() % 15;
		if(tablero[rand1][rand2]==7){
			i++;
		}
		else{
			tablero[rand1][rand2]=7;
		}
	}
	return;
}
void fcontarbombas(int fila, int columna){
	int i, j, contadorbombas;
	contadorbombas=0;
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(fila!=0){
				if(fila!=14){ //faltan contar primera e ultima columnas.
					if(tablero[fila-1+i][columna-1+j]==7){
					contadorbombas=contadorbombas+1;
					}
				}
				else{
					if(i<2){
					if(tablero[fila-1+i][columna-1+j]==7){
					contadorbombas=contadorbombas+1;
					}
					}	
				}
			}
			else{
				if(i<2){
					if(tablero[fila+i][columna-1+j]==7){
					contadorbombas=contadorbombas+1;
					}
				}
			}
		}
	}
	tablero[fila][columna]=contadorbombas;
}
