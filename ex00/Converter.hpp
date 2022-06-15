/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:07:03 by cnorma            #+#    #+#             */
/*   Updated: 2022/06/08 23:14:37 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
#define CONVERTER_H

#include <ios>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <exception>
#include <cerrno>

class Conv
{
private:
	const char* _arg;
	char _argC;
	int _argI;
	float _argF;
	double _argD;

	bool isInt();
	bool isChar();
	bool isFloat();
	bool isDouble();
	void whichType();
	bool checkValidC();
	bool checkValidI();
	bool checkValidF();
	bool checkValidD();
	bool isConstant();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
	class IncorrectTypeException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
public:
	Conv( void );
	Conv( char* const arg );
	Conv( Conv const & rhs );
	Conv const operator=(Conv const & rhs);
	~Conv( void );
	void printConv();
};

#endif
