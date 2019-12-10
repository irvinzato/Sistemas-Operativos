#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int x,y;
void menu();
void iniciar_matriz(int m[x][y],int a[y], time_t semilla,int rango);
void m_fifo(int m[x][y],int a[y]);
void s_fifo(int m[x][y],int a[y],int j,int *fa);
void pinta1(int j,int m[x][y]);
void pinta2(int fa,int j,int m[x][y],int a[y]);
void pinta(int m[x][y],int a[y]);

int main(){
menu();
}

void menu(){
	int n_pag;
	int secuencia;
	int rango;
	time_t semilla;
	int sem;
	printf("Dame el número de páginas en RAM\n\n");
	scanf("%d",&n_pag);
	printf("Ingresa el número total de páginas que serán accesadas\n\n");
	scanf("%d",&secuencia);
	printf("Ingresa el rango del rand()\n\n");
	scanf("%d",&rango);
	printf("Ingresa la semilla para iniciar el rand()\n");
	scanf("%d",&sem);
	semilla=(time_t)sem;
	int m[n_pag][secuencia];
	int a[secuencia];
	x=n_pag;
	y=secuencia;
	iniciar_matriz(m,a,semilla,rango);
	for(int i=0;i<y;i++){
	printf(" %d ",a[i]);

	}
	printf("\n");
	m_fifo(m,a);




	/*for(int i=0;i<n_pag;i++){
		for(int j=0;j<secuencia;j++){
		printf("%d",m[i][j]);
		}
		printf("\n");	
	}*/
	

}

void m_fifo(int m[x][y],int a[y]){
    int fa=0;
	pinta(m,a);
	
	for(int k=3;k<15;k++){
		sleep(2);
		printf("Entrando for...%d\n",k);
		printf("x: %d\n",x);
		s_fifo(m,a,k,&fa);

		/*for(int k=0;k<x;k++){
			printf("%d",m[k][j] );
		}*/

	} 

}

void s_fifo(int m[x][y],int a[y],int j,int *fa){
	int aux=0;
	printf("for...%d\n",j);
	for(int i=0;i<x;i++){
		if(m[i][j-1]==a[j]){
			aux=1;
			break;

		}else{
		aux=0;
	}
	}

	if(aux==1){
		pinta1(j,m);
	}else{
		pinta2(*fa,j,m,a);
		*fa++;
		if(*fa>x){
			*fa=0;
		}else;
	}
}

void pinta1(int j,int m[x][y]){
	for(int i=0;i<x;i++){
		m[i][j]=m[i][j-1];
		printf("%d\n",m[i][j]);
	}


}

void pinta2(int fa,int j,int m[x][y],int a[y]){
	printf("for2...%d\n",j);
	for(int i=0;i<x;i++){
		if(fa==i){
			m[fa][j]=a[j];
			printf("%d\n",m[fa][j]);
		}else{
			m[i][j]=m[i][j-1];
			printf("%d\n",m[i][j]);

		}
	}
}


void pinta(int m[x][y],int a[y]){
	for(int i=0;i<x;i++){
		for(int j=i;j<x;j++){
			if(m[i][j]==0){
				m[i][j]=a[i];
				printf("%d",m[i][j]);
			}else;
		}
		printf("\n");
	}
}

void iniciar_matriz(int m [x][y],int a[y],time_t semilla,int rango){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			m[i][j]=0;
		}	
	}
	srand((unsigned)time(&semilla));
	for(int i=0;i<y;i++){
		a[i]=1+rand()%rango;
	}
}

