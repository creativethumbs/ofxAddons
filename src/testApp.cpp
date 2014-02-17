//file handling code from here: http://forum.openframeworks.cc/t/simply-loading-a-text-file/833

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofAddListener(recognizer.speechRecognizedEvent, this, &testApp::speechRecognized);
    recognizer.initRecognizer();
    
    string poem = "frost-devotion.txt";
    
    //poems are loaded here
    recognizer.loadDictionaryFromFile(poem);
    
    ifstream fin; //declare a file stream
    fin.open( ofToDataPath(poem).c_str() );
    
    while(fin != NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        getline(fin, str); //get a line from the file, put it in the string
        dictionary.push_back(str); //push the string onto a vector of strings
    }
    
    recognizer.startListening();
    
    ofSetVerticalSync(true);
	ofBackgroundHex(0x0);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	box2d.init();
	box2d.setGravity(0, -0.7);
	box2d.createBounds();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
    
    myfont.loadFont("IQFONT-bold.otf", 30);
	
}

//--------------------------------------------------------------
void testApp::speechRecognized(string & wordRecognized)
{
    cout << wordRecognized << endl;
    for (int i = 0; i < dictionary.size(); i++) {
        if(wordRecognized == dictionary[i])
        {
            wordlist.push_back(wordRecognized);
            float r = 10;
            circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
            circles.back().get()->setPhysics(10.0, 0.45, 0.9);
            circles.back().get()->setup(box2d.getWorld(), ofRandom(300, 400), 300, r);
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<wordlist.size(); i++) {
		ofSetHexColor(0xffffff);
        myfont.drawString(wordlist[i], circles[i].get()->getPosition()[0],circles[i].get()->getPosition()[1]);
	}
    
	// draw the ground
	box2d.drawGround();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
