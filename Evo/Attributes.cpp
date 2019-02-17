#include "Attributes.h"

#include <vie/Random.h>

Attributes::Attributes() :
	strange(vie::Random::nextInt(MAX_VAL)),
	speed(vie::Random::nextInt(MAX_VAL)),
	stamina(vie::Random::nextInt(MAX_VAL)),
	life(1.0f)
{
}

Attributes::Attributes(float nstr, float nspd, float nstm) :
	strange(nstr),
	speed(nspd),
	stamina(nstm),
	life(1.0f)
{
}

void Attributes::init(float nstr, float nspd, float nstm)
{
	strange = nstr;
	speed = nspd;
	stamina = nstm;
}