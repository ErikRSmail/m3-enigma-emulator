class Plugboard{
    char plugs[2][13] ={{0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0}};
    int numPlugs = 0;
    public:
    char encrypt(char inChar);
    void setPlugs(char char1, char char2);
};
void Plugboard::setPlugs(char char1, char char2){
    plugs[0][numPlugs] = char1;
    plugs[1][numPlugs] = char2;
    numPlugs++;
}
char Plugboard::encrypt(char inChar){
    char outChar = inChar;
    for(int i=0;i<13;i++){
        if(plugs[0][i]==inChar){
            outChar=plugs[1][i];
            break;//intended to end the loop when we find a matching plug
        }
        else if(plugs[1][i]==inChar){
            outChar=plugs[0][i];
            break;//intended to end the loop when we find a matching plug
        }
    }
    return outChar;
}