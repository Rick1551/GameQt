#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <vector>
#include "Bullet.h"
#include <qdebug.h>

class Controller : public QObject
{
    Q_OBJECT

    //Propiedades a guardar/actualizar para conexion entre front-end y back-end
    Q_PROPERTY(double x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(double y READ y WRITE setY NOTIFY yChanged)

public:
    Controller(QObject* parent = nullptr);

    //Getters
    double x(){ return m_x; }
    double y(){ return m_y; }

    //Setters
    void setX(double value) {
        if(m_x != value) {
            m_x = value;
            emit xChanged();
        }
    }

    void setY(double value) {
        if(m_y != value){
            m_y = value;
            emit yChanged();
        }
    }

    //Funciones que se invocan para controlar el objeto con entrada de teclado en qml
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE  void moveRight();
    Q_INVOKABLE void applyThrust();
    Q_INVOKABLE void fireBullet();

public slots:
    //Actualiza el estado de movimiento vertical simula la gravedad
    void updateState();

signals:
    void xChanged();
    void yChanged();

private:
    double m_x; //Current position of our rect on x dimension
    double m_y; //y position
    double xSpeed;
    double minX;
    double maxX;
    double bottomY;
    double ySpeed;
    double maxThrust = -10;
    double gravity = 0.5;
    QTimer time;

};

#endif // CONTROLLER_H
