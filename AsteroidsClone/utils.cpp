#include "utils.h"


std::string read_file(const char* path)
{
	std::ifstream reader(path);

	if (reader.fail())
	{
		std::cout << "Could not read file\n";
		return std::string();
	}



	std::string fileContents;
	std::string temp;


	while (!reader.eof())
	{
		std::getline(reader, temp);
		fileContents.append(temp);
		fileContents.append("\n");
	}



	reader.close();

	return fileContents;

}

std::string read_file(std::string path)
{
	return read_file(path.c_str());
}




void error_callback(int error, const char* description)
{
	printf(description);
}