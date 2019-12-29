//
//  ofColorModule.hpp
//  001_midi_module
//
//  Created by nicola bertelloni on 26/12/2019.
//

#ifndef ofColorModule_hpp
#define ofColorModule_hpp

#include "ofMain.h"
#include "ofxGuiExtended.h"
#include <stdio.h>
class ofColorModule : public ofBaseApp {
public:
  void setup();
  void labelizer();
  
  ofxGui gui;
  ofxGuiPanel* colorPanelONE;
  ofxGuiContainer* colorContONE;
  
  ofParameter<ofColor> palette[8];
  string paletteLabel[8];
};

#endif /* ofColorModule_hpp */
