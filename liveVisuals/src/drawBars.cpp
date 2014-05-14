
#include "drawBars.h"


drawBars::drawBars() {
    
    
}

drawBars::~drawBars() {
    
}

void drawBars::setup() {
    //Bars bool
    barsOn = false;
    barsMove.set(0, 0);
}

void drawBars::update() {
    
    barsMove.y += 2.0f;
    if (barsMove.y >= ofGetHeight()) {
        barsMove.y *= -2.0f;
    }
    barsCounter += 0.05f;
    barsNoise = 255 * ofNoise(barsCounter); 
}

void drawBars::draw() {
        for (int i = 0; i < ofGetHeight(); i += 20) {
            ofPushMatrix();
            ofSetColor(255);
            ofRotateX(i * PI);
            ofLine(barsMove.x, barsMove.y + i, ofGetWidth(), barsMove.y + i);
            ofSetColor(100, 255, 255, barsNoise);
            ofRect(barsMove.x, barsMove.y + i, ofGetWidth(), 100);
            ofPopMatrix();
        }
}

