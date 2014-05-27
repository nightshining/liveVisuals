
#include "drawNumbers.h"

drawNumbers::drawNumbers() {
    
    
}

drawNumbers::~drawNumbers() {
    
}

void drawNumbers::setup() {
    
    counter.resize(100);
    for (int i = 0; i < counter.size(); i++) {
        counter[i] = ofRandom(0.0, 50.0);
    }
   
}

void drawNumbers::update() {
    
    for (int i = 0; i < counter.size(); i++) {
        counter[i] += 0.03;
    }
    
    
}

void drawNumbers::draw() {
    
    for (int i = 0; i < ofGetWidth(); i += 100) {
        for (int j = 0; j < ofGetHeight(); j += 100) {
                ofSetColor(ofColor::lightPink);
            ofDrawBitmapString("null: " + ofToString(counter[i]), i, j); 
            }
    }
   
    
  
}

void drawNumbers::changeDirection( int key ) {
    
  
    
}


