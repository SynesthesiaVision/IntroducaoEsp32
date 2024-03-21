//O presente código é apenas um exemplo de como acessar o modem sleep

void rf_on(){
    //Função de inicializar o WiFi do chip
    bool bye = WiFi.setSleep(false);
    WiFi.mode(WIFI_STA);
    vTaskDelay(pdMS_TO_TICKS(30));
    WiFi.begin(wifiConfig.ssid, wifiConfig.passwd);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
}

void rf_off(){
    //Função para desativar o WiFi
    bool bye = WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    btStop();
    bye = WiFi.setSleep(true); 
    vTaskDelay(pdMS_TO_TICKS(100));
}

void setup(){
//procedimentos de inicialização
}

void loop(){
//código a ser executado
}
