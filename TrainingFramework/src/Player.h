#pragma once 
#include "Sprite2D.h"
#include <SpriteAnimation2D.cpp>

class Player : public Sprite2D
{
public:
	Player(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~Player();
	void	HandleTouchEvents(GLint x, GLint y, bool bIsPressed);
	void	HandleKeyEvent(unsigned char key, bool bIsPresseded);
	void	Update(GLfloat deltaTime);
	int		GetLives();
	void	SetLives(int);
	void	Draw();

private:
	float speed = 100.0f;
	std::shared_ptr<SpriteAnimation2D> m_dino;
};
