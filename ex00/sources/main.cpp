#include <whatever.hpp>

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", a_p = " << &a << ", b = " << b << ", b_p = " << &b << std::endl;
	std::cout << "min( a, b ) = "  << ::min<int>( a, b ) << ", p = " << &(::min<int>( a, b )) << std::endl;
	std::cout << "max( a, b ) = "  << ::max<int>( a, b ) << ", p = " << &(::max<int>( a, b )) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;
	return 0;
}