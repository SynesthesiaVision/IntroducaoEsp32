const int wakeupInterval = 10; // Intervalo de tempo em segundos antes do despertar

void setup() {
  Serial.begin(115200);
  delay(1000); // Espera um momento para a inicialização da serial

  Serial.println("Colocando a ESP32 em Deep Sleep...");

  // Configura o tempo de espera para o despertar
  esp_sleep_enable_timer_wakeup(wakeupInterval * 1000000); // Converte segundos em microssegundos

  // Coloca a ESP32 em deep sleep
  esp_deep_sleep_start();
}

void loop() {
  // Este código não será executado, pois a ESP32 entrará em deep sleep imediatamente após o setup
}
