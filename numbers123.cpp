#include "numbers123.h"
#include <QDebug>
#include <QThread>
#include <QSound>
#include <QMediaPlayer>

Numbers123::Numbers123(QWidget *parent) : QWidget(parent){
    layoutV = new QVBoxLayout;
    layoutH = new QHBoxLayout;
    layoutH1 = new QHBoxLayout;
    layoutH->setSpacing(10);

    txtAsk = new QLabel;
    myAnsver = new MyQLineEdit;
    for (int i = 0; i < 10; i++){
        txt[i] = new QLabel("  ");  txt[i]->setMargin(3);
    }

    for (int i = 0; i < 10; i++)// -1 mean orange color after initialization
        marks.push_back(-1);
    initGeometry();
}

void Numbers123::initGeometry(){
    //qDebug() << "in initGeometry";

    // -1- dealing with checkbox
    chBox = new QCheckBox;
    chBox->setChecked(false);
    chBox->setMinimumSize(250, 39);
    chBox->setMaximumSize(250, 39);
    chBox->setStyleSheet("QCheckBox::indicator { width:20px; height: 20px; }");
    chBox->setText(QObject::tr("Extra level"));// harder level
    QFont fAsk( "Arial", 20);
    chBox->setFont(fAsk);
    layoutH1->addWidget(chBox);
    layoutV->addLayout(layoutH1);
    connect(chBox, SIGNAL(stateChanged(int)), this, SLOT(handleCheckBox(int)));
    // -1- end

    // -2- dealing with mark's rectangles
    runRectangles();
    for (int i = 0; i < 10; i++)
        layoutH->addWidget(txt[i]);

    layoutV->addLayout(layoutH);
    // -2- end

    // -3- dealing with question line
    getRundomNumbers();
    runQuestionLine();

    layoutV->addWidget(txtAsk);
    // -3- end

    // -4- dealing with edit Widget
    myAnsver->setAlignment( Qt::AlignHCenter);
    myAnsver->setFont(fAsk);
    myAnsver->setStyleSheet("QLineEdit { background-color : lightgreen;}");
    myAnsver->setText("?");
    myAnsver->setMaxLength(1);

    connect(myAnsver, SIGNAL(textChanged(const QString)), this,
            SLOT(handleModifiedAnsver(const QString)));
    layoutV->addWidget(myAnsver);
    // -4- end

    this->setLayout(layoutV);
}

void Numbers123::runQuestionLine(){//qDebug() << "runQuestionLine";
    QString * midtext = new QString;
    if (number == 1)
        midtext->append(QObject::tr(" simple numbers here "));
    else if (number == 2)
        midtext->append(QObject::tr(" decades here "));
    else if (number == 3)
        midtext->append(QObject::tr(" hundreds here "));

    QString * smallNumber = new QString;
    QString * longNumber = new QString;
    longNumber->append(QString::number(n1));
    longNumber->append(QString::number(n2));
    longNumber->append(QString::number(n3));
    longNumber->append(QString::number(hund));
    longNumber->append(QString::number(dec));
    longNumber->append(QString::number(sn));
    smallNumber->append(QString::number(hund));
    smallNumber->append(QString::number(dec));
    smallNumber->append(QString::number(sn));

    txtAsk->setText(QObject::tr("How many"));
    txtAsk->setMargin(3);
    txtAsk->setStyleSheet("QLabel { background-color : lightblue;}");
    QFont fAsk( "Arial", 20);
    txtAsk->setFont(fAsk);
    txtAsk->setAlignment(Qt::AlignCenter);

    if (chBox->isChecked())
        txtAsk->setText(txtAsk->text() + midtext + longNumber);
    else
        txtAsk->setText(txtAsk->text() + midtext + smallNumber);
}

void Numbers123::getRundomNumbers(){
    number = Random(1, 3); // 1 - simple number; 2 - decades; 3 - hundreds
    sn = Random(0, 9); // simple numbers
    QThread::msleep(58);
    dec = Random(0, 9); // decades
    QThread::msleep(11);
    hund = Random(0, 9); // hundreds
    QThread::msleep(21);
    n1 = Random(0, 9);// hundred thousands
    QThread::msleep(58);
    n2 = Random(0, 9);//  decades thousands
    QThread::msleep(31);
    n3 = Random(0, 9);// thousands
}

int Numbers123::Random(int min, int max)
{	srand( (int)clock() +  time( NULL ) % CLOCKS_PER_SEC);
    return min + rand() % (max - min + 1);
}

void Numbers123::runRectangles(){
    for (int i = 0; i < 10; i++){
        if (marks[i] == -1)             // initial color
            txt[i]->setStyleSheet("QLabel { background-color : orange;}");
        else if (marks[i] == 0)         // wrong ansver
            txt[i]->setStyleSheet("QLabel { background-color : red;}");
        else if (marks[i] == 1)         // right ansver
            txt[i]->setStyleSheet("QLabel { background-color : lightgreen;}");
        else
            qDebug() << "You in trouble: method runGeometry()";
    }
}

void Numbers123::handleCheckBox(int state){
    //qDebug() << "SLOT state " << state;
    runQuestionLine();
}

void Numbers123::handleModifiedAnsver(const QString &text){
    //qDebug() << "Modified text " << text;
    int numberToCompare;
    if (number == 1)
        numberToCompare = sn;
    else if (number == 2)
        numberToCompare = dec;
    else if (number == 3)
        numberToCompare = hund;

    if (text.toInt() == numberToCompare){
        marks.push_front(1);
        QSound::play(":/bell1.wav");
    }
    else {
        marks.push_front(0);
        QSound::play(":/bell2.wav");
    }

    runRectangles();
    getRundomNumbers();
    runQuestionLine();

    chBox->setFocus();
    myAnsver->setFocus();
}

