#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DiceWindow.h"
#include "askNumOfPlayers.h"
#include "instrhelp.h"

#include <QLCDNumber>
#include <ctime>
#include <QSignalMapper>
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/img/BackGround.jpg");

    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);

    QPalette pallete;

    pallete.setBrush(QPalette::Background,bkgnd);

    this->setPalette(pallete);

    ui->groupBox->hide();

    ui->roll_dice->setEnabled(false);


    ptrsToPositionLabel[0] = new QLabel(this);
    ptrsToPositionLabel[0] = ui->player1_position;

    ptrsToPositionLabel[1] = new QLabel(this);
    ptrsToPositionLabel[1] = ui->player2_position;

    ptrsToPositionLabel[2] = new QLabel(this);
    ptrsToPositionLabel[2] = ui->player3_position;

    ptrsToPositionLabel[3] = new QLabel(this);
    ptrsToPositionLabel[3] = ui->player4_position;

    ptrToCells = new QPushButton*[120];
    ptrToChoiceCells = new QPushButton*[120];

    for (int i = 1; i <= 116 ; i++)
    {
        ptrToChoiceCells[i] = new QPushButton(this);
        ptrToCells[i] = new QPushButton (this);
    }


    ptrToChoiceCells[1] = ui->choice_cell_1;ptrToChoiceCells[2] = ui->choice_cell_2;
    ptrToChoiceCells[3] = ui->choice_cell_3;ptrToChoiceCells[4] = ui->choice_cell_4;
    ptrToChoiceCells[5] = ui->choice_cell_5;ptrToChoiceCells[6] = ui->choice_cell_6;
    ptrToChoiceCells[7] = ui->choice_cell_7;ptrToChoiceCells[8] = ui->choice_cell_8;
    ptrToChoiceCells[9] = ui->choice_cell_9;ptrToChoiceCells[10] = ui->choice_cell_10;
    ptrToChoiceCells[11] = ui->choice_cell_11;ptrToChoiceCells[12] = ui->choice_cell_12;
    ptrToChoiceCells[13] = ui->choice_cell_13;ptrToChoiceCells[14] = ui->choice_cell_14;
    ptrToChoiceCells[15] = ui->choice_cell_15;ptrToChoiceCells[16] = ui->choice_cell_16;
    ptrToChoiceCells[17] = ui->choice_cell_17;ptrToChoiceCells[18] = ui->choice_cell_18;
    ptrToChoiceCells[19] = ui->choice_cell_19;ptrToChoiceCells[20] = ui->choice_cell_20;
    ptrToChoiceCells[21] = ui->choice_cell_21;ptrToChoiceCells[22] = ui->choice_cell_22;
    ptrToChoiceCells[23] = ui->choice_cell_23;ptrToChoiceCells[24] = ui->choice_cell_24;
    ptrToChoiceCells[25] = ui->choice_cell_25;ptrToChoiceCells[26] = ui->choice_cell_26;
    ptrToChoiceCells[27] = ui->choice_cell_27;ptrToChoiceCells[28] = ui->choice_cell_28;
    ptrToChoiceCells[29] = ui->choice_cell_29;ptrToChoiceCells[30] = ui->choice_cell_30;
    ptrToChoiceCells[31] = ui->choice_cell_31;ptrToChoiceCells[32] = ui->choice_cell_32;
    ptrToChoiceCells[33] = ui->choice_cell_33;ptrToChoiceCells[34] = ui->choice_cell_34;
    ptrToChoiceCells[35] = ui->choice_cell_35;ptrToChoiceCells[36] = ui->choice_cell_36;
    ptrToChoiceCells[37] = ui->choice_cell_37;ptrToChoiceCells[38] = ui->choice_cell_38;
    ptrToChoiceCells[39] = ui->choice_cell_39;ptrToChoiceCells[40] = ui->choice_cell_40;
    ptrToChoiceCells[41] = ui->choice_cell_41;ptrToChoiceCells[42] = ui->choice_cell_42;
    ptrToChoiceCells[43] = ui->choice_cell_43;ptrToChoiceCells[44] = ui->choice_cell_44;
    ptrToChoiceCells[45] = ui->choice_cell_45;ptrToChoiceCells[46] = ui->choice_cell_46;
    ptrToChoiceCells[47] = ui->choice_cell_47;ptrToChoiceCells[48] = ui->choice_cell_48;
    ptrToChoiceCells[49] = ui->choice_cell_49;ptrToChoiceCells[50] = ui->choice_cell_50;
    ptrToChoiceCells[51] = ui->choice_cell_51;ptrToChoiceCells[52] = ui->choice_cell_52;
    ptrToChoiceCells[53] = ui->choice_cell_53;ptrToChoiceCells[54] = ui->choice_cell_54;
    ptrToChoiceCells[55] = ui->choice_cell_55;ptrToChoiceCells[56] = ui->choice_cell_56;
    ptrToChoiceCells[57] = ui->choice_cell_57;ptrToChoiceCells[58] = ui->choice_cell_58;
    ptrToChoiceCells[59] = ui->choice_cell_59;ptrToChoiceCells[60] = ui->choice_cell_60;
    ptrToChoiceCells[61] = ui->choice_cell_61;ptrToChoiceCells[62] = ui->choice_cell_62;
    ptrToChoiceCells[63] = ui->choice_cell_63;ptrToChoiceCells[64] = ui->choice_cell_64;
    ptrToChoiceCells[65] = ui->choice_cell_65;ptrToChoiceCells[66] = ui->choice_cell_66;
    ptrToChoiceCells[67] = ui->choice_cell_67;ptrToChoiceCells[68] = ui->choice_cell_68;
    ptrToChoiceCells[69] = ui->choice_cell_69;ptrToChoiceCells[70] = ui->choice_cell_70;
    ptrToChoiceCells[71] = ui->choice_cell_71;ptrToChoiceCells[72] = ui->choice_cell_72;
    ptrToChoiceCells[73] = ui->choice_cell_73;ptrToChoiceCells[74] = ui->choice_cell_74;
    ptrToChoiceCells[75] = ui->choice_cell_75;ptrToChoiceCells[76] = ui->choice_cell_76;
    ptrToChoiceCells[77] = ui->choice_cell_77;ptrToChoiceCells[78] = ui->choice_cell_78;
    ptrToChoiceCells[79] = ui->choice_cell_79;ptrToChoiceCells[80] = ui->choice_cell_80;
    ptrToChoiceCells[81] = ui->choice_cell_81;ptrToChoiceCells[82] = ui->choice_cell_82;
    ptrToChoiceCells[83] = ui->choice_cell_83;ptrToChoiceCells[84] = ui->choice_cell_84;
    ptrToChoiceCells[85] = ui->choice_cell_85;ptrToChoiceCells[86] = ui->choice_cell_86;
    ptrToChoiceCells[87] = ui->choice_cell_87;ptrToChoiceCells[88] = ui->choice_cell_88;
    ptrToChoiceCells[89] = ui->choice_cell_89;ptrToChoiceCells[90] = ui->choice_cell_90;
    ptrToChoiceCells[91] = ui->choice_cell_91;ptrToChoiceCells[92] = ui->choice_cell_92;
    ptrToChoiceCells[93] = ui->choice_cell_93;ptrToChoiceCells[94] = ui->choice_cell_94;
    ptrToChoiceCells[95] = ui->choice_cell_95;ptrToChoiceCells[96] = ui->choice_cell_96;
    ptrToChoiceCells[97] = ui->choice_cell_97;ptrToChoiceCells[98] = ui->choice_cell_98;
    ptrToChoiceCells[99] = ui->choice_cell_99;ptrToChoiceCells[100] = ui->choice_cell_100;
    ptrToChoiceCells[101] = ui->choice_cell_101;ptrToChoiceCells[102] = ui->choice_cell_102;
    ptrToChoiceCells[103] = ui->choice_cell_103;ptrToChoiceCells[104] = ui->choice_cell_104;
    ptrToChoiceCells[105] = ui->choice_cell_105;ptrToChoiceCells[106] = ui->choice_cell_106;
    ptrToChoiceCells[107] = ui->choice_cell_107;ptrToChoiceCells[108] = ui->choice_cell_108;
    ptrToChoiceCells[109] = ui->choice_cell_109;ptrToChoiceCells[110] = ui->choice_cell_110;
    ptrToChoiceCells[111] = ui->choice_cell_111;ptrToChoiceCells[112] = ui->choice_cell_112;
    ptrToChoiceCells[113] = ui->choice_cell_113;ptrToChoiceCells[114] = ui->choice_cell_114;
    ptrToChoiceCells[115] = ui->choice_cell_115;ptrToChoiceCells[116] = ui->choice_cell_116;


    ptrToCells[1] = ui->cell_1;ptrToCells[2] = ui->cell_2;
    ptrToCells[3] = ui->cell_3;ptrToCells[4] = ui->cell_4;
    ptrToCells[5] = ui->cell_5;ptrToCells[6] = ui->cell_6;
    ptrToCells[7] = ui->cell_7;ptrToCells[8] = ui->cell_8;
    ptrToCells[9] = ui->cell_9;ptrToCells[10] = ui->cell_10;
    ptrToCells[11] = ui->cell_11;ptrToCells[12] = ui->cell_12;
    ptrToCells[13] = ui->cell_13;ptrToCells[14] = ui->cell_14;
    ptrToCells[15] = ui->cell_15;ptrToCells[16] = ui->cell_16;
    ptrToCells[17] = ui->cell_17;ptrToCells[18] = ui->cell_18;
    ptrToCells[19] = ui->cell_19;ptrToCells[20] = ui->cell_20;
    ptrToCells[21] = ui->cell_21;ptrToCells[22] = ui->cell_22;
    ptrToCells[23] = ui->cell_23;ptrToCells[24] = ui->cell_24;
    ptrToCells[25] = ui->cell_25;ptrToCells[26] = ui->cell_26;
    ptrToCells[27] = ui->cell_27;ptrToCells[28] = ui->cell_28;
    ptrToCells[29] = ui->cell_29;ptrToCells[30] = ui->cell_30;
    ptrToCells[31] = ui->cell_31;ptrToCells[32] = ui->cell_32;
    ptrToCells[33] = ui->cell_33;ptrToCells[34] = ui->cell_34;
    ptrToCells[35] = ui->cell_35;ptrToCells[36] = ui->cell_36;
    ptrToCells[37] = ui->cell_37;ptrToCells[38] = ui->cell_38;
    ptrToCells[39] = ui->cell_39;ptrToCells[40] = ui->cell_40;
    ptrToCells[41] = ui->cell_41;ptrToCells[42] = ui->cell_42;
    ptrToCells[43] = ui->cell_43;ptrToCells[44] = ui->cell_44;
    ptrToCells[45] = ui->cell_45;ptrToCells[46] = ui->cell_46;
    ptrToCells[47] = ui->cell_47;ptrToCells[48] = ui->cell_48;
    ptrToCells[49] = ui->cell_49;ptrToCells[50] = ui->cell_50;
    ptrToCells[51] = ui->cell_51;ptrToCells[52] = ui->cell_52;
    ptrToCells[53] = ui->cell_53;ptrToCells[54] = ui->cell_54;
    ptrToCells[55] = ui->cell_55;ptrToCells[56] = ui->cell_56;
    ptrToCells[57] = ui->cell_57;ptrToCells[58] = ui->cell_58;
    ptrToCells[59] = ui->cell_59;ptrToCells[60] = ui->cell_60;
    ptrToCells[61] = ui->cell_61;ptrToCells[62] = ui->cell_62;
    ptrToCells[63] = ui->cell_63;ptrToCells[64] = ui->cell_64;
    ptrToCells[65] = ui->cell_65;ptrToCells[66] = ui->cell_66;
    ptrToCells[67] = ui->cell_67;ptrToCells[68] = ui->cell_68;
    ptrToCells[69] = ui->cell_69;ptrToCells[70] = ui->cell_70;
    ptrToCells[71] = ui->cell_71;ptrToCells[72] = ui->cell_72;
    ptrToCells[73] = ui->cell_73;ptrToCells[74] = ui->cell_74;
    ptrToCells[75] = ui->cell_75;ptrToCells[76] = ui->cell_76;
    ptrToCells[77] = ui->cell_77;ptrToCells[78] = ui->cell_78;
    ptrToCells[79] = ui->cell_79;ptrToCells[80] = ui->cell_80;
    ptrToCells[81] = ui->cell_81;ptrToCells[82] = ui->cell_82;
    ptrToCells[83] = ui->cell_83;ptrToCells[84] = ui->cell_84;
    ptrToCells[85] = ui->cell_85;ptrToCells[86] = ui->cell_86;
    ptrToCells[87] = ui->cell_87;ptrToCells[88] = ui->cell_88;
    ptrToCells[89] = ui->cell_89;ptrToCells[90] = ui->cell_90;
    ptrToCells[91] = ui->cell_91;ptrToCells[92] = ui->cell_92;
    ptrToCells[93] = ui->cell_93;ptrToCells[94] = ui->cell_94;
    ptrToCells[95] = ui->cell_95;ptrToCells[96] = ui->cell_96;
    ptrToCells[97] = ui->cell_97;ptrToCells[98] = ui->cell_98;
    ptrToCells[99] = ui->cell_99;ptrToCells[100] = ui->cell_100;
    ptrToCells[101] = ui->cell_101;ptrToCells[102] = ui->cell_102;
    ptrToCells[103] = ui->cell_103;ptrToCells[104] = ui->cell_104;
    ptrToCells[105] = ui->cell_105;ptrToCells[106] = ui->cell_106;
    ptrToCells[107] = ui->cell_107;ptrToCells[108] = ui->cell_108;
    ptrToCells[109] = ui->cell_109;ptrToCells[110] = ui->cell_110;
    ptrToCells[111] = ui->cell_111;ptrToCells[112] = ui->cell_112;
    ptrToCells[113] = ui->cell_113;ptrToCells[114] = ui->cell_114;
    ptrToCells[115] = ui->cell_115;ptrToCells[116] = ui->cell_116;


    ptrToScoreLabel[0] = ui->player1_score;ptrToScoreLabel[1] = ui->player2_score;
    ptrToScoreLabel[2] = ui->player3_score;ptrToScoreLabel[3] = ui->player4_score;


    ptrToZeroCells[0] = ui->cell_0_player1;ptrToZeroCells[1] = ui->cell_0_player2;
    ptrToZeroCells[2] = ui->cell_0_player3;ptrToZeroCells[3] = ui->cell_0_player4;


    ptrToEqualDiceButtons = new QPushButton* [14];

    ptrToEqualDiceButtons[0] = ui->equal_dice_button1;ptrToEqualDiceButtons[1] = ui->equal_dice_button2;
    ptrToEqualDiceButtons[2] = ui->equal_dice_button3;ptrToEqualDiceButtons[3] = ui->equal_dice_button4;
    ptrToEqualDiceButtons[4] = ui->equal_dice_button5;ptrToEqualDiceButtons[5] = ui->equal_dice_button6;
    ptrToEqualDiceButtons[6] = ui->equal_dice_button7;ptrToEqualDiceButtons[7] = ui->equal_dice_button8;
    ptrToEqualDiceButtons[8] = ui->equal_dice_button9;ptrToEqualDiceButtons[9] = ui->equal_dice_button10;
    ptrToEqualDiceButtons[10] = ui->equal_dice_button11;ptrToEqualDiceButtons[11] = ui->equal_dice_button12;
    ptrToEqualDiceButtons[12] = ui->equal_dice_button13;ptrToEqualDiceButtons[13] = ui->equal_dice_button14;


    for (int i = 1; i <= 116; i++){
        ptrToChoiceCells[i]->hide();
    }

    ui->equal_dice_choices->hide();
    //ui->red_cell_treasure_choices->show();


    connect(ptrToChoiceCells[25], SIGNAL(clicked(bool)), this, SLOT(redButtonClicked()));

    for (int i = 1; i <= 116; i++)
    {
        if (i != 25)
            connect(ptrToChoiceCells[i], SIGNAL(clicked()), this, SLOT(buttonClicked()));
    }

    for (int i = 0; i <= 13 ; i++ ){
        connect(ptrToEqualDiceButtons[i], SIGNAL(clicked(bool)), this, SLOT(EqualDiceButtonsClicked()) );
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(NULL));

    askNumOfPlayers asknumofplayers;
    asknumofplayers.setModal(true);
    asknumofplayers.exec();
    int num_of_players = asknumofplayers.getNumber_of_players();


    AskNameOfPlayers asknameofplayers(num_of_players);
    asknameofplayers.setModal(true);
    asknameofplayers.exec();

    myGame = new Game(num_of_players);
    ui->groupBox->show();

    ui->player1_name->setText(asknameofplayers.getPlayer1_name());
    player_names[0] = asknameofplayers.getPlayer1_name();
    QString s = QString::number(myGame->getPositions()[0]);
    ui->player1_position->setText(s);
    s = QString::number(myGame->getNumOfWonTreasures(0));
    ui->player1_score->setText(s);
    ui->cell_0_player1->setText("1");


    ui->player2_name->setText(asknameofplayers.getPlayer2_name());
    player_names[1] = asknameofplayers.getPlayer2_name();
    s = QString::number(myGame->getPositions()[1]);
    ui->player2_position->setText(s);
    s = QString::number(myGame->getNumOfWonTreasures(1));
    ui->player2_score->setText(s);
    ui->cell_0_player2->setText("2");

    if (num_of_players >= 3){
        ui->player3_name->setText(asknameofplayers.getPlayer3_name());
        player_names[2] = asknameofplayers.getPlayer3_name();
        s = QString::number(myGame->getPositions()[2]);
        ui->player3_position->setText(s);
        s = QString::number(myGame->getNumOfWonTreasures(2));
        ui->player3_score->setText(s);
        ui->cell_0_player3->setText("3");
    }
    else{
        ui->cell_0_player3->hide();
        ui->player3_name->hide();
        ui->player3_position->hide();
        ui->player3_score->hide();
    }
    if (num_of_players >= 4){
        ui->player4_name->setText(asknameofplayers.getPlayer4_name());
        player_names[3] = asknameofplayers.getPlayer4_name();
        s = QString::number(myGame->getPositions()[3]);
        ui->player4_position->setText(s);
        s = QString::number(myGame->getNumOfWonTreasures(3));
        ui->player4_score->setText(s);
        ui->cell_0_player4->setText("4");
    }
    else{
        ui->cell_0_player4->hide();
        ui->player4_name->hide();
        ui->player4_position->hide();
        ui->player4_score->hide();
    }

    ui->current_turn_playe_name->setText(player_names[0] + "'s Turn");
    s = QString::number(myGame->getRound());
    ui->round_number->setText("Round " + s);

    myGame->contributeTreasures();//contribute treasures among orange cells randomly
    myGame->setTreasure();//define the goal treasure of current roun

    s = "Round number ";
    s += QString::number(myGame->getRound());
    s += " started. This Round's goal treasure is ";
    s += myGame->declareGoalTreasure();
    QMessageBox::information(this, "Message", s);


    cout << myGame->declareGoalTreasure() << endl;
    for (auto element : myGame->getOrangeCellsNumbers()){

        cout << element << " : " << myGame->getNameOfTreasure(element) << endl;

    }


    ui->roll_dice->setEnabled(true);
}

