#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Bullet
{
private:
	Sprite shape;
public:

	Bullet(Texture* texture, Vector2f pos);
	~Bullet();
	Sprite GetShape();
	void Move();
};