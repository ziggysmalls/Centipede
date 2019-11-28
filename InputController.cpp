#include "InputController.h"

InputController::InputController()
{
	player = nullptr;
}
void InputController::ControllerUpdate()
{

}
void InputController::Input(Blaster* blaster)
{
	player = blaster;
}
void InputController::Destroy()
{
	MarkForDestroy();
}
