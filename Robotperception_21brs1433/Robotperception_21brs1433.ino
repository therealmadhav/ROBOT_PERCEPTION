#include<SoftwareSerial.h>

// Define 2 channel relay pins

const int light = 13; // Relay pin 1 (IN1)

const int fan = 9;   // Relay pin 2 (IN2)

const int door = 11;

/* Create object named bt of the class SoftwareSerial */

SoftwareSerial bt(2, 3); /* (Rx,Tx) */

void setup() {

  bt.begin(9600); /* Define baud rate for software serial communication */

  Serial.begin(9600); /* Define baud rate for serial communication */

  // Set Relay pins as OUTPUT

   pinMode(light, OUTPUT);

   pinMode(fan, OUTPUT);

   pinMode(door, OUTPUT);

   digitalWrite(light, HIGH);

   digitalWrite(fan, HIGH);

   digitalWrite(door, HIGH);

}

void loop() {

  String data="";

  char ch;

  while (bt.available()) /* If data is available on serial port */

    { ch = bt.read(); /* Print character received on to the serial monitor */

      data=data+ch;

    }

   Serial.print(data);

  // Control the devices using voice command

    if ((data == "turn on light"))               // turn on Device1

    {

      digitalWrite(light, LOW);

      delay(200);

      data="";

    }

    else if ((data == "turn off light"))          // turn off Device1

    {

      digitalWrite(light, HIGH);

      delay(200);

      

    }  

    // Control the devices using voice command

    else if ((data == "turn on fan")) // turn on Device2

    {

      digitalWrite(fan, LOW);

      delay(200);

    }

    else if ((data== "turn off fan")) // turn off Device2

    {

      digitalWrite(fan, HIGH);

      delay(200);

    }

    else if ((data == "door lock")) // turn on Device2

    {

      digitalWrite(door, HIGH);

      delay(200);

    }---

    else if ((data== "door unlock")) // turn off Device2

    {

      digitalWrite(door, LOW);

      delay(200);

    }

}