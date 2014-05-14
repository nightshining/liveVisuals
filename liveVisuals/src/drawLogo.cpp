
#include "drawLogo.h"

drawLogo::drawLogo() {
    

}

drawLogo::~drawLogo() {
    
}

void drawLogo::setup() {
    
    //Logo imd and bool
    img.loadImage("logo.jpg");
    logoOn = false;
    
}

void drawLogo::update() {
    
    logoAlpha -= 3;

}

void drawLogo::draw() {
    
        ofPushMatrix();
        ofSetColor(255, 255, 255, logoAlpha);
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        img.setAnchorPoint(ofGetWidth() / 2 - 300, ofGetHeight() / 2 - 100);
        img.draw(0, 0, 600, 500);
        ofPopMatrix();
    }

