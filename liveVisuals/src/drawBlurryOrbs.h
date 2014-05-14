
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawBlurryOrbs : public ofBaseApp {
    
public:
    drawBlurryOrbs();
    ~drawBlurryOrbs();
    void setup();
    void drawOrbs(ofColor insideOrb, ofVec2f scale, float alpha);
    void update();
    
    //blurry orbs//
    float rotateOrbs, alphaOrbs, alphaOrbsTrigger;
    bool orbsOn;

};