/*
*	Ian Jessop
*	Fall 2017
*	Game.cpp
*	
*/



#include "Game.h"
/*
	Declaring needed objects
*/
Game::Game()
{
	sound = new Audio("./Sound/Ping.wav");
	ball = new PongBall(PongBall(sf::Vector2f(325.0f, 238.5f), "./Images/ball.png", "./Sound/paddle.wav", "./Sound/wall.wav"));	
	
	background = new Sprite(Sprite(sf::Vector2f(0.0, 0.0), "./Images/Background.png"));				
	startScreen = new Sprite(Sprite(sf::Vector2f(0.0, 0.0), "./Images/startScreen.png"));
	gameOver = new Sprite(Sprite(sf::Vector2f(0.0, 0.0), "./Images/gameOver.png"));
	youWin = new Sprite(Sprite(sf::Vector2f(0.0, 0.0), "./Images/youWin.png"));
	
	p1 = new Player(Player(sf::Vector2f(20.0, 188.5), "./Images/Paddle.png"));	
	p2 = new Computer(Computer(sf::Vector2f(610.0, 188.5), "./Images/Paddle.png"));						

	p1_Score = new Text(sf::Vector2f(162.5f, 0.0f), 16, "./arial.tff", "0");
	p2_Score = new  Text(sf::Vector2f(487.5f, 0.0f), 16, "./arial.tff", "0");

	window = new sf::RenderWindow (sf::VideoMode(650, 500), "pongClone!", sf::Style::Close | sf::Style::Titlebar);

	window->setVerticalSyncEnabled(true); 
}

/*
	Game Loop, continues till window closes
	Accepts keys W,S,Space and ESC
	Moves p1 paddle up or down if W or S is pressed
	First run through brings up Start Screen
	and then only pauses if asked to play again.
	Makes calls to p2 paddle, ball move and collision


*/
void Game::start()
{
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();
		}
		
		if (isPaused == 0)
		{
				deltaTime = clock.restart().asSeconds();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			p1->move(-paddleSpeed*deltaTime);
		}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			p1->move(paddleSpeed*deltaTime);
		}

			p2->paddleFollow(ball->spriteLocation().y, deltaTime);

			ball->move();
			ball->collision(*p1, *p2);
			render();
			checkScore();
		}
		else 
		{	
			if (firstRun && isPaused)
			{
				startScreen->Render(*window);
				window->display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
				{
					firstRun = 0;
					isPaused = 0;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				isPaused = 0;
				newGame();
			}
		}
	}	
}

/*
	Checks if the the computer/player scores and calculates the score.
	if score for either reaches 5 win/loss screen appears and game ends.
	call to sound for scoring audio.

*/
void Game::checkScore()
{
	if (ball->spriteLocation().x + ball_Radius < 0)
	{
		sound->play();
		if (p2_Score->getScore() == 5)
		{
			p2_Score->update();
			gameOver->Render(*window);
			window->display();
			isPaused = 1;
		}
		else
		{
			p2_Score->update();
			ball->reset(1.0f);
		}
	}
	else if (ball->spriteLocation().x - ball_Radius > 650)
	{
		sound->play();

		if (p1_Score->getScore() == 1)
		{
			p1_Score->update();
			youWin->Render(*window);
			window->display();
			isPaused = 1;
		}
		else
		{
			p1_Score->update();
			ball->reset(-1.0f);
		}
	}
}
/*
	Resets paddles,ball and scores back to original
*/
void Game::newGame()
{
	ball->reset(-1.0f);
	p1->reset();
	p2->reset();
	p1_Score->reset();
	p2_Score->reset();
}

/*
Calls render for all needed classes and then displays them
*/
void Game::render()
{
	window->clear();
	background->Render(*window);
	p1->Render(*window);
	p2->Render(*window);
	p1_Score->Render(*window);
	p2_Score->Render(*window);
	ball->Render(*window);
	window->display();
}
Game::~Game()
{}