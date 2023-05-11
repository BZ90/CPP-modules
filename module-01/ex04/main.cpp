#include "main.hpp"

int	replace(std::string filename, std::string to_replace, std::string replace_with)
{
	int				replace_index;
	std::string		line;
	std::ifstream	file;
	std::ofstream	file_replace;

	file.open(filename);
	if (!file.is_open())
	{
		std::cerr << "Error opening " << filename << std::endl;
		return (2);
	}
	filename.append(".replace");
	file_replace.open(filename);
	while (getline(file, line))
	{
		replace_index = line.find(to_replace);
		while (replace_index != -1)
		{
			line.erase(replace_index, to_replace.length());
			line.insert(replace_index, replace_with);
			replace_index = line.find(to_replace);
		}
		file_replace << line << std::endl;
	}
	file.close();
	file_replace.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "usage: Replace [filename] [to_replace] [replace_with]" << std::endl;
		return (1);
	}
	return (replace(argv[1], argv[2], argv[3]));
}