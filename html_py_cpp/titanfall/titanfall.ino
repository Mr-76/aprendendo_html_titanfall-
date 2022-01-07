#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "";  // Enter SSID here
const char* password = "";  //Enter Password here

ESP8266WebServer server(80);

uint8_t LED1pin = D7;
bool LED1status = LOW;

uint8_t LED2pin = D6;
bool LED2status = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  
  WiFi.begin(ssid, password);

  
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  delay(5000);

}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(){
  String ptr = "<!DOCTYPE html>\n\n<html lang = 'pt-br'>\n\t<head>\n\t\t<meta charset = 'UTF-8'>\n\t\t<title>BT-7274</title>\n\t\t<link rel='stylesheet' type='text/css' href='./style.css'>\n\t<head/>\n\n\n\t<body>\n\t\t<header>\n\t\t\t<h1 class = 'titulo_principal'>TITANFALL</h1>\n\n\n\t\t</header>\n\t\t<div style = 'background-color: black'class = 'presentation'>\n\t\t\t<h2 style = 'color:green;'><center><strong>STAND BY FOR TITANFALL</strong></center> </h2>\n\t\t\t<img id = 'titanfall'src = https://i2.wp.com/manualdosgames.com/wp-content/uploads/2017/06/titanfall_2.jpg'>\n\t\t\t<p style = 'background-color:black;color:white;border-bottom-width: 22px;border-bottom-style: solid;'><strong><em>BT-7274 is  Vanguard-class Titan</em></strong>, the first to be designed by the Militia.\n\t\t\tWith Vanguards, The Militia no longer needed to steal IMC Titans off the production li\n\t\t\tnes to supply their Pilots. A Vanguard-class Titan must obey three protocols:</p>\n\t\t</div>\n\t\t<div>\n\t\t\t<p style = 'background-color: red;'id= 'protocolos';><em><br> Protocol 1: Link to Pilot<br><br>\n\t\t\n\n\t\t\tProtocol 2: Uphold the Mission<br><br>\n\n\t\t\tProtocol 3: Protect the Pilot</br></em></br>\n\t\t\n\t\t\n\t\t\tWhile the \n\t\tIMC considers its Titans and Pilots to be interchangeable and disposable, the Militia views each of its new Vanguard Pilot-Titan units as a long-term \n\t\tinvestment. As a result, an experienced Vanguard Titan-Pilot team is far more flexible and deadlier than any single IMC Titan and Pilot on the Frontier\n\t\t.To BT-7274, his Pilot isn't just a teammate, but also a friend. </p>\n\t\t</div>\n\n\t\t<div class = 'general-titans'>\n\t\t\t<p style = 'font-style:italic;font-size:25px;display:inline-block;vertical-align:top;background-color:blue' id = 'types_of_titans'> Types of titans</p>\n\n\n\n\t\t\t<ul style='display:inline-block;vertical-align:top;width:18%;margin-left:15%;font-style: italic;font-size:25px;'>\n\t\t\t\t<li class = 'titan'>Scorch</li>\n\t\t\t\t<li class = 'titan'>Ronin</li>\t\n\t\t\t\t<li class = 'titan'>Monarch</li>\t\n\t\t\t\t<li class = 'titan'>Ion</li>\t\n\t\t\t\t<li class = 'titan'>Legion</li>\t\n\t\t\t\t<li class = 'titan'>Northstar</li>\n\t\t\t\t<li class ='titan'> Tone</li>\n\t\t\t</ul>\n\t\t\t<img style = 'width:30%;'src = 'https://assets1.ignimgs.com/thumbs/userUploaded/2016/9/2/characters-mobile3-1472851771315.jpg?width=1280' class='titanlist'>\n\t\t</div>\n\t</body>\n\n\n\n</html>\n";
  return ptr;
}
