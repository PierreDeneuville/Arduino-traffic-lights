/* 
 *  RGB Led Trafic light, manually controlled with a Joystick
 *  Hold Joystick button pressed to activate police car light
 */

//Define pins for R,G,and B
int RED = 11;
int GREEN = 10;
int BLUE = 6;

// Define pins for joystick switch + X and Y directions
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output


void setup() 
{
 // Set joystick switch pin to INPUT_PULLUP
  pinMode(SW_pin, INPUT_PULLUP);
 
 // Set RGB pins to OUTPUT
  pinMode(RED, OUTPUT);  
  pinMode(GREEN, OUTPUT);  
  pinMode(BLUE, OUTPUT);  
}

// Write R,G,and B values
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(RED, red_light_value);
  analogWrite(GREEN, green_light_value);
  analogWrite(BLUE, blue_light_value);
}

void loop() 
{ 

//Greenlight for LEFT
if (analogRead(X_pin) < 500)
  {
    RGB_color(0, 100, 0);  
    }

//Redlight for RIGHT
if (analogRead(X_pin) > 600)
  {
    RGB_color(100, 0, 0);
    }

//Orange light for UP
if (analogRead(Y_pin) < 500)
  {
    RGB_color(150, 50, 0);
    }

//Switch off light for DOWN
if (analogRead(Y_pin) > 600)
  {
    RGB_color(0, 0, 0);
    }

// "Police car" while joystick switch is pressed
if (digitalRead(SW_pin) == LOW)
  {
    RGB_color (36, 117, 125);
      delay(300);  
    RGB_color (150, 0, 0);
      delay(300);
  }

/*
 * "By default" light when Joystick in MIDDLE position
if (analogRead(X_pin) > 500 && analogRead(X_pin) < 600)
  {
    RGB_color(10, 10, 10);  
    }
*/
}