void MainWindow::on_roll_dice_clicked()
{
    myGame->setIsGuessTreasure(false);
    this->accessible_positions1.clear();
    this->accessible_positions2.clear();
    myGame->setPrizeTurn(false);

    int first_die = 0, second_die = 0;
    //
    DiceWindow dicewindow;
    dicewindow.setModal(true);
    dicewindow.exec();
    //
    first_die = dicewindow.getFirst_die();
    second_die = dicewindow.getSecond_die();
    ui->lcdNumber->display(first_die);
    ui->lcdNumber_2->display(second_die);
    //

    myGame->getPossibleMoves(this->accessible_positions1, myGame->getCurrentPosition(), first_die);

    for ( auto element : accessible_positions1 ) {
        ptrToChoiceCells[element]->show();
    }

    myGame->getPossibleMoves( this->accessible_positions2, myGame->getCurrentPosition(), second_die );

    if ( first_die != second_die ) {
        for ( auto element : accessible_positions2 ) {
            ptrToChoiceCells[element]->show();
        }
    } else {

        if (first_die == second_die)
        {
            int i = 0;
            for (auto element : myGame->getOrangeCellsNumbers()){
                QString s = "Move to ";
                s += QString::number(element);
                ptrToEqualDiceButtons[i]->setText(s);
                i++;
            }

            ui->change_goal_treasure->show();
            ui->equal_dice_button14->show();
            ui->dont_guess->hide();
            ui->equal_dice_choices->show();
        }


        vector<int> orange_cells = myGame->getOrangeCellsNumbers();


        for (int i = 0; i < orange_cells.size(); i++){
            if ( myGame->getIsFilledCell(orange_cells[i]) )
                ptrToEqualDiceButtons[i]->setEnabled(false);
            else
                ptrToEqualDiceButtons[i]->setEnabled(true);

        }

        if ( myGame->getIsFilledCell(15)){
            ptrToEqualDiceButtons[13]->setEnabled(false);
        }
        else{
            ptrToEqualDiceButtons[13]->setEnabled(true);
        }

    }


}

