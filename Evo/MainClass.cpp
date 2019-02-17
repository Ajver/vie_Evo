#include "MainClass.h"

#include <iostream>
#include <vie/Random.h>
#include <vie/ObjectsManager.h>
#include <vie/Input.h>
#include <vie/Window.h>
#include <vie/SpriteFont.h>

#include "Organism.h"
#include "World.h"
#include "Manager.h"

MainClass::MainClass() :
	m_fpsTimer(1000),
	m_world(nullptr)
{
	runEngine("Evo", 1280, 728);
}

MainClass::~MainClass() 
{
	delete m_world;
	delete m_manager;
}

void MainClass::onCreate() 
{
	setFPSLimit(-1);
	mainCamera->setScale(4.0f);
	m_world = new World();

	const int SIZE = 300;
	m_world->orgs.resize(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		int x = vie::Random::nextInt(-70, 70);
		int y = vie::Random::nextInt(-50, 50);
		m_world->orgs[i] = new Organism({ x, y }, m_world);
	}

	vie::Camera2D* managerCamera = new vie::Camera2D();
	managerCamera->setPosition(vie::Window::getScreenSize() * 0.5f);
	graphics->createLayer("manager", managerCamera);

	m_manager = new Manager(m_world);

	graphics->setFont(new vie::SpriteFont("Fonts/calibri.ttf", 20));
}

void MainClass::update(float et) 
{
	processUpdates(et);
	processTimers();
	processInput(et);
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(0, 0, 64));
	m_world->render(g);
	m_manager->render(g);
}

void MainClass::processUpdates(float et)
{
	m_world->update(et);
	m_manager->update(et);
}

void MainClass::processTimers()
{
	if (m_fpsTimer.tick())
	{
		m_fpsTimer.restart();
		std::cout << "FPS: " << getFpsCount() << std::endl;
	}
}

void MainClass::processInput(float et)
{
	scaleCamera(et);
	moveCamera(et);

	if (vie::Input::isKeyPressed(SDLK_ESCAPE))
		destroyEngine();
}

void MainClass::scaleCamera(float et) 
{
	const float CAMERA_SPEED = (vie::Input::isKeyPressed(SDLK_LSHIFT) ? 1.001f : 1.005f);

	if (vie::Input::isKeyPressed(SDLK_q))
		mainCamera->scaleDown(CAMERA_SPEED);

	if (vie::Input::isKeyPressed(SDLK_e))
		mainCamera->scaleUp(CAMERA_SPEED);
}

void MainClass::moveCamera(float et) 
{
	const float CAMERA_SPEED = (vie::Input::isKeyPressed(SDLK_LSHIFT) ? 100.0f : 250.0f) * et / mainCamera->getScale();

	if (vie::Input::isKeyPressed(SDLK_LEFT))
		mainCamera->move({ -CAMERA_SPEED , 0 });

	if (vie::Input::isKeyPressed(SDLK_RIGHT))
		mainCamera->move({ CAMERA_SPEED , 0 });

	if (vie::Input::isKeyPressed(SDLK_UP))
		mainCamera->move({ 0, -CAMERA_SPEED });

	if (vie::Input::isKeyPressed(SDLK_DOWN))
		mainCamera->move({ 0, CAMERA_SPEED });
}