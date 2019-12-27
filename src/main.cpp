#include "ofMain.h"
#include "ofApp.h"
#include "ofMidiModule.h"
#include "ofSoundModule.h"
#include "ofColorModule.h"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
  //	ofSetupOpenGL(920, 940, OF_WINDOW);			// <-------- setup the GL context
  //  ofRunApp(new ofMidiModule());
  
  ofGLFWWindowSettings settings;
  
  settings.setSize(920, 740);
  settings.setPosition(glm::vec2(20,20));
  settings.resizable = false;
  shared_ptr<ofAppBaseWindow> ofMidiWindow = ofCreateWindow(settings);
  shared_ptr<ofMidiModule> MidiModule(new ofMidiModule);
  ofRunApp(ofMidiWindow, MidiModule);
  
  settings.setSize(700, 400);
  settings.setPosition(glm::vec2(960,20));
  settings.resizable = false;
  shared_ptr<ofAppBaseWindow> ofSoundWindow = ofCreateWindow(settings);
  shared_ptr<ofSoundModule> SoundModule(new ofSoundModule);
  ofRunApp(ofSoundWindow, SoundModule);
  
  settings.setSize(920, 220);
  settings.setPosition(glm::vec2(20,820));
  settings.resizable = false;
  shared_ptr<ofAppBaseWindow> ofColorWindow = ofCreateWindow(settings);
  shared_ptr<ofColorModule> ColorModule(new ofColorModule);
  ofRunApp(ofColorWindow, ColorModule);
  
  settings.setSize(700, 500);
  settings.setPosition(glm::vec2(960,480));
//  settings.setGLVersion(3,2);
  shared_ptr<ofAppBaseWindow> ofAppWindow = ofCreateWindow(settings);
  shared_ptr<ofApp> MainApp(new ofApp);
  MainApp->midi = MidiModule;
  MainApp->sound = SoundModule;
  MainApp->color = ColorModule;
  ofRunApp(ofAppWindow, MainApp);
  
  if(false) {
    settings.windowMode = OF_FULLSCREEN;
//    settings.setGLVersion(3,2);
    shared_ptr<ofAppBaseWindow> ofFullAppWindow = ofCreateWindow(settings);
    shared_ptr<ofApp> FullApp(new ofApp);
    FullApp->midi = MidiModule;
    FullApp->sound = SoundModule;
    FullApp->color = ColorModule;
    ofRunApp(ofFullAppWindow, FullApp);
  }
  
  ofRunMainLoop();
}
