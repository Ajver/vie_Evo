#pragma once

#include <glm/glm.hpp>
#include <vie/Graphics.h>

#include "Attributes.h"

class World;
class Organism
{
public:
	Organism();
	Organism(const glm::vec2& pos, World* map);
	~Organism();

	void init(const glm::vec2& pos, World* map);
	void update(float et);
	void render(vie::Graphics* g);

	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 size;
	Attributes* attrib;
	bool isAlive;

private:
	float m_framesToMove;
	float m_ttl;
	World* m_world;
};

