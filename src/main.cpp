#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define CS_PIN 5  // Altere se usou outro pino para CS

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando cartão SD...");

  if (!SD.begin(CS_PIN)) {
    Serial.println("Falha ao inicializar o cartão SD!");
    return;
  }
  Serial.println("Cartão SD inicializado com sucesso.");

  // Verifica espaço total
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.print("Tamanho do cartão: ");
  Serial.print(cardSize);
  Serial.println(" MB");

  // Cria arquivo
  File file = SD.open("/teste.txt", FILE_WRITE);
  if (file) {
    file.println("Teste de escrita no cartão SD.");
    file.close();
    Serial.println("Arquivo escrito com sucesso.");
  } else {
    Serial.println("Erro ao criar o arquivo.");
  }

  // Lê o arquivo
  file = SD.open("/teste.txt");
  if (file) {
    Serial.println("Conteúdo do arquivo:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Erro ao abrir o arquivo.");
  }
}

void loop() {
  // Nada no loop
}
