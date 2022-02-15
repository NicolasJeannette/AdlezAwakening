#ifndef CUBE_H
#define CUBE_H
#include "QVector2D"

class Cube
{
public:
    Cube();
    ~Cube();
    QVector2D GetPosition(); // Récupération de la position de l'objet
    void DrawCube(); // Méthode Ecriture d'un cube
    QVector2D GetPositionHautDroite();
    QVector2D GetPositionBasGauche();
    QVector2D GetPositionBasDroite();
    QVector2D GetPositionHautGauche();
};

#endif // CUBE_H
