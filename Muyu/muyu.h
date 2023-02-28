#ifndef MUYU_H
#define MUYU_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
class Muyu : public QWidget
{
    Q_OBJECT
public:
    QPixmap m_Pixmap;
    int min=93;
    int max=100;
    int num=100;
    bool select=true;
    QTimer * m_Timer;


    explicit Muyu(QWidget *parent = nullptr);


    void choiceAnimation();


signals:
    void sizeSignal();

public slots:
};

#endif // MUYU_H
