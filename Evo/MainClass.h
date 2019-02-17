#include <vie/Engine.h>
#include <vie/Timer.h>

class World;
class Manager;

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void onCreate();
	void update(float et);
	void render(vie::Graphics* g);

private:
	vie::Timer m_fpsTimer;
	World* m_world;
	Manager* m_manager;

	void processUpdates(float et);
	void processTimers();
	void processInput(float et);
	void scaleCamera(float et);
	void moveCamera(float et);
};