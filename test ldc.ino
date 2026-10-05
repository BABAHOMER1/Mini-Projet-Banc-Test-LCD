// Banc_de_Test_I2C
// CIEL2
// DURIATTI_ANTONY
// 30/09/2026

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int bouton = 7;

byte carre[8] = {
  B11111,B11111,B11111, B11111, B11111, B11111, B11111, B11111
};

void setup() {
  pinMode(bouton, INPUT_PULLUP);   
  lcd.begin(16, 2);              
  lcd.createChar(0, carre);       
  lcd.clear();
  lcd.print("Lance le test");   
}

void loop() {

  if (digitalRead(bouton) == LOW) {
    lcd.clear();
    lcd.print("Test LCD");
    delay(2000);

 lcd.clear();
    lcd.print("Ecran Test!");
    delay(1000);

    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      delay(150);
    }

    // scroll 29 positions (string length + display length) to the right
    // to move it offscreen right:
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      // scroll one position right:
      lcd.scrollDisplayRight();
      delay(150);
    }

    // scroll 16 positions (display length + string length) to the left
    // to move it back to center:
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      delay(150);
    }
    delay(1000);

    lcd.clear();
    for (int ligne = 0; ligne < 2; ligne++) {
      for (int colonne = 0; colonne < 16; colonne++) {
        lcd.setCursor(colonne, ligne);
        lcd.write(byte(0));           
        delay(200);
      }
    }
    delay(2000);

    lcd.clear();
    lcd.print("Lance le test");
  }
}