
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawCube : public ofBaseApp {
    
public:
    drawCube();
    ~drawCube();
    void setup();
    void draw(float alpha);
    void update();
    
    //cube//
    float rotate, alphaTrigger;
    bool cubeOn;
};