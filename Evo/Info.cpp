#include "Info.h"

#include "World.h"
#include "Organism.h"


Info::Info(World* map) :
	m_world(map),
	averagePosition(0, 0),
	averageVelocity(0, 0),
	averageAttributes(0, 0, 0),
	aliveCount(0),
	deadCount(0),
	secTimer(1000)
{
}

Info::~Info()
{
}

void Info::update(float et)
{
	aliveCount = 0;
	deadCount = 0;
	total = m_world->orgs.size();

	averagePosition = { 0, 0 };
	averageVelocity = { 0, 0 };

	averageAttributes.strange = 0;
	averageAttributes.speed = 0;
	averageAttributes.stamina = 0;
	averageAttributes.life = 0;

	for (auto& o : m_world->orgs)
	{
		if (o->isAlive)
		{
			aliveCount++;
			averagePosition += o->position;
			averageVelocity += o->velocity;
			averageAttributes.strange += o->attrib->strange;
			averageAttributes.speed += o->attrib->speed;
			averageAttributes.stamina += o->attrib->stamina;
			averageAttributes.life += o->attrib->life;
		}
		else 
		{
			deadCount++;
		}
	}

	averagePosition /= aliveCount;
	averageVelocity /= aliveCount;
	averageAttributes.strange /= aliveCount;
	averageAttributes.speed /= aliveCount;
	averageAttributes.stamina /= aliveCount;
	averageAttributes.life /= aliveCount;

	updateTime();
}

void Info::updateTime()
{
	if (secTimer.tick())
	{
		secTimer.start(1000 / m_world->timeSpeed);

		if (++sec >= 60)
		{
			sec = 0;

			if (++min >= 60)
			{
				min = 0;
				hou++;
			}
		}
	}
}

std::string Info::getTimeStr() const
{
	std::string houStr = (hou < 10 ? "0" : "") + std::to_string(hou);
	std::string minStr = (min < 10 ? "0" : "") + std::to_string(min);
	std::string secStr = (sec < 10 ? "0" : "") + std::to_string(sec);

	return houStr + ":" + minStr + ":" + secStr;
}