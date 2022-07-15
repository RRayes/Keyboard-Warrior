const int NUM_BUTTONS = 24; //number of buttons on piano
const int NUM_LIGHTS = 24; //number of lights on piano
const int PIEZO = 11; //sets PIEZO(speaker) to 11th port on arduino board

int currentSeqInd = 0;  //init currentSeqInd to cycle through arrays.


int buttonFreqs[] = { //set the frequencies of what the buttons will be from left to right
  262,277,294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622,659, 698, 740, 784, 831,880,932,988 
};

// Ascending order of note
int buttonPins[] = {  //ports from arduino to buttons from left to right.
  37,36,35,34,33,32,31,30,29,28,10,9,8,7,6,5,4,3,22,23,24,25,26,27
};
int lightPins[] = { //lights from arduino ports to LEDs from left to right.
  A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,38,39,40,41,42,43,44,45
};

void setupLights() {    //initiates the arduino ports array is calling to as OUTPUTs and turns them to low (says these are LEDs and tells them to default to off).
  for (int i = 0; i < NUM_LIGHTS; i++) {
    int lightPin = lightPins[i];
    pinMode(lightPin, OUTPUT);
    digitalWrite(lightPin, LOW);
  }
}
void setupButtons() { //initiates the arduino ports array is calling to as INPUTs (buttons) and turns them to HIGH(which is off).
  for (int i = 0; i < NUM_LIGHTS; i++) {
   int buttonPin = buttonPins[i];
   pinMode(buttonPin, INPUT);
   digitalWrite(buttonPin, HIGH);
  }
}

void setup() {
  Serial.begin(9600); //opens serial port with arduino
  const int PIEZO = 11; //sets port 11 on ardunio as PIEZO (speaker)
  
  /* Init the lights to a LOW state */
  setupLights();
  /* Init buttons as inputs */
  setupButtons();
}


