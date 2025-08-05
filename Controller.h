#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

    //Propiedades a guardar/actualizar para conexion entre front-end y back-end
    Q_PROPERTY(double x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(double y READ y WRITE setY NOTIFY yChanged)

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

signals:
    void xChanged();
    void yChanged();

private:
    double m_x; //Current position of our rect on x dimension
    double m_y; //y position
    double xSpeed;

public:
    Controller();
};

#endif // CONTROLLER_H
