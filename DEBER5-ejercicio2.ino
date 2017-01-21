/*            DEBER 5- EJERCICIO 2
      2) Realizar un teclado TAB (el teclado antiguo de los teléfonos que en cada tecla
      se encuentran 3 letras y según el número de veces que se presione, se selecciona
      cada letra y se observe en comunicación serial.

      NOMBRE: ISRAEL GUDIÑO
      FECHA:18/01/2017
*/


#include <Keypad.h>
#include <TimerOne.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

const byte ROWS = 4; //CUATRO filas
const byte COLS = 4; //Cuatro columnas
//dSimbolos del teclado
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', ' '},
  {'4', '5', '6', ' '},
  {'7', '8', '9', ' '},
  {'*', '0', '#', ' '}
};

byte rowPins[ROWS] = {3, 2, 1, 0};
byte colPins[COLS] = {7, 6, 5, 4};

//Inicializamos las variables en el teclado
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int cont1 = 0;
int cont2 = 3;
int cont3 = 6;
int cont4 = 9;
int cont5 = 12;
int cont6 = 15;
int cont7 = 19;
int cont8 = 22;
int contador = 6;
int pos = 0;
char dato;


void setup() {

  Serial.begin(9600);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(tespe);
}

void loop() {

  char customKey = customKeypad.getKey();
  if (customKey)
  {
    if (customKey == '1')
    
    Serial.print('1');
    
    }
    if (customKey == '2') {
      cont1++;
      caracteres(cont1);
      if (cont1 == 3) {
        cont1 = 0;
      }
      contador = 0;
    }
    if (customKey == '3') {
      cont2++;
      caracteres(cont2);
      if (cont2 == 6) {
        cont2 = 3;
      }
      contador = 0;
    }

    if (customKey == '4') {

      cont3++;
      caracteres(cont3);
      if (cont3 == 9) {
        cont3 = 6;
      }
      contador = 0;

    }

    if (customKey == '5') {

      cont4++;
      caracteres(cont4);
      if (cont4 == 12) {
        cont4 = 9;
      }
      contador = 0;
    }

    if (customKey == '6') {

      cont5++;
      caracteres(cont5);
      if (cont5 == 15) {
        cont5 = 12;
      }
      contador = 0;
    }

    if (customKey == '7') {
      cont6++;
      caracteres(cont6);
      if (cont6 == 19) {
        cont6 = 15;
      }
      contador = 0;
    }

    if (customKey == '8') {
      cont7++;
      caracteres(cont7);
      if (cont7 == 22) {
        cont7 = 19;
      }
      contador = 0;
    }

    if (customKey == '9') {
      cont8++;
      caracteres(cont8);
      if (cont8 == 26) {
        cont8 = 22;
      }
      contador = 0;
    }

    if (customKey == '0') {
      Serial.print(' ');
    }
  }

//Parámetro para elegir la letra
char caracteres(int dato) {
  switch (dato) {

    case 1:
      dato = 'a';
      break;

    case 2:
      dato = 'b';
      break;

    case 3:
      dato = 'c';
      break;

    case 4:
      dato = 'd';
      break;

    case 5:
      dato = 'e';
      break;

    case 6:
      dato = 'f';
      break;

    case 7:
      dato = 'g';
      break;

    case 8:
      dato = 'h';
      break;

    case 9:
      dato = 'i';
      break;

    case 10:
      dato = 'j';
      break;

    case 11:
      dato = 'k';
      break;

    case 12:
      dato = 'l';
      break;

    case 13:
      dato = 'm';
      break;

    case 14:
      dato = 'n';
      break;

    case 15:
      dato = 'o';
      break;

    case 16:
      dato = 'p';
      break;

    case 17:
      dato = 'q';
      break;

    case 18:
      dato = 'r';
      break;

    case 19:
      dato = 's';
      break;

    case 20:
      dato = 't';
      break;

    case 21:
      dato = 'u';
      break;

    case 22:
      dato = 'v';
      break;

    case 23:
      dato = 'w';
      break;

    case 24:
      dato = 'x';
      break;

    case 25:
      dato = 'y';
      break;

    case 26:
      dato = 'z';
      break;
  }
  return dato;
}
void tespe() {
  contador++;
  if (contador == 6) {
    Serial.print(dato);
    cont1 = 0;
    cont2 = 3;
    cont3 = 6;
    cont4 = 9;
    cont5 = 12;
    cont6 = 15;
    cont7 = 19;
    cont8 = 22;
  }
}

