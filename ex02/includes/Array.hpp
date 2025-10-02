#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array
{
	private:
		size_t	_length = 0;
		T *		_elements;
	public:
		Array();
		Array( unsigned int n );
		~Array();
};

#endif

template <typename T>
inline Array<T>::Array()
{
	this->_elements = new T[this->_length];
}

template <typename T>
inline Array<T>::Array(unsigned int n)
{
	this->_elements = new T[n];
}

template <typename T>
inline Array<T>::~Array()
{
	delete [] this->_elements;
}
