#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "RIYA";
const char* password = "riya1234";

WebServer server(80);

// Motor Pins
#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3
#define ENA D4
#define ENB D5

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void handleRoot() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Robot</title>
<style>
body{
  text-align:center;
  font-family:Arial;
}
button{
  width:120px;
  height:80px;
  font-size:20px;
  margin:8px;
}
</style>
</head>
<body>

<h2>WiFi Robot Control</h2>

<p><a href="/forward"><button>Forward</button></a></p>

<p>
<a href="/left"><button>Left</button></a>
<a href="/stop"><button>Stop</button></a>
<a href="/right"><button>Right</button></a>
</p>

<p><a href="/backward"><button>Backward</button></a></p>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", page);
}

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  stopMotors();

  Serial.begin(115200);

  WiFi.softAP(ssid, password);

  Serial.println("WiFi Started");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);

  server.on("/forward", []() {
    forward();
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/backward", []() {
    backward();
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/left", []() {
    left();
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/right", []() {
    right();
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/stop", []() {
    stopMotors();
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}