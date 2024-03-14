// Definições de pinos
int buttonPin = 2; 
int ledPin = 13;  
int timerInterval = 1000; 


bool counting = false;
bool debounce = false;  
long startTime = 0; 

void IRAM_ATTR buttonInterrupt() {
  if (startTime >= 1000){
    debounce = false;
  }

if(debounce == false){
  if (digitalRead(buttonPin) == HIGH) {
    if (!counting) {  // Se não está contando, inicia a contagem
      startTime = millis(); // Armazena o tempo de início
      counting = true;  // Define a flag de contagem como verdadeira
      debounce = true;
    } else {  // Se está contando, para a contagem
      counting = false;  // Define a flag de contagem como falsa
      startTime = 0;  // Reinicia o tempo de início
      Serial.println("Contagem interrompida.");
    }
  }
}
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, RISING);
}

void loop() {
  if (counting) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    Serial.print("Tempo decorrido: ");
    Serial.print(elapsedTime / 1000);  // Exibe o tempo decorrido em segundos
    Serial.println(" segundos");
    
    // Acende o LED após 5 segundos
    if (elapsedTime >= 5000) {
      digitalWrite(ledPin, HIGH);
    }
  } else {
    digitalWrite(ledPin, LOW);  // Garante que o LED esteja apagado quando a contagem estiver parada
  }
  delay(100);  // Pequena pausa para estabilidade
}
