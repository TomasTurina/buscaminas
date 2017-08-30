#include <iostream>
#include <stdlib.h>
#include <time.h>
int tablero[15][15] = {0};
void ftablero();
void frand(int);

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
	//frand(bombas);
	//std::cout<<"\n";
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
	ftablero();
	break;
	}
	}
	return 0;
}

void ftablero(){
	int i, j;
	for(j=0;j<15;j++){          
		
		for(i=0;i<15;i++){
			std::cout<<tablero[j][i];
			std::cout<<" ";	
		}
		std::cout<<"\n";
	}
	return ;
}

void frand(int bombas){
	int num1, num2;
	num1=rand() % bombas + 1;
	std::cout<<num1<<"\n";
	num2=rand() % bombas + 1;
	std::cout<<num2;
	return;
}

