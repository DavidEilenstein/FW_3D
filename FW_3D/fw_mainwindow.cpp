#include "fw_mainwindow.h"
#include "ui_fw_mainwindow.h"

FW_MainWindow::FW_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FW_MainWindow)
{
    ui->setupUi(this);

    init_field();
    Populate_CB_Single(ui->comboBox_Bot_Mode, QSL_Bots, BOT_TREE);

    setWindowTitle("Four wins 3D");
}

FW_MainWindow::~FW_MainWindow()
{
    delete ui;
}

void FW_MainWindow::init_field()
{
    ConsolePrint("================ NEW GAME ================");

    Field.clear_init();

    player_moves = 0;

    ui->groupBox_FieldControl->setEnabled(true);
    ui->groupBox_BotSettings->setEnabled(true);
    FieldHighlight(0, 0, MARKER_EMPTY);
}

bool FW_MainWindow::check_end()
{
    char w;
    if(!Field.check_end(&w))
        return false;

    if(w == WIN_WHITE)
        ConsolePrint("Congratulations, you defeated the filthy bot in " + QString::number(player_moves) + " moves :-)");
    else if(w == WIN_BLACK)
        ConsolePrint("Ahahahaha! The bot beat the shit out of your dumb tactics :-P");
    else if(w == WIN_DRAW)
        ConsolePrint("Nice match! It is a draw.");

    ConsolePrint(": : : : : : : : : : : : : : : : : : : : : : : : : : :");
    ui->groupBox_FieldControl->setEnabled(false);
    ui->groupBox_BotSettings->setEnabled(true);

    return true;
}

void FW_MainWindow::ConsolePrint(QString text)
{
    QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + text);
    if(QSL_ConsoleText.size() > consoleLimit)
        QSL_ConsoleText.pop_front();

    QString QS_PlainText;
    for(int s = 0; s < QSL_ConsoleText.size(); s++)
    {
        if(s != 0)
            QS_PlainText.append("\n");
        QS_PlainText.append(QSL_ConsoleText[s]);
    }

    ui->plainTextEdit_Output->setPlainText(QS_PlainText);
    ui->plainTextEdit_Output->verticalScrollBar()->setValue(ui->plainTextEdit_Output->verticalScrollBar()->maximum());
    ui->plainTextEdit_Output->repaint();
    qApp->processEvents();
    this->repaint();
}

void FW_MainWindow::MakeMove_Player(int x, int y)
{
    QString QS_xy = QString::number(x) + " / " + QString::number(y);

    if(Field.is_full_stack(x, y))
    {
        ConsolePrint("Are you blind??? " + QS_xy + " is a full stack...");
        return;
    }


    ConsolePrint(QS_xy + " - level " + QString::number(Field.get_first_empty_index(x, y)) + " - Player (white)");
    Field.insert_marker(x, y, MARKER_WHITE);
    FieldHighlight(x, y, MARKER_WHITE);

    player_moves++;

    if(check_end())
        return;

    MakeMove_Bot();
}

void FW_MainWindow::MakeMove_Bot()
{
    ui->groupBox_FieldControl->setEnabled(false);
    ui->groupBox_BotSettings->setEnabled(false);

    int x = 0;
    int y = 0;

    QString bot_comment = "";

    bool made_move = false;

    //finish tripple?
    if(!made_move && ui->checkBox_TrippleAttack->isChecked())
    {
        if(Field.check_tripples(&x, &y, MARKER_BLACK))
        {
            made_move = true;
            bot_comment = " - finished tripple";
        }
    }

    //defend tripple?
    if(!made_move && ui->checkBox_TrippleDefend->isChecked())
    {
        if(Field.check_tripples(&x, &y, MARKER_WHITE))
        {
            made_move = true;
            bot_comment = " - defended tripple";
        }
    }

    //regular move calculated by bot
    if(!made_move)
    {
        switch (ui->comboBox_Bot_Mode->currentIndex())
        {

        case BOT_RANDOM:
        {
            Bot_Random.make_move(&Field, &x, &y);
            bot_comment = " - random";
        }
            break;

        case BOT_TREE:
        {
            double score;
            Bot_Tree.make_move(&Field, &x, &y, &score);
            bot_comment = " - score=" + QString::number(int(score * 100.0)) + "%";
        }
            break;

        default:
            ConsolePrint("INVALID BOT");
            break;
        }
    }

    QString QS_xy = QString::number(x) + " / " + QString::number(y);

    if(Field.is_full_stack(x, y))
    {
        ConsolePrint("Bot seems to be an idiot... Wanted to set marker at " + QS_xy + ", which is a full stack...");
        init_field();
        return;
    }

    ConsolePrint(QS_xy + " - level " + QString::number(Field.get_first_empty_index(x, y)) + " - Bot (black)" + bot_comment);
    Field.insert_marker(x, y, MARKER_BLACK);
    FieldHighlight(x, y, MARKER_BLACK);

    if(check_end())
        return;

    ConsolePrint("-----------------------------------------------");
    ui->groupBox_FieldControl->setEnabled(true);
    ui->groupBox_BotSettings->setEnabled(true);
}

