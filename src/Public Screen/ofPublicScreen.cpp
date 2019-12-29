//
//  ofPublicScreen.cpp
//  002_camera_tunnel
//
//  Created by nicola bertelloni on 30/12/2019.
//

#include "ofPublicScreen.hpp"

void ofPublicScreen::setup(){
  ofSetDataPathRoot("../Resources/data/");
  ofSetWindowTitle("PUBLIC MONITOR");
  fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA );
  fbo.begin();
  ofClear(0,0,0,255);
  fbo.end();
};

void ofPublicScreen::update(){
  fbo.begin();
  app->draw();
  fbo.end();
};

void ofPublicScreen::draw(){
   fbo.draw(0, 0);
}
void ofPublicScreen::keyPressed(int key){
    if(key == 'f' || key == 'F') {
      ofToggleFullscreen();
      fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA );
    };
};
