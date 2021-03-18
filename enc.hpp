#include <Arduino.h>
class enc{
    int pinA, pinB, Switch;
    double counter = 0; 
    int aState;
    int aLastState;  
public:
    enc(int pinA,int pinB,signed int Switch=-1);
    int Listen(int delay_ms=1);  
};