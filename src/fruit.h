#ifndef FRUIT_H
#define FRUIT_H

#include <string>

// The implemenation of the base "fruit" class

class Fruit {
    public:

        // Constructor
        Fruit(int x, int y, int val, std::string name)
             : _x(x), _y(y), _val(val), _name(name) {}

        // Overloaded constructor
        Fruit(int x, int y, int val, std::string name, std::vector<int> colour)
             : _x(x), _y(y), _val(val), _name(name), _colour(colour) {}

        // Getter methods
        int getX()const {return _x;}
        int getY() const {return _y;}
        int getVal() const {return _val; }
        bool getLengthens() const {return _lengthens; }
        bool getSpeeds() const {return _speeds; }
        std::string getName() const {return _name; }
        std::vector<int> getColour() const {return _colour; }

        // Necessary setter methods
        void setLengthens(bool lengthens){
            _lengthens = lengthens;
        }

        void setSpeeds(bool speeds){
            _speeds = speeds;
        }

        void setColour(std::vector<int> colour){
            _colour = colour;
        }

        void setVal(int val){
            _val = val;
        }

        void setName(std::string name){
            _name = name;
        }

        // Update function - reduces time and score
        void Update () {
            // Lose ten possible points
            setVal(getVal() - 10);
        }

    private:
        int _x=0;
        int _y=0;
        int _val=0; // Score increase
        bool _lengthens=true; // Increases the snake when eaten
        bool _speeds=false; // Increases the snake speed when eaten
        std::vector<int> _colour = {242, 90, 141};
        std::string _name = "Fruit";
};

// Basic points class - increases length

class Strawboring : public Fruit {
    public:
    
        // Constructor
        Strawboring(int x, int y) : Fruit(x, y, 5, "Strawboring") {}
};

// Points class that also increases speed and length

class Raspboost : public Fruit {
    public:

        // Constructor
        Raspboost(int x, int y) : Fruit(x, y, 15, "Raspboost", {199,44,72}) {
            setSpeeds(true);
        }

};

// Points class that does not increase length

class Aprinot : public Fruit {
    public:

        // Constructor
        Aprinot(int x, int y) : Fruit(x, y, 2, "Aprinot", {248, 184, 120}) {
            setLengthens(false);
        }
};

// High points class that decays to nothing - catch quickly

class Clementime : public Fruit {
    public:

        // Constructor
        Clementime(int x, int y, int duration)
                  : Fruit(x, y, duration * 10, "Clementime", {240, 116, 26}) {
            
        }
};

#endif