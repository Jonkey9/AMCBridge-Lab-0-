#include "Application.h"
int Application::execute(int argc, char *argv[])
{
	Parser Mapp;
	
	if ((argc<5)||(argc==6))return 3;
	else
	args = Mapp.Split(argc, argv);
	
	for (it = args.begin(); it != args.end(); it++)
	std::cout << it->first << ' ' << it->second << '\n';
	
	if (std::string(argv[1]) == "Cube")return Commands["Cube"]->execute(args);
	else
		if (std::string(argv[1]) == "Sphere")return Commands["Sphere"]->execute(args);
		else
			if (std::string(argv[1]) == "Split") return Commands["Split"]->execute(args);
			else
				return 3;


};


void Application::registerCommand(std::unique_ptr<Command> command)
{
	Commands.insert(std::make_pair(command->getName(), std::move(command)));
}


