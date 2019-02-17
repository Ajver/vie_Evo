#pragma once

#include <vector>
#include <vie/Graphics.h>

class Organism;
class Plant;

class Map
{
public:
	Map();
	~Map();

	void update(float et);
	void render(vie::Graphics* g);

	std::vector<Organism*> orgs;
	std::vector<Plant*> plants;
};

