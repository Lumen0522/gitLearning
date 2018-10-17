#ifndef STONE_H
#define STONE_H

#include <QRect>
#include <QPainter>

class Stone
{
public:
    Stone();
    ~Stone();

    enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};


    int _row;       //行信息
    int _col;       //列信息
    TYPE _type;     //棋子类型(将士象车马炮兵)
    bool _dead;     //如果棋子被杀则为true
    bool _red;      //如果棋子为红方则为true
    int _id;        //整形id号

    QString name(); //返回棋子类型
    void init(int id);//初始化棋子的信息，不是绘制
    void rotate();  //棋盘旋转
};

#endif // STONE_H
