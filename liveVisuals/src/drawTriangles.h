#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawTriangles : public ofBaseApp {
    
public:
    drawTriangles();
    ~drawTriangles();
    void setup();
    void draw(int moveL, int moveR);
    void update();
    
    //triangles//
    bool triOn;
    float rotateTri, rotateTri2;
    ofPoint triPos;
};

