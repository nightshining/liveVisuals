#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawDiamonds : public ofBaseApp {
    
public:
    drawDiamonds();
    ~drawDiamonds();
    void setup();
    void draw();
    void update();
    
    //diamonds//
   
    bool diamondsOn;
    float rotateDiamonds, counterDiamonds, sineDiamonds;
    ofPoint diamondsPos;
    
};

