#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

using namespace std;

class Apple{
    private:
        Segment appSeg
        bool beenHit = false;
        int R, G, B;
    public:
        /// Constructors ///
        Apple();
        Apple(Point);

        /// Accessors ///
        Segment getSegment();
        bool hasBeenHit();

        /// Mutators ///
        void setSegment(Segment);
        void setPoint(Point);
        void changeColor(int, int, int);

};

#endif // APPLE_H_INCLUDED
