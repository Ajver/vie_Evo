#pragma once

#define MAX_VAL 50

class Attributes
{
public:
	Attributes();
	Attributes(float nstr, float nspd, float nstm);

	void init(float nstr, float nspd, float nstm);

	float strange;
	float speed;
	float stamina;
	float life;

};

