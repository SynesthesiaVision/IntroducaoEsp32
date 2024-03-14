// Declaração de Variáveis e Pinos
TaskHandle_t Task1;
TaskHandle_t Task2;

// Pinos da LED
const int led1 = 4;
const int led2 = 5;

// Vamos caracterizar os pinos 4 e 5 como saídas/"output"
void setup() {
 Serial.begin(115200); 
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);

 // Criação da Task1 que será executada na função Task1code(), com prioridade 1 no core 0:

 xTaskCreatePinnedToCore(
 Task1code, /* Função da tarefa. */
 "Task1", /* Nome da tarefa. */
 10000, /* Tamanho da pilha da tarefa. */
 NULL, /* Parâmetro da tarefa. */
 1, /* Prioridade da tarefa. */
 &Task1, /* Handle da tarefa para acompanhamento. */
 0); /* Define a execução da tarefa no core 0 */ 
 delay(500); //aguarde 0,5 s

 // Criação da Task2 que será executada na função Task2code(), com prioridade 1 no core 1:

 xTaskCreatePinnedToCore(
 Task2code, /* Função da tarefa. */
 "Task2",  /* Nome da tarefa. */
 10000, /* Tamanho da pilha da tarefa. */
 NULL,  /* Parâmetro da tarefa. */
 1,  /* Prioridade da tarefa. */
 &Task2,  /* Handle da tarefa para acompanhamento. */
 1);  /* Define a execução da tarefa no core 1 */
 delay(500); //aguarde 0,5 s
}

// Lógica da Task1: pisca um LED a cada 1000 ms

void Task1code( void * pvParameters ){
 Serial.print("Task1 rodando no core ");
 Serial.println(xPortGetCoreID());
//Aqui escrevemos para que ele imprima a mensagem quando estiver rodando no core (núcleo).

 for(;;){ 
//for (para) quando isso acontecer, ligamos a led 1 por 1 segundo e depois desligamos.
 digitalWrite(led1, HIGH);
 delay(1000);
 digitalWrite(led1, LOW);
 delay(1000);
 } 
}

// Lógica da Task2: pisca um LED a cada 700 ms

void Task2code( void * pvParameters ){

 Serial.print("Task2 rodando no core ");
 Serial.println(xPortGetCoreID());

//Aqui escrevemos para que ele imprima a mensagem quando esitver rodando no core

 for(;;){
//for (para) quando isso acontecer, ligamos a led 2 por 0,7 segundos e depois desligamos.

 digitalWrite(led2, HIGH);
 delay(700);
 digitalWrite(led2, LOW);
 delay(700);
 }
}

void loop() {
 
}
