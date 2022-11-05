#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

const char* ssid     = "PRUTHVIK_11";
const char* password = "DKMSSD";

int lcdColumns = 16;
int lcdRows = 2;


LiquidCrystal_I2C lcd(0x3F, 16, 2);

WiFiServer server(80);

// Variable to store the HTTP request
String header;

unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

//-------------------------------IR SENOSR------------------------------------

const int IR_SENSOR_UP_1 = 50;     // the number of the pushbutton pin
const int IR_SENSOR_UP_2 = 50;     // the number of the pushbutton pin
const int IR_SENSOR_UP_3 = 50;     // the number of the pushbutton pin

const int IR_SENSOR_DN_1 = 50;     // the number of the pushbutton pin
const int IR_SENSOR_DN_2 = 50;     // the number of the pushbutton pin
const int IR_SENSOR_DN_3 = 50;     // the number of the pushbutton pin

//----------------------------TRAFFIC LIGHT-----------------------------------

const int RED_INDICATOR_1 = 0;     // the number of the pushbutton pin
const int YELLOW_INDICATOR_1 = 2;     // the number of the pushbutton pin
const int GREEN_INDICATOR_1 = 14;     // the number of the pushbutton pin

const int RED_INDICATOR_2 = 12;     // the number of the pushbutton pin
const int YELLOW_INDICATOR_2 = 13;     // the number of the pushbutton pin
const int GREEN_INDICATOR_2 = 15;     // the number of the pushbutton pin

String RED_INDICATOR_VALUE_1;     // the number of the pushbutton pin
String YELLOW_INDICATOR_VALUE_1;     // the number of the pushbutton pin
String GREEN_INDICATOR_VALUE_1;     // the number of the pushbutton pin

String RED_INDICATOR_VALUE_2;     // the number of the pushbutton pin
String YELLOW_INDICATOR_VALUE_2;     // the number of the pushbutton pin
String GREEN_INDICATOR_VALUE_2;     // the number of the pushbutton pin

// ---------------------------EMERGENCY VEHICLE------------------------------- 

 emergency_signal_detect = data.toInt();

//    Serial.print("emergency_signal_detected = ");
//    Serial.println(emergency_signal_detect);

    delay(100);
    check_emergency_signal();


//============================================================================
//-------------------------------STATE----------------------------------------
//============================================================================


//----------------------------TRAFFIC LIGHT-----------------------------------

int RED_INDICATOR_ST_1 = 2;     // the number of the pushbutton pin
int YELLOW_INDICATOR_ST_1 = 2;     // the number of the pushbutton pin
int GREEN_INDICATOR_ST_1 = 2;     // the number of the pushbutton pin

int RED_INDICATOR_ST_2 = 2;     // the number of the pushbutton pin
int YELLOW_INDICATOR_ST_2 = 2;     // the number of the pushbutton pin
int GREEN_INDICATOR_ST_2 = 2;     // the number of the pushbutton pin

//----------------------------IR SENOSR-----------------------------------

int IR_SENSOR_UP_1_ST = 2;     // the number of the pushbutton pin
int IR_SENSOR_UP_2_ST = 2;     // the number of the pushbutton pin
int IR_SENSOR_UP_3_ST = 2;     // the number of the pushbutton pin

int IR_SENSOR_DN_1_ST = 2;     // the number of the pushbutton pin
int IR_SENSOR_DN_2_ST = 2;     // the number of the pushbutton pin
int IR_SENSOR_DN_3_ST = 2;     // the number of the pushbutton pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  //----------------------------TRAFFIC LIGHT-----------------------------------

  pinMode(RED_INDICATOR_1, OUTPUT);
  pinMode(YELLOW_INDICATOR_1, OUTPUT);
  pinMode(GREEN_INDICATOR_1, OUTPUT);

  pinMode(RED_INDICATOR_2, OUTPUT);
  pinMode(YELLOW_INDICATOR_2, OUTPUT);
  pinMode(GREEN_INDICATOR_2, OUTPUT);

  //----------------------------IR SENOSR-------------------------------------

  pinMode(IR_SENSOR_UP_1, INPUT);
  pinMode(IR_SENSOR_UP_2, INPUT);
  pinMode(IR_SENSOR_UP_3, INPUT);

  pinMode(IR_SENSOR_DN_1, INPUT);
  pinMode(IR_SENSOR_DN_2, INPUT);
  pinMode(IR_SENSOR_DN_3, INPUT);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  server.begin();

  lcd.setCursor(0, 0);
  lcd.print("IOT TRAFFICLIGHT");
  lcd.setCursor(1, 1);      
  lcd.print("CONTROL SYSTEM");

}

