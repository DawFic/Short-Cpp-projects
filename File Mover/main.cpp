#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

//function prototypes
std::string getSourcePath();
std::string getDestinationPath();


int main()
{
	while(true)
	{
		try
		{
			std::string sourcePath = getSourcePath();	
			std::string destinationPath = getDestinationPath();
			std::cout<<sourcePath<<">>"<<destinationPath<<std::endl;
			std::filesystem::rename(sourcePath, destinationPath);
			break;
		}
		catch(std::filesystem::filesystem_error const& error)
		{
			std::cout<<error.what()<<std::endl;
			std::cout<<error.path1()<<std::endl;	
			std::cout<<error.path2()<<std::endl;	
		}
	}
}
//////////////////////////////////////////////////////////////////////////////

std::string getSourcePath()
{
	std::cout<<"Enter source path of the file to be moved: ";
	std::string sourcePath;
	std::cin>>sourcePath;
	return sourcePath;
}
std::string getDestinationPath()
{
	std::cout<<"Enter destination path of the file to be moved: ";
	std::string destinationPath;
	std::cin>>destinationPath;
	return destinationPath;
}
