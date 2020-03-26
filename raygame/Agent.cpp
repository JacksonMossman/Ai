#include "Agent.h"
#include "Behavior.h"
void Agent::update(float deltaTime)
{
	//set force to zero
	Vector2 totalforce = { 0,0 };
	//for each behavior on behavior list 
	for (auto i = m_BehaviourList.begin(); i != m_BehaviourList.end(); i++)
	{
		//call the behaviors update
		Vector2 force = (*i)->update(this, deltaTime);
		totalforce += force;
		
	}
	addForce(totalforce * deltaTime);
	m_Position += m_Velocity * deltaTime;

}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, YELLOW);
}

void Agent::draw(RenderTexture2D renderer)
{
}

void Agent::addBehaviour(Behavior* behavior)
{
	m_BehaviourList.insert(m_BehaviourList.end(), behavior);
}

void Agent::addForce(Vector2 force)
{
	m_Velocity += force;
}
