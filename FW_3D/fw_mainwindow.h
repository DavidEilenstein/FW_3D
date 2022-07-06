#ifndef FW_MAINWINDOW_H
#define FW_MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QScrollBar>
#include <QDateTime>
#include <FW_Enum.h>
#include <fw_field.h>
#include <fw_field_plot.h>
#include <fw_bot_random.h>
#include <fw_bot_tree.h>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class FW_MainWindow; }
QT_END_NAMESPACE

class FW_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FW_MainWindow(QWidget *parent = nullptr);
    ~FW_MainWindow();

public slots:
    void init_field();


private slots:

    bool check_end();

    void ConsolePrint(QString text);

    void MakeMove_Player(int x, int y);
    void MakeMove_Bot();
    void FieldHighlight(int x, int y, char m);

    bool Plot_Init();
    void Plot_Clear();
    bool Plot_Show();

    void on_comboBox_Bot_Mode_currentIndexChanged(int index);
    void on_spinBox_Bot_Param_valueChanged(int arg1);

    void on_pushButton_Field_00_clicked();
    void on_pushButton_Field_10_clicked();
    void on_pushButton_Field_20_clicked();
    void on_pushButton_Field_30_clicked();
    void on_pushButton_Field_01_clicked();
    void on_pushButton_Field_11_clicked();
    void on_pushButton_Field_21_clicked();
    void on_pushButton_Field_31_clicked();
    void on_pushButton_Field_02_clicked();
    void on_pushButton_Field_12_clicked();
    void on_pushButton_Field_22_clicked();
    void on_pushButton_Field_32_clicked();
    void on_pushButton_Field_03_clicked();
    void on_pushButton_Field_13_clicked();
    void on_pushButton_Field_23_clicked();
    void on_pushButton_Field_33_clicked();


    void on_pushButton_Restart_clicked();

    void on_pushButton_ClearConsole_clicked();

private:
    Ui::FW_MainWindow *ui;

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init = 0);

    FW_Field Field;
    int player_moves = 0;

    FW_Bot_Random Bot_Random;
    FW_Bot_Tree Bot_Tree;

    QStringList QSL_ConsoleText;
    const int consoleLimit = 1000;

    FW_Field_Plot FieldPlot;
};
#endif // FW_MAINWINDOW_H
