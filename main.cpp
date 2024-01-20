#include "mainwindow.h"
#include <windows.h>
#include <QApplication>
#include "shared.h"
#include <iostream>

int table[9][9];
int p,o,count=0;
//barresi yekta boodan adad
bool checker( int satr, int sotoon, int nom) {
    // yekta  boodan dar sotoon
    for (int i = 0; i < 9; i++) {
        count++;
        if (table[satr][i] == nom)
            return false;
    }
    //yekta boodan dar satr
    for (int i = 0; i < 9; i++) {
        count++;
        if (table[i][sotoon] == nom)
            return false;
    }
    //yektaboodan dar moraba
    for (int i = 0; i < 3; i++) {
        count++;
        for (int j = 0; j < 3; j++) {
            if (table[(satr / 3) * 3 + i][(sotoon / 3) * 3 + j] == nom)
                return false;
        }
    }

    return true;
}

//gharar dadan aadad dar jadval

bool move( int satr, int sotoon) {
    //barresi kamel shodan jadval
    if (sotoon == 9) {
        if (satr == 8) {
            return true;
        } else {
            satr++;
            sotoon = 0;
        }
    }
    //barresi por naboodan khane jadval
     count++;
    if (table[satr][sotoon] > 0) {

        return move( satr, sotoon + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
             count++;
            if (checker( satr, sotoon, i)) {
                table[satr][sotoon] = i;
                 count++;
                if (move( satr, sotoon + 1)) {
                    return true;
                }
                table[satr][sotoon] = 0;
            }
        }
        return false;
    }
}

//function shorooe
void start(){
    move(0,0);
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
