#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romdec.hpp"
#include <string.h>


TEST_CASE("Testes da funcao recebeString():"){	  //TEST_CASE que averigua o funcionamento de recebeString()

	char *recebida = recebeString();
	REQUIRE(strcmp(recebida,"testando") == 0);    // String usada para fazer comparação com a recebida do usuário
												  // ATENÇÃO -- VALOR DEVE SER MUDADO DE ACORDO COM A STRING QUE SE
												  // DESEJA SER INSERIDA
	recebida = recebeString();
	REQUIRE(strcmp(recebida,"X") == 0);    		  // String usada para fazer comparação com a recebida do usuário
												  // ATENÇÃO -- VALOR DEVE SER MUDADO DE ACORDO COM A STRING QUE SE
												  // DESEJA SER INSERIDA

	recebida = recebeString();
	REQUIRE(strcmp(recebida,"L") == 0);    		  // String usada para fazer comparação com a recebida do usuário
												  // ATENÇÃO -- VALOR DEVE SER MUDADO DE ACORDO COM A STRING QUE SE
												  // DESEJA SER INSERIDA

}


TEST_CASE("Testes da funcao converteRomDec():"){	//TEST_CASE que averigua o funcionamento de converterRomDec()

	char romano[30];
	int valor_decimal;

	strcpy(romano,"X");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 10);				//Verifica se o valor convertido corresponde ao valor 10

	strcpy(romano,"IX");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 9);				//Verifica se o valor convertido corresponde ao valor 9

	strcpy(romano,"XXI");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 21);				//Verifica se o valor convertido corresponde ao valor 21

	strcpy(romano," CCCLXXX");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 380);				//Verifica se o valor convertido corresponde ao valor 380

	strcpy(romano,"MX");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 1010);				//Verifica se o valor convertido corresponde ao valor 1010

	strcpy(romano,"MMCI");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 2101);				//Verifica se o valor convertido corresponde ao valor 2101

	strcpy(romano,"MMCCLXXXII");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 2282);				//Verifica se o valor convertido corresponde ao valor 2282

	strcpy(romano,"MMM");
	valor_decimal = converteRomDec(romano);
	REQUIRE(valor_decimal == 3000);				//Verifica se o valor convertido corresponde ao valor 3000

}