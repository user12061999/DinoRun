#include "Player.h"
#include "ResourceManagers.h"


Player::Player(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
	/* model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	 shader = ResourceManagers::GetInstance()->GetShader("Animation");
	 texture = ResourceManagers::GetInstance()->GetTexture("dino_run");
	 m_dino = std::make_shared<SpriteAnimation2D>(model, shader, texture, 3, 0.1f);
	m_dino->SetSize(60, 46);
	m_dino->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);*/

}

Player::~Player()
{
}

void Player::HandleTouchEvents(GLint x, GLint y, bool bIsPressed)
{
	
}

void Player::HandleKeyEvent(unsigned char key, bool bIsPresseded)
{
	
}

void Player::Draw() {
	m_dino->Draw();
}

void Player::Update(GLfloat deltaTime)
{
	m_dino->Update(deltaTime);
}