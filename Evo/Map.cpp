#include "Map.h"
#include "Organism.h"


Map::Map()
{
}

Map::~Map()
{
}

void Map::update(float et)
{
	for (int i = orgs.size() - 1; i >= 0; i--)
	{
		Organism* o = *((&orgs[0]) + i);
 		o->update(et);
	}
}

void Map::render(vie::Graphics* g)
{
	for (auto& o : orgs)
		o->render(g);
}
