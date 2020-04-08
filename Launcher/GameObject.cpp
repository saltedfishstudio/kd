#include "GameObject.h"

Vector3f GameObject::GetPosition()
{
	return *new Vector3f(1,1,1);
}

char* GameObject::GetName()
{
	return (char*)"Name";
}
