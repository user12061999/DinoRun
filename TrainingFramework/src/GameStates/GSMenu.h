#pragma once
#include "gamestatebase.h"
#include "GameButton.h"

class GSMenu :
	public GameStateBase
{
public:
	GSMenu();
	~GSMenu();
	
	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	float maxMove = 30.0f;
	float speed = 50.0f;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Sprite2D> m_Logo;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	//std::shared_ptr<Text>  m_Text_gameName;

};