void MainWindow::buttonClicked(){

    ui->equal_dice_choices->hide();

    QPushButton *button = (QPushButton*)sender();
    ui->roll_dice->setEnabled(false);

    int new_position;
    for (int i = 1; i <= 116; i++){
        if (ptrToChoiceCells[i] == button)
        {
            new_position = i;
            break;
        }
    }

    if (myGame->getColorOfCell(new_position) == "Orange"){

        QMessageBox::information(this, "Message", "Dear other plaers!!!! Please close your eyes!");
        QString s1 = "Cell ";
        s1 += QString::number(new_position);
        s1 += "'s treasure as seen by ";
        s1 += player_names[myGame->getTurn()];
        s1 += " is ";
        s1 += myGame->getNameOfTreasure(new_position);

        QMessageBox::information(this, "Message", s1);
    }

    int first_die = ui->lcdNumber->value();
    int second_die = ui->lcdNumber_2->value();

    int die_number;
    bool isFirstDie = false;
    for (auto element : accessible_positions1)
        if (new_position == element){
            die_number = first_die;
            isFirstDie = true;
        }

    if (isFirstDie == false)
        die_number = second_die;


    int player_id;
    player_id = myGame->playerInFilledCell(new_position);

    if (player_id != -1) {
        QString s = QString::number(0);
        ptrsToPositionLabel[player_id]->setText(s);
        s =  player_names[player_id] + " is moved to Blue cells";
        QMessageBox::information(this, "Message", s);
        changePositionsOnBoard(new_position, 0, player_id);
    }


    changePositionsOnBoard(myGame->getCurrentPosition(), new_position, myGame->getTurn());
    myGame->changePosition(new_position);

    QString s = QString::number(myGame->getCurrentPosition());
    ptrsToPositionLabel[myGame->getTurn()]->setText(s);


    for (int i = 1; i <= 116; i++)
        ptrToChoiceCells[i]->hide();

    if (myGame->getMoveNumber() == 2){

        if (die_number == first_die){

            vector<int> final_positions;
            myGame->getPossibleMoves(final_positions, new_position, second_die);

            for (auto element : final_positions) {
                ptrToChoiceCells[element]->show();
            }

        }else if (die_number == second_die) {

            vector<int> final_positions;
            myGame->getPossibleMoves(final_positions, new_position, first_die);

            for (auto element : final_positions) {
                ptrToChoiceCells[element]->show();
            }
        }

    }else{

        ui->roll_dice->setEnabled(true);
        myGame->nextTurn();
        ui->current_turn_playe_name->setText(player_names[myGame->getTurn()] + "'s Turn");
        ui->lcdNumber->display(0);
        ui->lcdNumber_2->display(0);
    }
}

