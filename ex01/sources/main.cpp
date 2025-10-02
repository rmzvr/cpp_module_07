#include <iter.hpp>

template< typename T >
void	increment(T & i)
{
	i++;
}

template<>
void	increment(std::string & i) = delete;

template< typename T >
void	print(T const & t)
{
	std::cout << t << std::endl;
}

int main( void ) {
	int const			constInts[] = { 1, 2, 3, 4, 5 };
	float				modifiableFloats[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };

	std::string			strings[] = { "Hi ", "world", "!" };
	std::string const	constStrings[] = { "Hello ", "world", "!" };

	iter(modifiableFloats, (sizeof(modifiableFloats) / sizeof(modifiableFloats[0])), increment<float>);

	iter(modifiableFloats, (sizeof(modifiableFloats) / sizeof(modifiableFloats[0])), print<float>);

	// iter(constInts, (sizeof(constInts) / sizeof(constInts[0])), increment);

	iter(constInts, (sizeof(constInts) / sizeof(constInts[0])), print<int>);

	// iter(strings, (sizeof(strings) / sizeof(strings[0])), increment);

	iter(constStrings, (sizeof(constStrings) / sizeof(constStrings[0])), print<std::string>);
	return 0;
}