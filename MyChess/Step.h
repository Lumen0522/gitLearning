#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step : public QObject
{
    Q_OBJECT
public:
    explicit Step(QObject *parent = 0);
    ~Step();

    int _moveid;    //将移动的棋子id号
    int _killid;    //将被吃掉的棋子id号
    int _rowFrom;   //moveid的行
    int _colFrom;   //moveid的列
    int _rowTo;     //killid的行
    int _colTo;     //killid的列

signals:

public slots:
};

#endif // STEP_H
