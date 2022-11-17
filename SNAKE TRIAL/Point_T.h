#ifndef POINT_T_H_INCLUDED
#define POINT_T_H_INCLUDED

struct Point_T
{
public:
    Point_T(int x, int y);
    void setX(int input);
    void setY(int input);
    int getX();
    int getY();
private:
    int x;
    int y;
};

#endif // POINT_T_H_INCLUDED
