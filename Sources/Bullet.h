#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Bullet
{
private:
	Sprite shape;
public:

	inline Bullet(Texture* texture, Vector2f pos);
	inline Sprite GetShape();
	inline void Move();
	inline ~Bullet();
};