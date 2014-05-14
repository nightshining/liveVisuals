#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawSpheres : public ofBaseApp {
    
public:
    drawSpheres();
    ~drawSpheres();
    void setup();
    void draw(ofColor c1, int size);
    void update();
    
    //sphere//
    float rotateSphere, noise, sphereNoise;
    ofPoint spherePos;
    bool sphereOn;
};

