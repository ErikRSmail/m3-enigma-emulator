#pragma once

//rotor offsets are managed by enigma rather than the rotors.
class Rotor{
    char leftContacts[26];
    char rightContacts[26];
    public:
    int offset; //0=A, ..., 25=z
    int notch; //0=A, ..., 25=z

    Rotor();
    void setRotor(int whichRotor);
    char rencrypt(char inChar);
    char lencrypt(char inChar);
};
const char ROTORCONTACTS[6][27]={
    {"abcdefghijklmnopqrstuvwxyz"},//right
    {"ekmflgdqvzntowyhxuspaibrcj"},//I
    {"ajdksiruxblhwtmcqgznpyfvoe"},//II
    {"bdfhjlcprtxvznyeiwgakmusqo"},//III
    {"esovpzjayquirhxlnftgkdcmwb"},//IV
    {"vzbrgityupsdnhlxawmjqofeck"}//V
    };
void Rotor::setRotor(int whichRotor){
    offset=0;//Enigma sets the offsets AFTER the rotors are chosen and placed.
    for(int i=0;i<26;i++){
        rightContacts[i]=ROTORCONTACTS[0][i];
        leftContacts[i]=ROTORCONTACTS[whichRotor][i];
    }//yuck
    if(whichRotor==1){notch=16;}
    else if(whichRotor==2){notch=4;}
    else if(whichRotor==3){notch=21;}
    else if(whichRotor==4){notch=9;}
    else if(whichRotor==5){notch=25;}
}
Rotor::Rotor(){
    offset=0;
    for(int i=0;i<26;i++){
        leftContacts[i]=ROTORCONTACTS[0][i];
        rightContacts[i]=ROTORCONTACTS[0][i];
    }
}
//add offset->correct overflow->right to left substitution->subtract offset->correct underflow->done
char Rotor::rencrypt(char inChar){
    char outChar = inChar;
    if(outChar+offset>122){
        outChar = outChar-26;
    }
    outChar = outChar + offset;
    for(int i=0;i<26;i++){//searches left contacts for match and does subsitution
        if(rightContacts[i]==outChar){
            outChar=leftContacts[i];
            i=26;
        }
    }
    outChar = outChar - offset;
    if(outChar<97){//underflow check and correct; a=97 in ASCII
        outChar = outChar + 26;
    }
    return outChar;
}
//add offset->correct overflow->left to right substitution->subtract offset->correct underflow->done
char Rotor::lencrypt(char inChar){
    char outChar = inChar;
    if(outChar+offset>122){//overflow check and correct; z=122 in ASCII
        outChar = outChar-26;
    }
    outChar = outChar+offset;
    for(int i=0;i<26;i++){//searches left contacts for match and does subsitution
        if(leftContacts[i]==outChar){
            outChar=rightContacts[i];
            i=26;
        }
    }
    outChar = outChar - offset;
    if(outChar<97){//underflow check and correct; a=97 in ASCII
        outChar = outChar + 26;
    }
    return outChar;
}