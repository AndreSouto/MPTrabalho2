/**********************************************************************************************************
Aluno: Andre Luis Souto Ferreira 		140016261
Metodos de Programacao
**********************************************************************************************************/
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

int validaRom(char *romano){

}

int converteRomDec(char *romano){	//Função que recebe a string inserida pelo usuário e converte em decimal


	int i = 0;									//Contador
	int auxiliar, auxiliar2; 					//Variáveis para auxiliar na soma
	int valor_dec = 0;
	int validacao = validaRom(romano);			//Valida ou não a sequência de números romanos inserida


	if(validacao == 1){							//Se válida, executa processo de conversão							



		while(*(romano+i) != '\0'){				//Percorre toda a string até encontrar o último caracter: \0

			if(*(romano + i) == 'I'){			//Caso em que caracter é igual a I

				auxiliar = 1;
			}
			else if(*(romano + i) == 'V'){		//Caso em que caracter é igual a V

				auxiliar = 5;
			}
			else if(*(romano + i) == 'X'){		//Caso em que caracter é igual a X
				
				auxiliar = 10;
			}
			else if(*(romano + i) == 'L'){		//Caso em que caracter é igual a L

				auxiliar = 50;
			}
			else if(*(romano + i) == 'C'){		//Caso em que caracter é igual a C
				
				auxiliar = 100;
			}
			else if(*(romano + i) == 'D'){		//Caso em que caracter é igual a D
				
				auxiliar = 500;
			}
			else if(*(romano + i) == 'M'){		//Caso em que caracter é igual a M
				
				auxiliar = 1000;
			}


			if(*(romano + (i+1)) != '\0'){				//Pega o próximo caracter da string

				
				if(*(romano + (i+1)) == 'I'){			//Caso em que caracter é igual a I

					auxiliar2 = 1;
				}
				else if(*(romano + (i+1)) == 'V'){		//Caso em que caracter é igual a V

					auxiliar2 = 5;
				}
				else if(*(romano + (i+1)) == 'X'){		//Caso em que caracter é igual a X

					auxiliar2 = 10;
				}
				else if(*(romano + (i+1)) == 'L'){		//Caso em que caracter é igual a L

					auxiliar2 = 50;
				}
				else if(*(romano + (i+1)) == 'C'){		//Caso em que caracter é igual a C

					auxiliar2 = 100;
				}
				else if(*(romano + (i+1)) == 'D'){		//Caso em que caracter é igual a D

					auxiliar2 = 500;
				}
				else if(*(romano + (i+1)) == 'M'){		//Caso em que caracter é igual a M
					
					auxiliar2 = 1000;
				}

				if(auxiliar < auxiliar2){		//Caso o próximo seja maior que o atual, subtrai

					valor_dec = valor_dec + (auxiliar2 - auxiliar);
					i++;
				}	
				else{							//Caso o próximo seja menor ou igual ao atual, soma

					valor_dec = valor_dec + (auxiliar + auxiliar2);
					i++;
				}

			}
			else{			//Caso não exista próximo caracter, apenas soma ao valor_dec

				valor_dec = valor_dec + auxiliar; 
			}

			i++;
		}
	}
	else{				//Se não, retorna -1

		valor_dec = -1ç
	}


	return valor_dec;
}
