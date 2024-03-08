#define LED 21
#define BUTTON 2 // Altere para o pino ao qual o botão está conectado

hw_timer_t *My_timer = NULL;
volatile bool buttonPressed = false;

void IRAM_ATTR onTimer() {
  digitalWrite(LED, HIGH);  // Liga a LED
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); // Configura o botão com pull-up interno

  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);

  attachInterrupt(digitalPinToInterrupt(BUTTON), [] {
    buttonPressed = true;
  }, FALLING);
}

void loop() {
  if (buttonPressed) {
    delay(3000);  // Espera 5 minutos (300.000 milissegundos) antes de ligar a LED
    timerAlarmEnable(My_timer);  // Ativa o temporizador para ligar a LED
    buttonPressed = false;  // Reseta a flag do botão para evitar repetição
  }
  // Aqui você pode adicionar lógica adicional enquanto a LED está ligada, se necessário
}
