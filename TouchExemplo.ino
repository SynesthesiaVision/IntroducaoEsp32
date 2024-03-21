int med; //variavel que armazenará a medição
int limiar = 20; //valor de limiar da leitura capacitiva
int ledPin = 18; //pino do LED

void setup() {
    Serial.begin(115200);
}

void loop() {
    med = touchRead(4); //lê o valor do T0
    Serial.print(med);
    if(med > limiar ){ //se a leitura de T0 for maior que o limiar o LED acende
        digitalWrite(ledPin, HIGH);
        }
    delay(500);
}
