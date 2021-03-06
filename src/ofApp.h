#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    int x,y;
    ofPoint velocity;
    ofVideoPlayer currVid;
    ofImage texture;
    ofFbo fbo;
    ofShader shader;
    std::vector<ofFile> videos;
    std::vector<ofFile> images;
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