void MainWindow::on_roll_dice_released()
{
    ui->roll_dice->setEnabled(false);
}

void MainWindow::on_pushButton_released()
{
    ui->pushButton->setEnabled(false);
}

void MainWindow::EqualDiceButtonsClicked(){

    int new_position;

    //this variable is for when the player wants to guess the goal treasure
    int player_guess;

    ui->equal_dice_choices->hide();
    QPushButton *button = (QPushButton*)sender();

    for (int i = 1; i <= 116; i++)
        ptrToChoiceCells[i]->hide();


    //finding the clicked button
    int i = 0;
    for (auto element : myGame->getOrangeCellsNumbers()){

        if (button == ptrToEqualDiceButtons[i])
        {

            if (!myGame->getIsGuessTreasure())
            {
                new_position = element;
                changePositionsOnBoard(myGame->getCurrentPosition(), element, myGame->getTurn());
            }
            else
            {
                player_guess = element;
            }
        }

        i++;
    }
    //


    if (button == ptrToEqualDiceButtons[13])
    {
        new_position = 15;
        changePositionsOnBoard(myGame->getCurrentPosition(), new_position, myGame->getTurn());
    }

    if (myGame->getIsGuessTreasure())
    {
        //
        QMessageBox::information(this, "Message", "Dear Other Players , Please Close your Eyes!");
        QString showtrs = "Cell ";
        showtrs += QString::number(player_guess);
        showtrs += "'s Treasure as seen by ";
        showtrs += player_names[myGame->getTurn()];
        showtrs += " is ";
        showtrs += myGame->getNameOfTreasure(player_guess);
        QMessageBox::information(this, "Message", showtrs);
        //

        if (myGame->declareGoalTreasure() == myGame->getNameOfTreasure(player_guess))
        {
            QString s = player_names[myGame->getTurn()];
            s += "'s guess, ";
            s += QString::number(player_guess);
            s += ", was correct and he/she won this round's goal treasure, ";
            s += myGame->declareGoalTreasure();
            QMessageBox::information(this, "Message", s);


            int player_id = myGame->getTurn();
            myGame->addNumOfWonTreasures(player_id);
            ptrToScoreLabel[player_id]->setText(QString::number(myGame->getNumOfWonTreasures(player_id)));

            myGame->goToNextRound();
            myGame->initializeMoveNumber();
            myGame->setPrizeTurn(true);

            if (myGame->getRound() <= 13)
            {
                s = "Round ";
                s += QString::number(myGame->getRound());
                ui->round_number->setText(s);
                myGame->removeGoalTreasure();
                myGame->setTreasure();

                s = "Round number ";
                s += QString::number(myGame->getRound());
                s += " started. This Round's goal treasure is ";
                s += myGame->declareGoalTreasure();
                QMessageBox::information(this, "Message", s);

                int i = 0;
                for (auto element : myGame->getOrangeCellsNumbers())
                {
                    QString s = "It's ";
                    s += QString::number(element);
                    ptrToEqualDiceButtons[i]->setText(s);
                    i++;
                }

                ptrToEqualDiceButtons[13]->hide();
                ui->change_goal_treasure->hide();
                ui->dont_guess->show();
                ui->equal_dice_choices->show();
            }
            else
            {
                vector<int> winners;
                myGame->getWinnersId(winners);
                QString s;

                s = player_names[winners[0]];

                if (winners.size() > 1){

                    for (int i = 1; i < winners.size(); i++){
                        s += ", ";
                        s += player_names[winners[i]];
                    }

                }


                s += " won the game!!!";
                QMessageBox::information(this, "Message", s);
                this->close();
            }
        }
        else
        {
            QString s = player_names[myGame->getTurn()];
            s += "'s guess, ";
            s += QString::number(player_guess);
            s += ", was not correct";
            QMessageBox::information(this, "Message", s);

            s = player_names[myGame->getTurn()];
            s += " is moved to Blue cells ";
            changePositionsOnBoard(myGame->getCurrentPosition(), 0, myGame->getTurn());

            myGame->changePosition(0);
            QMessageBox::information(this, "Message", s);


            s = QString::number(myGame->getCurrentPosition());
            ptrsToPositionLabel[myGame->getTurn()]->setText(s);


            myGame->initializeMoveNumber();
            myGame->nextTurn();
            myGame->setPrizeTurn(false);

            ui->roll_dice->setEnabled(true);
            ui->current_turn_playe_name->setText(player_names[myGame->getTurn()] + "'s Turn");
            ui->lcdNumber->display(0);
            ui->lcdNumber_2->display(0);
            ptrToEqualDiceButtons[13]->show();

        }

    }

    if (new_position != 15 && !myGame->getIsGuessTreasure())
    {
        QMessageBox::information(this, "Message", "Dear other plaers!!!! Please close your eyes!");
        QString s1 = "Cell ";
        s1 += QString::number(new_position);
        s1 += "'s treasure as seen by ";
        s1 += player_names[myGame->getTurn()];
        s1 += " is ";
        s1 += myGame->getNameOfTreasure(new_position);

        QMessageBox::information(this, "Message", s1);

    }
    if (!myGame->getIsGuessTreasure())
    {
        myGame->changePosition(new_position);
        QString s = QString::number(myGame->getCurrentPosition());
        ptrsToPositionLabel[myGame->getTurn()]->setText(s);


        ui->roll_dice->setEnabled(true);
        myGame->nextTurn();
        ui->current_turn_playe_name->setText(player_names[myGame->getTurn()] + "'s Turn");
        ui->lcdNumber->display(0);
        ui->lcdNumber_2->display(0);

        myGame->initializeMoveNumber();
    }
}

