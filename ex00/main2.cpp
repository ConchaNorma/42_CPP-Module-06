/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/06/07 08:18:25 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

void getType(std::string &str, std::string &type)
{
	if (str.length() == 1 && !isdigit(str[0]))
		type = "char";
	else if (str.find('.') != std::string::npos && \
		str.find('f') != std::string::npos)
	{
		type = "float";
		stof(str, NULL);
	}
	else if (isDouble(str) || isNanInf(str))
	{
		type = "double";
		stod(str, NULL);
	}
	else
	{
		type = "integer";
		stoi(str, NULL);
	}
}

void	displayChar(std::string str){
	int result;

	if (str.size() == 1 && isdigit(str[0]) == false)
		std::cout << static_cast<char>(str[0])<< std::endl;
	else {
		std::size_t lastChar;
		result = std::stoi(str, &lastChar, 10);
		if (isprint(result))
			std::cout << static_cast<char>(result) << std::endl;
		if (result <= 32 || result >= 127)
			std::cout << "Non displayable" << std::endl;
	}
	return ;
}

void	displayInt(std::string str){
	int result;

	std::size_t lastChar;
	result = std::stoi(str, &lastChar, 10);
	std::cout << static_cast<int>(result) << std::endl;
	return ;
}

void	displayFloat(std::string str){
	float result;

	std::size_t lastChar;
	result = std::stof(str, &lastChar);
	std::cout << static_cast<float>(result);
	if (roundf(result) == result)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	return ;
}

void	displayDouble(std::string str){
	double result;

	std::size_t lastChar;
	result = std::stod(str, &lastChar);
	std::cout << static_cast<double>(result);
	if (roundf(result) == result)
		std::cout << ".0";
	std::cout << std::endl;
	return ;
}

void	displayconvert(std::string str)
{
	std::cout << "char: ";
	try
	{
		displayChar(str);
	}
	catch (std::invalid_argument&)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		displayInt(str);
	}
	catch (std::invalid_argument&)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		displayFloat(str);
	}
	catch (std::invalid_argument&)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		displayDouble(str);
	}
	catch (std::invalid_argument&)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "Non displayable" << std::endl;
	}
	return ;
}


int	main(int ac, char const **av){
	std::string str;

	if (ac == 2)
	{
		str = static_cast<std::string>(av[1]);
		displayconvert(str);
	}
	else
		std::cout << "You need one Parameter" << std::endl;
	return (0);
}
