#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    video.setup(640, 480);
    
    widthSize = ofGetWidth() / size;
    heightSize = ofGetHeight() / size;
    
    gap = (video.getWidth() - video.getHeight())/2;
   
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString((int)ofGetFrameRate()));
    video.update();
    if(video.isFrameNew()){
        p = video.getPixels();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(p.size() > 0){
        int radius = size/2;
        
        for (int y = 0; y < heightSize; y++) {
            for (int x = 0; x < widthSize; x++) {
                float rx = ofGetWidth() - (x*size + radius);//mirror
                float ry = y*size + radius;
                int n = x + y * widthSize;
                int cx = (int)ofMap(x * radius, 0, ofGetWidth()/2, gap, 640 - gap);
                int cy = (int)ofMap(y * radius, 0, ofGetHeight()/2, 0, 480);
                ofSetColor(p.getColor(cx, cy));
                ofDrawCircle(rx, ry, radius);
            }
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
