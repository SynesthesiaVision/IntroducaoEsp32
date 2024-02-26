#define button 14 //pino do botão
#define LEDPIN 5 //pino do LED

void IRAM_ATTR changeLed(){ //função de interrupção

  digitalWrite(LEDPIN, HIGH);
  
} 
 
void setup()
{
 
pinMode(LEDPIN, OUTPUT);
pinMode(button, INPUT);

attachInterrupt(button, changeLed, FALLING); /*função que define que o pino 14, do botão,  vai gerar uma interrupção quando for solto após pressionado(borda de descida) e assim executar a função changeLed()*/

digitalWrite(LEDPIN, LOW);
}
 
void loop()
{
}