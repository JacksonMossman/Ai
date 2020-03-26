#include "SeekBehavior.h"

SeekBehavior::SeekBehavior()
{
}

SeekBehavior::~SeekBehavior()
{
}

Vector2 SeekBehavior::update(Agent* agent, float deltaTime)
{
	//If the target is null
	if (agent == nullptr) {
		return Vector2{ 0,0 };
	}
	//Return a zero vector

//Get this agent's position
	Vector2 pos = agent->getPosition();
//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();
//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();

//Multiply the direction by the speed we want the agent to move
	direction = direction * 250;
//Subtract the agent's current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->GetVelocity();
//Return the force
	return force;
}
