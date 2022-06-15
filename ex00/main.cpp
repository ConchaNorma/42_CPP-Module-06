/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/06/10 08:05:46 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && !std::strlen(argv[1])))
	{
		std:: cout << "Please enter one argument CHAR or INT or FLOAT or DOUBLE" << std::endl;
		return 1;
	}
	try
	{
		Conv toConvert(argv[1]);
		// Conv toConvertCopy(toConvert);

		toConvert.printConv();
		// toConvertCopy.printConv();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
