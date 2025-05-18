#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <wifi_credentials.h> //fichier contenant les identifiants Wi-Fi



// Adresse et DB Influx
const char* influxHost = "http://192.168.1.137:8086/";
const char* influxDb   = "mesure_iot";

// Broche analogique du capteur PIR
const int pirPin = 14;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connexion WiFi…");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println(" connecté !");
  // Initialise la broche en entrée si besoin
  pinMode(pirPin, INPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Lecture de la valeur brute (0–4095) et conversion en tension (0–3.3V)
    int raw = analogRead(pirPin);
    float tension = raw * (3.3f / 4095.0f);

    // Prépare la ligne InfluxDB (Line Protocol)
    // Ici : measurement = "presence", tag = "capteur=pir", field = "voltage"
    String lp = "presence,capteur=pir voltage=" + String(tension, 3);
    // Si tu veux un timestamp précis en secondes, ajoute :
    // lp += " " + String(time(NULL));

    // Envoi HTTP POST
    HTTPClient http;
    String url = String(influxHost) + "write?db=" + influxDb + "&precision=s";
    http.begin(url);
    http.addHeader("Content-Type", "text/plain");
    int code = http.POST(lp);

    if (code == 204 || code == 200) {
      Serial.printf("Données envoyées : %s → code %d\n", lp.c_str(), code);
    } else {
      Serial.printf("Erreur envoi (%d) : %s\n", code, http.getString().c_str());
    }
    http.end();
  } else {
    Serial.println("WiFi déconnecté, tentative de reconnexion…");
    WiFi.reconnect();
  }

  // Attente 100 ms
  delay(100);
}

