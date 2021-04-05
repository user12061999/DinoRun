#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "SpriteAnimation2D.h"

class Sprite2D;
class Sprite3D;
class Text;


class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

	
	void SetNewPostionForBullet();

private:
	bool inAir=false;
	int score=0;
	std::string txtscore;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Sprite2D> m_BackGround1;
	std::shared_ptr<Text>  m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<SpriteAnimation2D> m_anim;
	std::shared_ptr<SpriteAnimation2D> pte_anim;
	std::list<std::shared_ptr<SpriteAnimation2D>>	m_listpte;
	std::list<std::shared_ptr<SpriteAnimation2D>>	m_listrike;
	float time = 3;
	float time_spawn_pte = 1;
	float test = 1;
	float yVelo = 0;
	//khai bao Map
};