int songload = 0; //is a song loaded yet?
int songloops = 0;
int songlen;  
int *notes;  //points to song notes array
int *durations; //points to duration of notes array
int *offtones;  //points to duration between notes array
int counter=0;
void loop() {

  while(songload == 0) { //when no song is loaded, wait for song to be seleceted
    if (Serial.available() > 0)  //ardiuno recieves data from serial port execute
    {          
      char song = Serial.read(); //set data received equal to variable song
      
      if( song == '1' ) { // tetris
        songlen = 74;   //song length
        songloops = 1;  //how many time you want song to loop
        notes = new int[songlen];  //sets notes array equal in length to selected song
        durations = new int[songlen];  //sets durations array equal in length to selected song
        offtones = new int[songlen];   //sets offtones array equal in length to selected song
              int loadsong[] = {       //song notes
                                16,11,12,14,12,11,9,9,12,16,14,12,11,12,14,16,12,9,9,14,  //20
                                17,21,19,17,16,12,16,14,12,11,11,12,14,16,12,9,9,16,11,12, //40
                                14,12,11,9,9,12,16,14,12,11,12,14,16,12,9,9,14,17,21,19, //60
                                17,16,12,16,14,12,11,11,12,14,16,12,9,9 //74
                                };
              int loaddurs[] = {   //duration notes are held for
                                250,250,250,250,250,250,250,250,250,250,  //10
                                250,250,250,250,250,250,250,250,250,250,  //20
                                250,250,250,250,250,250,250,250,250,250,  //30
                                250,250,250,250,250,250,250,250,250,250,  //40
                                250,250,250,250,250,250,250,250,250,250,  //50
                                250,250,250,250,250,250,250,250,250,250,  //60
                                250,250,250,250,250,250,250,250,250,250,250,250,
                                };
              int loadofft[] = {   // duration between notes
                                 0,0,0,0,0,0,0,0,0,0,  //10
                                 0,0,0,0,0,0,0,0,0,0,  //20
                                 0,0,0,0,0,0,0,0,0,0,  //30
                                 0,0,0,0,0,0,0,0,0,0,  //40
                                 0,0,0,0,0,0,0,0,0,0,  //50
                                 0,0,0,0,0,0,0,0,0,0,  //60
                                 0,0,0,0,0,0,0,0,0,0,0,0,0
                                 };
                  for(int i=0;i<songlen;i++) {
                  notes[i] = loadsong[i];    //loads notes array with loadsong array elements
                  durations[i] = loaddurs[i];  //loads durations array with loadsong array elements
                  offtones[i] = loadofft[i];  //loads offtones array with loadsong array elements
                     }
          songload = 1;     //exits loop since song has been selected. (songload=1 not 0)
      }
      
      if( song == '2' ) { // mario
        songlen = 236;   //song length
        songloops = 1;   //how many time you want song to loop
           int loadsong[] = {   //song notes
                            16,16,16,12,16,19,7,12,7,4, //10
                            9,11,8,9,7,16,19,21,17,19,
                            16,12,14,11,12,7,4,9,11,8,9,
                            7,16,19,21,17,19,16,12,14,11,
                            19,18,17,15,16,10,9,12,9,12,
                            14,19,18,17,15,16,19,19,19,19,
                            18,17,15,16,10,9,12,9,12,14,
                            15,14,12,19,18,17,15,16,10,9,
                            12,9,12,14,19,18,17,15,16,19,
                            19,18,17,15,16,10,9,12,19,12,
                            14,15,14,12,12,12,12,12,14,16,
                            12,9,7,12,12,12,12,14,16,12,
                            12,12,12,14,16,12,9,7,16,16,
                            16,12,16,19,7,12,7,7,9,11,
                            8,9,7,16,19,21,17,19,16,12,
                            14,11,12,7,4,9,11,8,9,7,
                            16,19,21,17,19,16,12,14,11,16,
                            12,7,10,9,17,17,9,11,21,21,
                            21,19,17,16,12,9,7,16,12,7,
                            10,9,17,17,9,11,17,17,17,16,
                            14,12,16,12,7,10,9,17,17,9,
                            11,21,21,21,19,17,16,12,9,7,
                            16,12,7,10,9,17,17,9,11,17,
                            17,17,16,14,12 //236
                            };
           int loaddurs[] = {     //duration notes are held for
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,250,125,125,125,125, //20
                            125,125,125,125,125,125,250,125,125,125,125,125,125,125,125,125,125,125,125,125, //40
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //60
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //80
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //100
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //120
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //140
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //160
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //180
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //200
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125, //220
                            125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125  //236
                            };
           int loadofft[] = {   // duration between notes
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //20
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //40
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //60
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //80
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //100
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //120
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //140
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //160
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //180
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //200
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //220
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//236
                             };
                     notes = new int[songlen];   //sets notes array equal in length to selected song
                    durations = new int[songlen];  //sets durations array equal in length to selected song
                    offtones = new int[songlen];   //sets offtones array equal in length to selected song
               for(int i=0;i<songlen;i++) {
               notes[i] = loadsong[i];   //loads notes array with loadsong array elements
               durations[i] = loaddurs[i]; //loads durations array with loadsong array elements
                offtones[i] = loadofft[i]; //loads offtones array with loadsong array elements
                }
              songload = 1;   //exits loop since song has been selected. (songload=1 not 0)
      }
      
      if( song == '3' ) { // zelda
        songlen = 40;     //song length
        songloops = 1;    //how many time you want song to loop
        int loadsong[] = {   //song notes
                          5,9,11,5,9,11,5,9,11,16, //10
                          14,11,12,11,7,4,2,4,7,4, //20
                          5,9,11,5,9,11,5,9,11,16, //30
                          14,11,12,16,11,7,11,7,2,4 //40
                          };
        int loaddurs[] = {    // duration between notes
                          250,250,500,250,250,500,250,250,250,250, //10
                          500,250,250,250,250,750,250,250,250,750, //20
                          250,250,500,250,250,500,250,250,250,250, //30
                          250,250,500,250,250,500,250,250,250,1000 //40
                          };
        int loadofft[] = {0,0,0,0,0,0,0,0,0,0, //10
                          0,0,0,0,0,0,0,0,0,0, //20
                          0,0,0,0,0,0,0,0,0,0, //30
                          0,0,0,0,0,0,0,0,0,0 //40
                          };
                    notes = new int[songlen];       //loads notes array with loadsong array elements
                    durations = new int[songlen];   //loads durations array with loadsong array elements
                    offtones = new int[songlen];    //loads offtones array with loadsong array elements
             for(int i=0;i<songlen;i++) {
             notes[i] = loadsong[i];    //loads notes array with loadsong array elements
             durations[i] = loaddurs[i];   //loads durations array with loadsong array elements
             offtones[i] = loadofft[i];    //loads offtones array with loadsong array elements
                }
            songload = 1;   //exits loop since song has been selected. (songload=1 not 0)
      }
     
      if( song == '4' ) { // pokemon
        songlen = 58;    //song length
        songloops = 1;    //how many time you want song to loop
        int loadsong[] = {   //song notes
                          14,14,14,14,14,12,9,5,7,14,    //10
                          14,12,10,12,15,15,15,15,15,14, //20
                          12,10,10,14,14,12,10,14,14,14, //30
                          14,14,14,12,9,5,14,14,12,10,   //40
                          12,15,15,15,15,15,14,12,10,10, //50
                          14,14,12,10,14,14,17,19        //58
                           };
        int loaddurs[] = {   //duration notes are held for
                          125,125,125,250,125,125,125,250,125,125,   //10
                          125,125,125,500,125,125,125,125, 125,125,  //20
                          125,125,125,125,125,125,125,500,125,125,   //30
                          125,125,125,125,125,125,125,125,125,125,   //40
                          500,125,125,125,125,125,125,125,125,125,   //50
                          125,125,125,125,500,250,250,500            //58
                        };
        int loadofft[] = {   // duration between notes
                          0,0,0,0,0,0,0,0,0,0,     //10
                          0,0,0,500,0,0,0,0,0,0,   //20
                          0,0,0,0,0,0,0,250,0,0,   //30
                          0,0,0,0,0,0,0,0,0,400,   //40
                          0,0,0,0,0,0,0,0,0,0,     //50
                          0,0,0,400,0,0,0,0       //58
                          };
                      notes = new int[songlen];
                      durations = new int[songlen];
                      offtones = new int[songlen];
                for(int i=0;i<songlen;i++) {
                   notes[i] = loadsong[i];        //loads notes array with loadsong array elements
                   durations[i] = loaddurs[i];    //loads durations array with loadsong array elements
                   offtones[i] = loadofft[i];     //loads offtones array with loadsong array elements
                    }
             songload = 1;     //exits loop since song has been selected. (songload=1 not 0)
      }
      if( song == '7' ) { // Free Play Mode
        for(int i=0;i<24;i++) {      //go through all notes
      if(digitalRead(buttonPins[i]) == LOW) { //if button is low (down)
        tone(PIEZO, buttonFreqs[i]); //play note buzz     
        while(digitalRead(buttonPins[i]) == LOW) {     //holds sound until button is released.(without this line there is no sound)     
        }
        noTone(PIEZO); // no tone plays when button is not pressed.
         }
     }
     songload = 1;    //exits loop since song has been selected. (songload=1 not 0)
      }
    }   //serial available
  }    //song not loaded
      
  /* Turn on current light in sequence */
  int index = notes[currentSeqInd];
  digitalWrite(lightPins[index], HIGH);

  /* Wait for user to push the button associated with that light */
  while (digitalRead(buttonPins[index]) != LOW) {
    // Do nothing
    // see if a wrong key is pressed, if so, do something
    for(int i=0;i<24;i++) { //go through all notes
      if(i != index && digitalRead(buttonPins[i]) == LOW) { //if button is low (down)
        tone(PIEZO, buttonFreqs[i]); //play wrong note buzz
        while(digitalRead(buttonPins[i]) == LOW) { //while button remains down
          //wait for user to release wrong key
        }
        noTone(PIEZO);
      }
    }
  }

  
    tone(PIEZO, buttonFreqs[index]); //calls on the buttonsfreqs array to play correct tone based on index value (notes(currentseqind))
    delay(durations[currentSeqInd]); //calls on the durations array to hold the correct note duration based on currentseqind value. (how many notes into the song you are.)
    noTone(PIEZO);                   //turns sound off
    delay (30);                      // delay so you cant accidentally press note twice by holding down button
    delay(offtones[currentSeqInd]); //calls on the durations array to hold the correct note duration based on currentseqind value. (how many notes into the song you are.)
    Serial.println(counter);     //follows the notes in song for troubleshooting purposes
    counter ++;
    

  /* Turn off the light */
  digitalWrite(lightPins[index], LOW);     
  /* Update to the next light and note */
  currentSeqInd++;
  if(currentSeqInd >= songlen) { //if amount of notes played is equal to song length 
    songloops--;                 //-1 from songloops
    if(songloops == 0) {
      songload = 0;              //  set game back to choose song mode
      delete[] notes;            //unallocate memory used to store notes 
      delete[] durations;        //unallocate memory used to store durations 
      delete[] offtones;         //unallocate memory used to store offtones 
    }
    currentSeqInd = 0;         //restart currentseqind (note counter)
  }
}
