#ifndef POINT_T_H_INCLUDED
#define POINT_T_H_INCLUDED

struct Point_T
{
public:
    Point_T(int x, int y);
    Point_T();
    void setX(int input);
    void setY(int input);
    int getX() const;
    int getY() const;
    Point_T operator=(const Point_T& other);
private:
    int x;
    int y;
};

#endif // POINT_T_H_INCLUDED
