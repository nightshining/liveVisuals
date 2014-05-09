#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFullscreen(true);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFrameRate(60);
    
    //Key Counter
    counter = 0;
    
    //Cube bool
    cubeOn = false;
    
    //Line bool
    linesOn = false;
    lineLeft.set(0, 0);
    lineRight.set(1, 0);
    
    //Pent bool
    pentOn = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (cubeOn == true) {
    rotate += 0.53f;
    alphaTrigger -= 5;
    }
    
    if (linesOn == true) {
    lineLeft.x -= 0.10f;
    lineRight.x += 0.10f;
    counterLine += 0.003f;
    sineWave = 50 * sin(counterLine);
    }
 
    if (pentOn == true) {
    rotatePent += 0.75f;
    alphaTriggerPent -= 5;
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(cubeOn == true){
    drawCube(alphaTrigger);
    }
    
    if (linesOn == true) {
    drawLines(sineWave);
    }
   
    if (pentOn == true) {
    drawPent(alphaTriggerPent);
    }
    
}

void testApp::drawCube(float alpha) {
    
    for (int i = 0; i < 200; i += 35) {
   
    ofPushMatrix();
    ofSetColor(ofColor::whiteSmoke, 180);
    ofNoFill();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateY(rotate);
    ofDrawBox(0, 0, -1, i + 100, i + 100, i + 100);
    ofSetColor(ofColor::teal, alpha);
    ofFill();
    ofDrawBox(0, 0, -1, i + 50, i + 50, i + 50);
    ofPopMatrix();
        
    }
}

void testApp::drawLines(float counterLine) {
    
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

void testApp::drawPent(float alpha) {
    
    for(int i = 0; i < 200; i+=15){
        
        ofSetCircleResolution(5);

        ofPushMatrix();
        ofSetColor(ofColor::teal, alphaTriggerPent);
        ofFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZ(-rotatePent);
        ofCircle(0, 0, i);
        ofPopMatrix();
        
        ofPushMatrix();
        ofSetColor(ofColor::whiteSmoke, 180);
        ofNoFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZ(rotatePent);
        ofCircle(0, 0, i + 100);
        ofPopMatrix();
    }
    
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

    ///// SIFT THROUGH VISUALS /////
    
    if (key == OF_KEY_UP) {
        counter++;
        //Keep an eye on Key Counter
        cout << "Change Visual: " << counter << endl;
    }
    else if (key == OF_KEY_DOWN){
        counter--;
        //Keep an eye on Key Counter
        cout << "Change Visual: " << counter << endl;
    }
    
    //Turn CUBE on
    counter == 1 ? cubeOn = true : cubeOn = false;
    
    //CUBE ACTIONS//
    if (key == 'c') {
        alphaTrigger = 150;
    }
    
    //Turn LINES on
    counter == 2 ? linesOn = true : linesOn = false;

    //LINES ACTIONS
    if (counter == 2) {
        lineLeft.x = 0.0;
        lineRight.x = 0.0;
        counterLine = 0.0;
    } 
    
    //Turn LINES on
    counter == 3 ? pentOn = true : pentOn = false;
    
    //PENT ACTIONS
    if (key == 'p') {
    alphaTriggerPent = 250;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

  
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

   
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
