#include "MainClass.h"

#include <iostream>
#include <vie/Random.h>
#include <vie/ObjectsManager.h>

#include "Organism.h"
#include "Map.h"

MainClass::MainClass() :
	fpsTimer(1000),
	map(nullptr)
{
	runEngine("Evo", 1280, 728);
}

MainClass::~MainClass() 
{
	delete map;
}

void MainClass::onCreate() 
{
	setFPSLimit(-1);
	mainCamera->setScale(8.0f);
	map = new Map();

	const int size = 300;
	map->orgs.resize(size);
	for (int i = 0; i < size; i++)
	{
		int x = vie::Random::nextInt(-70, 70);
		int y = vie::Random::nextInt(-50, 50);
		map->orgs[i] = new Organism({ x, y });
	}
}

void MainClass::update(float et) 
{
	map->update(et);
	if (fpsTimer.tick())
	{
		fpsTimer.restart();
		std::cout << "FPS: " << getFpsCount() << std::endl;
	}
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(0, 0, 64));
	map->render(g);
}