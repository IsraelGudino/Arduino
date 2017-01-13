/*SEGUNDO BIMESTRE -DEBER 1 - COMUNICACIÓN SERIAL Y LCD

   El programa consiste en lo siguiente:

   El usuario debe ingresar la palabra o palabras que quiere vizualizar en el LCD,
   a continuación escoge unas de las tres formas de vizualización (A-B-C), la misma que será
   ingresada por el teclado. Y tambíen hay una interrupción la cual finaliza el programa.

   INTEGRANTES:  Israel Gudiño

   FECHA: 22/12/2016
*/


#include<LiquidCrystal.h>
LiquidCrystal lcd (9, 8, 7, 6, 5, 4);
String dato; //Vector en donde guardaremos la palabra ingresada
int tamano; //Variable en donde guardaremos el tamaño del vector "dato"
int power = 1;//Contador para la interrupción

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(0, interrumpir, RISING);//Cual el pin 2 lea el cambio de 0 a 1 se activa la interrupción
}

void loop() {
  if (power == 1) {
    if (Serial.available() > 0) {
      lcd.clear();
      grabarPalabra();
      empezar();
      Serial.println("");
    }
  }
  else {
    lcd.clear();
    power = power - 2;
    lcd.print("SISTEMA OFF");
    Serial.println("SISTEMA OFF");
    Serial.end();//Finaliza el programa
  }
}

//En este método grabamos la palabra ingresada
void grabarPalabra() {
  Serial.println("Ingrese la palabra a visualizarce en el LCD");
  t_espera();
  dato = Serial.readString();
  tamano = dato.length();
  Serial.println("");
}

//En este método ingresamos que juego queremos vizualizar
void empezar() {
  char respuest;//Variable con la que compararemos la opción ingresada
  Serial.println("Elija un juego (A,B;C):");
  t_espera();
  respuest = Serial.read();
  if ((respuest == 'A') || (respuest == 'a')) {
    juego1();
  }
  else {
    if ((respuest == 'B') || (respuest == 'b')) {
      juego2();
    }
    else {
      if ((respuest == 'C') || (respuest == 'c')) {
        juego3();
      }
      else {
        Serial.println(" ");
        grabarPalabra();
      }
    }
  }
}

//Juego 1
void juego1() {
  int vel;
  for ( int a = 1; a < 30; a++) {
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 0);
    lcd.print(dato);
    vel = 150 - (a * 5);
    delay(vel);//Tiempo de espera
    lcd.setCursor(0, 0);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(dato);
    vel = 150 - (a * 5);
    delay(vel);//Tiempo de espera
  }

  lcd.clear();//Limpiamos la pantalla del LCD
}

//Juego 2
void juego2() {
  lcd.setCursor(16, 0);
  lcd.print(dato);
  int k = 0;
  for (; k < (17 + tamano); k++) {
    lcd.setCursor(16, 0); // ponemos el cursor fuera del reango del display
    lcd.autoscroll();    // Activa el scroll automatico
    lcd.print(" ");      // imprime un character en blanco
    delay(100);
  }
  lcd.noAutoscroll();//Desactiva el scroll automatico
  lcd.clear();//Limpia la pantalla del LCD
}

//Juego 3
void juego3() {
  int i = 0;
  int j = 0;
  char mensaje3[tamano];
  dato.toCharArray(mensaje3, tamano + 1);
  for (; i < tamano; i++) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(mensaje3[i]);
    delay(200);
    lcd.setCursor(i, j);
    lcd.print('*');
  }
  for (; i >= 0; i--) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(mensaje3[i]);
    delay(200);
    lcd.setCursor(i, j);
    lcd.print(" ");
  }
  lcd.clear();//Limpia la pantalla del LCD
}

//Tiempo de espera. Este método se ejecuta mientras el usuario no ingrese ningún dato
void t_espera() {
  for (; Serial.available() == 0; ) {
  }
}

//Método de interrupción
void interrumpir() {
  power = power + 1;
}
