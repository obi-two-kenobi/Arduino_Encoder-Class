#include "enc.hpp"

enc::enc(int pinA,int pinB,signed int Switch){
    this->pinA = pinA;
    this->pinB = pinB;
    this->Switch = Switch;
    pinMode(pinA,INPUT);
    pinMode(pinB,INPUT);
    if(Switch != -1) pinMode(Switch,INPUT);
    this->aLastState = digitalRead(this->pinA); 
}

int enc::Listen(int delay_ms){
       this->aState = digitalRead(this->pinA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (this->aState != this->aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(this->pinB) != this->aState) { 
       this->counter +=0.5;
     } else {
       this->counter -=0.5;
     }
   } 
   this->aLastState = this->aState; // Updates the previous state of the outputA with the current state
   delay(delay_ms);
   return this->counter;
}