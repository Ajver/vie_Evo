#pragma once

#include <vie/Graphics.h>

#include "Info.h"

class World;

class Manager
{
public:
	Manager(World* map);
	~Manager();

	void update(float et);
	void render(vie::Graphics* g);

private:
	World* m_world;
	Info m_info;
	glm::vec2 m_position;
	glm::vec2 m_size;

	void renderInfo(vie::Graphics* g);

};

