#include "drawAlphas.h"


drawAlphas::drawAlphas() {
    
    
}

drawAlphas::~drawAlphas() {
    
}

void drawAlphas::setup() {
    
    //Alphas bool
    alphasSetPos.set(0, 0);
    alphasOn = false;
    
}

void drawAlphas::update() {
    
    counterAlphas += 0.05f;
    counterAlphas2 += 0.01f;
    
    sineAlphas = 240 * sin(counterAlphas);
    sineAlphas2 = 240 * sin(counterAlphas2);
}

void drawAlphas::draw(int posX, int posY, float alpha) {
    
    ofSetCircleResolution(100);
    
    ofSetColor(ofColor::white, alpha);
    ofFill();
    ofPushMatrix();
    ofRect(posX, posY, ofGetWidth(), ofGetHeight() / 2);
    ofPopMatrix();
    
    for (int i = 0; i < ofGetWidth(); i += 200) {
        ofSetColor(ofColor::white, -alpha);
        ofFill();
        ofPushMatrix();
        ofCircle(posX + i, posY + 150, 50);
        ofPopMatrix();
    }
    
}
