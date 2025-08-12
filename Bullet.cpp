#include "Bullet.h"

Bullet::Bullet() {}

void Bullet::updateBullet() {

    setY(m_y + ySpeed);

}