void sensorLogic() {
  //----------------------------LOGIC 1-------------------------------------

  if ((IR_SENSOR_UP_1_ST == HIGH) && (IR_SENSOR_UP_2_ST == LOW) && (IR_SENSOR_UP_3_ST == LOW))
  {
    digitalWrite(RED_INDICATOR_1, HIGH);
    digitalWrite(YELLOW_INDICATOR_1, LOW);
    digitalWrite(GREEN_INDICATOR_1, LOW);

    RED_INDICATOR_VALUE_1 = "visible";
    YELLOW_INDICATOR_VALUE_1 = "none";
    GREEN_INDICATOR_VALUE_1 = "none";

  }
  else if ((IR_SENSOR_UP_1_ST == LOW) && (IR_SENSOR_UP_2_ST == HIGH) && (IR_SENSOR_UP_3_ST == LOW)) {
    digitalWrite(RED_INDICATOR_1, LOW);
    digitalWrite(YELLOW_INDICATOR_1, HIGH);
    digitalWrite(GREEN_INDICATOR_1, LOW);

    RED_INDICATOR_VALUE_1 = "none";
    YELLOW_INDICATOR_VALUE_1 = "visible";
    GREEN_INDICATOR_VALUE_1 = "none";

  }
  else if ((IR_SENSOR_UP_1_ST == LOW) && (IR_SENSOR_UP_2_ST == LOW) && (IR_SENSOR_UP_3_ST == HIGH)) {
    digitalWrite(RED_INDICATOR_1, LOW);
    digitalWrite(YELLOW_INDICATOR_1, LOW);
    digitalWrite(GREEN_INDICATOR_1, HIGH);

    RED_INDICATOR_VALUE_1 = "none";
    YELLOW_INDICATOR_VALUE_1 = "none";
    GREEN_INDICATOR_VALUE_1 = "visible";

  }
  else {
    digitalWrite(RED_INDICATOR_1, HIGH);
    digitalWrite(YELLOW_INDICATOR_1, LOW);
    digitalWrite(GREEN_INDICATOR_1, LOW);

    RED_INDICATOR_VALUE_1 = "visible";
    YELLOW_INDICATOR_VALUE_1 = "none";
    GREEN_INDICATOR_VALUE_1 = "none";
    delay(3000);
    digitalWrite(RED_INDICATOR_1, LOW);
    digitalWrite(YELLOW_INDICATOR_1, HIGH);
    digitalWrite(GREEN_INDICATOR_1, LOW);

    RED_INDICATOR_VALUE_1 = "none";
    YELLOW_INDICATOR_VALUE_1 = "visible";
    GREEN_INDICATOR_VALUE_1 = "none";
    delay(3000);

    digitalWrite(RED_INDICATOR_1, LOW);
    digitalWrite(YELLOW_INDICATOR_1, LOW);
    digitalWrite(GREEN_INDICATOR_1, HIGH);

    RED_INDICATOR_VALUE_1 = "none";
    YELLOW_INDICATOR_VALUE_1 = "none";
    GREEN_INDICATOR_VALUE_1 = "visible";
    delay(3000);

  }

  //----------------------------LOGIC 2-------------------------------------

  if ((IR_SENSOR_DN_1_ST == HIGH) && (IR_SENSOR_DN_2_ST == LOW) && (IR_SENSOR_DN_3_ST == LOW))
  {
    digitalWrite(RED_INDICATOR_2, HIGH);
    digitalWrite(YELLOW_INDICATOR_2, LOW);
    digitalWrite(GREEN_INDICATOR_2, LOW);

    RED_INDICATOR_VALUE_2 = "visible";
    YELLOW_INDICATOR_VALUE_2 = "none";
    GREEN_INDICATOR_VALUE_2 = "none";

  }
  else if ((IR_SENSOR_DN_1_ST == LOW) && (IR_SENSOR_DN_2_ST == HIGH) && (IR_SENSOR_DN_3_ST == LOW)) {
    digitalWrite(RED_INDICATOR_2, LOW);
    digitalWrite(YELLOW_INDICATOR_2, HIGH);
    digitalWrite(GREEN_INDICATOR_2, LOW);

    RED_INDICATOR_VALUE_2 = "none";
    YELLOW_INDICATOR_VALUE_2 = "visible";
    GREEN_INDICATOR_VALUE_2 = "none";

  }
  else if ((IR_SENSOR_DN_1_ST == LOW) && (IR_SENSOR_DN_2_ST == LOW) && (IR_SENSOR_DN_3_ST == HIGH)) {
    digitalWrite(RED_INDICATOR_2, LOW);
    digitalWrite(YELLOW_INDICATOR_2, LOW);
    digitalWrite(GREEN_INDICATOR_2, HIGH);

    RED_INDICATOR_VALUE_2 = "none";
    YELLOW_INDICATOR_VALUE_2 = "none";
    GREEN_INDICATOR_VALUE_2 = "visible";

  }
  else
  {
    digitalWrite(RED_INDICATOR_2, HIGH);
    digitalWrite(YELLOW_INDICATOR_2, LOW);
    digitalWrite(GREEN_INDICATOR_2, LOW);

    RED_INDICATOR_VALUE_2 = "visible";
    YELLOW_INDICATOR_VALUE_2 = "none";
    GREEN_INDICATOR_VALUE_2 = "none";
    delay(3000);
    digitalWrite(RED_INDICATOR_2, LOW);
    digitalWrite(YELLOW_INDICATOR_2, HIGH);
    digitalWrite(GREEN_INDICATOR_2, LOW);

    RED_INDICATOR_VALUE_2 = "none";
    YELLOW_INDICATOR_VALUE_2 = "visible";
    GREEN_INDICATOR_VALUE_2 = "none";
    delay(3000);
    digitalWrite(RED_INDICATOR_2, LOW);
    digitalWrite(YELLOW_INDICATOR_2, LOW);
    digitalWrite(GREEN_INDICATOR_2, HIGH);

    RED_INDICATOR_VALUE_2 = "none";
    YELLOW_INDICATOR_VALUE_2 = "none";
    GREEN_INDICATOR_VALUE_2 = "visible";
    delay(3000);

  }

}


