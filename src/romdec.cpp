#include <stdio.h>
#include <stdlib.h>

char *recebeString(){ //Função que recebe string do usuário e valida o tamanho da mesma

	char *string_retornada = (char*)malloc(sizeof(char));

	printf("Insira um valor em numeros romanos\n");
	scanf("%s",string_retornada);

	int contador = 0;
	while(*(string_retornada + contador) != '\0'){
			
		contador++; 
	}

	while(contador >= 29){

		printf("Tamanho maior que 30.\n");
		printf("Insira um valor em numeros romanos\n");
		scanf("%s",string_retornada);

		int contador = 0;
		while(*(string_retornada + contador) != '\0'){
			
			contador++;
		}
	}

	return string_retornada;
}