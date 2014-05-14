#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////
//M.Romeo 2014

#include "ofMain.h"

class drawAlphas : public ofBaseApp {
    
public:
    drawAlphas();
    ~drawAlphas();
    void setup();
    void draw(int posX, int posY, float alpha);
    void update();
    
    ofPoint alphasSetPos;
    float sineAlphas, counterAlphas;
    float sineAlphas2, counterAlphas2;
    bool alphasOn;
    
};

