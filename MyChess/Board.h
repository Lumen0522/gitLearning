#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include"Stone.h"
#include<QVector>
#include"Step.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

    /* game data */

    Stone _s[32];           //棋子
    int _r;                 //棋子半径
    QPoint _off;
    bool _bSide;            //换方
    QVector<Step*> _steps;  //走棋信息数组

    /* game status */

    int _selectid;         //被选中棋子
    bool _bRedTurn;        //轮到红方
    void init(bool bRedSide);//初始化棋盘(包括每颗棋子的信息录入，以及旋转)


    /* draw functions */

    void paintEvent(QPaintEvent *);//绘画类
    void drawPlate(QPainter& p);//绘制棋盘Line
    void drawPlace(QPainter& p);//绘制对角线
    void drawInitPosition(QPainter& p);//绘制棋盘上的细节
    void drawInitPosition(QPainter& p, int row, int col);
    void drawStone(QPainter& p);//绘制32颗棋子
    void drawStone(QPainter& p, int id);//重载函数



    /* function for coordinate */

    QPoint center(int row, int col);                     //将棋子的行列坐标转换为像素点坐标
    QPoint center(int id);                              //重载函数
    QPoint topLeft(int row, int col);                   //返回与棋子内切的矩形的左上角像素坐标
    QPoint topLeft(int id);//重载函数
    QRect cell(int row, int col);                       //返回由棋子确定的矩形
    QRect cell(int id);
    bool getClickRowCol(QPoint pt, int& row, int& col);  //判断鼠标点击处是否有棋子


    /* help function */

    QString name(int id);//返回棋子名称
    bool red(int id);
    bool sameColor(int id1, int id2);
    int getStoneId(int row, int col);
    void killStone(int id);
    void reliveStone(int id);
    void moveStone(int moveid, int row, int col);
    bool isDead(int id);


    /* move stone */

    void mouseReleaseEvent(QMouseEvent *);          //鼠标释放事件
    void click(QPoint pt);                          //对鼠标点击进行判断，并调用重载函数
    virtual void click(int id, int row, int col);   //虚函数，进行选中或者移动操作
    void trySelectStone(int id);                    //对_selectid 进行修改
    void tryMoveStone(int killid, int row, int col);//判断能否移动，并尝试移动
    void moveStone(int moveid, int killid, int row, int col);//移动棋子
    void saveStep(int moveid, int killid, int row, int col, QVector<Step *> &steps);//对移动吃子情况进行记录
    void backOne();                                 //悔棋函数
    void back(Step* step);
    virtual void back();

     /* rule */

     bool canMove(int moveid, int killid, int row, int col);          //判断是否可以移动
     bool canMoveChe(int moveid, int killid, int row, int col);
     bool canMoveMa(int moveid, int killid, int row, int col);
     bool canMovePao(int moveid, int killid, int row, int col);
     bool canMoveBing(int moveid, int killid, int row, int col);
     bool canMoveJiang(int moveid, int killid, int row, int col);
     bool canMoveShi(int moveid, int killid, int row, int col);
     bool canMoveXiang(int moveid, int killid, int row, int col);
     bool canSelect(int id);

     /* rule helper */

     int getStoneCountAtLine(int row1, int col1, int row2, int col2); //判断处于同一条直线上的两棋盘位置之间有几颗棋子
     int relation(int row1, int col1, int row, int col);              //返回两棋子之间位置关系值
     bool isBottomSide(int id);                                       //判断换方是否是红方

signals:

public slots:
      void slotBack();
};

#endif // BOARD_H
