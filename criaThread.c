#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>	// biblioteca com as funçoes de criacao de thread

void *funcao_thread( void *arg){
	printf("\nSou a nova thread, vou esperar 15s.");
	sleep(15);

	// Posso terminar a função ou usar o pthread_exit para sair a força
	//pthread_exit(1);

	printf("\nTerminei a espera.");	
}

int main(){

	pthread_t thread;
	printf("\nCriei a thread");
	// cria uma nova thread, concorrente ao processo principal
	
	/*
	 ponteiro para a thread
	 atributo para a thread
	 funcao a ser executada
	 argumento para a rotina
	*/	
	pthread_create( &thread, NULL, &funcao_thread, NULL);
	printf("\nEstou esperando o fim da thread");
	
	// identificação da thread
	// valor retornado quando a thread termina
	pthread_join(thread, NULL);
	printf("\nA thread acabou e eu tambem vou acabar. Tchau!");
	return 0;
}