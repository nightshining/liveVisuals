
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawLines : public ofBaseApp {
    
public:
    drawLines();
    ~drawLines();
    void setup();
    void draw(float counterLine);
    void update();
    void reset();
    
    //lines//
    float counterLine, sineWave;
    ofPoint lineLeft, lineRight;
    bool linesOn;
    
};