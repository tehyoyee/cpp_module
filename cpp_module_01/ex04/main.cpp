/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:06:48 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/12 19:06:49 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int argc, char *argv[])
{
	size_t pos;
	size_t s1_len;
	size_t s2_len;
	std::ifstream ifs;
	std::ofstream ofs;
	std::string s1;
	std::string s2;
	std::string infile;
	std::string outfile;
	std::string content;


	if (argc != 4)
		exit_error("incorrect argument number");
	infile = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	s1_len = s1.size();
	s2_len = s2.size();
	if (infile.size() == 0 || s1_len == 0 || s2_len == 0)
		exit_error("incorrect file name");
	ifs.open(infile);

	if (ifs.fail())
		exit_error("file cannot be opened");
	outfile = infile.append(".new");
	ofs.open(outfile);
	if (ofs.fail())
		exit_error("file cannot be opened");

	while (getline(ifs, content))
	{
		pos = 0;
		while ((pos = content.find(s1, pos)) != std::string::npos)
		{
			content.erase(pos, s1_len);
			content.insert(pos, s2);
			pos += s2_len;
		}
		ofs << content;
		if (ifs.eof())
			break;
		ofs << std::endl;
	}
}
