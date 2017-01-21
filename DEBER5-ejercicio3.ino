/*            DEBER 5- EJERCICIO 3
      3)Ingresar palabras por comunicación serial, se genere una rotación o juego en la lcd.

      NOMBRE: ISRAEL GUDIÑO
      FECHA:18/01/2017
*/

#include<LiquidCrystal.h>
LiquidCrystal lcd (9, 8, 7, 6, 5, 4);

String dato; //Vector en donde guardaremos la palabra ingresada
int tamano; //Variable en donde guardaremos el tamaño

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
      grabarPalabra();
      juego();
      Serial.println("");
}

//En este método grabamos la palabra ingresada
void grabarPalabra() {
  Serial.println("Ingrese la palabra a visualizarce en el LCD");
  t_espera();
  dato = Serial.readString();
  tamano = dato.length();
  Serial.println("");
}

//Juego
void juego() {
  lcd.setCursor(16, 0);
  lcd.print(dato);
  int k = 0;
  for (; k < (17 + tamano); k++) {
    lcd.setCursor(15, 0); // ponemos el cursor fuera del reango del display
    lcd.autoscroll();    // Activa el scroll automatico
    lcd.print(" ");      // imprime un character en blanco
    delay(100);
  }
  lcd.noAutoscroll();//Desactiva el scroll automatico
  lcd.clear();//Limpia la pantalla del LCD
}

//Tiempo de espera. Este método se ejecuta mientras el usuario no ingrese ningún dato
void t_espera() {
  for (; Serial.available() == 0; ) {
  }
}
