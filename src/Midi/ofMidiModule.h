#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxGuiExtended.h"

class ofMidiModule : public ofBaseApp, public ofxMidiListener{
  
public:
  void setup();
  void exit();
  void labelizer();
  
  ofxMidiIn midiIn;
  void newMidiMessage(ofxMidiMessage& msg);
  
  ofParameter<int> knobsONE[16];
  string knobsONELabel[16];
  ofParameter<int> knobsTWO[16];
  string knobsTWOLabel[16];
  ofParameter<bool> padsONE[8];
  string padsONELabel[8];
  ofParameter<bool> padsTWO[8];
  string padsTWOLabel[8];
  ofParameter<bool> channel;
  ofParameter<bool> arrows[4];
  
  ofxGui gui;
  ofxGuiGroup* knobsOne;
  ofxGuiContainer* knobsOneTop;
  ofxGuiContainer* knobsOneBottom;
  
  ofxGuiGroup* padsOne;
  ofxGuiContainer* padOneCont;
  
  ofxGuiGroup* knobsTwo;
  ofxGuiContainer* knobsTwoTop;
  ofxGuiContainer* knobsTwoBottom;
  
  ofxGuiGroup* padsTwo;
  ofxGuiContainer* padTwoCont;
  
  
  int SLIDER_WIDTH = 100;
  int SLIDER_HEIGHT = 80;
  int PAD_WIDTH = 100;
  int PAD_HEIGHT = 80;
};

