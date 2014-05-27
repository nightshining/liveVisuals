
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawTunnel : public ofBaseApp {
    
public:
    drawTunnel();
    ~drawTunnel();
    void setup();
    void draw();
    void update();
    void changeDirection(int key);
    
    float rotateX, rotateY;
    bool tunnelOn;
    bool trails;
    float controlSpeed;
};