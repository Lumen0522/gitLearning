#ifndef SINGLEGAME_H
#define SINGLEGAME_H
#include"Board.h"

class SingleGame:public Board
{
    Q_OBJECT
public:
    explicit SingleGame(QWidget *parent = 0);
    ~SingleGame();
    int _level; //记录博弈算法的层次深度
    void back();
    virtual void click(int id,int row,int col);//在SingleGame子类中重载click函数

    Step* getBestMove();                       //函数返回当前最佳操作
    void getAllPossibleMove(QVector<Step*>& steps);//利用一个数组保存所有可行策略
    int getMinScore(int level, int curMin);        //返回执行两步后每个分支得分最小值中的最大值
    int getMaxScore(int level, int curMax);        //返回执行两步后每个分支得分最大值中的最小值
    int score();                                   //计算当前局面分
    void fakeMove(Step* step);                     //由killStone和moveStone组成
    void unfakeMove(Step* step);                   //将fakeMove的棋子移动回去
signals:

public slots:// 槽函数
    void computerMove();
};

#endif // SINGLEGAME_H
