#ifndef STRLABEL_H
#define STRLABEL_H

#include <QLabel>
#include <QString>
#include <QTimer>

class StrLabel : public QLabel
{
    Q_OBJECT
public:
    QString m_Str;

    bool m_Free;

    int m_MoveNum=0;

    QTimer * m_MoveTimer;

    StrLabel(QString str);

    void moving();

    void startMoving();

signals:

    void moveSignal();
public slots:
};

#endif // STRLABEL_H
