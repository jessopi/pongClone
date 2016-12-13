#include "PongBall.h"

PongBall::PongBall(sf::Vector2f position, std::string texturePath)
	{
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
void PongBall::reset(float direction)
{
	spriteImage.setPosition(320.0f, 240.0f);
	ballX = 0;

	ballX = direction * MOVESPEED;

	ballY = 0.0f;
}
void PongBall::collision(Sprite &p1, Computer &p2)
{
	if (this->spriteLocation().x - 8.0f < p1.spriteLocation().x + 15.0 &&
		this->spriteLocation().x - 8.0f > p1.spriteLocation().x &&
		this->spriteLocation().y + 8.0f >= p1.spriteLocation().y &&
		this->spriteLocation().y - 8.0f <= p1.spriteLocation().y + 100.0)
	{
		findBounceAngle(p1.spriteLocation().y, this->spriteLocation().y);

		ballX = MOVESPEED*cos(bounceAngle);
		ballY = MOVESPEED*-sin(bounceAngle);
		move();
	}
	else if (this->spriteLocation().x - 8.0f < p2.spriteLocation().x  &&
		this->spriteLocation().x - 8.0f > p2.spriteLocation().x - 20.0f &&
		this->spriteLocation().y + 8.0f >= p2.spriteLocation().y &&
		this->spriteLocation().y - 8.0f <= p2.spriteLocation().y + 100.0f)
	{
		findBounceAngle(p2.spriteLocation().y, this->spriteLocation().y);

		ballX = -MOVESPEED*cos(bounceAngle);
		ballY = MOVESPEED*-sin(bounceAngle);
		move();
	}
	//move();
	wallCollision();
}
void PongBall::wallCollision()
{
	if (this->spriteLocation().y - 4.0f < 21.5f)
	{
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
		move();
	}
	else if (this->spriteLocation().y + 8.0f > 498.0f)
	{
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
void PongBall::findBounceAngle(float A, float B)
{
	float relativeIntersectY = (((PADDLEHEIGHT / 2) + A) - B); //middle Y of  paddle, minus the Y intersection of the ball

	float normalizedRelativeIntersectionY = (relativeIntersectY / (PADDLEHEIGHT / 2)); //divide again to get 1 to -1 range

	bounceAngle = normalizedRelativeIntersectionY * MAXBOUNCEANGLE;
}