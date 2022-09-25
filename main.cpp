#include<iostream>
#include<string>
#include"Rotor.h"
#include"Plugboard.h"
#include"Reflector.h"
#include"Enigma.h"

//Must always setRotors and setReflector.
//Must set rotors BEFORE windows else we will get windows 000
//setWindows is optional. not calling this gives us windows 000
//setRingSettings is optional. should be called after setWindows for now
//setPlugs is optional
//setRotors,setWindows,setRingSettings is left to right
int main(){ 
    Enigma enigma;
    enigma.setRotors(2,4,5); //left to right 
    enigma.setWindows(1,11,0); //B L A = 1,11,0
    enigma.setRingSettings(1,20,11); //2 21 12 => 1 20 11
    enigma.setReflector('B');
    enigma.setPlugs('a','v');
    enigma.setPlugs('b','s');
    enigma.setPlugs('c','g');
    enigma.setPlugs('d','l');
    enigma.setPlugs('f','u');
    enigma.setPlugs('h','z');
    enigma.setPlugs('i','n');
    enigma.setPlugs('k','m');
    enigma.setPlugs('o','w');
    enigma.setPlugs('r','x');
    std::string plaintext = "edpudnrgyszrcxnuytpomrmbofktbzrezkmlxlvefgueysiozveqmikubpmmylklttdeismdicagykuactcdomohwxmuuiaubstslrnbzszwnrfxwfyssxjzvijhidishprklkayupadtxqspinqmatlpifsvkdasctacdpbopvhjk";
    
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::string ciphertext = enigma.encrypt(plaintext);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
}

/*
TODO:
-refactor Enigma into M3 and M4
--refactor Rotor into M3Rotor and M4Rotor.
-Add -many- error messages and catches.
*/