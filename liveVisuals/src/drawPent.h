
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawPent : public ofBaseApp {
    
public:
    drawPent();
    ~drawPent();
    void setup();
    void draw(float alpha);
    void update();
    void reset();
    
    //pentagram//
    float rotatePent, alphaTriggerPent;
    bool pentOn;
};