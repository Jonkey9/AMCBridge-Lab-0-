#include "Cube.h"
Vec Cube::Normals(Vec a, Vec b, Vec c)
{
	double wrki;
	Vec v1, v2,n;

	v1.x = a.x - b.x;
	v1.y = a.y - b.y;
	v1.z = a.z - b.z;

	v2.x = b.x - c.x;
	v2.y = b.y - c.y;
	v2.z = b.z - c.z;

	wrki = sqrt(pow((v1.y*v2.z - v1.z * v2.y),2) + pow((v1.z * v2.x - v1.x * v2.z),2) + pow((v1.x * v2.y - v1.y * v2.x),2));
	n.x = (v1.y * v2.z - v1.z * v2.y) / wrki;
	n.y = (v1.z * v2.x - v1.x * v2.z) / wrki;
	n.z = (v1.x * v2.y - v1.y * v2.x) / wrki;

	return n;


}



int Cube::execute(const std::map<std::string, std::string>& args)
{
	
	Parser Check;
	STLParser WriteCube;
	std::map<std::string, std::string>params = args;
	if (std::stoi(params["L"]) <= 0)return 1;
	else
		if (Check.CheckFileName(params["filepath"]) == 2)return 2;
		else
			OriginPoint = Check.Point(params["origin"]);
	
	double L = std::stod(params["L"]);
	
	
	ArrayOrigin.push_back({ {OriginPoint[0]},{OriginPoint[1]},{OriginPoint[2]} });//0
	ArrayOrigin.push_back({ {OriginPoint[0]+L},{OriginPoint[1]},{OriginPoint[2]} });//1
	ArrayOrigin.push_back({ {OriginPoint[0]+L},{OriginPoint[1]+L},{OriginPoint[2]} });//2
	ArrayOrigin.push_back({ {OriginPoint[0]},{OriginPoint[1]+L},{OriginPoint[2]} });//3
	ArrayOrigin.push_back({ {OriginPoint[0]},{OriginPoint[1]},{OriginPoint[2]-L} });//4
	ArrayOrigin.push_back({ {OriginPoint[0]+L},{OriginPoint[1]},{OriginPoint[2]-L} });//5
	ArrayOrigin.push_back({ {OriginPoint[0]+L},{OriginPoint[1]+L},{OriginPoint[2]-L} });//6
	ArrayOrigin.push_back({ {OriginPoint[0]},{OriginPoint[1]+L},{OriginPoint[2]-L} });//7

	

	normal = Normals(ArrayOrigin[0], ArrayOrigin[1], ArrayOrigin[2]);
	triangleSoup.push_back({ ArrayOrigin[0],normal });//1
	triangleSoup.push_back({ ArrayOrigin[1],normal });
	triangleSoup.push_back({ ArrayOrigin[2],normal });


	normal = Normals(ArrayOrigin[2], ArrayOrigin[3], ArrayOrigin[0]);
	triangleSoup.push_back({ ArrayOrigin[2],normal });//2
	triangleSoup.push_back({ ArrayOrigin[3],normal });
	triangleSoup.push_back({ ArrayOrigin[0],normal });



	normal = Normals(ArrayOrigin[1], ArrayOrigin[5], ArrayOrigin[6]);
	triangleSoup.push_back({ ArrayOrigin[1],normal });//3
	triangleSoup.push_back({ ArrayOrigin[5],normal });
	triangleSoup.push_back({ ArrayOrigin[6],normal });



	normal = Normals(ArrayOrigin[6], ArrayOrigin[2], ArrayOrigin[1]);
	triangleSoup.push_back({ ArrayOrigin[6],normal });//4
	triangleSoup.push_back({ ArrayOrigin[2],normal });
	triangleSoup.push_back({ ArrayOrigin[1],normal });



	normal = Normals(ArrayOrigin[7], ArrayOrigin[6], ArrayOrigin[5]);
	triangleSoup.push_back({ ArrayOrigin[7],normal });//5
	triangleSoup.push_back({ ArrayOrigin[6],normal });
	triangleSoup.push_back({ ArrayOrigin[5],normal });


	normal = Normals(ArrayOrigin[5], ArrayOrigin[4], ArrayOrigin[7]);
	triangleSoup.push_back({ ArrayOrigin[5],normal });//6
	triangleSoup.push_back({ ArrayOrigin[4],normal });
	triangleSoup.push_back({ ArrayOrigin[7],normal });


	normal = Normals(ArrayOrigin[4], ArrayOrigin[0], ArrayOrigin[3]);
	triangleSoup.push_back({ ArrayOrigin[4],normal });//7
	triangleSoup.push_back({ ArrayOrigin[0],normal });
	triangleSoup.push_back({ ArrayOrigin[3],normal });


	normal = Normals(ArrayOrigin[3], ArrayOrigin[7], ArrayOrigin[4]);
	triangleSoup.push_back({ ArrayOrigin[3],normal });//8
	triangleSoup.push_back({ ArrayOrigin[7],normal });
	triangleSoup.push_back({ ArrayOrigin[4],normal });


	normal = Normals(ArrayOrigin[3], ArrayOrigin[2], ArrayOrigin[6]);
	triangleSoup.push_back({ ArrayOrigin[3],normal });//9
	triangleSoup.push_back({ ArrayOrigin[2],normal });
	triangleSoup.push_back({ ArrayOrigin[6],normal });


	normal = Normals(ArrayOrigin[6], ArrayOrigin[7], ArrayOrigin[3]);
	triangleSoup.push_back({ ArrayOrigin[6],normal });//10
	triangleSoup.push_back({ ArrayOrigin[7],normal });
	triangleSoup.push_back({ ArrayOrigin[3],normal });


	normal = Normals(ArrayOrigin[0], ArrayOrigin[4], ArrayOrigin[1]);
	triangleSoup.push_back({ ArrayOrigin[0],normal });//11
	triangleSoup.push_back({ ArrayOrigin[4],normal });
	triangleSoup.push_back({ ArrayOrigin[1],normal });


	normal = Normals(ArrayOrigin[1], ArrayOrigin[4], ArrayOrigin[5]);
	triangleSoup.push_back({ ArrayOrigin[1],normal });//12
	triangleSoup.push_back({ ArrayOrigin[4],normal });
	triangleSoup.push_back({ ArrayOrigin[5],normal });

	

	WriteCube.write(triangleSoup,params["filepath"]);
	return 0;
}



const std::string& Cube::getName() const
{
	return Name;
}

