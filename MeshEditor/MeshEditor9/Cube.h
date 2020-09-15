#pragma once
#include"Command.h"
#include"Parser.h"
#include "STLParser.h"


	class Cube :public Command
	{
	public:
		
		const std::string& getName() const override;
		int execute(const std::map<std::string, std::string>& args) override;

	private:
		std::string Name = "Cube";
		TriangleSoup triangleSoup;
		Vec normal{ 0,0,0 };
		std::vector<double>OriginPoint;
		std::vector<Vec>ArrayOrigin;
		double L;
		std::string filename;
		Vec Normals(Vec,Vec,Vec);

	};



