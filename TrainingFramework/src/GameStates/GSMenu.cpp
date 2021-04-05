#include "GSMenu.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_menu");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);
	//logo
	/*texture = ResourceManagers::GetInstance()->GetTexture("Button\\play");
	m_Logo = std::make_shared<Sprite2D>(model, shader, texture);
	m_Logo->Set2DPosition(100, 100);
	m_Logo->SetSize(300, 150);*/


	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\play");
	std::shared_ptr<GameButton> buttonPlay = std::make_shared<GameButton>(model, shader, texture);
	buttonPlay->Set2DPosition((float)screenWidth / 2, 400);
	buttonPlay->SetSize(50, 50);
	buttonPlay->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(buttonPlay);



	//credit button

	texture = ResourceManagers::GetInstance()->GetTexture("Button\\credit");
	std::shared_ptr<GameButton> buttonCredit = std::make_shared<GameButton>(model, shader, texture);
	buttonCredit->Set2DPosition((float)screenWidth / 2, 460);
	buttonCredit->SetSize(50, 50);
	buttonCredit->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Credit);
		});
	m_listButton.push_back(buttonCredit);
	

	//setting button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\setting");
	std::shared_ptr<GameButton> buttonsetting = std::make_shared<GameButton>(model, shader, texture);
	buttonsetting = std::make_shared<GameButton>(model, shader, texture);
	buttonsetting->Set2DPosition((float)screenWidth / 2, 520);
	buttonsetting->SetSize(50, 50);
	buttonsetting->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Setting);
		});
	m_listButton.push_back(buttonsetting);

	//quit button
	texture = ResourceManagers::GetInstance()->GetTexture("Button\\quit");
	std::shared_ptr<GameButton> buttonquit = std::make_shared<GameButton>(model, shader, texture);
	buttonquit->Set2DPosition((float)screenWidth / 2, 580);
	buttonquit->SetSize(50, 50);
	buttonquit->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(buttonquit);


	//text game title
	
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	//m_Text_gameName = std::make_shared< Text>(shader, font, "SAMPLE NAME", TEXT_COLOR::GREEN, 1.0);
	//m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 80, 120));
	
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMenu::Update(float deltaTime)
{

	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	//m_Logo->Update(deltaTime);
}

void GSMenu::Draw()
{
	m_BackGround->Draw();
	//m_Logo->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
	//m_Text_gameName->Draw();
}

