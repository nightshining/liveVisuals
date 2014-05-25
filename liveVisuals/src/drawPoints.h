
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawPoints : public ofBaseApp {
    
public:
    drawPoints();
    ~drawPoints();
    void setup();
    void update();
    void draw();
    
    //points//
    bool pointsOn;
    float pointsGreen, pointsCounter;
    float pointsRed, pointsCounter2;
    ofVideoPlayer vid1;
    ofFbo fbo;
    
};