#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
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

    Q_INVOKABLE void moveLeft(){
        setX(m_x - xSpeed);
        if(m_x < minX){setX(minX);}
    }

    Q_INVOKABLE  void moveRight(){
        setX(m_x + xSpeed);
        if(m_x > maxX) { setX(maxX); }
    }

    Q_INVOKABLE void applyThrust(){
        ySpeed = maxThrust;
        if(m_y < bottomY/2.5){
            ySpeed = 0;
        }

    }


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
