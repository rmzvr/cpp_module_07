#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class Array
{
	private:
		size_t	_length = 0;
		T *		_elements = nullptr;
	public:
		Array();
		Array( unsigned int n );
		Array( Array<T> const & other );
		Array<T> & operator=( Array<T> const & other );
		~Array();

		T &			operator[]( size_t idx );
		T const &	operator[]( size_t idx ) const;
};

template <typename T>
inline Array<T>::Array()
{
	std::cout << "Default constructor called" << std::endl;
	this->_elements = new T[0]();
}

template <typename T>
inline Array<T>::Array( unsigned int n )
{
	std::cout << "Parameterized constructor called" << std::endl;
	this->_length = static_cast<size_t>(n);
	this->_elements = new T[this->_length]();
}

template <typename T>
inline Array<T>::Array( Array<T> const &other ) : _length(other._length), _elements(new T[this->_length]())
{
	std::cout << "Copy constructor called" << std::endl;
	for (size_t i = 0; i < this->_length; ++i)
	{
		this->_elements[i] = other._elements[i];
	}
}

template <typename T>
inline Array<T> &Array<T>::operator=( Array<T> const &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_length = other._length;
		if (this->_elements != nullptr)
		{
			delete [] this->_elements;
		}
		this->_elements = new T[this->_length]();
		for (size_t i = 0; i < this->_length; ++i)
		{
			this->_elements[i] = other._elements[i];
		}
	}
	return (*this);
}

template <typename T>
inline Array<T>::~Array()
{
	std::cout << "Default destructor called" << std::endl;
	if (this->_elements != nullptr)
	{
		delete [] this->_elements;
	}
}

template <typename T>
inline T & Array<T>::operator[]( size_t idx )
{
	std::cout << "Non-const subscript operator called" << std::endl;
	if (this->_length > 0 && idx < this->_length)
	{
		return this->_elements[idx];
	}
	throw std::exception();
}

template <typename T>
inline T const & Array<T>::operator[]( size_t idx ) const
{
	std::cout << "Const subscript operator called" << std::endl;
	if (this->_length > 0 && idx < this->_length)
	{
		return this->_elements[idx];
	}
	throw std::exception();
}

#endif