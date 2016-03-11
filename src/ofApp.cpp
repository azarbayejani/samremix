#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    x,y = 0;
    velocity.set(1,1);
//    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA); //or GL_RED if you are using the programmable renderer
    shader.load("shaders/shader");
    videos = { "/Users/azar/Downloads/0001 1000-zRvnAgQalZE.mp4", "/Users/azar/Downloads/gffg-TQOzY5tmOMk.mp4" };
    images = {
        "images/16-01_3000_k3.png",
        "/Users/azar/Downloads/09-2_4096_k3.png",
        "/Users/azar/Downloads/output.20160224T225001 2/7_1024_k5.png",
        "images/09-2_4096_k3.png",
        "images/14-02_3000_k3.png",
        "images/14-02_3000_k7.png",
        "images/14-02_3000_k11.png",
        "images/18-01_3000_k3.png",
        "images/18-01_3000_k7.png",

    };
    currVid.load(videos.at(0));
    texture.load(images.at(0));
    currVid.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    currVid.update();
    if (random() < 0.0001) {
        currVid.load(videos.at(rand() % videos.size()));
        currVid.play();
    }
    if (random() < 0.0001) {
        texture.load(images.at(rand() % images.size()));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    
    if (x > ofGetWidth()/2 || x < -ofGetWidth()/2) {
        velocity.x = -velocity.x;
    }
    if (y > ofGetHeight()/2 || y < -ofGetHeight()/2) {
        velocity.y = -velocity.y;
    }

    
    ofPushMatrix();
    ofTranslate(x+=velocity.x,y+=velocity.y);
    texture.draw(-texture.getWidth()/2,-texture.getHeight()/2);
    ofPopMatrix();
    shader.begin();
    currVid.draw(0,0,width,height);
    shader.setUniform1f("threshold", .88);
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == (int) '1') {
        currVid.load(videos.at(rand() % videos.size()));
        currVid.play();
    }
    if (key == (int) '2') {
        texture.load(images.at(rand() % images.size()));
    }
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
