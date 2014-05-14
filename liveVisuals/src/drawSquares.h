#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawSquares : public ofBaseApp {
    
public:
    drawSquares();
    ~drawSquares();
    void setup();
    void draw();
    void update();
    
    //squares//
    float rotateSquares;
    int alphaSquares;
    bool squaresOn;
    
};

