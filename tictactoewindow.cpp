#include "tictactoewindow.h"
#include "ui_tictactoewindow.h"
int amount_step=0;
static int first=0, second =0;
TicTacToeWindow::TicTacToeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToeWindow)
{
    ui->setupUi(this);

}

TicTacToeWindow::~TicTacToeWindow()
{
    delete ui;
}


void TicTacToeWindow::on_my_but_0_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(0);
        if(person == 1){
            ui->my_but_0->setText("X");
        }
        else if(person==2){
            ui->my_but_0->setText("O");
        }
        End_game = WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_1_clicked()
{

    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(1);
        if(person == 1){
            ui->my_but_1->setText("X");
        }
        else if(person==2){
            ui->my_but_1->setText("O");
        }
       End_game = WhoWin(pressedBut, person);
    }
    amount_step++;
}

void TicTacToeWindow::on_my_but_2_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(2);
        if(person == 1){
            ui->my_but_2->setText("X");
        }
        else if(person == 2){
            ui->my_but_2->setText("O");
        }
        End_game =WhoWin(pressedBut, person);
    }
    amount_step++;
}

void TicTacToeWindow::on_my_but_3_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(3);
        if(person == 1){
            ui->my_but_3->setText("X");
        }
        else if(person==2){
            ui->my_but_3->setText("O");
        }
       End_game = WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_4_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(4);
        if(person == 1){
            ui->my_but_4->setText("X");
        }
        else if(person==2){
            ui->my_but_4->setText("O");
        }
        End_game =WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_5_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(5);
         if(person == 1){
             ui->my_but_5->setText("X");
           }
         else if(person==2){
             ui->my_but_5->setText("O");
          }
         End_game =WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_6_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(6);
        if(person == 1){
            ui->my_but_6->setText("X");
        }
        else if(person==2){
            ui->my_but_6->setText("O");
        }
        End_game =WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_7_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(7);
        if(person == 1){
            ui->my_but_7->setText("X");
        }
        else if(person==2){
            ui->my_but_7->setText("O");
        }
        End_game =WhoWin(pressedBut, person);
    }
amount_step++;
}

void TicTacToeWindow::on_my_but_8_clicked()
{
    if(End_game||amount_step==9){
        restart();
    }
    else{
        int person = WhoNow(8);
        if(person == 1){
            ui->my_but_8->setText("X");
        }
        else if(person==2){
            ui->my_but_8->setText("O");
        }
        WhoWin(pressedBut, person);
    }
amount_step++;
}

int TicTacToeWindow:: WhoNow(int but_index)
{
    if(End_game||amount_step==9){
        restart();
    }
    if(pressedBut[but_index]==0){
        step_couter++;
        mod = step_couter%2;
        switch(mod){
        case 1: ui->player->setText("Гравець 2");
            pressedBut[but_index]=1;
            return 1;
        case 0: ui->player->setText("Гравець 1");
            pressedBut[but_index]=2;
            return 2;
        }
    }

    return 0;
}
 bool TicTacToeWindow:: WhoWin(int pressed_But[],int gamer)
 {
     if(End_game||amount_step==9){
         restart();
     }
     int temp[3]={0};
     bool temp_win = true;
     for(int i=0; i < 8 ; i++)
     {
         for(int j = 0 ; j < 3; j++)
         {
          if(pressed_But[CombWin[i][j]]!=gamer){
              temp_win = false;
              break;
          }
          else{
              temp[j] = CombWin[i][j];
          }
         }
         if(temp_win){
             ui->queue->setText("Переможець:");
             ui->player->setText("Гравець "+QString::number(gamer));
             if(gamer==1)
                 first++;
             else
                 second++;
             ui->label->setText("Рахунок: Гравець 1 -  "+QString::number(first) + " : Гравець 2 - " +
                                QString::number(second) );
             return true;
         }
         temp_win=true;
     }
     return false;
 }

 void TicTacToeWindow:: restart()
 {
     QMessageBox:: StandardButton result = QMessageBox::question(this,"Що робити?","Хочете зіграти ще раз?", QMessageBox::Yes| QMessageBox::No);
     if(result==QMessageBox::No)
         this->close();
     End_game = false;
     step_couter = 0;
     for(int i =0 ; i < 9; i++){
         pressedBut[i]=0;
     }
     QPushButton* newButArray[]={ui->my_but_0, ui->my_but_1, ui->my_but_2, ui->my_but_3,
                                 ui->my_but_4, ui->my_but_5, ui->my_but_6, ui->my_but_7, ui->my_but_8};
     for(int i=0; i < 9; i++){
         newButArray[i]->setText("");
     }
     ui->queue->setText("Черга: ");
     ui->player->setText("Гравець 1");
     amount_step=-1;
 }




void TicTacToeWindow::on_my_but_restart_clicked()
{
    restart();
}
