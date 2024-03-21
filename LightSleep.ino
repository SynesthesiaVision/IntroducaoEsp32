void setup() {
  Serial.begin(115200);
  delay(1000); // Espera um momento para a inicialização da serial

  Serial.println("Colocando a ESP32 em Light Sleep...");

  // Configura um pino GPIO para acordar a ESP32 do light sleep
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, HIGH); // GPIO 32, HIGH para acordar

  // Coloca a ESP32 em light sleep
  esp_light_sleep_start();

  // O código não continuará a partir deste ponto até que a ESP32 seja acordada
}

void loop() {
  // Este código não será executado enquanto a ESP32 estiver em light sleep
}
