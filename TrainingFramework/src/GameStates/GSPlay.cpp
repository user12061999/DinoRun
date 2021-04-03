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
	txtscore = std::to_string(score);
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

	texture = ResourceManagers::GetInstance()->GetTexture("Menu\\back_play");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(20, 20);
	button->SetSize(40, 40);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);


	//text game title
	
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font,txtscore, TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2((float)screenWidth/2, 100));

	
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("dino_run");
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
	}
	time -= deltaTime;
	test -= deltaTime;
	m_anim->Update(deltaTime);

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
		auto texture = ResourceManagers::GetInstance()->GetTexture("trike");

		//BackGround
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		std::shared_ptr<Sprite2D> trike = std::make_shared<GameButton>(model, shader, texture);
		trike->Set2DPosition((float)screenWidth, 500);
		trike->SetSize(70, 70);
		m_listrike.push_back(trike);
		time = 3;
	}
	//di chuyen trike
	for (auto it : m_listrike)
	{
		it->Set2DPosition(it->Get2DPosition().x - 300 * deltaTime, 500);
		if (it->Get2DPosition().x < 0) {
			
		}
		/*if (test <= 0) {
			cout << m_anim->Get2DPosition().x - it->Get2DPosition().x << endl;
			test = 1;
		}*/
	}
	for (auto it : m_listrike) {
		Vector2 a = Vector2(it->Get2DPosition().x - (float)it->Get2DSize().x / 2, it->Get2DPosition().y - (float)it->Get2DSize().y / 2);
		Vector2 b = Vector2(m_anim->Get2DPosition().x + (float)m_anim->Get2DSize().x / 2, m_anim->Get2DPosition().y + (float)m_anim->Get2DSize().y / 2);
		Vector2 c = Vector2(m_anim->Get2DPosition().x - (float)m_anim->Get2DSize().x / 2, m_anim->Get2DPosition().y - (float)m_anim->Get2DSize().y / 2);
		if (a.x < b.x&&a.x>c.x && a.y < b.y) {
			cout << "va cham";
		}
		if (a.x < c.x) {
			score++;
			txtscore = std::to_string(score);
			cout << score;
		}
	}
	m_score->Update(deltaTime);
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
	m_anim->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}