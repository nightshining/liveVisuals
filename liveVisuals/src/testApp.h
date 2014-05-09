#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        
    //cube//
    void drawCube(float alpha);
    float rotate, alphaTrigger;
    bool cubeOn;
    
    //lines//
    void drawLines(float counterLine);
    float counterLine, sineWave;
    ofPoint lineLeft, lineRight;
    bool linesOn;
    
    //pentagram//
    void drawPent(float alpha);
    float rotatePent, alphaTriggerPent;
    bool pentOn;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	//Cycle through visuals
    int counter;
    
    
};
