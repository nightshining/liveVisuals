#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawSpirals : public ofBaseApp {
    
public:
    drawSpirals();
    ~drawSpirals();
    void setup();
    void draw();
    void update();
    
    //spiral//
    float counterSpiral, rotateSpiral, sineSpiral;
    bool spiralOn;
};

