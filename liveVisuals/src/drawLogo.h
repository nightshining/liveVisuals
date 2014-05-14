
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawLogo : public ofBaseApp {
    
public:
    drawLogo();
    ~drawLogo();
    void setup();
    void draw();
    void update();

    ofImage img;
    bool logoOn;
    int logoAlpha;

};