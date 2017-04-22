/**********************************************************************************************************
Aluno: Andre Luis Souto Ferreira 		140016261
Metodos de Programacao
**********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>    


char *recebeString(){ //Função que recebe string do usuário e valida o tamanho da mesma

	char *string_retornada = (char*)malloc(30*sizeof(char));	//Alocando dinamicamente a string para a mesma 
																//não ser perdida após retorno da função
	printf("Insira um valor em numeros romanos\n");
	fgets(string_retornada,30,stdin);					//fgets usado para conter warning dado pelo cppcheck
														//inicialmente havia sido usado scanf()
	
	int i = 0;
	while(*(string_retornada + i) != '\n'){
		i++;
	}


	*(string_retornada + i) = '\0';		//Troca '\n' por '\0' para não ter erro de comparação

	return string_retornada;			//Retorno da string
}


int validaRom(char *romano){	//Função que valida o valor romano, se valer retorna 1 se não, retorna -1

	int contadorV = 0, contadorD = 0, contadorL = 0;			//Contadores para V,D e L
	int i = 0;										


	/** Primeira filtragem: Valores D,L e V não podem aparecer mais de uma vez **/
	while(*(romano+i) != '\0'){				

		if(*(romano + i) == 'V'){		

			contadorV++;				//Contador de V
		}

		if(*(romano + i) == 'L'){		

			contadorD++;				//Contador de D
		}

		if(*(romano + i) == 'D'){		

			contadorL++;				//Contador de L
		}

		i++;
	}

	if(contadorL > 1 || contadorD > 1 || contadorV > 1){	//Caso V,L ou D apareçam mais que uma vez, retorna -1

		return -1;
	}


	/** Segunda filtragem: Os valores I,C,X e M não podem aparecer mais do que três vezes seguidas **/
	i = 0;
	int j = 0;
	int contadorI = 0, contadorC = 0, contadorX = 0, contadorM = 0;			//Contador das letras

	while(*(romano+i) != '\0'){				

		if(*(romano + i) == 'I'){		//Verifica se I aparece mais que três vezes seguidas

			contadorI = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'I'){

					contadorI++;
					j++;
				}
				else{

					break;
				}
			}

			if(contadorI > 3){			//Se aparecer, retorna -1

				return -1;
			}
		}

		if(*(romano + i) == 'C'){		//Verifica se C aparece mais que três vezes seguidas

			contadorC = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'C'){

					contadorC++;
					j++;
				}
				else{

					break;
				}
			}
		
			if(contadorC > 3){		 	//Se aparecer, retorna -1

				return -1;
			}
		}

		if(*(romano + i) == 'X'){		//Verifica se X aparece mais que três vezes seguidas
			
			contadorX = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'X'){

					contadorX++;
					j++;
				}
				else{

					break;
				}
			}

			if(contadorX > 3){			//Se aparecer, retorna -1

				return -1;
			}
		}

		if(*(romano + i) == 'M'){		//Verifica se M aparece mais que três vezes seguidas

			contadorM = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'M'){

					contadorM++;
					j++;
				}
				else{

					break;
				}
			}

			if(contadorM > 3){			//Se aparecer, retorna -1

				return -1;
			}
		}

		i++;

	}


	/** Terceira filtragem: Quando a esquerda de símbolos de maior valor, I,C,X só podem ser usados uma vez **/
	i = 0;

	while(*(romano+i) != '\0'){				

		if(*(romano + i) == 'I'){		//Verifica se I está a esquerda de um símbolo de maior valor e qtas vezes

			contadorI = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'I'){

					contadorI++;
				}
				else{

					if(contadorI > 1){

						return -1;
					}
				}
				j++;
			}
		}

		if(*(romano + i) == 'C'){		//Verifica se C está a esquerda de um símbolo de maior valor e qtas vezes

			contadorD = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'C'){

					contadorD++;
				}
				else{

					if(*(romano + j) == 'D' || *(romano + j) == 'M'){
						
						if(contadorD > 1){

							return -1;
						}
					}
				}
				j++;
			}
		}

		if(*(romano + i) == 'X'){		//Verifica se X está a esquerda de um símbolo de maior valor e qtas vezes

			contadorX = 1;
			j = i + 1;

			while(*(romano + j) != '\0'){

				if(*(romano + j) == 'X'){

					contadorX++;
				}
				else{

					if(*(romano + j) != 'V' && *(romano + j) != 'I'){
						
						if(contadorX > 1){

							return -1;
						}
					}
				}
				j++;
			}
		}

		i++;
	}


	/** Quarta filtragem: De M e D só se subtrai C, de C e L só se subtrai X, de X e V só se subtrai I **/
	i = 0;

	while(*(romano+i) != '\0'){				

		if(*(romano + i) == 'C'){	//Se for C, vale tudo	

			//Qualquer opcao é válida
		}

		if(*(romano + i) == 'X'){	//Se for X, só pode estar antes de C,L,V e I

			if(*(romano + (i + 1)) == 'D' || *(romano + (i + 1)) == 'M' || *(romano + (i + 1)) == 'C' || 
			   *(romano + (i + 1)) == 'L' || *(romano + (i + 1)) == '\0'){
				
				if(*(romano + (i + 1)) != 'C' && *(romano + (i + 1)) != 'L' && *(romano + (i + 1)) != '\0'){
					
					return -1;
				}
			}
		}

		if(*(romano + i) == 'I'){	//Se for I, só pode estar antes de X, de V e de outro I

			if(*(romano + (i + 1)) != 'X' && *(romano + (i + 1)) != 'V' && *(romano + (i + 1)) != '\0' &&
			   *(romano + (i + 1)) != 'I'){

				return -1;
			}
		}

		if(*(romano + i) == 'V'){	//Se for V, só pode estar antes de I

			if(*(romano + (i + 1)) != 'I' && *(romano + (i + 1)) != '\0'){

				return -1;
			}	
		}

		if(*(romano + i) == 'M'){	//Se for M, vale tudo

			//Qualquer opcao é válida
		}

		if(*(romano + i) == 'D'){	//Se for D, só não pode estar antes de M

			if(*(romano + (i + 1)) == 'M'){

				return -1;
			}
		}

		if(*(romano + i) == 'L'){	//Se for L, só não pode estar antes de M,D ou C

			if(*(romano + (i + 1)) == 'M' || *(romano + (i + 1)) == 'D' || *(romano + (i + 1)) == 'C'){

				return -1;
			}
		}

		i++;
	}


	return 1;		//Retorna 1 indicando que está tudo certo com os símbolos e suas ordens na string
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

		valor_dec = -1;
	}


	return valor_dec;
}
