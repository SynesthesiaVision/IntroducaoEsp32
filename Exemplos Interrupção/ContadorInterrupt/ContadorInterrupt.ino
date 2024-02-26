#define button 22 //pino do botão

int pressed = 0; //variável que conta quantas vezes o botão foi pressionado

void IRAM_ATTR contar(){ //função de interrupção
  pressed++; //incrementa a quantidade de vezes que o botão foi pressionado
  Serial.print(pressed); //mostra no monitor serial a variável pressed
} 
 
void setup()
{
Serial.begin(115200); //inicializa o monitor serial
pinMode(button, INPUT); //configura o pino button do ESP32 como input

attachInterrupt(button, contar, RISING); /*função que define que o pino 14, do botão,  vai gerar uma interrupção quando for solto após pressionado(borda de descida) e assim executar a função changeLed()*/
}
 
void loop()
{
}