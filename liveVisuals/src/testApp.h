#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    //logo
    void drawLogo();
    ofImage img;
    bool logoOn;
    int logoAlpha;
        
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
    
    //blurry orbs//
    void drawBlurryOrbs(ofColor insideOrb, ofVec2f scale, float alpha);
    float rotateOrbs, alphaOrbs, alphaOrbsTrigger;
    bool orbsOn;
    
    //points//
    void drawPoints();
    bool pointsOn;
    float pointsGreen, pointsCounter;
    float pointsRed, pointsCounter2;
    ofVideoPlayer vid1;
    
    //bars//
    void drawBars();
    bool barsOn;
    ofPoint barsMove;
    float barsCounter, barsNoise;
    
    //spiral//
    void drawSpiral();
    float counterSpiral, rotateSpiral, sineSpiral; 
    bool spiralOn;
    
    //triangles//
    void drawTri(int moveL, int moveR);
    bool triOn;
    float rotateTri, rotateTri2;
    ofPoint triPos;
    
    //circles//
    void drawCir();
    int cirAlpha, cirRotate;
    bool cirOn;
    
    //squares//
    void drawSquares();
    float rotateSquares;
    int alphaSquares;
    bool squaresOn;
    
    //alphas//
    void drawAlphas(int posX, int posY, float alpha);
    ofPoint alphasSetPos;
    float sineAlphas, counterAlphas;
    float sineAlphas2, counterAlphas2;
    bool alphasOn;
    
    //sphere//
    void drawSphere(ofColor c1, int size);
    float rotateSphere, noise, sphereNoise;
    ofPoint spherePos;
    bool sphereOn;
    
    //diamonds//
    void drawDiamonds();
    bool diamondsOn;
    float rotateDiamonds, counterDiamonds, sineDiamonds;
    ofPoint diamondsPos;
    
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
    ofEasyCam cam;
};
