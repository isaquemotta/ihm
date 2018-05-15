


// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <Wire.h>
#include <LiquidCrystal.h>


// ========================================================================================================
// --- Mapeamento de Hardware ---
#define     menu     8
#define     enter    9

int led=10;
// ========================================================================================================
// --- Protótipo das Funções ---
void readButts();
void list_menu();
void menu_select();
int estado = 0;

// ========================================================================================================
// --- Declaração de Objetos ---
LiquidCrystal lcd(12,11,5,4,3,2);


// ========================================================================================================
// --- Variáveis Globais ---
int      line[5] = {0,1,2,3,4},
         line_bk[5],
         index,
         menu_number = 1;

boolean  menu_flag  = 0,
         enter_flag = 0,
         sub_menu = 0;


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  pinMode(led,OUTPUT);
  //Serial.begin(9600);
  pinMode(menu,  INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
 

  
 lcd.begin (16,4);
// lcd.setBacklight(HIGH);
  lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(">");
 
 
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{

  if(!sub_menu)
  {
    lcd.setCursor(1,line[0]);
    lcd.print("1) Motor        ");
    lcd.setCursor(1,line[1]);
    lcd.print("2) Luz        ");
    lcd.setCursor(1,line[2]);
    lcd.print("3) Valvula        ");
    lcd.setCursor(1,line[3]);
    lcd.print("4) Atuador     ");
    lcd.setCursor(1,line[4]);
    lcd.print("5) Help         ");
  }
  

  readButts();

  

 
  
   
  
} //end loop


void readButts()
{
  
   if(!digitalRead(menu))  menu_flag  = 0x01;
   if(!digitalRead(enter)) enter_flag = 0x01;

   if(digitalRead(menu) && menu_flag)
   {
       menu_flag = 0x00;
       list_menu();
       menu_number+=1;
       if(menu_number > 5) menu_number = 1;
    
   } //end if menu

   if(digitalRead(enter) && enter_flag)
   {
      enter_flag = 0x00; 
      sub_menu = !sub_menu;
      menu_select();
    
   } //end if menu
  
  
} //end readButts


void list_menu()
{
  for(int i=4; i>-1; i--) 
  {
     index = i-1;
     line_bk[i] = line[i];
     
     if(index < 0) line[i] = line_bk[i+4];
     
     else line[i] = line[i-1];

  }

} //end list_menu


void menu_select()
{

    switch(menu_number)
    {
       case 1: 
               lcd.setCursor(1,0);
               lcd.print("Controle Motor  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 2: 
                
               lcd.setCursor(1,0);
               lcd.print("Controle luz  ");
                
                estado = digitalRead(enter);
                 if (estado == HIGH)
                  digitalWrite(led, LOW);

  else
    digitalWrite(led, HIGH);
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 3: 
               lcd.setCursor(1,0);
               lcd.print("Control valvula  ");             
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 4: 
               lcd.setCursor(1,0);
               lcd.print("Atuador Ctrl  ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
       case 5: 
               lcd.setCursor(1,0);
               lcd.print("Help System    ");
               lcd.setCursor(0,1);
               lcd.print("                "); 
               break;
      
    } //end switch
  
 
} //end menu_select





