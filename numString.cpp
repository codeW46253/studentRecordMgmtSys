/**
 * ------------------------------------------------------------------------------------------------------------------------------
 * 
 * Description:
 * 
 * This code provide functionality to work between string and int/double/float.
 * This code gives users to check a character whether it is a number or an alphabet.
 * This code also gives user to check whether the string can be convert into an
 * integer or a double with floating point.
 * 
 * Programer : Zul Iskandar bin Zainorhan
 * Date      : 20th November 2023
 * ------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <math.h>

// Check whether the character is an alphabet 
bool isAlpha(char character) {
    if (!((65 <= (int)character && (int)character <= 90) || (97 <= (int)character && (int)character <= 122))) {
        return false;
    }
    return true;
}

// Check wheteher the character is a number
bool isNumber(char character) {
    if (!( 48 <= (int)character && (int)character <=  57)) {
        return false;
    }
    return true;
}

// Check whether the character is a point
bool isPoint(char character) {
    if ((int)character == 46) return true;
    return false;
}

// Check whether the string contain an alphabet
bool hasNumber(std::string strIn) {
    int numberOfNumber = 0;
    for (int charIndex = 0; charIndex < (int)strIn.length(); charIndex++) {
        if (isNumber(strIn[charIndex])) numberOfNumber++;
    }
    if (numberOfNumber >= 1) return true;
    return false;
}

// Check whether the string contain alphabet
bool hasAlpha(std::string strIn) {
    int numberOfAlpha = 0;
    for (int charIndex = 0; charIndex < (int)strIn.length(); charIndex++) {
        if (isAlpha(strIn[charIndex])) numberOfAlpha++;
    }
    if (numberOfAlpha >= 1) return true;
    return false;
}

// Check whether the string contain a point/full-stop mark
bool hasPoint(std::string strIn) {
    int numberOfPoint = 0;
    for (int charIndex = 0; charIndex < (int)strIn.length(); charIndex++) {
        if (isPoint(strIn[charIndex])) numberOfPoint++;
    }
    if (numberOfPoint >= 1) return true;
    return false;
}

// Check whether the string contain multiple point/full-stop mark
bool hasMultiplePoint(std::string strIn) {
    int numberOfPoint = 0;
    for (int charIndex = 0; charIndex < (int)strIn.length(); charIndex++) {
        if (isPoint(strIn[charIndex])) numberOfPoint++;
    }
    if (numberOfPoint >= 2) return true;
    return false;
}

// Check whether the string can be an integer
bool canBeInt(std::string strIn) {
    if (hasNumber(strIn) && !(hasAlpha(strIn) || hasPoint(strIn))) return true;
    return false;
}

// Check whether the string can be a floating number[double]
bool canBeDouble(std::string strIn) {
    if ((hasNumber(strIn) && hasPoint(strIn)) && !(hasMultiplePoint(strIn) || hasAlpha(strIn))) return true;
    return false;
}

// Convert string to integer
int strToInt(std::string strIn) {
    int strNumber = 0;
    for (int charIndex = 0; charIndex < (int)strIn.length(); charIndex++) {
        int numberPlace = (int)strIn.length() - (charIndex + 1);
        if (strIn[charIndex] == '0') strNumber += (0 * pow(10, numberPlace));
        if (strIn[charIndex] == '1') strNumber += (1 * pow(10, numberPlace));
        if (strIn[charIndex] == '2') strNumber += (2 * pow(10, numberPlace));
        if (strIn[charIndex] == '3') strNumber += (3 * pow(10, numberPlace));
        if (strIn[charIndex] == '4') strNumber += (4 * pow(10, numberPlace));
        if (strIn[charIndex] == '5') strNumber += (5 * pow(10, numberPlace));
        if (strIn[charIndex] == '6') strNumber += (6 * pow(10, numberPlace));
        if (strIn[charIndex] == '7') strNumber += (7 * pow(10, numberPlace));
        if (strIn[charIndex] == '8') strNumber += (8 * pow(10, numberPlace));
        if (strIn[charIndex] == '9') strNumber += (9 * pow(10, numberPlace));
        
    }

    return strNumber;
}

// Convert string to floating point[double]
double strToDouble(std::string strIn) {
    int numLength = (int)strIn.length();
    double lpoint = 0;
    double rpoint = 0;
    double strDouble = 0.00;

    int pointIndex = 0;
    // find point index
    int rIndex = -1;
    bool pointed = false;
    for (int charIndex = 0; charIndex < numLength; charIndex++) {
        if (!pointed) {
            int numberPlace = numLength - (charIndex + 1);
            if (strIn[charIndex] == '0') lpoint += (0 * pow(10, numberPlace));
            if (strIn[charIndex] == '1') lpoint += (1 * pow(10, numberPlace));
            if (strIn[charIndex] == '2') lpoint += (2 * pow(10, numberPlace));
            if (strIn[charIndex] == '3') lpoint += (3 * pow(10, numberPlace));
            if (strIn[charIndex] == '4') lpoint += (4 * pow(10, numberPlace));
            if (strIn[charIndex] == '5') lpoint += (5 * pow(10, numberPlace));
            if (strIn[charIndex] == '6') lpoint += (6 * pow(10, numberPlace));
            if (strIn[charIndex] == '7') lpoint += (7 * pow(10, numberPlace));
            if (strIn[charIndex] == '8') lpoint += (8 * pow(10, numberPlace));
            if (strIn[charIndex] == '9') lpoint += (9 * pow(10, numberPlace));
            if (strIn[charIndex] == '.') {
                pointed = true;
                pointIndex = charIndex;
                lpoint /= pow(10, pointIndex + (numLength - 4));
            }
        }
        if (pointed) {
            rIndex += 1;
            int numberPlace = numLength - (charIndex + 1);
            if (strIn[charIndex] == '0') rpoint += (0 * pow(10, numberPlace));
            if (strIn[charIndex] == '1') rpoint += (1 * pow(10, numberPlace));
            if (strIn[charIndex] == '2') rpoint += (2 * pow(10, numberPlace));
            if (strIn[charIndex] == '3') rpoint += (3 * pow(10, numberPlace));
            if (strIn[charIndex] == '4') rpoint += (4 * pow(10, numberPlace));
            if (strIn[charIndex] == '5') rpoint += (5 * pow(10, numberPlace));
            if (strIn[charIndex] == '6') rpoint += (6 * pow(10, numberPlace));
            if (strIn[charIndex] == '7') rpoint += (7 * pow(10, numberPlace));
            if (strIn[charIndex] == '8') rpoint += (8 * pow(10, numberPlace));
            if (strIn[charIndex] == '9') rpoint += (9 * pow(10, numberPlace));
        }
    }
    strDouble =  lpoint + (rpoint / pow(10, rIndex));

    return strDouble;
}