void MainWindow::on_change_goal_treasure_clicked()
{
    for (int i = 1; i <= 116; i++)
        ptrToChoiceCells[i]->hide();

    myGame->setTreasure();
    QString s1 = "Round number ";
    s1 += QString::number(myGame->getRound());
    s1 += ", this round's goal treasure has changed to ";
    s1 += myGame->declareGoalTreasure();
    QMessageBox::information(this, "Message", s1);

    ui->equal_dice_choices->hide();
    ui->roll_dice->setEnabled(true);
    myGame->nextTurn();
    ui->current_turn_playe_name->setText(player_names[myGame->getTurn()] + "'s Turn");
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    myGame->initializeMoveNumber();

}

void MainWindow::redButtonClicked()
{

    //player can attempt to guess the goal treausre. so isGuessGoalTreasure should become true
    myGame->setIsGuessTreasure(true);

    //if we had equal dice numbers in previous turns, button should become hidden first(actually the will show again)
    ui->equal_dice_choices->hide();

    ui->roll_dice->setEnabled(false);

    QPushButton *button = (QPushButton*)sender();

    int new_position = 25;

    int player_id;
    player_id = myGame->playerInFilledCell(new_position);

    if (player_id != -1) {
        QString s = QString::number(0);
        ptrsToPositionLabel[player_id]->setText(s);
        s =  player_names[player_id] + " is moved to Blue cells";
        QMessageBox::information(this, "Message", s);
        changePositionsOnBoard(new_position, 0, player_id);
    }
    //

    //
    ptrToCells[myGame->getCurrentPosition()]->setText("");
    ptrToChoiceCells[myGame->getCurrentPosition()]->setText("");
    changePositionsOnBoard(myGame->getCurrentPosition(), new_position, myGame->getTurn());
    myGame->changePosition(new_position);
    QString s = QString::number(myGame->getCurrentPosition());
    ptrsToPositionLabel[myGame->getTurn()]->setText(s);
    //

    for (int i = 1; i <= 116; i++)
        ptrToChoiceCells[i]->hide();

    int i = 0;
    for (auto element : myGame->getOrangeCellsNumbers()){
        QString s = "It's ";
        s += QString::number(element);
        ptrToEqualDiceButtons[i]->setText(s);
        ptrToEqualDiceButtons[i]->setEnabled(true);
        i++;
    }


    //Violet cell shouldn't  be displayed
    ptrToEqualDiceButtons[13]->hide();
    ui->change_goal_treasure->hide();
    ui->equal_dice_choices->show();
    ui->dont_guess->show();

}

