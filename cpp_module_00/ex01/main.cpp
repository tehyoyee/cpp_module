#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	Phonebook phonebook;
	int	index = 0;

	while (std::getline(std::cin, cmd))
	{
		index %= 8;
		if (cmd == "ADD")
		{
			phonebook.add_contact(index);
			index++;
		}
		else if (cmd == "SEARCH")
		{
			show_field_name();
			for (int i = 0; i < 8; i++)
				phonebook.show(i);
			show_selected(phonebook);
		}
		else if (cmd == "EXIT")
			exit(0);
	}
}
