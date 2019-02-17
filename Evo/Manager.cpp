#include "Manager.h"

#include <vie/Window.h>

#include <iostream>

#include "World.h"
#include "Info.h"

#define WIDTH 400

Manager::Manager(World* map) :
	m_size(WIDTH, vie::Window::getScreenHeight()),
	m_position(vie::Window::getScreenWidth() - WIDTH, 0),
	m_world(map),
	m_info(map)
{
}

Manager::~Manager()
{
}

void Manager::update(float et)
{
	m_info.update(et);
}

void Manager::render(vie::Graphics* g)
{
	g->switchLayer("manager");
	g->setColor(vie::COLOR::DARK_GRAY);
	g->fillRect(m_position, m_size);

	renderInfo(g);
}

void Manager::renderInfo(vie::Graphics* g)
{
	g->setColor(vie::COLOR::WHITE);

	static const float MARGIN = 20.0f;

	g->drawString("Total organisms: " + std::to_string(m_info.total), { m_position.x + MARGIN, MARGIN });
	g->drawString("Alive: " + std::to_string(m_info.aliveCount), { m_position.x + MARGIN, MARGIN * 2.0f });
	g->drawString("Dead: " + std::to_string(m_info.deadCount), { m_position.x + MARGIN, MARGIN * 3.0f });

	g->drawString("Average position:", { m_position.x + MARGIN, MARGIN * 4.0f });
	g->drawString(std::to_string(m_info.averagePosition.x), { m_position.x + MARGIN, MARGIN * 5.0f });
	g->drawString(std::to_string(m_info.averagePosition.y), { m_position.x + MARGIN + 150.0f, MARGIN * 5.0f });

	g->drawString("Average velociti: ", { m_position.x + MARGIN, MARGIN * 6.0f });
	g->drawString(std::to_string(m_info.averageVelocity.x), { m_position.x + MARGIN, MARGIN * 7.0f });
	g->drawString(std::to_string(m_info.averageVelocity.y), { m_position.x + MARGIN + 150.0f, MARGIN * 7.0f });

	g->drawString("Average strange: " + std::to_string(m_info.averageAttributes.strange), { m_position.x + MARGIN, MARGIN * 8.0f });
	g->drawString("Average speed: " + std::to_string(m_info.averageAttributes.speed), { m_position.x + MARGIN, MARGIN * 9.0f });
	g->drawString("Average stamina: " + std::to_string(m_info.averageAttributes.stamina), { m_position.x + MARGIN, MARGIN * 10.0f });
	g->drawString("Average life: " + std::to_string(m_info.averageAttributes.life), { m_position.x + MARGIN, MARGIN * 11.0f });

	g->drawString("World time speed: " + std::to_string(m_world->timeSpeed), { vie::Window::getScreenWidth() - MARGIN, m_size.y - MARGIN * 3.0f }, vie::TextJustification::RIGHT);
	g->drawString("Time from begin: " + m_info.getTimeStr(), { vie::Window::getScreenWidth() - MARGIN, m_size.y - MARGIN * 2.0f }, vie::TextJustification::RIGHT);
}

