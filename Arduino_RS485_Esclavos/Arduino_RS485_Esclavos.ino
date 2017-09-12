
const int En_WrRd_RS485 =  2;

const int Led_1 =  13; 
const int Led_2 =  6; 
const int Led_3 =  5;  

char VarChar = ' ';
String BufferIn = "";        
boolean StringCompleta = false; 

void setup() 
{ 
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
      
      //if ((BufferIn.indexOf('B')) >= 0)
      if ((BufferIn.indexOf('C')) >= 0)
      {
          if (BufferIn.indexOf('1' ) >= 0)
          {
            Serial.print("OK");
            delay(500);
            
              
                  
              digitalWrite(Led_2, HIGH);
               
             
             
            
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



