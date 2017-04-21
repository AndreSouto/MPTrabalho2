#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romdec.hpp"
#include <string.h>


TEST_CASE("Testes da função recebeString()"){	  //TEST_CASE que averigua o funcionamento de recebString()

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

TEST_CASE("Segundo teste"){

	REQUIRE(1 == 1);
}