#pragma once
#include <iostream>
#include"Command.h"
#include"Parser.h"

class Application
{
public:
	void registerCommand(std::unique_ptr<Command> command);
	int execute(int argc, char *argv[]);

private:

	std::map<std::string, std::unique_ptr<Command>> Commands;
	std::map<std::string, std::string> args;
	std::map<std::string, std::string>::iterator it;

};