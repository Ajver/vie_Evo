#include <vie/Engine.h>
#include <vie/Timer.h>

class Map;

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void onCreate();
	void update(float et);
	void render(vie::Graphics* g);

private:
	vie::Timer fpsTimer;
	Map* map;
};