#ifndef TICTACTOEWINDOW_H
#define TICTACTOEWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
QT_BEGIN_NAMESPACE

namespace Ui { class TicTacToeWindow; }
QT_END_NAMESPACE

class TicTacToeWindow : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToeWindow(QWidget *parent = nullptr);
    ~TicTacToeWindow();

private slots:
    void on_my_but_0_clicked();

    void on_my_but_1_clicked();

    void on_my_but_2_clicked();

    void on_my_but_3_clicked();

    void on_my_but_4_clicked();

    void on_my_but_5_clicked();

    void on_my_but_6_clicked();

    void on_my_but_7_clicked();

    void on_my_but_8_clicked();
    int WhoNow(int but_index);
    bool WhoWin(int pressed_But[],int gamer);
    void restart();

private:
    Ui::TicTacToeWindow *ui;
    int step_couter=0;
    int pressedBut[9]={0};
    int mod;
    int CombWin[8][3]={{0,4,8}, {2, 4, 6}, {0, 1,2}, {3, 4 ,5}, {6, 7 ,8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}};
    bool End_game=false;
};
#endif // TICTACTOEWINDOW_H
