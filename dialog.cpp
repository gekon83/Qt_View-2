#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    square = new MySquare();
    scene->addItem(square);

    item = new MyItem();
    scene->addItem(item);
}

Dialog::~Dialog()
{
    delete ui;
}

