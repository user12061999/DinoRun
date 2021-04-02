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
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 25);
	button->SetSize(100, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);


	//sound button
	texture = ResourceManagers::GetInstance()->GetTexture("sound_off");
	std::shared_ptr<GameButton> buttonPlay = std::make_shared<GameButton>(model, shader, texture);
	buttonPlay->Set2DPosition(350, 290);
	buttonPlay->SetSize(60, 60);
	m_listButton.push_back(buttonPlay);


	//music button
	texture = ResourceManagers::GetInstance()->GetTexture("sound_on");
	std::shared_ptr<GameButton> buttonmusic = std::make_shared<GameButton>(model, shader, texture);
	buttonmusic = std::make_shared<GameButton>(model, shader, texture);
	buttonmusic->Set2DPosition(350, 370);
	buttonmusic->SetSize(60, 60);
	m_listButton.push_back(buttonmusic);

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

