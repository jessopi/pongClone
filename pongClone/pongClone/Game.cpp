#include "Game.h"

/*
	Initializing objects with initial position,sound and images.
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

	p1_Score = new Text(sf::Vector2f(162.5f, 0.0f), 16, "./Font/arial.ttf", "0");
	p2_Score = new  Text(sf::Vector2f(487.5f, 0.0f), 16, "./Font/arial.ttf", "0");

	window = new sf::RenderWindow (sf::VideoMode(650, 500), "pongClone!", sf::Style::Close | sf::Style::Titlebar);

	window->setVerticalSyncEnabled(true); 
}

/*
	Main game loop, continues till window closes.
	Handles calling functions for moving paddles and ball.
	Polls for accepted keys such as spacebar, Esc, W and S.
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
		
		/*
			While game is not paused.
		*/

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

			/*
				Call to track the pongballs movement with the paddle.
			*/

			p2->paddleFollow(ball->spriteLocation().y, deltaTime);

			ball->move();

			/*
				Checks if any collision occured with the pongball for p1,p2 paddles.
			*/

			ball->collision(*p1, *p2);
			render();
			checkScore();
		}
		else 
		{	
			/*
				First time program is run the start screen is displayed and prompts
				user to press spacebar to begin.
			*/

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
	Checks if the the computer/player scores and increments the score.
	If score == 5 then call to end game image and the game is paused.
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

		if (p1_Score->getScore() == 5)
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
	Resets the paddles, ball and scores back to the initial values.
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
	clears window and renders the needed objects to the screen.
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