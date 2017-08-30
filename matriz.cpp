#include <iostream>
int tablero[15][15] = {0};
void ftablero();

int main(){
	int bombas;
	while(true){
	std::cout<<"Ingrese la cantidad de bombas, entre 10 y 80: ";
	std::cin>>bombas;
	if (bombas<10 || bombas>80){
		std::cout<<"Solo numeros entre 10 y 80\n";
	}
	else{
	tablero[1][1]=2;
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
