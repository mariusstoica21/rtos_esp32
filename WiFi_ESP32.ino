#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif
 
const char* ssid     = "netis";
const char* password = "password";

WiFiServer server(80);

static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;
static TaskHandle_t task_3 = NULL;
static TaskHandle_t task_4 = NULL;

static int ledState = 0;
static String message = "OFF";
static int gasValue = 0;
static int pirStat = 0;
static int action = 0;


const int gasPin = 34;
const int pirPin = 35;                 

void onOffLed(void* parameter)
{

  while(1)
  {
    digitalWrite(LED_BUILTIN,ledState);    
    vTaskSuspend(task_1);
  }
}

void printMessage(void* parameter)
{

  while(1)
  {
      lcd.init();
      lcd.backlight();
      lcd.setCursor(0,0);
      lcd.print(message); 
      vTaskSuspend(task_2);  
  }
}

void readGas(void* parameter)
{

  while(1)
  {
      gasValue = analogRead(gasPin); 
  }
}

void readPir(void* parameter)
{

  while(1)
  {
      pirStat = digitalRead(pirPin);  
  }
}



void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);  
    pinMode(gasPin, INPUT);
    pinMode(pirPin, INPUT); 

    lcd.init();
    lcd.backlight();
    
    delay(10);

    

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

    xTaskCreatePinnedToCore(
      onOffLed,
      "Task 1",
      1024,
      NULL,
      1,
      &task_1,
      app_cpu);

   xTaskCreatePinnedToCore(
      printMessage,
      "Task 2",
      1024,
      NULL,
      1,
      &task_2,
      app_cpu);
    xTaskCreatePinnedToCore(
        readGas,
        "Task 3",
        1024,
        NULL,
        1,
        &task_3,
        app_cpu);

   xTaskCreatePinnedToCore(
        readPir,
        "Task 4",
        1024,
        NULL,
        1,
        &task_4,
        app_cpu);

  vTaskSuspend(task_3);
  vTaskSuspend(task_4);

}

void loop(){
 
  
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor        
        if (c == '\n') 
        {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) 
          {
            
            
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<head><style>body {background-image: url(https://i.postimg.cc/rmPF0wh0/back.jpg);}</style></head>");
            if (action == 0) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/D0rXgbYN/Component-120-1.png\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 1) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/ZKLNvpNB/Component-119-1.png\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 2) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/WbJ2QvN2/Component-122-1.png\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 3) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/CKMdyQrm/Component-124-1.png\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 4) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/Pf0BBvV7/Component-126-1.png\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 5) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/s226B30S/Component-127-1.png\" border=\"0\" alt=\"Logo\"></p>");
            client.print("<br>");
            client.print("<br>");
            client.print("<a href=\"/ON\"><img src=\"https://i.postimg.cc/SxZPyXNC/Component-131-1.png\" border=\"0\" alt=\"Logo\"></a>");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("<img src=\"https://i.postimg.cc/rmWxw5pY/Component-159-1.png\" border=\"0\" alt=\"Logo\">");
            client.print("<br>");
            client.print("<br>");
            client.print("<a href=\"/OFF\"><img src=\"https://i.postimg.cc/g0nTrYn5/Component-134-1.png\" border=\"0\" alt=\"Logo\"></a>");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("<img src=\"https://i.postimg.cc/J05XbmZN/Component-160-1.png\" border=\"0\" alt=\"Logo\">");
            client.print("<br>");
            client.print("<br>");
            client.print("<a href=\"/GAS\"><img src=\"https://i.postimg.cc/3r2YKH49/Component-140-1.png\" border=\"0\" alt=\"Logo\"></a>");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");          
            client.print("<img src=\"https://i.postimg.cc/28mkJnN8/Component-163-1.png\" border=\"0\" alt=\"Logo\">");
            client.print("<br>");
            client.print("<br>");
            client.print("<a href=\"/PIR\"><img src=\"https://i.postimg.cc/G28gxYsr/Component-146-1.png\" border=\"0\" alt=\"Logo\"></a>");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp");
            client.print("&nbsp"); 
            client.print("<img src=\"https://i.postimg.cc/Ss0Y3jGL/Component-162-1.png\" border=\"0\" alt=\"Logo\">");
            client.print("<br>");
            client.print("<br>");
            if (action == 0 || action == 1) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/ZnqcKVWF/led1.jpg\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 2 || action == 3) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/t4xBxn7W/gas.jpg\" border=\"0\" alt=\"Logo\"></p>");
            if (action == 4 || action == 5) client.print("<p style=\"text-align:left;\"><img src=\"https://i.postimg.cc/vmvLrryg/pir.jpg\" border=\"0\" alt=\"Logo\"></p>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } 
          else 
          {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } 
        else if (c != '\r') 
        {  
          // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }      
        // Check to see if the client request was "GET /ON"
        if (currentLine.endsWith("GET /ON")) 
        {
          ledState = 1;
          message = "";
          message = "ON";
          vTaskResume(task_1);
          vTaskResume(task_2);  
          action = 1;
        }
        if (currentLine.endsWith("GET /OFF")) 
        {
          ledState = 0;
          message = "";
          message = "OFF";
          vTaskResume(task_1);
          vTaskResume(task_2);
          action = 0;
        }
        if (currentLine.endsWith("GET /GAS")) 
        {
          vTaskResume(task_3);
          if (gasValue > 4000)
          {
             message = "";
             message = "GAS DETECTED!!!";
             action = 2;
          }
          else
          {
            message = "";
            message = "No gas detected";
            action = 3;
          }
          
          vTaskResume(task_2);      
        }
        if (currentLine.endsWith("GET /PIR")) 
        {
          vTaskResume(task_4);
          if (pirStat == HIGH) 
          {
            message = "";
            message = "MOTION DETECTED!!!";
            action = 4;
          } 
          else 
          {
            message = "";
            message = "No motion";
            action = 5;
          }
          
          vTaskResume(task_2);      
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
