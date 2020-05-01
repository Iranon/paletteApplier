#pragma once

//--------------------------------------------------------------
//Sega Master System palette
std::vector<float> givenPalette = {
    0, 0, 0,
    85, 0, 0,
    170, 0, 0,
    255, 0, 0,
    0, 85, 0,
    85, 85, 0,
    170, 85, 0,
    255, 85, 0,
    0, 170, 0,
    85, 170, 0,
    170, 170, 0,
    255, 170, 0,
    0, 255, 0,
    85, 255, 0,
    170, 255, 0,
    255, 255, 0,
    0, 0, 85,
    85, 0, 85,
    170, 0, 85,
    255, 0, 85,
    0, 85, 85,
    85, 85, 85,
    170, 85, 85,
    255, 85, 85,
    0, 170, 85,
    85, 170, 85,
    170, 170, 85,
    255, 170, 85,
    0, 255, 85,
    85, 255, 85,
    170, 255, 85,
    255, 255, 85,
    0, 0, 170,
    85, 0, 170,
    170, 0, 170,
    255, 0, 170,
    0, 85, 170,
    85, 85, 170,
    170, 85, 170,
    255, 85, 170,
    0, 170, 170,
    85, 170, 170,
    170, 170, 170,
    255, 170, 170,
    0, 255, 170,
    85, 255, 170,
    170, 255, 170,
    255, 255, 170,
    0, 0, 255,
    85, 0, 255,
    170, 0, 255,
    255, 0, 255,
    0, 85, 255,
    85, 85, 255,
    170, 85, 255,
    255, 85, 255,
    0, 170, 255,
    85, 170, 255,
    170, 170, 255,
    255, 170, 255,
    0, 255, 255,
    85, 255, 255,
    170, 255, 255,
    255, 255, 255
};

//Function that returns the closest color of the palette
ofColor getPaletteColor(float inRed, float inGreen, float inBlue) {

    ofColor colorOut;
    float minDist = 999;

    for(unsigned int i = 0; i < givenPalette.size()-1; i+=3) {  //reading palette vector
        float palRed = givenPalette[i];
        float palGreen = givenPalette[i+1];
        float palBlue = givenPalette[i+2];
        ofColor palCol(palRed, palGreen, palBlue);

        float colorDistance = ofDist(inRed, inGreen, inBlue, palRed, palGreen, palBlue);

        if(colorDistance < minDist){
              colorOut = palCol;
              minDist = colorDistance;
             }
    }

    return colorOut;
}
