#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(39);

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor color;
	for (int x = 0; x <= ofGetWidth(); x += 120) {

		for (int y = 0; y <= ofGetHeight(); y += 120) {

			for (int size = 0; size <= 60; size += 10) {

				ofPushMatrix();
				ofTranslate(x, y);

				auto noise_value = ofNoise(x * 0.00035, y * 0.00035, size * 0.001 + ofGetFrameNum() * 0.01);
				ofRotateZ(ofMap(noise_value, 0, 1, -360, 360));
				ofRotateX(ofMap(noise_value, 0, 1, -360, 360));
				ofRotateY(ofMap(noise_value, 0, 1, -360, 360));

				color.setHsb(ofMap(x, 0, ofGetWindowWidth(), 0, 255), 100, 255);

				ofNoFill();
				ofSetColor(color, ofMap(size, 0, 150, 255, 0));
				ofDrawBox(size);

				ofPopMatrix();
			}
		}
	}

	/*
	int start = 30;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}