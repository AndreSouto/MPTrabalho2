#include <stdio.h>
#include <stdlib.h>

char *recebeString(){ //Função que recebe string do usuário e valida o tamanho da mesma

	char *string_retornada = (char*)malloc(sizeof(char));	//Alocando dinamicamente a string para a mesma 
															//não ser perdida após retorno da função
	printf("Insira um valor em numeros romanos\n");
	scanf("%s",string_retornada);

	int contador = 0;
	while(*(string_retornada + contador) != '\0'){			//Contagem de caracteres na string
			
		contador++; 
	}

	while(contador >= 29){									//Verificação se a string tem tamanho válido
															//Caso não tenha, usuário deve inserir outra
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

int converteRomDec(char *romano){	//Função que recebe a string inserida pelo usuário e converte em decimal


}
