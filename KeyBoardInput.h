
#ifndef _KeyBoardInput
#define _KeyBoardInput
#include "Game Components/TEAL/CommonElements.h"

#include "InputController.h"
class KeyBoardInput : public InputController
{
public:
	KeyBoardInput();
	void Destroy();
	void Input(Blaster* blaster);
	 void ControllerUpdate();

	 
};
#endif // _KeyBoardInput

