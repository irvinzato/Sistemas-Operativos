#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 4
#define M 5

int m[N][M];
int l1,l2;
int ia;
int auxN = N-1;
int auxM = M-1;

void *imprimirm(void *th){

	for(int i=0;i<N;i++){
		for(int j=0;i<M;j++){
			m[i][j]=1+rand()%100;
			printf("%d\n", m[i][j] );
		}
		printf("\n");
	}
}

void *invertir(void *th){
	int tid = (long) th;

	if(tid < l2){
		for(int i=0;i<l1;i++){

			int aux = m[tid][i];
			m[tid][i] = m[auxN-tid][auxM-i];
			m[auxN-tid][auxM-i]= aux;
		}

	}else{
		for(int j=0; j<l2;j++){

			int aux = m[tid][j];
			m[tid][j] = m[auxN-tid][auxM-j];
			m[auxN-tid][auxM-j]= aux;			


		}
	}


	pthread_exit(NULL);
}

void *ordenrenglon(void *th){
	int tid = (long) th;

	for(int i=0;i<M;i++){
		for(int j=i+1;j<M;j++){
			if(m[tid][i]>m[tid][j]){
				int aux2= m[tid][j];
				m[tid][j]=m[tid][i];
				m[tid][i]=aux2;
			}

		}

	}
pthread_exit(NULL);
}

void *ordenrcolumna(void *th){
	int tid = (long) th;

	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(m[i][tid]>m[j][tid]){
				int aux2= m[j][tid];
				m[j][tid]=m[i][tid];
				m[i][tid]=aux2;
			}

		}

	}
pthread_exit(NULL);
}

int main(){

	pthread_t h[N];

	long tid[N];

	l1 = (M/2) + (M%2);
	if(M%2 != 0){
		l2 = l1 - 1;
	}else{
		l2 = l1;
	}

	ia = (N/2) + (N%2);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			m[i][j]=1+rand()%100;
			printf(" %d ", m[i][j] );
		}
		printf("\n");
	}

	for(int i=0;i<N;i++){
		tid[i]=i;
		pthread_create(&h[i],NULL,invertir,(void *) tid[i]);

	}



	for(int e=0;e<N;e++){
		pthread_join(h[e],NULL);

	}

		printf("\n\n");
		for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf(" %d ", m[i][j] );
		}
		printf("\n");
	}

	for(int i=0;i<N;i++){
		tid[i]=i;
		pthread_create(&h[i],NULL,ordenrenglon,(void *) tid[i]);

	}

	for(int e=0;e<N;e++){
		pthread_join(h[e],NULL);

	}

		for(int i=0;i<N;i++){
		tid[i]=i;
		pthread_create(&h[i],NULL,ordenrcolumna,(void *) tid[i]);

	}

	printf("\n\n");
		for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf(" %d ", m[i][j] );
		}
		printf("\n");
	}


}