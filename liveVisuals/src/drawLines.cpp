
#include "drawLines.h"

drawLines::drawLines() {
    
    
}

drawLines::~drawLines() {
    
}

void drawLines::setup() {
    
    //Line bool
    linesOn = false;
    lineLeft.set(0, 0);
    lineRight.set(1, 0);
}

void drawLines::update() {
    
    lineLeft.x -= 0.10f;
    lineRight.x += 0.10f;
    counterLine += 0.003f;
    sineWave = 50 * sin(counterLine);
}

void drawLines::draw(float counterLine) {
    
    for(int i = 0; i < 200; i++){
        ofPushMatrix();
        ofSetColor(ofColor::magenta, i + 50);
        ofRotateY(i * PI / 2 + sineWave);
        ofRotateX(i * PI + sineWave);
        ofTranslate(ofGetWidth() / 2, ofGetHeight() - 200);
        ofScale(counterLine, counterLine);
        ofLine(lineLeft.x, lineLeft.y - i, lineRight.x, lineRight.y + i);
        ofPopMatrix();
    }
}

void drawLines::reset() {

    lineLeft.x = 0.0;
    lineRight.x = 0.0;
    counterLine = 0.0;

}
