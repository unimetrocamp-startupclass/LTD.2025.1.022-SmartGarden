#include <LiquidCrystal.h>  // Biblioteca para o display LCD 16x2

int umi = 0;                      // Valor da umidade do solo
const int relePin = 2;           // Pino do relé (bomba)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Pinos padrão do LCD Keypad Shield

void setup() {
  pinMode(relePin, OUTPUT);      
  digitalWrite(relePin, HIGH);   // Relé desligado no início (inativo)
  lcd.begin(16, 2);              // Inicializa o LCD 16x2
  Serial.begin(9600);            // Inicializa comunicação serial a 9600 bps
}

void loop() {
  int leitura = analogRead(A2);                      // Lê a umidade do solo
  umi = map(leitura, 1023, 0, 0, 100);               // Converte para porcentagem (0% = seco)

  Serial.print("Leitura analogica: ");
  Serial.print(leitura);
  Serial.print(" - Umidade: ");
  Serial.print(umi);
  Serial.println("%");

  // Primeira linha: status
  lcd.setCursor(0, 0);
  lcd.print("                "); 
  lcd.setCursor(0, 0);

  if (umi >= 45) {
    lcd.print("Umidade ok");
    digitalWrite(relePin, HIGH); 
  } else {
    lcd.print("Umidade baixa");
    digitalWrite(relePin, LOW); 
  }

  // Segunda linha: valor da umidade
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(umi);
  lcd.print("%   "); // Espaço extra para apagar valores antigos

  delay(1000);
}
