#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        //Constructors
        Point();
        Point(int, int);

        //Accessors
        int getX() const;
        int getY() const;

        // Mutators
        void setX(const int);
        void setY(const int);

};


#endif // POINT_H_INCLUDED