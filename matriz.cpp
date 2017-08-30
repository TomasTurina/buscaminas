#include <iostream>
int matriz[15][15] = {0};

int main(){
	matriz[1][1]=2;
	int i, j;
	for(j=0;j<15;j++){          
		
		for(i=0;i<15;i++){
			std::cout<<matriz[j][i];
			std::cout<<" ";	
		}
		std::cout<<"\n";
	}
	return 0;
}
