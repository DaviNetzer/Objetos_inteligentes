#include <Servo.h>
#include "AdafruitIO_WiFi.h"
/************************ Configurações do Adafruit IO *******************************/
//Insira seu nome de usuário e chave. Essas informações são encontras acessando
//a conta no Adafruit IO
#define IO_USERNAME "allanlinux"
#define IO_KEY "80jecnQoCpw3CsNpyo0yZownkkkkkk"

/********************* Configuração do WIFI **************************************/
//Insira o SSID e Senha da rede WIFI a qual irá conectar
#define WIFI_SSID "Vivo-162A"
#define WIFI_PASS "12345"


/***************Configurações do comunicaçaão************/
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/************************ Mapeamento de IO *******************************/
Servo servo;
int trigPin = 14;
int echoPin = 12;
int servoPin = 16;
long duration, dist, average;
long aver[3];   //array for average

/*
  -------------------------------------------------
        NodeMCU / ESP8266  |  NodeMCU / ESP8266  |
        D0 = 16            |  D6 = 12            |
        D1 = 5             |  D7 = 13            |
        D2 = 4             |  D8 = 15            |
        D3 = 0             |  D9 = 3             |
        D4 = 2             |  D10 = 1            |
        D5 = 14            |                     |
  -------------------------------------------------
*/

/************************ Configuração dos tópicos *******************************/
// configura o tópico "allanlinux/feeds/smartbin"
AdafruitIO_Feed *feed = io.feed("smartbin");

/************************ Função setup *******************************/
void setup() {

  Serial.begin(115200);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);
  delay(100);
  servo.detach();

  // Aguarda serial monitor
  while (! Serial);

  conectaBroker(); //função para conectar ao broker


}

/************************ Função loop *******************************/
void loop() {

  // processa as mensagens e mantêm a conexão ativa
  byte state = io.run();


  //verifica se está conectado
  if (state == AIO_NET_DISCONNECTED | state == AIO_DISCONNECTED) {
    conectaBroker(); //função para conectar ao broker
    io.connect();
  }

  for (int i = 0; i <= 2; i++) {
    measure();
    aver[i] = dist;
    delay(10);
  }
  dist = (aver[0] + aver[1] + aver[2]) / 3;

  if ( dist < 10 ) {
    servo.attach(servoPin);
    delay(1);
    servo.write(0);
    delay(3000);
    servo.write(180);
    delay(1000);
    servo.detach();
  }

}

/****** Função de tratamento dos dados recebidos em L1***************/
void sendCommand(AdafruitIO_Data *data) {

  //Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    servo.attach(servoPin);
    delay(1);
    servo.write(0);
    delay(3000);
    servo.write(180);
    delay(1000);
    servo.detach();
  }

}


/****** Função para conectar ao WIFI e Broker***************/
void conectaBroker() {

  //mensagem inicial
  Serial.print("Conectando ao Adafruit IO");

  // chama função de conexão io.adafruit.com
  io.connect();

  // instancia um novo handler para recepção da mensagem do feed
  feed->onMessage(sendCommand);

  // Aguarda conexação ser estabelecida
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // Conectado
  Serial.println();
  Serial.println(io.statusText());

  // certifica de que o feeds obtenha valores atuais imediatamente
  feed->get();
}

/****** Função que faz a medição ***************/
void measure() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration / 2) / 29.1;
}
