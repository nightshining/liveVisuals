
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawNumbers : public ofBaseApp {
    
public:
    drawNumbers();
    ~drawNumbers();
    void setup();
    void draw();
    void update();
    void changeDirection(int key);
    
    vector<float>counter;
    bool numbersOn;
    
};