/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/06/10 08:04:20 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Conv::Conv( void ) : _arg("")
{
	whichType();
}

Conv::Conv( char* const arg ) : _arg(arg)
{
	whichType();
}

Conv::Conv( Conv const & rhs ) : _arg(rhs._arg)
{
	whichType();
}

Conv const Conv::operator=(Conv const & rhs)
{
	new (this) Conv(rhs);
	return *this;
}

Conv::~Conv( void )
{

}

const char* Conv::IncorrectTypeException::what() const throw()
{
	return "type exception : type is not CHAR or INT or FLOAT or DOUBLE";
}

bool Conv::isChar()
{
	if (std::strlen(this->_arg) == 1 && this->_arg[0] < 127 && this->_arg[0] >= 32
	&& !std::isdigit(this->_arg[0]))
		return 1;
	return 0;
}

bool Conv::isInt()
{
	size_t i = 0;

	if (this->_arg[i] == '-' || this->_arg[i] == '+')
		i++;
	while (i < std::strlen(this->_arg))
	{
		if (!std::isdigit(this->_arg[i]))
			return 0;
		i++;
	}
	return 1;
}

bool Conv::isFloat()
{
	size_t i = 0;
	int	point = 0;

	if (this->_arg[i] == '-' || this->_arg[i] == '+')
		i++;
	while (i < std::strlen(this->_arg) - 1)
	{
		if (!std::isdigit(this->_arg[i]) && _arg[i] != '.')
			return 0;
		if (_arg[i] != '.')
			point++;
		if (point > 1)
			return 0;
		i++;
	}
	if (this->_arg[i] != 'f')
		return 0;
	return 1;
}

bool Conv::isDouble()
{
	size_t i = 0;
	int	point = 0;

	if (this->_arg[i] == '-' || this->_arg[i] == '+')
		i++;
	while (i < std::strlen(this->_arg) - 1)
	{
		if (!std::isdigit(this->_arg[i]) && _arg[i] != '.')
			return 0;
		if (_arg[i] == '.')
			point++;
		if (point > 1)
			return 0;
		i++;
	}
	if (this->_arg[i] == 'f' or !std::isdigit(this->_arg[i]))
		return 0;
	return 1;
}

void Conv::whichType()
{
	if (isChar())
	{
		_argC = _arg[0];
		_argI = static_cast<int>(_argC);
		_argF = static_cast<float>(_argC);
		_argD = static_cast<double>(_argC);
	}
	else
	{
		_argC = static_cast<char>(std::strtod(_arg, NULL));
		_argI = static_cast<int>(std::strtod(_arg, NULL));
		_argF = static_cast<float>(std::strtod(_arg, NULL));
		_argD = std::strtod(_arg, NULL);
	}
	if (!isConstant() && !isInt() && !isChar() && !isDouble()&& !isFloat())
		throw IncorrectTypeException();
}

bool Conv::checkValidC()
{
	if ((this->_argI >= 32 and this->_argI < 127))
		return 1;
	return 0;
}

bool Conv::checkValidI()
{
	if (this->_argD >= INT_MIN and this->_argD <= INT_MAX)
		return 1;
	return 0;
}

bool Conv::checkValidF()
{
	if (_argD != 0.0 and _argD >= -FLT_MIN and _argD <= FLT_MIN)
		return 0;
	if (this->_argD >= -FLT_MAX and this->_argD <= FLT_MAX and checkValidD())
		return 1;
	return 0;
}

bool Conv::checkValidD()
{
	errno = 0;
	std::strtod(_arg, NULL);
	if (errno == ERANGE)
		return 0;
	return 1;
}

bool Conv::isConstant()
{
	if (this->_argD != this->_argD or this->_argF == INFINITY or -this->_argF == INFINITY)
		return 1;
	return 0;
}

void Conv::printChar()
{
	if (checkValidC())
		std::cout << "char: '" << this->_argC << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void Conv::printInt()
{
	if (checkValidI())
		std::cout << "int: " << this->_argI << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Conv::printFloat()
{
	if (checkValidF())
	{
		std::cout << "float: ";
		if (_argF - _argI == 0)
		{
			std::cout << _argF << ".0f" << std::endl;
		}
		else
			std::cout << _argF << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}

void Conv::printDouble()
{
	if (checkValidD())
	{
		std::cout << "double: ";
		if (_argD - _argI == 0)
		{
			std::cout << _argD << ".0" << std::endl;
		}
		else
			std::cout << _argD << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

void Conv::printConv()
{
	if (isConstant())
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		if (this->_argD != this->_argD)
		{
			std::cout << "float1: " << _argF << "f" << std::endl;
			std::cout << "double1: " << _argD << std::endl;
		}
		else if (this->_argF == INFINITY)
		{
			std::cout << "float: " << _argF << "f" << std::endl;
			std::cout << "double: " << _argD <<std::endl;
		}
		else
		{
			std::cout << "float: " << _argF << "f" << std::endl;
			std::cout << "double: " << _argD << std::endl;
		}
	}
	else
	{
		if (isChar())
			std::cout << "type: Char" << std::endl;
		else if (isInt())
			std::cout << "type: Int" << std::endl;
		else if (isDouble())
			std::cout << "type: Doulbe" << std::endl;
		else if (isFloat())
			std::cout << "type: Float" << std::endl;
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
}
