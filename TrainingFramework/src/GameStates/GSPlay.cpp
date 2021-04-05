#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"

using namespace std;
extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
	float test = 1;
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_gameplay");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);
	//BackGround1
	
	m_BackGround1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround1->Set2DPosition((float)screenWidth / 2 + (float)screenWidth, (float)screenHeight / 2);
	m_BackGround1->SetSize(screenWidth, screenHeight);

	texture = ResourceManagers::GetInstance()->GetTexture("Button\\Quit");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(25, 25);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);


	//text game title
	
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, std::to_string(score), TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2((float)screenWidth/2, 100));

	//din
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Trex\\Trex");
	m_anim = std::make_shared<SpriteAnimation2D>(model, shader, texture, 3, 0.2f);
	m_anim->Set2DPosition(80,500);
	m_anim->SetSize(70, 70);

	
	//m_dino = std::make_shared<Player>(model, shader, texture, 2, 0.5f);

	//ResourceManagers::GetInstance()->PlaySound("dino_sound.mp3");

}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (key = 'w' && inAir==false) {
		yVelo = -200;
		ResourceManagers::GetInstance()->PlaySound("jump.mp3");
		m_anim->SetTexture(ResourceManagers::GetInstance()->GetTexture("Trex\\Trex_jump"));
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}

}

void GSPlay::Update(float deltaTime)
{
	m_anim->Set2DPosition(m_anim->Get2DPosition().x, m_anim->Get2DPosition().y + yVelo * deltaTime);
	if (m_anim->Get2DPosition().y >= 500) {
		yVelo = 0;
	}
	if (m_anim->Get2DPosition().y <= 400) {
		yVelo = 200;
	}
	if (m_anim->Get2DPosition().y < 500) {
		inAir = true;
	}
	else if (m_anim->Get2DPosition().y >= 500) {
		inAir = false;
		m_anim->SetTexture(ResourceManagers::GetInstance()->GetTexture("Trex\\Trex"));
	}
	time -= deltaTime;
	test -= deltaTime;
	time_spawn_pte -= deltaTime;
	score =score+deltaTime;
	//loop background
	if (m_BackGround->Get2DPosition().x <= -screenWidth / 2) {
		m_BackGround->Set2DPosition((float)screenWidth / 2 + (float)screenWidth, (float)screenHeight / 2);
	}
	else
	{
		m_BackGround->Set2DPosition(m_BackGround->Get2DPosition().x - 100 * deltaTime, (float)screenHeight / 2);
	}
	if (m_BackGround1->Get2DPosition().x <= -screenWidth / 2) {
		m_BackGround1->Set2DPosition((float)screenWidth / 2 + (float)screenWidth, (float)screenHeight / 2);
	}
	else
	{
		m_BackGround1->Set2DPosition(m_BackGround1->Get2DPosition().x - 100 * deltaTime, (float)screenHeight / 2);
	}

	//spawn trike
	if (time <= 0) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
		auto texture = ResourceManagers::GetInstance()->GetTexture("Trex\\trike");

		//BackGround
		auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
		std::shared_ptr<SpriteAnimation2D> trike = std::make_shared<SpriteAnimation2D>(model, shader, texture, 3, 0.2f);
		trike->Set2DPosition((float)screenWidth, 500);
		trike->SetSize(70, 70);
		m_listrike.push_back(trike);
		time = (float)(rand() % (7 - 3 + 1) + 3);
	}

	//spawn pte
	float size_pte =(float) (rand() % (70 - 35 + 1) + 35);
	if (time_spawn_pte<=0) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
		auto texture = ResourceManagers::GetInstance()->GetTexture("Trex\\Pte");

		//BackGround
		auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
		std::shared_ptr<SpriteAnimation2D> pte = std::make_shared<SpriteAnimation2D>(model, shader, texture, 3, 0.2f);
		pte->Set2DPosition((float)screenWidth, (float)(rand() % (300 - 35 + 1) + 35));
		pte->SetSize((int)size_pte, (int)size_pte);
		m_listpte.push_back(pte);
		time_spawn_pte = (float)(rand() % (7 - 1 + 1) + 1);
		ResourceManagers::GetInstance()->PlaySound("pte_sound.mp3");
	}
	//di chuyen trike
	for (auto it : m_listrike)
	{
		it->Set2DPosition(it->Get2DPosition().x - 300 * deltaTime, 500);
		if (it->Get2DPosition().x < 0) {
			
		}
		it->Update(deltaTime);
	}
	//di chuyen pte
	for (auto it : m_listpte)
	{
		it->Set2DPosition(it->Get2DPosition().x - (rand() % (1000 + 200 + 1) + -200) * deltaTime, it->Get2DPosition().y);
		if (it->Get2DPosition().x < 0) {

		}
		it->Update(deltaTime);
	}
	for (auto it : m_listrike) {
		Vector2 a = Vector2(it->Get2DPosition().x - (float)it->Get2DSize().x / 2, it->Get2DPosition().y - (float)it->Get2DSize().y / 2);
		Vector2 b = Vector2(m_anim->Get2DPosition().x + (float)m_anim->Get2DSize().x / 2, m_anim->Get2DPosition().y + (float)m_anim->Get2DSize().y / 2);
		Vector2 c = Vector2(m_anim->Get2DPosition().x - (float)m_anim->Get2DSize().x / 2, m_anim->Get2DPosition().y - (float)m_anim->Get2DSize().y / 2);
		if (a.x < b.x&&a.x>c.x && a.y < b.y) {
			GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Over);
		}
		if (a.x < c.x) {

		}
	}
	m_score->Update(deltaTime);
	m_anim->Update(deltaTime);
	
	//pte_anim->Update(deltaTime);
}

void GSPlay::Draw()
{
	
	m_BackGround->Draw();
	m_BackGround1->Draw();
	m_score->Draw();
	
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listrike)
	{
		it->Draw();
	}
	for (auto it : m_listpte)
	{
		it->Draw();
	}
	m_anim->Draw();
	//pte_anim->Draw();
}
