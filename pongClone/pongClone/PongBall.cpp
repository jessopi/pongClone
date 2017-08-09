#include "PongBall.h"

PongBall::PongBall(sf::Vector2f position, std::string texturePath,std::string p_Sound,std::string w_Sound)
	{
		paddleSound = new Audio(p_Sound);
		wallSound = new Audio(w_Sound);
		spriteTexture.loadFromFile(texturePath);
		spriteImage.setTexture(spriteTexture);
		spriteImage.setPosition(position);
		spriteImage.setOrigin(10.0f / 2, 10.0f / 2);
		ballX = -MOVESPEED;
		ballY = 0.0f;
	}
PongBall::PongBall()
{
}
void PongBall::move()
{
	spriteImage.move(ballX, ballY);
}

/*
	Places ball in sarting position and moves in last direction.
*/
void PongBall::reset(float direction)
{
	spriteImage.setPosition(325.0f, 238.5f);
	ballX = direction * MOVESPEED;
	ballY = 0.0f;
}

/*
	Function to check if the ball made contact with p1 or p2 paddle
	conditionals for dimensions of paddle
	calls sound if true
	sets ballX, ballY;
	calls wall collision

*/
void PongBall::collision(Sprite &p1, Computer &p2)
{
	if (this->spriteLocation().x - 8.0f < p1.spriteLocation().x + 15.0 &&
		this->spriteLocation().x - 8.0f > p1.spriteLocation().x &&
		this->spriteLocation().y + 8.0f >= p1.spriteLocation().y &&
		this->spriteLocation().y - 8.0f <= p1.spriteLocation().y + 100.0)
	{
		findBounceAngle(p1.spriteLocation().y, this->spriteLocation().y);
		paddleSound->play();
		ballX = MOVESPEED*cos(bounceAngle);
		ballY = MOVESPEED*-sin(bounceAngle);
	}
	else if (this->spriteLocation().x - 8.0f < p2.spriteLocation().x  &&
		this->spriteLocation().x - 8.0f > p2.spriteLocation().x - 20.0f &&
		this->spriteLocation().y + 8.0f >= p2.spriteLocation().y &&
		this->spriteLocation().y - 8.0f <= p2.spriteLocation().y + 100.0f)
	{
		findBounceAngle(p2.spriteLocation().y, this->spriteLocation().y);
		paddleSound->play();
		ballX = -MOVESPEED*cos(bounceAngle);
		ballY = MOVESPEED*-sin(bounceAngle);
	}
	wallCollision();
}

/*
	Check if pongball makes contact with the wall
	if true then a call to wallsound is made
	checks the X pos of ball to determine angle/direction which the ball should move
*/
void PongBall::wallCollision()
{
	if (this->spriteLocation().y - 4.0f < 21.5f)
	{
		wallSound->play();
		if (ballX > 0)
		{
			ballX = MOVESPEED*cos(bounceAngle);

			ballY = MOVESPEED*sin(abs(bounceAngle));
		}
		else if (ballX < 0)
		{
			ballX = -MOVESPEED*cos(-bounceAngle);
			ballY = MOVESPEED*sin(abs(bounceAngle));
		}
	}
	else if (this->spriteLocation().y + 8.0f > 498.0f)
	{
		wallSound->play();
		if (ballX > 0)
		{
			ballX = MOVESPEED*cos(bounceAngle);
			ballY = MOVESPEED*sin(-abs(bounceAngle));
		}
		else if (ballX < 0)
		{
			ballX = -MOVESPEED*cos(bounceAngle);
			ballY = MOVESPEED*sin(-abs(bounceAngle));
		}
	}
}

/*
	Calculates angle of the ball coming off of the paddle.
	
*/
void PongBall::findBounceAngle(float A, float B)
{
	float relativeIntersectY = (((PADDLEHEIGHT / 2) + A) - B); //middle Y of  paddle, minus the Y intersection of the ball

	float normalizedRelativeIntersectionY = (relativeIntersectY / (PADDLEHEIGHT / 2)); //divide again to get 1 to -1 range

	bounceAngle = normalizedRelativeIntersectionY * MAXBOUNCEANGLE;
}
PongBall::~PongBall()
{}