#include "tictactoewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTacToeWindow w;
    w.show();
    return a.exec();
}