void FW_MainWindow::FieldHighlight(int x, int y, char m)
{
    QString stylesheet;
    if(m == MARKER_BLACK)
        stylesheet = "Background-color: rgb(0, 0, 0);\ncolor: rgb(255, 255, 255);\nfont-size: 15px;";
    else if(m == MARKER_WHITE)
        stylesheet = "Background-color: rgb(255, 255, 255);\ncolor: rgb(0, 0, 0);\nfont-size: 15px;";
    else
        stylesheet = "";

    ui->pushButton_Field_00->setStyleSheet(x == 0 && y == 0 ? stylesheet : "");
    ui->pushButton_Field_01->setStyleSheet(x == 0 && y == 1 ? stylesheet : "");
    ui->pushButton_Field_02->setStyleSheet(x == 0 && y == 2 ? stylesheet : "");
    ui->pushButton_Field_03->setStyleSheet(x == 0 && y == 3 ? stylesheet : "");

    ui->pushButton_Field_10->setStyleSheet(x == 1 && y == 0 ? stylesheet : "");
    ui->pushButton_Field_11->setStyleSheet(x == 1 && y == 1 ? stylesheet : "");
    ui->pushButton_Field_12->setStyleSheet(x == 1 && y == 2 ? stylesheet : "");
    ui->pushButton_Field_13->setStyleSheet(x == 1 && y == 3 ? stylesheet : "");

    ui->pushButton_Field_20->setStyleSheet(x == 2 && y == 0 ? stylesheet : "");
    ui->pushButton_Field_21->setStyleSheet(x == 2 && y == 1 ? stylesheet : "");
    ui->pushButton_Field_22->setStyleSheet(x == 2 && y == 2 ? stylesheet : "");
    ui->pushButton_Field_23->setStyleSheet(x == 2 && y == 3 ? stylesheet : "");

    ui->pushButton_Field_30->setStyleSheet(x == 3 && y == 0 ? stylesheet : "");
    ui->pushButton_Field_31->setStyleSheet(x == 3 && y == 1 ? stylesheet : "");
    ui->pushButton_Field_32->setStyleSheet(x == 3 && y == 2 ? stylesheet : "");
    ui->pushButton_Field_33->setStyleSheet(x == 3 && y == 3 ? stylesheet : "");

    qApp->processEvents();
    this->repaint();
}

void FW_MainWindow::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void FW_MainWindow::on_comboBox_Bot_Mode_currentIndexChanged(int index)
{
    ui->spinBox_Bot_Param->setEnabled(index == BOT_TREE);
}

void FW_MainWindow::on_spinBox_Bot_Param_valueChanged(int arg1)
{
    switch (ui->comboBox_Bot_Mode->currentIndex())
    {
    case BOT_TREE:
    {
        Bot_Tree.set_depths(arg1);
        ConsolePrint("Changed BotTree's depth to " + QString::number(arg1));
    }
        break;

    default:
        break;
    }
}

void FW_MainWindow::on_pushButton_Field_00_clicked()
{
    MakeMove_Player(0, 0);
}

void FW_MainWindow::on_pushButton_Field_10_clicked()
{
    MakeMove_Player(1, 0);
}

void FW_MainWindow::on_pushButton_Field_20_clicked()
{
    MakeMove_Player(2, 0);
}

void FW_MainWindow::on_pushButton_Field_30_clicked()
{
    MakeMove_Player(3, 0);
}

void FW_MainWindow::on_pushButton_Field_01_clicked()
{
    MakeMove_Player(0, 1);
}

void FW_MainWindow::on_pushButton_Field_11_clicked()
{
    MakeMove_Player(1, 1);
}

void FW_MainWindow::on_pushButton_Field_21_clicked()
{
    MakeMove_Player(2, 1);
}

void FW_MainWindow::on_pushButton_Field_31_clicked()
{
    MakeMove_Player(3, 1);
}

void FW_MainWindow::on_pushButton_Field_02_clicked()
{
    MakeMove_Player(0, 2);
}

void FW_MainWindow::on_pushButton_Field_12_clicked()
{
    MakeMove_Player(1, 2);
}

void FW_MainWindow::on_pushButton_Field_22_clicked()
{
    MakeMove_Player(2, 2);
}

void FW_MainWindow::on_pushButton_Field_32_clicked()
{
    MakeMove_Player(3, 2);
}

void FW_MainWindow::on_pushButton_Field_03_clicked()
{
    MakeMove_Player(0, 3);
}

void FW_MainWindow::on_pushButton_Field_13_clicked()
{
    MakeMove_Player(1, 3);
}

void FW_MainWindow::on_pushButton_Field_23_clicked()
{
    MakeMove_Player(2, 3);
}

void FW_MainWindow::on_pushButton_Field_33_clicked()
{
    MakeMove_Player(3, 3);
}

void FW_MainWindow::on_pushButton_Restart_clicked()
{
    init_field();
}

void FW_MainWindow::on_pushButton_ClearConsole_clicked()
{
    QSL_ConsoleText.clear();
    ConsolePrint("xxxxxxxxxxxxxxxxxx Cleared the console xxxxxxxxxxxxxxxxxx");
}
