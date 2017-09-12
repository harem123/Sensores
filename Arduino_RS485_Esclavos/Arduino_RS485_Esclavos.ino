
const int En_WrRd_RS485 =  2;

const int Led_1 =  13; 
const int Led_2 =  6; 
const int Led_3 =  5;  
// ++ pines de sensado my pins y pin de salida 
int myPins[] = {7, 8,9};
int sN=33;
boolean flag;
// ++++++++++++++++++++++++++++++
// variables de buffering
char VarChar = ' ';
String BufferIn = "";        
boolean StringCompleta = false; 

void setup() 
{ 
  //++ defino pines de entrada 
  for(int j= 0 ; j <2; j++){
  pinMode(myPins[j],INPUT);}
// +++

  Serial.begin(9600);
  BufferIn.reserve(5);  
    
  pinMode(En_WrRd_RS485, OUTPUT);
  
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  
  digitalWrite(En_WrRd_RS485, LOW); 
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, LOW); 
} 
 
void loop() 
{ 
  if (StringCompleta) 
  {         
       delay(50);
       digitalWrite(En_WrRd_RS485, LOW); 
      Serial.print(BufferIn);
      
      
      if ((BufferIn.indexOf('C')) >= 0)
      {
          if (BufferIn.indexOf('1' ) >= 0)
          {
            flag = true;
            Serial.print("OK");
            delay(500);
            while(flag == true)
            {
              digitalWrite(Led_2, HIGH);
              for(int i = 0; i<3; i++)
              {
                if (digitalRead(myPins[i]) == HIGH)
                {
                  sN = i;
                  Serial.print(sN);
                  flag = false;
                }
              }
            }
             
            
            delay(500);
            digitalWrite(Led_2, LOW);
            Serial.print("out");
            
          }
          
      }
      StringCompleta = false;
      BufferIn = "";
  } 
} 

void serialEvent() {
  while (Serial.available()) 
  {
    VarChar = (char)Serial.read();
    BufferIn += VarChar;
    if (VarChar == 'Z') { StringCompleta = true; }   
  }
}



