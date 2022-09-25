class Enigma{
    Plugboard plugboard;
    Rotor leftRotor;
    Rotor middleRotor;
    Rotor rightRotor;
    Reflector reflector;
    bool shouldDoubleStep=false;
    void updateRotors();

    public:
    std::string encrypt(std::string plaintext);
    void setRotors(int left, int middle, int right);
    void setPlugs(char socket1, char socket2);
    void setWindows(int left, int middle, int right);
    void setReflector(char whichReflector);
    void setRingSettings(int left, int middle, int right);
};
std::string Enigma::encrypt(std::string plaintext){
    std::string ciphertext = plaintext;
    for(int i = 0; i< ciphertext.length(); i++){
        updateRotors();
        ciphertext[i] = plugboard.encrypt(ciphertext[i]);
        ciphertext[i] = rightRotor.rencrypt(ciphertext[i]);
        ciphertext[i] = middleRotor.rencrypt(ciphertext[i]);
        ciphertext[i] = leftRotor.rencrypt(ciphertext[i]);
        ciphertext[i] = reflector.encrypt(ciphertext[i]);
        ciphertext[i] = leftRotor.lencrypt(ciphertext[i]);
        ciphertext[i] = middleRotor.lencrypt(ciphertext[i]);
        ciphertext[i] = rightRotor.lencrypt(ciphertext[i]);
        ciphertext[i] = plugboard.encrypt(ciphertext[i]);
    }
    return ciphertext;
}
void Enigma::setRotors(int left, int middle, int right){
    leftRotor.setRotor(left);
    middleRotor.setRotor(middle);
    rightRotor.setRotor(right);
}
void Enigma::setPlugs(char char1, char char2){
    plugboard.setPlugs(char1,char2);
}
void Enigma::setWindows(int left, int middle, int right){
    (leftRotor.offset+=left)%26;
    (middleRotor.offset+=middle)%26;
    (rightRotor.offset+=right)%26;
}
void Enigma::setRingSettings(int left, int middle, int right){
    (leftRotor.offset-=left);
    while (leftRotor.offset<0){leftRotor.offset+=26;}
    leftRotor.offset = leftRotor.offset%26;
    (middleRotor.offset-=middle);
    while (middleRotor.offset<0){middleRotor.offset+=26;}
    middleRotor.offset = middleRotor.offset%26;
    (rightRotor.offset-=right);
    while (rightRotor.offset<0){rightRotor.offset+=26;}
    rightRotor.offset = rightRotor.offset%26;
    //wow.
    (leftRotor.notch-=left);
    while (leftRotor.notch<0){leftRotor.notch=26;}
    leftRotor.notch = leftRotor.notch%26;
    (middleRotor.notch-=middle);
    while (middleRotor.notch<0){middleRotor.notch+=26;}
    middleRotor.notch = middleRotor.notch%26;
    (rightRotor.notch-=right);
    while (rightRotor.notch<0){rightRotor.notch+=26;}
    rightRotor.notch = rightRotor.notch%26;
}
void Enigma::setReflector(char whichReflector){reflector.setReflector(whichReflector);}
void Enigma::updateRotors(){//need to implement double step...
    rightRotor.offset++;
    if(rightRotor.offset==rightRotor.notch + 1){//check if notch passed before overflow correct
        middleRotor.offset++;
        if (middleRotor.offset==middleRotor.notch){
            shouldDoubleStep=true;
        }
        if(middleRotor.offset==middleRotor.notch + 1){
            leftRotor.offset++;
        }
    }
    else if(shouldDoubleStep==true){
        middleRotor.offset++;
        if(middleRotor.offset==middleRotor.notch + 1){
            leftRotor.offset++;
        }
        shouldDoubleStep=false;
    }
    if(rightRotor.offset>25){rightRotor.offset = rightRotor.offset - 26;}
    if(middleRotor.offset>25){middleRotor.offset = middleRotor.offset - 26;}
    if(leftRotor.offset>25){leftRotor.offset = leftRotor.offset - 26;}
}