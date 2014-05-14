#include "drawSquares.h"


drawSquares::drawSquares() {
    
    
}

drawSquares::~drawSquares() {
    
}

void drawSquares::setup() {
    
    //Squares bool
    squaresOn = false;
    
}

void drawSquares::update() {

    rotateSquares += 0.55f;
    alphaSquares -= 10;

}

void drawSquares::draw() {
    
    for (int i = 0; i < ofGetWidth(); i += 75) {
        for (int j = 0; j < ofGetHeight(); j += 75) {
            ofPushMatrix();
            ofTranslate(i, j);
            ofRotateY(rotateSquares + i * PI);
            ofRotateX(i * PI / rotateSquares);
            ofSetColor(ofColor::salmon, 255);
            ofNoFill();
            ofRect(0,0, 25, 25);
            
            ofSetColor(ofColor::white, alphaSquares);
            ofNoFill();
            ofRect(0,0, 50, 50);
            ofPopMatrix();
        }
    }
    
}



