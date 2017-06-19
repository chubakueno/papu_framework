#include "Bullet.h"
#include "ResourceManager.h"
#include "GLTexture.h"


void Bullet::draw(SpriteBacth& spriteBatch) const {
	static GLTexture textures[] =
	{
		ResourceManager::getTexture("Textures/Bullet1.png"),
		ResourceManager::getTexture("Textures/Bullet2.png"),
		ResourceManager::getTexture("Textures/Bullet3.png"),
		ResourceManager::getTexture("Textures/Bullet4.png"),
	};
	Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 posAnSize = glm::vec4(_position.x, _position.y, 30, 30);
	spriteBatch.draw(posAnSize, uv, textures[_bulletType].id, 0.0f, color);
}

bool Bullet::update() {
	_position += _direction * _speed;
	_lifeTime--;
	return _lifeTime > 0;
}

Bullet::Bullet(glm::vec2 po, glm::vec2 dir, float speed, int lifeTime, int bulletType)
{
	_lifeTime = lifeTime;
	_position = po;
	_direction = dir;
	_speed = speed;
	_bulletType = bulletType;
}

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}
