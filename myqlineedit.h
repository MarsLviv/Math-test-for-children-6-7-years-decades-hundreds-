#ifndef MYQLINEEDIT_H
#define MYQLINEEDIT_H
#include <QLineEdit>

/* need this class to get text in edit field selected after click in */

class MyQLineEdit : public QLineEdit{
    Q_OBJECT
public:
    MyQLineEdit(QWidget *parent = nullptr);
    virtual ~MyQLineEdit(){}
protected:
    void focusInEvent(QFocusEvent *e);
    void mousePressEvent(QMouseEvent *me);
    bool _selectOnMousePress;
};

#endif // MYQLINEEDIT_H
