#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawCircles : public ofBaseApp {
    
public:
    drawCircles();
    ~drawCircles();
    void setup();
    void draw();
    void update();
    
    //circles//
    void drawCir();
    int cirAlpha, cirRotate;
    bool cirOn;
   
};

