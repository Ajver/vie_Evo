#pragma once

#include "Attributes.h"
#include <glm/glm.hpp>
#include <vie/Timer.h>
#include <string>

class World;

class Info
{
public:
	Info(World* map);
	~Info();

	void update(float et);

	glm::vec2 averagePosition;
	glm::vec2 averageVelocity;
	Attributes averageAttributes;
	int aliveCount;
	int deadCount;
	int total;

	std::string getTimeStr() const;

private: 
	World* m_world;
	vie::Timer secTimer;
	int hou, min, sec;

	void updateTime();
};

