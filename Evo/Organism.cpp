#include "Organism.h"

#include <vie/Random.h>

#define FRAMES_TO_MOVE 2.0f
#define TIME_TO_LIFE 20.0f

Organism::Organism() : 
	position(0, 0),
	velocity(0, 0),
	isAlive(true),
	m_world(nullptr),
	m_framesToMove(0),
	attrib(new Attributes()),
	m_ttl(TIME_TO_LIFE)
{
}

Organism::Organism(const glm::vec2& pos, World* map) :
	position(pos),
	velocity(0, 0),
	isAlive(true),
	m_world(map),
	m_framesToMove(0),
	attrib(new Attributes()),
	m_ttl(TIME_TO_LIFE)
{
	size.x = 1;
	size.y = 1;
}

Organism::~Organism()
{
}

void Organism::init(const glm::vec2& pos, World* map)
{
	position = pos;
	m_world = map;
}

void Organism::update(float et)
{
	if (!isAlive) 
		return;

	if ((m_framesToMove -= et) < 0)
	{
		m_framesToMove = vie::Random::nextInt(FRAMES_TO_MOVE, FRAMES_TO_MOVE + 2);

		velocity.x = vie::Random::nextInt(-attrib->speed * attrib->life, attrib->speed * attrib->life);
		velocity.y = vie::Random::nextInt(-attrib->speed * attrib->life, attrib->speed * attrib->life);
	}

	if ((m_ttl -= et) < 0)
	{
		m_ttl = vie::Random::nextInt(TIME_TO_LIFE, TIME_TO_LIFE*1.5f);

		float lifeMod;
		if (attrib->stamina < MAX_VAL)
			lifeMod = 1.0f - (MAX_VAL - attrib->stamina) / 1000.0f;
		else
			lifeMod = 0.999f;

		attrib->life *= lifeMod;

		isAlive = attrib->life > 0.1f && attrib->stamina * attrib->life > 0.1f;
	}

	position += velocity * et;
}

void Organism::render(vie::Graphics* g)
{
	if(isAlive)
		g->setColor(vie::COLOR::PINK);
	else
		g->setColor(vie::COLOR::GRAY);

	g->fillRect(position, size);
}
