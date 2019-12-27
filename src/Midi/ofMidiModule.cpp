#include "ofMidiModule.h"

//   ----------------------------------------------------
void ofMidiModule::setup(){
  ofSetWindowTitle("MIDI Mad Module");
  ofSetLogLevel(OF_LOG_VERBOSE);
  
  midiIn.listInPorts();
  midiIn.openPort(0);
  midiIn.ignoreTypes(false, false, false);
  midiIn.addListener(this);
  midiIn.setVerbose(true);
  
//   ----------------------------------------------------
  ofMidiModule::labelizer();
  
  knobsOne = gui.addGroup("USER - knobs");
  knobsOne->loadTheme("themes/one.json", true);
  knobsOne->setPosition(ofPoint(20,10));
  knobsOneTop = knobsOne->addContainer("Knobs top", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 0; i < 8; i++){
    knobsOneTop->add(knobsONE[i].set(knobsONELabel[i], 0, 0, 100), ofJson({{"type", "circular"},{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}, {"precision", 0}}));
  }
  knobsOneBottom = knobsOne->addContainer("Knobs Bottom", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 8; i < 16; i++){
    knobsOneBottom->add(knobsONE[i].set(knobsONELabel[i], 0, 0, 100), ofJson({{"type", "circular"},{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}, {"precision", 0}}));
  }
  
  padsOne =  gui.addGroup("USER - pads");
  padsOne->loadTheme("themes/one.json", true);
  padsOne->setPosition(knobsOne->getShape().getBottomLeft() + ofPoint(0,2));
  padOneCont = padsOne->addContainer("pads one", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 0; i < 8; i++){
    padOneCont->add<ofxGuiButton>(padsONE[i].set(padsONELabel[i], false), ofJson({{"type", "fullsize"}, {"text-align", "center"}, {"width", PAD_WIDTH}, {"height", PAD_HEIGHT}}));
  }
  
//   ----------------------------------------------------

  knobsTwo = gui.addGroup("FACTORY - knobs");
  knobsTwo->loadTheme("themes/two.json", true);
  knobsTwo->setPosition(padsOne->getShape().getBottomLeft() + ofPoint(0,10));
  knobsTwoTop = knobsTwo->addContainer("Knobs top", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 0; i < 8; i++){
    knobsTwoTop->add(knobsTWO[i].set(knobsTWOLabel[i], 0, 0, 100), ofJson({{"type", "circular"},{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}, {"precision", 0}}));
  }
  knobsTwoBottom = knobsTwo->addContainer("Knobs Bottom", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 8; i < 16; i++){
    knobsTwoBottom->add(knobsTWO[i].set(knobsTWOLabel[i], 0, 0, 100), ofJson({{"type", "circular"},{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}, {"precision", 0}}));
  }
  padsTwo = gui.addGroup("FACTORY - pads");
  padsTwo->loadTheme("themes/two.json", true);
  padsTwo->setPosition(knobsTwo->getShape().getBottomLeft() + ofPoint(0,2));
  padTwoCont = padsTwo->addContainer("Pads bottom", ofJson({{"direction", "horizontal"}}));
  for(unsigned int i = 0; i < 8; i++){
    padTwoCont->add<ofxGuiButton>(padsTWO[i].set(padsTWOLabel[i], false), ofJson({{"type", "fullsize"}, {"text-align", "center"}, {"width", PAD_WIDTH}, {"height", PAD_HEIGHT}}));
  }

//   ----------------------------------------------------
  
  ofBackground(10);
}
//--------------------------------------------------------------
void ofMidiModule::newMidiMessage(ofxMidiMessage &msg) {
  ofLog(OF_LOG_VERBOSE, "midi play : " + msg.getStatusString(msg.status));
  ofLog(OF_LOG_VERBOSE, "midi play : " + ofToString(msg.channel));
  ofLog(OF_LOG_VERBOSE, "midi play on channel:" + ofToString(msg.channel));
  ofLog(OF_LOG_VERBOSE, "midi play control:" + ofToString(msg.control));
  ofLog(OF_LOG_VERBOSE, "midi play pitch:" + ofToString(msg.pitch));
  ofLog(OF_LOG_VERBOSE, "midi play whith value:" + ofToString(msg.value));
  ofLog(OF_LOG_VERBOSE, "-------------------------------------------- \n");
  
  int value = ofMap(msg.value, 0, 127, 0, 100);
  
//  if(msg.status == MIDI_SYSEX) channel != channel;

//  KNOBS mapping
  switch (msg.control) {
    case 21:
      msg.channel == 7 ? knobsONE[0] = value : knobsTWO[0] = value;
      break;
    case 22:
      msg.channel == 7 ? knobsONE[1] = value : knobsTWO[1] = value;
      break;
    case 23:
      msg.channel == 7 ? knobsONE[2] = value : knobsTWO[2] = value;
      break;
    case 24:
      msg.channel == 7 ? knobsONE[3] = value : knobsTWO[3] = value;
      break;
    case 25:
      msg.channel == 7 ? knobsONE[4] = value : knobsTWO[4] = value;
      break;
    case 26:
      msg.channel == 7 ? knobsONE[5] = value : knobsTWO[5] = value;
      break;
    case 27:
      msg.channel == 7 ? knobsONE[6] = value : knobsTWO[6] = value;
      break;
    case 28:
      msg.channel == 7 ? knobsONE[7] = value : knobsTWO[7] = value;
      break;
    case 41:
      msg.channel == 7 ? knobsONE[8] = value : knobsTWO[8] = value;
      break;
    case 42:
      msg.channel == 7 ? knobsONE[9] = value : knobsTWO[9] = value;
      break;
    case 43:
      msg.channel == 7 ? knobsONE[10] = value : knobsTWO[10] = value;
      break;
    case 44:
      msg.channel == 7 ? knobsONE[11] = value : knobsTWO[11] = value;
      break;
    case 45:
      msg.channel == 7 ? knobsONE[12] = value : knobsTWO[12] = value;
      break;
    case 46:
      msg.channel == 7 ? knobsONE[13] = value : knobsTWO[13] = value;
      break;
    case 47:
      msg.channel == 7 ? knobsONE[14] = value : knobsTWO[14] = value;
      break;
    case 48:
      msg.channel == 7 ? knobsONE[15] = value : knobsTWO[15] = value;
      break;
    default:
      break;
  }
  
//  PADS Mapping
  if(!(msg.status == MIDI_NOTE_ON)) return;
  switch (msg.pitch) {
    case 9:
      msg.channel == 7 ? padsONE[0] = !padsONE[0] : padsTWO[0] = !padsTWO[0];
      break;
    case 10:
      msg.channel == 7 ? padsONE[1] = !padsONE[1] : padsTWO[1] = !padsTWO[1];
      break;
    case 11:
      msg.channel == 7 ? padsONE[2] = !padsONE[2] : padsTWO[2] = !padsTWO[2];
      break;
    case 12:
      msg.channel == 7 ? padsONE[3] = !padsONE[3] : padsTWO[3] = !padsTWO[3];
      break;
    case 25:
      msg.channel == 7 ? padsONE[4] = !padsONE[4] : padsTWO[4] = !padsTWO[4];
      break;
    case 26:
      msg.channel == 7 ? padsONE[5] = !padsONE[5] : padsTWO[5] = !padsTWO[5];
      break;
    case 27:
      msg.channel == 7 ? padsONE[6] = !padsONE[6] : padsTWO[6] = !padsTWO[6];
      break;
    case 28:
      msg.channel == 7 ? padsONE[7] = !padsONE[7] : padsTWO[7] = !padsTWO[7];
      break;
    default:
      break;
  }
}
//--------------------------------------------------------------
void ofMidiModule::exit() {
  midiIn.closePort(); midiIn.removeListener(this);
}
