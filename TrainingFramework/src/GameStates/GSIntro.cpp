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
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo_3");

	m_logo = std::make_shared<Sprite2D>(model, shader, texture);
	m_logo->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_logo->SetSize(150, 160);
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
	m_time += deltaTime;
	if (m_time > 1.3)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		m_time = 0;
	}
}

void GSIntro::Draw()
{
	m_logo->Draw();
}
