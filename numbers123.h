#ifndef NUMBERS123_H
#define NUMBERS123_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include "myqlineedit.h"

class Numbers123 : public QWidget{
    Q_OBJECT
public:
    explicit Numbers123(QWidget *parent = nullptr);

private:
    void initGeometry();// in this func initialization of interface
    QVBoxLayout * layoutV;
    QHBoxLayout * layoutH;
    QHBoxLayout * layoutH1;
    QCheckBox * chBox;

    void runQuestionLine();// implement question line "How many ..."
    QLabel * txtAsk;

    void getRundomNumbers();// get numbers for question number
    int Random(int, int);
    int sn, dec, hund; // hund - hundreds; dec - decades; sn - just numbers
    int number, n1, n2, n3;// n1, n2, n3 - bigger numbers; number - mean range
                            // to solve
    void runRectangles();// color rectangle indicate about ansvers
    QLabel * txt[10];// all ansvers keeps in marks, but I use onle first 10 to
    QVector<int> marks;// show in rectangles

    MyQLineEdit * myAnsver;// field for ansver. It always in selected mode

signals:

public slots:
    void handleCheckBox(int);// hundle check/uncheck CheckBox to show longer/shorter number
    void handleModifiedAnsver(const QString &text);// hundle provided answer
};

#endif // NUMBERS123_H
