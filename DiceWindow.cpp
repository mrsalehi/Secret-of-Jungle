#include "DiceWindow.h"
#include "ui_DiceWindow.h"

#include "DicePool.h"
#include <QMessageBox>

using namespace std;

DiceWindow::DiceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiceWindow)
{
    ui->setupUi(this);

    DicePool myDice;
    myDice.rollDice();

    this->first_die = myDice.getFirstDie();
    this->second_die = myDice.getSecondDie();

    QString s = QString::number(first_die);
    ui->lineEdit->setText(s);

    s = QString::number(second_die);
    ui->lineEdit_2->setText(s);
    ui->expshn->hide();
}

DiceWindow::~DiceWindow()
{
    delete ui;
}

int isvalid = 0;

void DiceWindow::on_pushButton_clicked()
{
    isvalid = 0;
    try
    {
        QString s1 = ui->lineEdit->text();
        QString s2 = ui->lineEdit_2->text();
        if ((s1!= "1" && s1!= "2" && s1!= "3" && s1!= "4" && s1!= "5" && s1!= "6") || (s2!= "1" && s2!= "2" && s2!= "3" && s2!= "4" && s2!= "5" && s2!= "6"))
        {
           throw string ("Dices are Invalid!");
        }
        else
        {
            if (s1 == "1")
            {
                first_die = 1;
            }
            if (s1 == "2")
            {
                first_die = 2;
            }
            if (s1 == "3")
            {
                first_die = 3;
            }
            if (s1 == "4")
            {
                first_die = 4;
            }
            if (s1 == "5")
            {
                first_die = 5;
            }
            if (s1 == "6")
            {
                first_die = 6;
            }
            if (s2 == "1")
            {
                second_die = 1;
            }
            if (s2 == "2")
            {
                second_die = 2;
            }
            if (s2 == "3")
            {
                second_die = 3;
            }
            if (s2 == "4")
            {
                second_die = 4;
            }
            if (s2 == "5")
            {
                second_die = 5;
            }
            if (s2 == "6")
            {
                second_die = 6;
            }
        }
    }
    catch (string &s)
    {
        QMessageBox::warning(this, "Warning", "Dices Are Invalid!");
        isvalid = 1;
    }


//    QStringList list1 = s1.split("");
//    QStringList list2 = s2.split("");

//    if (list1.size() == 1 && list2.size() == 1){

//        if (49 =< (int)list1[0] && (int)list1[0] <= 54 && 49 =< (int)list2[0] && (int)list2[0] <= 54){
//            first_die = (int)(list1[0] - 49);
//            second_die = (int)(list2[0] - 49);
//        }
//        else{
//            QMessageBox::warning(this, "Error", "Please enter valid numbers.");
//        }
//    }
//    else{
//        QMessageBox::warning(this, "Error", "Please enter valid numbers.");
//    }

    if (isvalid == 0)
    {
        hide();
    }
}

int DiceWindow::getSecond_die() const
{
    return second_die;
}

int DiceWindow::getFirst_die() const
{
    return first_die;
}
