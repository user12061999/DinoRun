#pragma once
#include "Sprite2D.h"

class SpriteAnimation2D : public Sprite2D
{
private:
	//std::string		m_Text;
	//void			CaculateWorldMatrix();
protected:
	//Vector2			m_Vec2DPos;
	//GLint			m_iHeight;
	//GLint			m_iWidth;
	int m_currentFrame;
	int m_numFrames;
	float m_currentTime;
	float m_frameTime;
public:
	SpriteAnimation2D(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, int, float);
	//void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
};

