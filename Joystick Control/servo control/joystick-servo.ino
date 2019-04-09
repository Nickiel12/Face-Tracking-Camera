#include <Servo.h>

Servo servoTilt//, servoTurn;

int tiltMicroSeconds = 1100;
int maxTilt = 1700;
//int turnMicroSeconds = 1100;
//int maxTurn = ??;

void setup() {
    Serial.begin(19200);
    servoTilt.attach(9);
    servoTilt.writeMicroseconds(microSeconds);
}

/*
void turn(bool right, int speed){
    if (right == true){
        if (turnMicroSeconds + speed < maxTurn){
            turnMicroSeconds += speed;
        }else{
            return
        }
    } else {
        if (turnMicroSeconds - speed > 0) {
            turnMicroSeconds -= speed;
        }else {
            return
        }
    }
}
*/

void tilt(bool down, int speed){
    if (down == true){
        if (tiltMicroSeconds + speed < maxTilt){
            tiltMicroSeconds += speed;
        }else{
            return;
        }
    } else {
        if (tiltMicroSeconds - speed > 0) {
            tiltMicroSeconds -= speed;
        }else {
            return;
        }
    }
}

void loop() {
        while(Serial.available() > 0) {
        // read the incoming byte:
        char axes = Serial.read();
        if (axes == 'z'){
            return;
        } else if (axes == 'Z') {
            return;
        }

        switch(axes){
            case 'a': //level 1 up
                tilt(true,1);
                break;
            case 'b': //level2 up
                tilt(true,2);
                break;
            case 'c': //level3 up
                tilt(true,3);
                break;
            case 'd': //level4 up
                tilt(true,4);
                break;
            case 'e': //level5 up
                tilt(true,5);
                break;
            case 'f': //level6 up
                tilt(true,6);
                break;
            case 'g': //level 7 up
                tilt(true,7);
                break;
            case 'h': //level 8 up
                tilt(true,8);
                break;
            case 'i': //level 9 up
                tilt(true,9);
                break;
            case 'j': //level 10 up
                tilt(true,10);
                break;
            
            case 'k': //level 1 down
                tilt(false, 1);
                break;
            case 'l': //level 2 down
                tilt(false, 2);
                break;
            case 'm': //level 3 down
                tilt(false, 3);
                break;
            case 'n': //level 4 down
                tilt(false, 4);
                break;
            case 'o': //level 5 down
                tilt(false, 5);
                break;
            case 'p': //level 6 down
                tilt(false, 6);
                break;
            case 'q': //level 7 down
                tilt(false, 7);
                break;
            case 'r': //level 8 down
                tilt(false, 8);
                break;
            case 's': //level 9 down
                tilt(false, 9);
                break;
            case 't': //level 10 down
                tilt(false, 10);
                break;

            /*
            case 'A': //level 1 right
                turn(true, 1);
                break;
            case 'B': //level 2 right
                turn(true, 2);
                break;
            case 'C': //level 3 right
                turn(true, 3);
                break;
            case 'D': //level 4 right
                turn(true, 4);
                break;
            case 'E': //level 5 right
                turn(true, 5);
                break;
            case 'F': //level 6 right
                turn(true, 6);
                break;
            case 'G': //level 7 righ
                turn(true, 7);
                break;
            case 'H': //level 8 right
                turn(true, 8);
                break;
            case 'I': //level 9 right
                turn(true, 9);
                break;
            case 'J': //level 10 right
                turn(true, 10);
                break;
            
            case 'K': //level 1 left
                turn(false, 1);
                break;
            case 'L': //level 2 left
                turn(false, 2);
                break;
            case 'M': //level 3 left
                turn(false, 3);
                break;
            case 'N': //level 4 left
                turn(false, 4);
                break;
            case 'O': //level 5 left
                turn(false, 5);
                break;
            case 'P': //level 6 left
                turn(false, 6);
                break;
            case 'Q': //level 7 left
                turn(false, 7);
                break;
            case 'R': //level 8 left 
                turn(false, 8);
                break;
            case 'S': //level 9 left
                turn(false, 9);
                break;
            case 'T': //level 10 left
                turn(false, 10);
                break;
            */
        }
    }
    servoTilt.writeMicroseconds(tiltMicroSeconds);
    //servoTurn.writeMicroseconds(turnMicroSeconds);
}