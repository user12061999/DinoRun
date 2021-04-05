#include "GSIntro.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSIntro::GSIntro()
{
	m_time = 0;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


GSIntro::~GSIntro()
{
}


void GSIntro::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo");

	m_logo = std::make_shared<Sprite2D>(model, shader, texture);
	m_logo->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_logo->SetSize(150, 160);
	ResourceManagers::GetInstance()->PlaySound("main_theme.mp3");

	//dino
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Trex\\Trex");
	m_anim = std::make_shared<SpriteAnimation2D>(model, shader, texture, 3, 0.2f);
	m_anim->Set2DPosition(80, 500);
	m_anim->SetSize(70, 70);
}

void GSIntro::Exit()
{
	
}


void GSIntro::Pause()
{
	
}

void GSIntro::Resume()
{
	
}


void GSIntro::HandleEvents()
{
	
}

void GSIntro::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSIntro::HandleTouchEvents(int x, int y, bool bIsPressed)
{

}

void GSIntro::Update(float deltaTime)
{
	m_logo->Update(deltaTime);
	m_anim->Set2DPosition(m_anim->Get2DPosition().x - 400 * deltaTime, 500);
	m_anim->Update(deltaTime);
	m_time += deltaTime;
	if (m_time > 5)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		m_time = 0;
	}
	
}

void GSIntro::Draw()
{
	m_logo->Draw();
	m_anim->Draw();
}
