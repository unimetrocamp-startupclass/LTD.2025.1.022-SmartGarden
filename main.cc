#include <LiquidCrystal.h>

int umi = 0;
const int relePin = 12; // D12 controla o relé

LiquidCrystal lcd_1(0, 1, 2, 3, 4, 5);

void setup()
{
  pinMode(A0, INPUT);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, HIGH); // Inicialmente desliga o relé
  lcd_1.begin(16, 2);
}

void loop()
{
  umi = map(analogRead(A0), 0, 1023, 0, 100);

  lcd_1.setCursor(0, 0);
  lcd_1.noAutoscroll();
  lcd_1.print("                ");
  lcd_1.setCursor(0, 0);

  if (umi <= 30) {
    lcd_1.print("umidade baixa");
    digitalWrite(relePin, HIGH); // Liga a bomba
  } else {
    lcd_1.print("umidade adequada");
    digitalWrite(relePin, LOW); // Desliga a bomba
  }

  delay(500);
}
