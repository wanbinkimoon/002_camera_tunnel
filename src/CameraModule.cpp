//
//  CameraModule.cpp
//  002_camera_tunnel
//
//  Created by nicola bertelloni on 27/12/2019.
//
#include "ofApp.h"

#include <stdio.h>
void ofApp::camera(){
  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
  ofSetColor(color->palette[0]);
  vidGrabber.draw(0,0);
}

void ofApp::circle(){
  ofEnableBlendMode(OF_BLENDMODE_SCREEN);
  
  if(midi->padsTWO[1]) ofNoFill();
  
  float circNumb = ofMap(midi->knobsONE[0], 0, 100, 1, 40);
  float maxRadius = midi->knobsONE[1] + sound->centroid * ofGetWidth()*0.45;
  float radiusStep = maxRadius / circNumb;
  
  for(unsigned int i = 0; i < circNumb; i++){
    float radius = radiusStep * i;
    int circAlpha = ofMap(i, 0, circNumb, 10, 120);
    
    ofColor circColor = ofColor(color->palette[1], circAlpha);
    ofSetColor(circColor);
    
    ofDrawCircle(ofGetWidth()*0.5,ofGetHeight()*0.5, radius);
  }
}
