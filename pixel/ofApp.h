#pragma once

#include "ofMain.h"


class pixelObject{
public:
    float spd;
    float degree;
    int timer;
    int resetTime;
    bool reset;
    
    pixelObject():degree(0.),reset(false)
    {
        spd = ofRandom(0.25, 1.2);
        resetTime = ofRandom(0.3, 2.) * 100;
    }
    
    void update(){
        if(!reset){
            degree += spd;
        }else{
            degree -= spd * 4;
            if(degree <= 0) {
                degree = 0;
                timer++;
                if(timer > resetTime){
                    reset = false;
                }
            }
        }
    }
    
    void render(int type, float x, float y, float size, ofColor c){
        ofPushMatrix();
        ofTranslate(x, y);
        ofRotate(degree);
        ofTranslate(-size/2., -size/2.);
        ofSetColor(c);
        switch (type) {
            case 0:
                ofDrawCircle(0, 0, size);
                break;
                
            case 1:
                ofDrawRectangle(0, 0, size, size);
                break;
                
            case 2:
                ofDrawLine(0, 0, size, size);
                break;
                
            case 3:
                ofDrawRectangle(- size, - size, size*2, size*2);
                break;
                
        }
        ofPopMatrix();
    }
    
    void roll(){
        reset = true;
        timer = 0;
    }
    
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<pixelObject>obj;
    
    int widthSize;
    int heightSize;
    int total;
    int gap;
    int size = 20;
    
    ofPixels p;
    ofVideoGrabber video;
    
};
