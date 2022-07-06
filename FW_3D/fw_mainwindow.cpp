#include "fw_mainwindow.h"
#include "ui_fw_mainwindow.h"

FW_MainWindow::FW_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FW_MainWindow)
{
    ui->setupUi(this);

    Plot_Init();
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
    Plot_Clear();

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

    if(w == WIN_PLAYER)
    {
        ConsolePrint("Congratulations, you defeated the filthy bot in " + QString::number(player_moves) + " moves :-)", COL_PLAYER);
        FieldPlot.set_color(QSl_Colors[COL_PLAYER]);
    }
    else if(w == WIN_BOT)
    {
        ConsolePrint("Ahahahaha! The bot beat the shit out of your dumb tactics :-P", COL_BOT);
        FieldPlot.set_color(QSl_Colors[COL_BOT]);
    }
    else if(w == WIN_DRAW)
    {
        ConsolePrint("Nice match! It is a draw.", COL_EMPTY);
        FieldPlot.set_color(QSl_Colors[COL_EMPTY]);
    }

    ConsolePrint(": : : : : : : : : : : : : : : : : : : : : : : : : : :");
    ui->groupBox_FieldControl->setEnabled(false);
    ui->groupBox_BotSettings->setEnabled(true);

    return true;
}

void FW_MainWindow::ConsolePrint(QString text, size_t col_index)
{
    /*
    switch (col_index) {
    case COL_PLAYER:    QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + "<span style= \"color:#00ff00;\">" + text + "</span> ");   break;
    case COL_BOT:       QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + "<span style= \"color:#0000ff;\">" + text + "</span> ");   break;
    case COL_EMPTY:     QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + "<span style= \"color:#808080;\">" + text + "</span> ");   break;
    case COL_ERROR:     QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + "<span style= \"color:#ff0000;\">" + text + "</span> ");   break;
    default:            QSL_ConsoleText.append("[" + QDateTime::currentDateTime().time().toString() + "] " + "<span style= \"color:#000000;\">" + text + "</span> ");   break;}
    */

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
        ConsolePrint("Are you blind??? " + QS_xy + " is a full stack...", COL_ERROR);
        return;
    }


    ConsolePrint(QS_xy + " - level " + QString::number(Field.get_first_empty_index(x, y)) + " - Player", COL_PLAYER);
    Field.insert_marker(x, y, MARKER_PLAYER);
    Plot_Show();
    FieldHighlight(x, y, MARKER_PLAYER);

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
        if(Field.check_tripples(&x, &y, MARKER_BOT))
        {
            made_move = true;
            bot_comment = " - finished tripple";
        }
    }

    //defend tripple?
    if(!made_move && ui->checkBox_TrippleDefend->isChecked())
    {
        if(Field.check_tripples(&x, &y, MARKER_PLAYER))
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
            ConsolePrint("INVALID BOT", COL_ERROR);
            break;
        }
    }

    QString QS_xy = QString::number(x) + " / " + QString::number(y);

    if(Field.is_full_stack(x, y))
    {
        ConsolePrint("Bot seems to be an idiot... Wanted to set marker at " + QS_xy + ", which is a full stack...", COL_ERROR);
        init_field();
        return;
    }

    ConsolePrint(QS_xy + " - level " + QString::number(Field.get_first_empty_index(x, y)) + " - Bot" + bot_comment, COL_BOT);
    Field.insert_marker(x, y, MARKER_BOT);
    Plot_Show();
    FieldHighlight(x, y, MARKER_BOT);

    if(check_end())
        return;

    ConsolePrint("-----------------------------------------------");
    ui->groupBox_FieldControl->setEnabled(true);
    ui->groupBox_BotSettings->setEnabled(true);
}

void FW_MainWindow::FieldHighlight(int x, int y, char m)
{
    QString stylesheet;
    if(m == MARKER_BOT)
        stylesheet = "Background-color: " + QSl_Colors[COL_BOT] + ";\ncolor: rgb(255, 255, 255);\nfont-size: 15px;";
    else if(m == MARKER_PLAYER)
        stylesheet = "Background-color: " + QSl_Colors[COL_PLAYER] + ";\ncolor: rgb(255, 255, 255);\nfont-size: 15px;";
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

bool FW_MainWindow::Plot_Init()
{
    return FieldPlot.init(ui->gridLayout_3D_Field);
}

void FW_MainWindow::Plot_Clear()
{
    FieldPlot.clear();
}

bool FW_MainWindow::Plot_Show()
{
    return FieldPlot.plot(&Field);
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
        ConsolePrint("Changed BotTree's depth to " + QString::number(arg1), COL_BOT);
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
