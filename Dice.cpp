#include "Dice.h"
#include "ui_dice.h"

Dice::Dice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dice)
{
    ui->setupUi(this);
}

Dice::~Dice()
{
    delete ui;
}

