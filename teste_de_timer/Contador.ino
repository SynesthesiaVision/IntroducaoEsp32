#define LED 12


hw_timer_t * timer = NULL;



void cb_timer(){
    unsigned int counter = 1;
    Serial.print(millis()/1000);
    Serial.println(" segundos");
   
    counter++;
}

void startTimer(){
    //inicialização do timer. Parametros:
    /* 0 - seleção do timer a ser usado, de 0 a 3.
      80 - prescaler. O clock principal do ESP32 é 80MHz. Dividimos por 80 para ter 1us por tick.
    true - true para contador progressivo, false para regressivo
    */
    timer = timerBegin(0, 80, true);

    /*conecta à interrupção do timer
     - timer é a instância do hw_timer
     - endereço da função a ser chamada pelo timer
     - edge=true gera uma interrupção
    */
    timerAttachInterrupt(timer, &cb_timer, true);

    /* - o timer instanciado no inicio
       - o valor em us para 1s
       - auto-reload. true para repetir o alarme
    */
    timerAlarmWrite(timer, 1000000, true); 

    //ativa o alarme
    timerAlarmEnable(timer);
}

void stopTimer(){
    timerEnd(timer);
    timer = NULL; 
}

void setup(){
    Serial.begin(115200);
    startTimer();
}

void loop(){}
    
