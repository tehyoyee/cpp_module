#include "utils.hpp"

int main(int argc, char *argv[])
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string s1;
	std::string s2;
	std::string infile;
	// char *infile;
	std::string outfile;
	// char *outfile;

	if (argc != 4)
		exit_error("incorrect argument number");
	infile = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (infile.length() == 0 || s1.length() == 0 || s2.length() == 0)
		exit_error("incorrect file name");
	ifs.open(infile);
	if (ifs.fail())
		exit_error("file cannot be opened");
	outfile = infile.append(".new");
	ofs.open(outfile);
	if (ofs.fail())
		exit_error("file cannot be opened");
}