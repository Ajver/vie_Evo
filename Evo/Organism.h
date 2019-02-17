#pragma once

#include <glm/glm.hpp>
#include <vie/Graphics.h>

class Organism
{
public:
	Organism();
	Organism(const glm::vec2& npos);
	~Organism();

	void init(const glm::vec2& npos);
	void update(float et);
	void render(vie::Graphics* g);

private: 
	glm::vec2 position;
	glm::vec2 size;
};