void check_emergency_signal()
{
  if (emergency_signal_detect >= 0)
  {
    if (emergency_signal_detect == 1)
    {
      sig1_green_delay = 40;
      signal_count = 43;
      //Serial.println("signal 1 emergency");
    }
    else if (emergency_signal_detect == 2)
    {
      sig2_green_delay = 40;
      signal_count = 10;
      //Serial.println("signal 2 emergency");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  //----------------------------IR SENOSR-------------------------------------

  IR_SENSOR_UP_1_ST = digitalRead(IR_SENSOR_UP_1);
  IR_SENSOR_UP_2_ST = digitalRead(IR_SENSOR_UP_2);
  IR_SENSOR_UP_3_ST = digitalRead(IR_SENSOR_UP_3);

  IR_SENSOR_DN_1_ST = digitalRead(IR_SENSOR_DN_1);
  IR_SENSOR_DN_2_ST = digitalRead(IR_SENSOR_DN_2);
  IR_SENSOR_DN_3_ST = digitalRead(IR_SENSOR_DN_3);

  sensorLogic();

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page
            client.println("<!DOCTYPE html> <html> <head> <title></title> </head> <body> <h1>IOT Traffic Signal Monitoring System</h1><hr /> <br /><br /><br /><br /><br /><br /> <div id=\"div_refresh\">");
            client.println("<img style=\"width: 600px; visibility: ;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/4-way.png\">");
            client.println("<img style=\"width: 40px; display:");
            client.println("; bottom: 420px; right: 190px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/green-vertical.png\">");
            client.println("<img style=\"width: 40px; display:");
            client.println(GREEN_INDICATOR_VALUE_1);
            client.println("; bottom: 420px; right: 190px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/red-vertical.png\">");
            client.println("<img style=\"width: 40px; display:");
            client.println(RED_INDICATOR_VALUE_1);
            client.println("; bottom: 420px; right: 190px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/red-vertical.png\">");
            client.println("<img style=\"width: 40px; display:");
            client.println(YELLOW_INDICATOR_VALUE_1);
            client.println("; bottom: 420px; right: 190px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/yellow-vertical.png\">");
            client.println("<!-- horizontal -->");
            client.println("<img style=\"width: 110px; display:");
            client.println(GREEN_INDICATOR_VALUE_2);
            client.println("; bottom: 140px; right: 320px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/green-horizontal.png\">");
            client.println("<img style=\"width: 110px; display:");
            client.println(RED_INDICATOR_VALUE_2);
            client.println("; bottom: 140px; right: 320px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/red-horizontal.png\">");
            client.println("<img style=\"width: 110px; display:");
            client.println(YELLOW_INDICATOR_VALUE_2);
            client.println("; bottom: 140px; right: 320px; position: relative;\" src=\"https://listone.000webhostapp.com/emergency%20vehicle%20project/yellow-horizontal.png\">");
            client.println("<p id=\"demo\"></p> </div>");
            client.println("<script src=\"http://code.jquery.com/jquery-latest.js\"></script> <script> $(document).ready(function(){ $(\"#div_refresh\").load(\"index.html\"); setInterval(function() { $(\"#div_refresh\").load(\"index.html\"); }, 1000); }); document.getElementById(\"demo\").innerHTML = Math.floor(Math.random() * 100); </script> </body> </html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}



 emergency_signal_detect = data.toInt();
//    Serial.print("emergency_signal_detected = ");
//    Serial.println(emergency_signal_detect);
    delay(100);
    check_emergency_signal();



void check_emergency_signal()
{
  if (emergency_signal_detect >= 0)
  {
    if (emergency_signal_detect == 1)
    {
      sig1_green_delay = 40;
      signal_count = 43;
      //Serial.println("signal 1 emergency");
    }
    else if (emergency_signal_detect == 2)
    {
      sig2_green_delay = 40;
      signal_count = 10;
      //Serial.println("signal 2 emergency");
}
}