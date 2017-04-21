#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romdec.hpp"


TEST_CASE("vetores tem que ter tamanho menor ou igual a 30") {

    std::vector<int> v( 5 );
    
    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );
    
    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );
        
        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
  	}
 }