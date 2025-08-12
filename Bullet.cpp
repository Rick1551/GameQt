#include "Bullet.h"

Bullet::Bullet(QObject* parent) : m_x(1500/2), m_y(800 - 50), ySpeed(0) {
    connect(&bTime, &QTimer::timeout, this, &Bullet::updateBullet);
    bTime.start(16);
}

void Bullet::updateBullet() {

    setY(m_y + ySpeed);

}
