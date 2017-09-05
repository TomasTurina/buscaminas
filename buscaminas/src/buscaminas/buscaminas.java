package buscaminas;

import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class buscaminas {
		
	public static void main(String[] args) {

		int tablero[][] = new int[15][15];

		boolean c, d;
		c=false;
		d=true;
		
		while(d==true)
		{
			int bombas, fila, columna, filabomba, columnabomba, puntos, i, j, num;
			
			for (int k=0; k<15; k++)
			{
				for (int l=0; l<15; l++)
				{
					tablero[k][l]=0;
				}
			}
			
			filabomba=0;
			columnabomba=0;
			puntos=0;
			
			while(true)
			{
				@SuppressWarnings("resource")
				Scanner s = new Scanner(System.in);
				System.out.println("Ingrese la cantidad de bombas, entre 10 y 80: ");
				bombas = Integer.parseInt(s.nextLine());
				
				if (bombas<10 || bombas>80)
				{
					System.out.println("Solo numeros entre 10 y 80\n");
				}
				else
				{
					fbombas(bombas, tablero);
					for(i=0;i<15;i++)
					{
						for(j=0;j<15;j++)
						{
							if(tablero[i][j]!=9)
							{
								fcontarbombas(i, j, tablero);
							}
						}
					}
					break;
				}
			}
			
			while(true)
			{
				//system("cls");
				ftablero(tablero, filabomba, columnabomba);
				
				if(fganar(tablero)==0)
				{
					System.out.println("Ganaste!\n");
					break;
				}
				else
				{
					System.out.println("Posiciones faltantes: " + fganar(tablero) + "\n");
				}
				if(c==true)
				{
					System.out.println("Ya ingresaste esa posicion.\n");
					c=false;
					puntos--;
				}
				
				fila=0;
				columna=0;
				@SuppressWarnings("resource")
				Scanner s = new Scanner(System.in);
				System.out.println("Ingrese fila: ");
				fila = Integer.parseInt(s.nextLine());
				@SuppressWarnings("resource")
				Scanner t = new Scanner(System.in);
				System.out.println("Ingrese columna: ");
				columna = Integer.parseInt(t.nextLine());
				
				if (fila<15 && columna<15 && fila>=0 && columna>=0)
				{
					if(tablero[fila][columna]>=10)
					{
						c=true;
					}
					if (tablero[fila][columna]==9)
					{
						//system("cls");
						tablero[fila][columna]=19;
						filabomba=fila;
						columnabomba=columna;
						ftablero(tablero, filabomba, columnabomba);
						System.out.println("Perdiste! Puntos: " + puntos + "\n");
						break;
					}
					else
					{
						if (tablero[fila][columna]<9)
						{
							tablero[fila][columna]+=10;
						}
						puntos++;
						//fcontarbombas(fila, columna);
						//system("cls");
						if(tablero[fila][columna]==10)
						{
							fverceros(fila, columna, tablero);
						}
						
						ftablero(tablero, filabomba, columnabomba);
					}	
				}
				else
				{
					System.out.println("Ingrese una posicion valida del tablero.\n");
					//system("PAUSE");
				}
			}
			
			@SuppressWarnings("resource")
			Scanner s = new Scanner(System.in);
			System.out.println("Para jugar otra partida ingrese 1, para salir ingrese otro numero.");
			num = Integer.parseInt(s.nextLine());
			System.out.println("\n");
			if(num!=1)
			{
				d=false;
				System.out.println("Gracias por jugar!");
			}
		}
	}

	public static void ftablero(int[][] tablero, int filabomba, int columnabomba)
	{
		int i, j, ict, k;
		ict = 0;
		
		String tableroimpreso = "\n";
		
		for(j=0;j<15;j++)
		{          
			if(j==0)
			{
				for(k=0;k<15;k++)
				{
					if(k==0)
					{
						tableroimpreso += "    ";
					}
					tableroimpreso += k;
					if(k>=10)
					{
						tableroimpreso += " ";
					}
					else
					{
						tableroimpreso += "  ";
					}
				}
				tableroimpreso += "\n";
				tableroimpreso += "    ____________________________________________";
				tableroimpreso += "\n";
			}
			
			for(i=0;i<15;i++)
			{
				if(i==0)
				{
					tableroimpreso += i + ict;
					ict=ict+1;
					if(ict<=10)
					{
						tableroimpreso += "  ";
					}
					else
					{
						tableroimpreso += " ";
					}
					tableroimpreso += "|";
				}
				
				if (tablero[filabomba][columnabomba]==19)
				{
					if(tablero[j][i]==9)
					{
						tablero[j][i]=19;
					}
				}
				if(tablero[j][i]>=0 && tablero[j][i]<10)
				{
					tableroimpreso += 'X';
				}
				else if(tablero[j][i]==19)
				{
					tableroimpreso += '*';
				}
				else
				{
					tableroimpreso += tablero[j][i]-10;
				}
				tableroimpreso += "  ";	
			}
			
			tableroimpreso += "\n";
		}
		
		System.out.println(tableroimpreso);
		
		return;
	}
	
	public static void fbombas(int bombas, int[][] tablero)
	{
		int rand1, rand2, i;
		
		for(i = bombas;i>0;i--)
		{
			rand1 = ThreadLocalRandom.current().nextInt(0, 14 + 1);
			rand2 = ThreadLocalRandom.current().nextInt(0, 14 + 1);
			
			if(tablero[rand1][rand2]==9)
			{
				i++;
			}
			else
			{
				tablero[rand1][rand2]=9;
			}
		}
		
		return;
	}
	
	public static void fcontarbombas(int fila, int columna, int tablero[][])
	{
		int i, j, contadorbombas, iniciofila, iniciocolumna, finfila, fincolumna;
		contadorbombas=0;
		
		if(fila==0)
		{
			iniciofila=1;
			finfila=2;
		}
		else if(fila==14)
		{
			finfila=1;
			iniciofila=0;
		}
		else
		{
			iniciofila=0;
			finfila=2;
		}
		if(columna==0)
		{
			iniciocolumna=1;
			fincolumna=2;
		}
		else if(columna==14)
		{
			fincolumna=1;
			iniciocolumna=0;
		}
		else
		{
			iniciocolumna=0;
			fincolumna=2;
		}
		
		for(i=iniciofila;i<=finfila;i++)
		{
			for(j=iniciocolumna;j<=fincolumna;j++)
			{
				if(tablero[fila-1+i][columna-1+j]==9)
				{
					contadorbombas++;
				}
			}
			if(contadorbombas>0)
			{
				tablero[fila][columna]=contadorbombas;
			}
		}
		
		return;
	}
	
	public static void fverceros(int fila, int columna, int[][] tablero)
	{
		int i, j, iniciofila, iniciocolumna, finfila, fincolumna;
		
		if(fila==0)
		{
			iniciofila=1;
			finfila=2;
		}
		else if(fila==14)
		{
			finfila=1;
			iniciofila=0;
		}
		else
		{
			iniciofila=0;
			finfila=2;
		}
		if(columna==0)
		{
			iniciocolumna=1;
			fincolumna=2;
		}
		else if(columna==14)
		{
			fincolumna=1;
			iniciocolumna=0;
		}
		else
		{
			iniciocolumna=0;
			fincolumna=2;
		}
		
		for(i=iniciofila;i<=finfila;i++){
			for(j=iniciocolumna;j<=fincolumna;j++)
			{
				if(tablero[fila-1+i][columna-1+j]==0)
				{
					tablero[fila-1+i][columna-1+j]+=10;
					fverceros(fila-1+i, columna-1+j, tablero);
				}
				else if(tablero[fila-1+i][columna-1+j]<9)
				{
					tablero[fila-1+i][columna-1+j]+=10;
				}
			}
		}
		
		return;
	}
	
	public static int fganar(int[][] tablero)
	{
		int i, j, cpos;
		cpos=0;
		
		for (i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
			{
				if(tablero[i][j]<9)
				{
					cpos++;
				}
			}
		}
		return cpos;
	}
	
}
