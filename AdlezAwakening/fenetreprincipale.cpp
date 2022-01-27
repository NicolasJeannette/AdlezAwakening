#include "fenetreprincipale.h"
#include <QGraphicsView>
#include <QTimer>
#include <QLayout>
#include "ui_fenetreprincipale.h"
#include "GameManager.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::FenetrePrincipale)
    ,scene(new QGraphicsScene(this))
    ,view(new QGraphicsView(scene,this))
    , game(new GameManager(*scene,this))
{
    ui->setupUi(this);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

