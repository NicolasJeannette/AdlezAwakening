#ifndef GAMEMANAGER_H
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QList>
#include <iostream>

#include <QGraphicsPixmapItem>
class QGraphicsScene;
#define GAMEMANAGER_H

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager(QGraphicsScene &scene, QObject *parent = 0);
    ~GameManager();

private:
    QGraphicsScene &scene;

};
#endif // GAMEMANAGER_H
