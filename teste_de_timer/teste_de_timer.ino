#define LED 12
#define BUTTON 2

//Instanciação do timer
hw_timer_t *My_timer = NULL;

//Função chamada pela interrupção
void IRAM_ATTR onTimer()
{
     digitalWrite(LED, HIGH); // Liga a LED
}

//Inicialização
void setup()
 {
     pinMode(LED, OUTPUT);
     digitalWrite(LED, LOW);
     pinMode(BUTTON, INPUT_PULLUP);
    //Timer definido com clock dividido por  80  =  1MHz
     My_timer = timerBegin(0, 80, true);

    //Executa onTimer ao chegar no limite do tempo
    timerAttachInterrupt(My_timer, &onTimer, true);

    //Define o tempo  de espera em 3 segundos
    timerAlarmWrite(My_timer, 3000000, true); 
}
//Loop com a função de monitorar um botão
void loop()
 {
     if (!digitalRead(BUTTON))
     { 
           timerAlarmEnable(My_timer); 
       } 
}
