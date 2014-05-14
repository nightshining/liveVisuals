
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawBars : public ofBaseApp {
    
public:
    drawBars();
    ~drawBars();
    void setup();
    void draw();
    void update();
    
    bool barsOn;
    ofPoint barsMove;
    float barsCounter, barsNoise;
};