void MainWindow::on_dont_guess_clicked()
{

    ui->equal_dice_choices->hide();
    myGame->setIsGuessTreasure(false);

    int first_die = ui->lcdNumber->value();
    int second_die = ui->lcdNumber_2->value();


    int new_position = 25;

    //
    int die_number;
    bool isFirstDie = false;
    for (auto element : accessible_positions1)
        if (new_position == element){
            die_number = first_die;
            isFirstDie = true;
        }

    if (isFirstDie == false)
        die_number = second_die;
    //

    if (myGame->getMoveNumber() == 2){
        if (die_number == first_die){

            vector<int> final_positions;
            myGame->getPossibleMoves(final_positions, new_position, second_die);

            for (auto element : final_positions) {
                ptrToChoiceCells[element]->show();
            }

        }else if (die_number == second_die) {

            vector<int> final_positions;
            myGame->getPossibleMoves(final_positions, new_position, first_die);

            for (auto element : final_positions) {
                ptrToChoiceCells[element]->show();
            }
        }

    }else{

        ui->roll_dice->setEnabled(true);

        if (!myGame->isPrizeTurn()){
            myGame->nextTurn();
            myGame->setPrizeTurn(false);
        }

        ui->current_turn_playe_name->setText(player_names[myGame->getTurn()] + "'s Turn");
        ui->lcdNumber->display(0);
        ui->lcdNumber_2->display(0);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    instrhelp openings;
    openings.setModal(true);
    openings.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation" , "Do you really want to Close the Application?", QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes)
            {
                QApplication::quit();
            }
}

void MainWindow::changePositionsOnBoard(int src, int dest, int player_number)
{
    if (src != 0){

        ptrToCells[src]->setText("");
        ptrToChoiceCells[src]->setText("");

    }else{

        ptrToZeroCells[player_number]->setText("");

    }

    if (dest != 0){

        ptrToCells[dest]->setText(QString::number(player_number + 1));
        ptrToChoiceCells[dest]->setText(QString::number(player_number + 1));

    }else{

        ptrToZeroCells[player_number]->setText(QString::number(player_number + 1));

    }

}
