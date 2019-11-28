// Ezequiel Arrieta 2019
#include "BlasterFactory.h"
#include "Blaster.h"


BlasterFactory* BlasterFactory::InstancePtr = nullptr;
Blaster* BlasterFactory::privateCreateBlaster()
{
	Blaster* BlasterPtr = myBlasterPool.getBlaster();


	BlasterPtr->SetExternalManagement(RecycleBlaster);



	BlasterPtr->Initialize();

	return BlasterPtr;
}
Blaster* BlasterFactory::privateCreateBlaster(InputController* input)
{
	Blaster* BlasterPtr = myBlasterPool.getBlaster();


	BlasterPtr->SetExternalManagement(RecycleBlaster);



	BlasterPtr->Initialize(input);

	return BlasterPtr;
}
void BlasterFactory::privateRecycleBlaster(GameObject* f)
{
	myBlasterPool.ReturnBlaster(static_cast<Blaster*>(f));
}
void BlasterFactory::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}
