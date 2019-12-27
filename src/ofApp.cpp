#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//  shader.load("shader/shader");
  
  camWidth = ofGetWidth();
  camHeight = ofGetHeight();
  
  vidGrabber.setVerbose(true);
  vidGrabber.setup(camWidth,camHeight);

  ofEnableAlphaBlending();
  
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//  shader.begin();
//  shader.setUniform1f("u_time", ofGetElapsedTimef());
//  shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  
  if(midi->padsONE[0]) ofApp::camera();
  
  if(midi->padsTWO[0]) ofApp::circle();
  ofApp::circle();
//  shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  std::cout << "Letter pressed: " << key << "\n";
  
  if(key == 'f' || key == 'F') FULLSCREEN = !FULLSCREEN;
  if(key == 's' || key == 'S') vidGrabber.videoSettings();
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

