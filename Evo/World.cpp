#include "World.h"
#include "Organism.h"

#include <vie/Input.h>


World::World() :
	timeSpeed(1.0f)
{
}

World::~World()
{
}

void World::update(float et)
{
	for (int i = orgs.size() - 1; i >= 0; i--)
	{
		Organism* o = *((&orgs[0]) + i);
 		o->update(et * timeSpeed);
	}

	const float TIME_SPEED_CHANGE = vie::Input::isKeyPressed(SDLK_LSHIFT) ? 1.001f : 1.005f;

	if (vie::Input::isKeyPressed(SDLK_z))
		timeSpeed /= TIME_SPEED_CHANGE;

	if (vie::Input::isKeyPressed(SDLK_x))
		timeSpeed *= TIME_SPEED_CHANGE;
}

void World::render(vie::Graphics* g)
{
	g->switchLayer("main");
	for (auto& o : orgs)
		o->render(g);
}
