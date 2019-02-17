#include "Organism.h"
#include <vie/Random.h>

Organism::Organism() : position(0, 0) {}

Organism::Organism(const glm::vec2& npos) :
	position(npos)
{
	size.x = 1;
	size.y = 1;
}

Organism::~Organism()
{
}

void Organism::init(const glm::vec2& npos)
{
	position = npos;
}

void Organism::update(float et)
{
	position.x += vie::Random::nextInt(-1, 1);
	position.y += vie::Random::nextInt(-1, 1);
}

void Organism::render(vie::Graphics* g)
{
	g->setColor(vie::COLOR::PINK);
	g->fillRect(position, size);
}
