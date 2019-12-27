#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//  shader.load("shader/shader");
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
//  shader.begin();
//  shader.setUniform1f("u_time", ofGetElapsedTimef());
//  shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  
  ofSetColor(color->palette[0]);
  ofDrawCircle(ofGetWidth()*0.5,ofGetHeight()*0.5, midi->knobsONE[0] + sound->centroid * ofGetWidth()*0.45);
//  shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  std::cout << "Letter pressed: " << key << "\n";
  
//  F = 102
  if(key == 102) FULLSCREEN = !FULLSCREEN;
    
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

