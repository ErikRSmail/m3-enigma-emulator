#pragma once

class Reflector{
    char contacts[2][13];
    public:

    Reflector();
    void setReflector(char whichReflector);
    char encrypt(char inChar);
};
const char REFLECTORCONTACTS[4][14] = {
        {"abcdefgijkmtv"},{"yruhqslpxnozw"},//B Reflector
        {"abcdeghklmnqs"},{"fvpjioyrzxwtu"} //C Reflector
};
Reflector::Reflector(){
    for(int i=0;i<2;i++){
        for(int j=0;j<13;j++){
            contacts[i][j]=REFLECTORCONTACTS[i][j];
        }
    }
}
char Reflector::encrypt(char inChar){
    char outChar;
    for(int i=0;i<13;i++){
        if(inChar==contacts[0][i]){
            outChar = contacts[1][i];
        }
        else if(inChar==contacts[1][i]){
            outChar=contacts[0][i];
        }
    }
    return outChar;
}
void Reflector::setReflector(char whichReflector){
    if(whichReflector== 'B'){
        for(int i=0;i<2;i++){
            for(int j=0;j<13;j++){
                contacts[i][j]=REFLECTORCONTACTS[i][j];
            }
        }
    }
    else if(whichReflector== 'C'){
        for(int i=0;i<2;i++){
            for(int j=0;j<13;j++){
                contacts[i][j]=REFLECTORCONTACTS[i+2][j];
            }
        }
    }
}