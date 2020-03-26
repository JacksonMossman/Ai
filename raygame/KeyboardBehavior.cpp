#include "KeyboardBehavior.h"
KeyboardBehavior::KeyboardBehavior()
{
}
Vector2 KeyboardBehavior::update(Agent* agent, float deltaTime)
{
	Vector2 force = { 0,0 };

	if (IsKeyDown(KEY_UP))
		force.y = -500.0f;
	if (IsKeyDown(KEY_DOWN))
		force.y = 500.0f;
	if (IsKeyDown(KEY_LEFT))
		force.x = -500.0f;
	if (IsKeyDown(KEY_RIGHT))
		force.x = 500.0f;
	if(!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
	{
		if (agent->GetVelocity().x > 0)
		{
			force.x = -100;
		}
		 if (agent->GetVelocity().x < 0)
		{
			force.x = 100;
		}
		 if (agent->GetVelocity().y > 0)
		{
			force.y = -100;
		}
		if (agent->GetVelocity().y < 0)
		{
			force.y = 100;
		}
	}
	return force;
}