#pragma once
#include "raylib.h"
#include <vector>
class Behavior;
class Agent
{
public:
	Agent() {};
	virtual ~Agent() {};
	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	void draw();

	// Draw the agent
	virtual void draw(RenderTexture2D renderer);

	// Add a behaviour to the agent
	void addBehaviour(Behavior* behaviour);

	//add a foce to objects velocity 
	void addForce(Vector2 force);

	// Movement functions
	void setPosition(Vector2 position) { m_Position = position; }
	Vector2 getPosition() { return m_Position; }

	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 GetVelocity() { return m_Velocity; }

protected:
	std::vector<Behavior*> m_BehaviourList;
	Vector2 m_Position = { 0,0 };
	Vector2 m_Velocity = { 0,0 };
};
