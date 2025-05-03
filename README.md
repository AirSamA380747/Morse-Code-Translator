To use the Morse Code Translator, you can either download the file and just open it or you can copy and paste the code to run it. To do this,  firstly copy all the code in the Sentence-to-Morse-Code file and then 
open notepad or something similar on your device. Paste the code into notepad. Then go to Save As, then call it something related to Morse Code but make sure at the end you write .html Then choose file type to all files.
Once you've saved it, you should be able to open it and use the translator.
The Arduino code is used so you can broadcast Morse Code locally to an AM Radio tuned to 1600-1700 KHz. To use it, either download the file and upload it to you Arduino or copy and paste the code into Arduino IDE and then upload it.
To change what the Morse Code says, use the translator to get the sentence you want to translate in Morse Code and then find the line in the code that says:

String morseMessage = "";

And then copy and paste the Morse Code string from the translator into the speech marks. Then if you upload the code and tune the radio, everything should work.
