# Teste SD Card Esp32


<img src="https://cdn-1.ehs.eti.br/esp32_sdcard.png" align="center"/>

⚠️ IMPORTANTE sobre VCC:

Se o módulo SD tiver regulador de tensão (AMS1117), você pode ligar no 5V

Se for um módulo SD sem regulador, alimente com 3.3V direto

✅ Dicas
Use cartões SD formatados em FAT32

Use fios curtos para conexões SPI (melhor estabilidade)

Verifique se o leitor SD é de nível lógico 3.3V ou 5V compatível

Sempre use o mesmo pino CS que você indicar no SD.begin()
