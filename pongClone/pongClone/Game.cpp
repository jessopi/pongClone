#include "Game.h"
Game::Game()
{
	sound = new Audio("./Ping.wav");
	ball = new PongBall(PongBall(sf::Vector2f(325.0f, 238.5f), "./ball.png", "./paddle.wav", "./wall.wav"));	
	background = new Sprite(Sprite(sf::Vector2f(0.0, 0.0), "./Background.png"));				

	p1 = new Sprite(Sprite(sf::Vector2f(20.0, 188.5), "./Paddle.png"));	
	p2 = new Computer(Computer(sf::Vector2f(610.0, 188.5), "./Paddle.png"));						

	p1_Score = new Text(sf::Vector2f(162.5f, 0.0f), 16, "./arial.tff", "0");
	p2_Score = new  Text(sf::Vector2f(487.5f, 0.0f), 16, "./arial.tff", "0");

	winnerText = new Text(sf::Vector2f(330.0f, 240.0f), 20, "./arial.tff", "");
	window = new sf::RenderWindow (sf::VideoMode(650, 500), "Pong Game!", sf::Style::Close | sf::Style::Titlebar);

	window->setVerticalSyncEnabled(true); 
}

void Game::start()
{
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();
		}
		
		if (PAUSE == 1)
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				PAUSE = 1;
				newGame();
			}
		}
	}	
}
void Game::checkScore()
{
	if (ball->spriteLocation().x + ball_Radius < 0)
	{
		sound->play();
		if (p2_Score->getScore() == 10)
		{
			winnerText->setText("				You Lose! \n Press spacebar to play again!");
			p2_Score->update();
			render();
			PAUSE = 0;
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

		if (p1_Score->getScore() == 10)
		{
			winnerText->setText("				 You Win! \n Press spacebar to play again!");
			p1_Score->update();
			render();
			PAUSE = 0;
		}
		else
		{
			p1_Score->update();
			ball->reset(-1.0f);
		}
	}
}
void Game::newGame()
{
	winnerText->setText("");
	ball->reset(-1.0f);
	p1->reset();
	p1_Score->reset();
	p2_Score->reset();
}
void Game::render()
{
	window->clear();
	background->Render(*window);
	p1->Render(*window);
	p2->Render(*window);
	p1_Score->Render(*window);
	p2_Score->Render(*window);
	winnerText->Render(*window);
	ball->Render(*window);
	window->display();
}