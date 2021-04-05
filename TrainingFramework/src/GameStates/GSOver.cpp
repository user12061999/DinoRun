#include "GSOver.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSOver::GSOver()
{

}


GSOver::~GSOver()
{
}



void GSOver::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_gameplay");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\play");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition((float)screenWidth/2, 500);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\quit");
	std::shared_ptr<GameButton> buttonquit = std::make_shared<GameButton>(model, shader, texture);
	buttonquit->Set2DPosition((float)screenWidth / 2, 650);
	buttonquit->SetSize(100, 100);
	buttonquit->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});
	m_listButton.push_back(buttonquit);

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_text = std::make_shared< Text>(shader, font, "Game Over", TEXT_COLOR::RED, 3.0);
	m_text->Set2DPosition(Vector2((float)screenWidth / 2, 100));

}

void GSOver::Exit()
{
}


void GSOver::Pause()
{

}

void GSOver::Resume()
{

}


void GSOver::HandleEvents()
{

}

void GSOver::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSOver::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSOver::Update(float deltaTime)
{

	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSOver::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_text->Draw();
	//m_Text_gameName->Draw();
}

