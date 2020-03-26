#include "WanderBehavior.h"
#include <cstdlib>
WanderBehavior::WanderBehavior()
{
}
WanderBehavior::~WanderBehavior()
{
}
Vector2 WanderBehavior::update(Agent* agent, float deltaTime)
{
	float randMaxHalf = ((float)RAND_MAX) / 2;

	Vector2 targetPos = Vector2{rand() - randMaxHalf,rand() - randMaxHalf }.normalize() * m_radius ;

	targetPos += Vector2{ (float)rand() - randMaxHalf ,(float)rand() - randMaxHalf }.normalize() * m_jitter;

	targetPos = targetPos.normalize() * m_radius;

	Vector2 heading = agent->GetVelocity().normalize();

	
	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	
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

