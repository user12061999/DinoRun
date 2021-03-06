#include "GSSetting.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSSetting::GSSetting()
{

}


GSSetting::~GSSetting()
{
}



void GSSetting::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_gameplay");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\quit");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);


	//sound button
	texture = ResourceManagers::GetInstance()->GetTexture("sound_off");
	std::shared_ptr<GameButton> buttonmusic_off = std::make_shared<GameButton>(model, shader, texture);
	buttonmusic_off->Set2DPosition(350, 190);
	buttonmusic_off->SetSize(100, 100);
	buttonmusic_off->SetOnClick([]() {
		
		});
	m_listButton.push_back(buttonmusic_off);


	//music button
	texture = ResourceManagers::GetInstance()->GetTexture("sound_on");
	std::shared_ptr<GameButton> buttonmusic_on = std::make_shared<GameButton>(model, shader, texture);
	buttonmusic_on = std::make_shared<GameButton>(model, shader, texture);
	buttonmusic_on->Set2DPosition(350, 370);
	buttonmusic_on->SetSize(100, 100);
	buttonmusic_on->SetOnClick([]() {
		
		});
	m_listButton.push_back(buttonmusic_on);

}

void GSSetting::Exit()
{
}


void GSSetting::Pause()
{

}

void GSSetting::Resume()
{

}


void GSSetting::HandleEvents()
{

}

void GSSetting::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSSetting::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSSetting::Update(float deltaTime)
{

	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSSetting::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	//m_Text_gameName->Draw();
}

