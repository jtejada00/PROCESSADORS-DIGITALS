# PRACTICA 3: WIFI

## Codi:

```C++
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
// SSID & Password
const char* ssid = "iPhone"; // Enter your SSID here
const char* password = "1234567890"; //Enter your Password here
WebServer server(80);

void handle_root();

// Object of WebServer(HTTP port, 80 is defult)
void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);
// Connect to your wi-fi modem
WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}
void loop() {
server.handleClient();
}
// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My Primera Pagina con ESP32, somos los mejores!!! - Station Mode &#128522;</h1>\
</body>\
</html>";
// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}

```


### Funcionament:

Aquest programa crea una pàgina web. Per això necessitem inicialment connectar la nostra placa a una xarxa Wi-Fi, la mateixa a la qual està el nostre ordinador:

Quan la xarxa Wi-Fi està connectada a la placa aquesta llança per pantalla un missatge dient que el dispositiu ja està connectat a la xarxa. I seguidament ens dona una IP, a la que ens hem de connectar per visualitzar la pàgina web creada. Aquesta IP quan la fiquem al cercador del nostre ordinador ens portarà a la pàgina web que hem creat anteriorment.