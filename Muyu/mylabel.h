#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = 0);
    int num=0;

    void changeText();
signals:

public slots:
};

#endif // MYLABEL_H
