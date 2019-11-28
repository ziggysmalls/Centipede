#ifndef _InputController
#define _InputController
#include "Game Components/TEAL/CommonElements.h"
class Blaster;
class InputController : GameObject
{
public:
	InputController();
	virtual void Input(Blaster* player);
	virtual void ControllerUpdate();
	void Destroy();

protected:
	Blaster* player;

};
#endif

