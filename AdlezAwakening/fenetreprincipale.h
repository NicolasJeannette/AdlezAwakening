#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
class QGraphicsScene;
class QGraphicsView;
class GameManager;

QT_BEGIN_NAMESPACE
namespace Ui { class FenetrePrincipale; }
QT_END_NAMESPACE

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    Ui::FenetrePrincipale *ui;
    FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();

private:
    QGraphicsScene *scene;
        QGraphicsView *view;

        GameManager *game;
};
#endif // FENETREPRINCIPALE_H
