#ifndef WALL_H
#define WALL_H

// The implementation of the Wall class
// A temporary barrier

class Wall {

    public:

        // Constructor
        Wall(int x, int y, int duration)
            : _x(x), _y(y), _duration(duration){}

        // Getter methods
        int getX()const {return _x;}
        int getY() const {return _y;}
        int getDuration() const {return _duration; }
        
        // Update method - reduce wall lifespan by one
        void update(){
            _duration--;
        }

    private:
        int _x=0;
        int _y=0;
        int _duration=0;
};

#endif