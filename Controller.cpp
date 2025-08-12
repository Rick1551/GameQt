#include "Controller.h"


Controller::Controller(QObject* parent) : m_x(1500/2 -50), m_y(800 - 50), xSpeed(10), minX(0),
    maxX(1485),bottomY(800),ySpeed(0){
    //&Controller
    connect(&time, &QTimer::timeout, this, &Controller::updateState);
    time.start(16); //60fps

}

void Controller::moveLeft(){
    setX(m_x - xSpeed);
    if(m_x < minX){setX(minX);}
}

void Controller::moveRight(){
    setX(m_x + xSpeed);
    if(m_x > maxX) { setX(maxX); }
}

void Controller::applyThrust(){
    ySpeed = maxThrust;
    if(m_y < bottomY/2.5){
        ySpeed = 0;
    }

}

void Controller::fireBullet() {
    QObject* newBullet = new Bullet();
    std::vector<Bullet*> bulletList;
    bulletList.push_back(newBullet);
}


void Controller::updateState() {
    double oldY = m_y;

    ySpeed += gravity;

    // Limitar velocidad
    //double maxFallSpeed = 50;
    double maxRiseSpeed = -50;
    //if (ySpeed > maxFallSpeed) ySpeed = maxFallSpeed;
    if (ySpeed < maxRiseSpeed) ySpeed = maxRiseSpeed;

    m_y += ySpeed;

    // Limitar posición
    //double topY = 0;
    if (m_y > bottomY - 50) {
        m_y = bottomY - 50;
        ySpeed = 0;
    } //else if (m_y < bottomY/2) {
        //m_y = topY;
        //ySpeed = 0;
    //}

    if (m_y != oldY) {
        emit yChanged();
    }
}

