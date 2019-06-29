#include<Servo.h>

Servo s1;//0(squish) - 140 (flat) // right //11
Servo s2;//140(squish) - 0 (flat) // left //12
Servo s3;//0(squish) - 180 (flat) // tail //13
Servo s4;//180(squish) - 0(flat) // left_up //8
//Servo s5;//180(squish) - 0(flat) // left_up //8

/*
Format for ACTION:
const int ACTION[][5] = { {time (ms), s1, s2, s3, s4},
...,
}
*/

const int crawling[5][5] = {{0, 70, 70, 180, 0}, 
{675, 25, 115, 135, 45},
{1950, 25, 115, 50, 130},
{3225, 70, 70, 95, 85},
{3900, 70, 70, 180, 0}};

const int walking[5][5] = {{0, 70, 70, 180, 0},
{315, 25, 115, 135, 45},
{910, 25, 115, 50, 130},
{1225, 70, 70, 95, 85},
{1820, 70, 70, 180, 0}};

const int runing[5][5] = {{0, 70, 70, 180, 0},
{135, 25, 115, 135, 45},
{390, 25, 115, 50, 130},
{525, 70, 70, 95, 85},
{780, 70, 70, 180, 0}};

const int sleeping[4][5] = {{0, 140, 0, 170, 0},
{2025, 95, 45, 125, 0},
{4050, 140, 0, 170, 0},
{4250, 140, 0, 170, 0}};

const int mating[3][5] = {{0, 70, 70, 90, 90},
{450, 70, 70, 45, 90},
{900, 70, 70, 90, 90}};

const int tail_wag[3][5] = {{0, -1, -1, 180, 90},
{210, -1, -1, 150, 90},
{420, -1, -1, 180, 90}};

const int excited[3][5] = {{0, 140, 0, 180, 180},
{210, 140, 0, 150, 150},
{420, 140, 0, 180, 180}};

const int tail_walk[3][5] = {{0, -1, -1, 180, -1},
{900, -1, -1, 0, -1},
{1800, -1, -1, 180, -1}};

const int swim__left[3][5] = {{0, 30, 110, -1, -1},
{450, 0, 80, -1, -1},
{950, 0, 80, -1, -1}};

const int swim__right[3][5] = {{0, 0, 80, -1, -1},
{900, 60, 140, -1, -1},
{1400, 60, 140, -1, -1}};

const int cautious_searching[6][5] = {{0, 30, 110, 90, 90},
{450, 0, 80, 90, 90},
{950, 0, 80, 90, 90},
{1850, 60, 140, 90, 90},
{2350, 60, 140, 90, 90},
{2800, 30, 110, 90, 90}};

const int sneaky_sneaky[15][5] = {{0, 30, 110, 90, 90},
{450, 0, 80, 90, 90},
{950, 0, 80, 90, 90},
{1850, 60, 140, 90, 90},
{2350, 60, 140, 90, 90},
{2799, 30, 110, 90, 90},
{2801, 70, 70, 180, 0},
{2935, 25, 115, 135, 45},
{3190, 25, 115, 50, 130},
{3325, 70, 70, 95, 85},
{3580, 70, 70, 180, 0},
{3715, 25, 115, 135, 45},
{3970, 25, 115, 50, 130},
{4105, 70, 70, 95, 85},
{4360, 70, 70, 180, 0}};

const int shock[4][5] = {{0, 140, 0, 180, 0},
{3, 140, 0, 150, 30},
{18, 140, 0, 150, 180},
{1018, 140, 0, 150, 180}};

const int relax[3][5] = {{0, -1, -1, 150, 180},
{450, -1, -1, 180, 150},
{2700, -1, -1, 180, 0}};

const int flinching[5][5] = {{0, 70, 70, 90, 90},
{90, 70, 100, 90, 120},
{1090, 70, 100, 90, 120},
{1540, 70, 70, 90, 90},
{4040, 70, 70, 90, 90}};

const int left[3][5] = {{0, 45, 95, -1, 90},
{225, 0, 50, -1, 135},
{450, 45, 95, -1, 90}};

const int right[3][5] = {{0, 45, 95, -1, 90},
{225, 90, 140, -1, 135},
{450, 45, 95, -1, 90}};

const int dance[17][5] = {{0, 45, 95, 90, 90},
{225, 0, 50, 90, 135},
{450, 45, 95, 90, 90},
{675, 90, 140, 90, 135},
{900, 45, 95, 90, 90},
{1125, 0, 50, 90, 135},
{1350, 45, 95, 90, 90},
{1575, 0, 50, 90, 135},
{1800, 45, 95, 90, 90},
{2025, 90, 140, 90, 135},
{2250, 45, 95, 90, 90},
{2475, 0, 50, 90, 135},
{2700, 45, 95, 90, 90},
{2925, 90, 140, 90, 135},
{3150, 45, 95, 90, 90},
{3375, 90, 140, 90, 135},
{3600, 45, 95, 90, 90}};

const int poking[6][5] = {{0, 70, 70, 90, 90},
{90, 70, 40, 90, 60},
{180, 70, 70, 90, 90},
{270, 70, 40, 90, 60},
{360, 70, 70, 90, 90},
{2860, 70, 70, 90, 90}};

const int panting[3][5] = {{0, 90, 50, 90, 70},
{300, 60, 80, 90, 100},
{600, 90, 50, 90, 70}};

const int limping[8][5] = {{0, 100, 100, 90, 90},
{100, 90, 100, 90, 90},
{200, 80, 100, 80, 90},
{500, 50, 130, 50, 90},
{600, 50, 130, 50, 90},
{700, 60, 130, 50, 90},
{800, 70, 130, 60, 90},
{1100, 100, 100, 90, 90}};

const int showing_off[17][5] = {{0, 30, 110, 180, 90},
{210, 30, 110, 150, 90},
{420, 30, 110, 180, 90},
{630, 30, 110, 150, 90},
{840, 30, 110, 180, 90},
{1050, 30, 110, 150, 90},
{1260, 30, 110, 180, 90},
{1710, 0, 80, 180, 90},
{2210, 0, 80, 180, 90},
{2420, 0, 80, 150, 90},
{2630, 0, 80, 180, 90},
{2840, 0, 80, 150, 90},
{3050, 0, 80, 180, 90},
{3260, 0, 80, 150, 90},
{3470, 0, 80, 180, 90},
{4370, 60, 140, 180, 90},
{4870, 60, 140, 180, 90}};

const int spasm[9][5] = {{0, 70, 70, 90, 90},
{90, 40, 100, 60, 120},
{240, 70, 70, 90, 90},
{330, 40, 100, 60, 120},
{480, 70, 70, 90, 90},
{2480, 70, 70, 90, 90},
{2570, 40, 100, 60, 120},
{2720, 70, 70, 90, 90},
{4720, 70, 70, 90, 90}};

const int amazed[20][5] = {{0, 140, 0, 180, 0},
{280, 0, 140, 40, 140},
{779, 0, 140, 40, 140},
{781, 0, 140, 180, 180},
{929, 0, 140, 150, 150},
{931, 0, 140, 30, 150},
{1079, 0, 140, 0, 180},
{1081, 0, 140, 180, 180},
{1229, 0, 140, 150, 150},
{1231, 0, 140, 30, 150},
{1379, 0, 140, 0, 180},
{1381, 0, 140, 180, 180},
{1529, 0, 140, 150, 150},
{1531, 0, 140, 30, 150},
{1679, 0, 140, 0, 180},
{1681, 0, 140, 180, 180},
{1829, 0, 140, 150, 150},
{1831, 0, 140, 30, 150},
{1980, 0, 140, 0, 180},
{3980, 0, 140, 0, 180}};

const int angry[3][5] = {{0, 0, 140, 120, 180},
{150, 0, 140, 90, 150},
{300, 0, 140, 120, 180}};

const int clapping[4][5] = {{0, 0, 140, 120, 180},
{279, 0, 140, 135, 135},
{281, 0, 140, 135, 30},
{560, 0, 140, 165, 0}};

const int scared[5][5] = {{0, 70, 70, 120, 90},
{1, 0, 140, 120, 180},
{69, 7, 133, 134, 166},
{71, 7, 133, 127, 166},
{140, 0, 140, 113, 180}};

const int hiding[25][5] = {{0, 140, 0, 180, 0},
{1, 30, 110, 180, 0},
{450, 0, 80, 180, 0},
{470, 0, 80, 180, 0},
{2270, 60, 140, 180, 0},
{2290, 60, 140, 180, 0},
{3189, 30, 110, 180, 0},
{3191, 70, 70, 180, 0},
{3250, 50, 90, 20, 160},
{3460, 50, 90, 90, 90},
{3520, 70, 70, 110, 70},
{3730, 70, 70, 180, 0},
{3790, 50, 90, 20, 160},
{4000, 50, 90, 90, 90},
{4060, 70, 70, 110, 70},
{4270, 70, 70, 180, 0},
{4330, 50, 90, 20, 160},
{4540, 50, 90, 90, 90},
{4600, 70, 70, 110, 70},
{4810, 70, 70, 180, 0},
{4870, 50, 90, 20, 160},
{5080, 50, 90, 90, 90},
{5140, 70 ,70, 110, 70},
{5350, 70, 70, 180, 0},
{5370, 70, 70, 180, 0}};

const int jumping[4][5] = {{0, 140, 0, 180, 0},
{140, 0, 140, 40, 140},
{320, 180, 0, 180, 0},
{1120, 180, 0, 180, 0}};

const int bored[4][5] = {{0, 140, 0, 180, 0},
{500, 140, 0, 130, 0},
{550, 140, 0, 180, 0},
{1050, 140, 0, 180, 0}};

const int shakedry[26][5] = {{0, 90, 90, 130, 0},
{1800, 90, 90, 130, 180},
{1890, 105, 105, 130, 180},
{1980, 90, 90, 130, 180},
{2070, 105, 105, 130, 180},
{2160, 90, 90, 130, 180},
{2250, 105, 105, 130, 180},
{2340, 90, 90, 130, 180},
{2430, 105, 105, 130, 180},
{2520, 90, 90, 130, 180},
{2560, 100, 100, 130, 180},
{2600, 90, 90, 130, 180},
{2640, 100, 100, 130, 180},
{2680, 90, 90, 130, 180},
{2720, 100, 100, 130, 180},
{2760, 90, 90, 130, 180},
{2800, 100, 100, 130, 180},
{2840, 90, 90, 130, 180},
{2880, 100, 100, 130, 180},
{2920, 90, 90, 130, 180},
{2960, 100, 100, 130, 180},
{3000, 90, 90, 130, 180},
{3040, 100, 100, 130, 180},
{3080, 90, 90, 130, 180},
{3120, 100, 100, 130, 180},
{3160, 90, 90, 130, 180}};

const int retreat[22][5] = {{0, 0, 140, 50, 40},
{1120, 140, 140, 50, 40},
{1819, 140, 0, 50, 40},
{1821, 0, 140, 50, 40},
{2940, 140, 140, 50, 40},
{3639, 140, 0, 50, 40},
{3641, 0, 140, 50, 40},
{4760, 140, 140, 50, 40},
{5459, 140, 0, 50, 40},
{5461, 0, 140, 50, 40},
{6580, 140, 140, 50, 40},
{7279, 140, 0, 50, 40},
{7281, 0, 140, 50, 40},
{8400, 140, 140, 50, 40},
{9099, 140, 0, 50, 40},
{9109, 0, 140, 50, 40},
{10220, 140, 140, 50, 40},
{10919, 140, 0, 50, 40},
{10921, 0, 140, 50, 40},
{12040, 140, 140, 50, 40},
{12740, 140, 0, 50, 40},
{12870, 140, 0, 180, 40}};

const int dying[9][5] = {{0, 120, 50, 180, 50},
{299, 90, 50, 180, 35},
{301, 120, 50, 180, 50},
{2699, 90, 50, 180, 35},
{2701, 100, 50, 180, 40},
{6199, 30, 50, 180, 5},
{6201, 50, 50, 180, 0},
{10200, 0, 50, 180, 17},
{13200, 0, 80, 180, 17}};

const int lazy[4][5] = {{0, 140, 0, 180, 0},
{1500, 40, 100, 180, 0},
{2500, 40, 100, 180, 100},
{4000, 40, 0, 180, 0}};

const int fighting[19][5] = {{0, 140, 0, 0, 0},
{700, 140, 140, 0, 0},
{879, 140, 140, 0, 180},
{881, 0, 140, 0, 180},
{1580, 140, 0, 0, 40},
{2139, 140, 0, 0, 180},
{2141, 0, 140, 0, 40},
{2320, 0, 140, 0, 180},
{3020, 140, 0, 0, 40},
{3579, 140, 0, 0, 180},
{3581, 0, 140, 0, 40},
{3760, 0, 140, 0, 180},
{4460, 140, 0, 0, 40},
{5019, 140, 0, 0, 180},
{5021, 0, 140, 0, 40},
{5200, 0, 140, 0, 180},
{5900, 140, 0, 0, 40},
{6459, 140, 0, 0, 180},
{6461, 0, 140, 0, 40}};

const int progressive_panting[13][5] = {{0, 90, 50, 90, 70},
{300, 60, 80, 90, 100},
{600, 90, 50, 90, 70},
{930, 60, 80, 90, 100},
{1260, 90, 50, 90, 70},
{1620, 60, 80, 90, 100},
{1980, 90, 50, 90, 70},
{2370, 60, 80, 90, 100},
{2760, 90, 50, 90, 70},
{3180, 60, 80, 90, 100},
{3600, 90, 50, 90, 70},
{4050, 60, 80, 90, 100},
{4500, 90, 50, 90, 70}};

const int blank1[2][5] = {{0, -1, -1, -1, -1},
{100, -1, -1, -1, -1}};

const int blank5[2][5] = {{0, -1, -1, -1, -1},
{500, -1, -1, -1, -1}};

const int blank0[2][5] = {{0, -1, -1, -1, -1},
{1, -1, -1, -1, -1}};

const int twitching[5][5] = {{0, 0, 140, 120, 180},
{9, 10, 130, 170, 170},
{11, 15, 125, 165, 165},
{20, 5, 135, 175, 175},
{3020, 5, 135, 175, 175}};


unsigned long START_TIME;

const byte trig_pin = 5;
const byte echo_pin = 6;
const byte shock_pin = 7;

float sound_cum = 0;
const byte sound_samples = 140;

const byte far_limit = 50;
const byte close_limit = 20;
const byte shock_limit = 2;
const int shock_length = 10000;

int shock_count = 0;
int shock_elapsed = 0;
unsigned long shock_start = 0;

unsigned long hold_start = 0;
const int hold_limit = 500;

bool shock_transition = false;


#define NIL 0

#define STATE_ALONE     1
#define STATE_FAR       2
#define STATE_CLOSE     3

#define STATE_SHOCK     4
#define STATE_CHILL     5

#define CRAWLING            11
#define WALKING             12
#define RUNNING             13
#define SLEEPING            14
#define MATING              15
#define TAIL_WAG            16
#define EXCITED             17
#define TAIL_WALK           18
#define SWIM_LEFT           19
#define SWIM_RIGHT          20
#define CAUTIOUS_SEARCHING  21
#define SNEAKY_SNEAKY       22
#define SHOCK               23
#define RELAX               24
#define FLINCHING           25
#define LEFT                26
#define RIGHT               27
#define DANCE               28
#define POKING              29
#define PANTING             30
#define LIMPING             31
#define SHOWING_OFF         32
#define SPASM               33
#define AMAZED              34
#define ANGRY               35
#define CLAPPING            36
#define SCARED              37
#define HIDING              38
#define JUMPING             39
#define BORED               40
#define SHAKEDRY            41
#define RETREAT             42
#define DYING               43
#define LAZY                44
#define FIGHTING            45
#define PROGRESSIVE_PANTING 46
#define BLANK1              47
#define BLANK5              48
#define BLANK0              49
#define TWITCHING           50

#define C_C   101
#define C_F   102
#define C_A   103
#define S_C   104
#define S_F   105
#define S_A   106
#define S_I   107

byte SHOCK_STATE = NIL;
byte DIST_STATE = NIL;
byte DIST_HOLD_STATE = NIL;
byte DIST_NEW_STATE = NIL;
byte ACTIVE_ACTION = NIL;
byte OLD_SHOCK_STATE = NIL;
byte OLD_DIST_STATE = NIL;
byte ACTIVE_SET = NIL;
byte OLD_ACTIVE_SET = NIL;
byte ACTION_COUNT = 0;

// Action sets
// Each action set is a byte array containing actions to be carried out in sequence
byte CHILL_CLOSE[11] = {CLAPPING, CLAPPING, JUMPING, NIL, CLAPPING, CLAPPING, CLAPPING,
  NIL, NIL, NIL, NIL}; // nonstatic
byte CHILL_FAR[16] = {NIL, NIL, NIL, NIL, NIL, BLANK1, BLANK1, LEFT, RIGHT, LEFT, RIGHT,
  BLANK1, BLANK1, NIL, NIL, NIL}; // nonstatic
byte CHILL_ALONE[17] = {WALKING, WALKING, BLANK5, DANCE, PANTING, PANTING, DANCE, PANTING, 
  DANCE, DANCE, PANTING, PROGRESSIVE_PANTING, CRAWLING, CRAWLING, BLANK5, BLANK5, BLANK5};
byte SHOCK_CLOSE[30] = {SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED,
  SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, SCARED, TWITCHING,
  TWITCHING, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5, BLANK5};
byte SHOCK_FAR[2] = {RETREAT, RETREAT};
byte SHOCK_ALONE[9] = {CAUTIOUS_SEARCHING, CAUTIOUS_SEARCHING, BLANK5, SCARED, SCARED,
  SCARED, SCARED, SCARED, SCARED};
byte SHOCK_INITIAL[1] = {SHOCK};


byte progress(int t, int action[][5], byte len){
  for(byte i=0; i<len; i++){
    if(t < action[i][0]){
      return i-1;
    }
  }
  return len-1;
}

bool execute(int ACTION[][5]){
  // Require variables: ACTION, START_TIME
  // ACTION is an array containing the information of the action
  // START_TIME is, as the name suggests, the start time (with millis())
  // Should be reset separately everytime ACTION is changed

  int CURRENT_TIME = millis() - START_TIME;
  byte lengt = (sizeof(ACTION[0])/sizeof(ACTION[0][0]));

  // If CURRENT_TIME exceeds the last time, START_TIME should be reset
  // In other words, if nothing else happens, it will loop
  // When the loop happens, it returns true; otherwise, it returns false.
  // This way, we know when an action is completed

  // We need to find the current position of the progression
  byte pos = progress(CURRENT_TIME, ACTION, lengt);
  // This is given as the most recently passed checkpoint
  
  if(pos == lengt-1){
    START_TIME = millis();
    CURRENT_TIME = 0;
    pos = 0;
    return true;
  }

  // Now, we need to calculate the position that the servos should be at
  // for the current time, and move them as needed

  float delta = ACTION[pos+1][0] - ACTION[pos][0];
  int elapsed = CURRENT_TIME - ACTION[pos][0];

  float gradient[4];
  float posit[4];

  for(byte i=0; i<4; i++){
    gradient[i] = (ACTION[pos+1][i+1] - ACTION[pos][i+1]) / delta * 1.0;
  }


  for(byte i=0; i<4; i++){
    posit[i] = ACTION[pos][i+1] + elapsed * gradient[i];
  }

  // For actions which isolate certain parts
  bool mov[4];

  for(byte i=0; i<4; i++){
    if(ACTION[pos][i+1] == -1){
      mov[i] = false;
    }else{
      mov[i] = true;
    }
  }

  if(mov[0]){
    s1.write(posit[0]);
  }
  if(mov[1]){
    s2.write(posit[1]);
  }
  if(mov[2]){
    s3.write(posit[2]);
  }
  if(mov[3]){
    s4.write(posit[3]);
  }
  
  return false;
}

float get_reading_ultrasonic(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  float duration = pulseIn(echo_pin, HIGH, 10000);
  float distance = (duration * 0.0343) / 2; // centimeters

  if(distance < 1500 && distance > 0){
    sound_cum -= sound_cum/sound_samples;
    sound_cum += distance;
  }

  return sound_cum/sound_samples;
}

bool get_reading_shock(){
  if(digitalRead(shock_pin) == HIGH){
    shock_count++;
  }else{
    shock_count = 0;
  }

  if(shock_count >= shock_limit){
    shock_count = 0;
    return true;
  }else{
    return false;
  }
}

bool handler(byte act){
  // Actions which are unused are commented out here to save memory.
  // Should more actions be required and SRAM is exceeded, use PROGMEM
  switch(act){
    case CRAWLING:
      return execute(crawling);
      break;
    case WALKING:
      return execute(walking);
      break;
    case RUNNING:
      return execute(runing);
      break;
    /*
    case SLEEPING:
      return execute(sleeping);
      break;
    */
    case MATING:
      return execute(mating);
      break;
    /*
    case TAIL_WAG:
      return execute(tail_wag);
      break;
    */
    case EXCITED:
      return execute(excited);
      break;
    /*
    case TAIL_WALK:
      return execute(tail_walk);
      break;
    case SWIM_LEFT:
      return execute(swim__left);
      break;
    case SWIM_RIGHT:
      return execute(swim__right);
      break;
    */
    case CAUTIOUS_SEARCHING:
      return execute(cautious_searching);
      break;
    /*
    case SNEAKY_SNEAKY:
      return execute(sneaky_sneaky);
      break;
    */
    case SHOCK:
      return execute(shock);
      break;
    /*
    case RELAX:
      return execute(relax);
      break;
    case FLINCHING:
      return execute(flinching);
      break;
    */
    case LEFT:
      return execute(left);
      break;
    case RIGHT:
      return execute(right);
      break;
    case DANCE:
      return execute(dance);
      break;
    /*
    case POKING:
      return execute(poking);
      break;
    */
    case PANTING:
      return execute(panting);
      break;
    /*
    case LIMPING:
      return execute(limping);
      break;
    case SHOWING_OFF:
      return execute(showing_off);
      break;
    case SPASM:
      return execute(spasm);
      break;
    case AMAZED:
      return execute(amazed);
      break;
    case ANGRY:
      return execute(angry);
      break;
    */
    case CLAPPING:
      return execute(clapping);
      break;
    case SCARED:
      return execute(scared);
      break;
    /*
    case HIDING:
      return execute(hiding);
      break;
    */
    case JUMPING:
      return execute(jumping);
      break;
    /*
    case BORED:
      return execute(bored);
      break;
    case SHAKEDRY:
      return execute(shakedry);
      break;
    */
    case RETREAT:
      return execute(retreat);
      break;
    /*
    case DYING:
      return execute(dying);
      break;
    case LAZY:
      return execute(lazy);
      break;
    case FIGHTING:
      return execute(fighting);
      break;
    */
    case PROGRESSIVE_PANTING:
      return execute(progressive_panting);
      break;
    case BLANK1:
      return execute(blank1);
      break;
    case BLANK5:
      return execute(blank5);
      break;
    case BLANK0:
      return execute(blank0);
      break;
    case TWITCHING:
      return execute(twitching);
      break;
    default:
      return false;
  }
}

void set_active_action(byte act_s, byte act_c){
  switch(act_s){
    case C_C:
      ACTIVE_ACTION = CHILL_CLOSE[act_c];
      break;
    case C_F:
      ACTIVE_ACTION = CHILL_FAR[act_c];
      break;
    case C_A:
      ACTIVE_ACTION = CHILL_ALONE[act_c];
      break;
    case S_C:
      ACTIVE_ACTION = SHOCK_CLOSE[act_c];
      break;
    case S_F:
      ACTIVE_ACTION = SHOCK_FAR[act_c];
      break;
    case S_A:
      ACTIVE_ACTION = SHOCK_ALONE[act_c];
      break;
    case S_I:
      ACTIVE_ACTION = SHOCK_INITIAL[act_c];
      break;
  }
}

// Hardcoded function to retrieve length of action set
int get_length(byte act_s){
  switch(act_s){
    case C_C:
      return 11;
      break;
    case C_F:
      return 16;
      break;
    case C_A:
      return 17;
      break;
    case S_C:
      return 30;
      break;
    case S_F:
      return 2;
      break;
    case S_A:
      return 9;
      break;
    case S_I:
      return 1;
      break;
  }
}

void new_CHILL_FAR(){
  if(random(0, 3)){
    for(byte i=0; i<5; i++){
      CHILL_FAR[i] = EXCITED;
    }
  }else{
    for(byte i=0; i<5; i++){
      CHILL_FAR[i] = BLANK0;
    }
  }

  if(random(0, 2)){
    for(byte i=13; i<16; i++){
      CHILL_FAR[i] = RUNNING;
    }
  }else{
    for(byte i=13; i<16; i++){
      CHILL_FAR[i] = BLANK0;
    }
  }

}

void new_CHILL_CLOSE(){
  if(random(0, 3)){
    CHILL_CLOSE[3] = JUMPING;
  }else{
    CHILL_CLOSE[3] = BLANK0;
  }

  if(random(0, 2)){
    for(byte i=7; i<9; i++){
      CHILL_CLOSE[i] = CLAPPING;
    }
  }else{
    for(byte i=7; i<9; i++){
      CHILL_CLOSE[i] = BLANK0;
    }
  }

  if(random(0, 2)){
    for(byte i=9; i<11; i++){
      CHILL_CLOSE[i] = RUNNING;
    }
  }else{
    for(byte i=9; i<11; i++){
      CHILL_CLOSE[i] = BLANK0;
    }
  }
}

void reset_variable_sets(){
  new_CHILL_FAR();
  new_CHILL_CLOSE();
}


void setup() {
  // put your setup code here, to run once:
  s1.attach(11);
  s2.attach(12);
  s3.attach(13);
  s4.attach(8);
  Serial.begin(9600);
  /*
  s1.write(70);
  s2.write(70);
  s3.write(90);
  s4.write(0);
  */

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  pinMode(shock_pin, INPUT);

  START_TIME = millis();
}

void loop(){
  // Collect sensor information
  float dist = get_reading_ultrasonic();
  bool shocked = get_reading_shock();

  // Determine next state and logic pathway
  if(dist < close_limit){
    DIST_NEW_STATE = STATE_CLOSE;
  }else if(dist < far_limit){
    DIST_NEW_STATE = STATE_FAR;
  }else{
    DIST_NEW_STATE = STATE_ALONE;
  }

  if(DIST_NEW_STATE != DIST_STATE){
    if(DIST_NEW_STATE != DIST_HOLD_STATE){
      DIST_HOLD_STATE = DIST_NEW_STATE;
      hold_start = millis();
    }
    if(millis() - hold_start > hold_limit){
      DIST_STATE = DIST_HOLD_STATE;
      Serial.println(F("New Distance State:"));
      Serial.println(DIST_STATE);
    }
  }

  if(shocked || (OLD_DIST_STATE == STATE_ALONE && DIST_STATE == STATE_CLOSE)){
    SHOCK_STATE = STATE_SHOCK;
    if(OLD_SHOCK_STATE != STATE_SHOCK){
      shock_transition = true;
      Serial.println(F("Shock transition started"));
    }
  }
  

  // Select action set to use
  if(SHOCK_STATE == STATE_SHOCK){
    if(shock_transition){
      ACTIVE_SET = S_I;
    }else{
      switch(DIST_STATE){
        case STATE_ALONE:
          if(millis() - shock_start > shock_length){
            ACTIVE_SET = C_A;
            SHOCK_STATE = STATE_CHILL;
            Serial.println(F("Shock state exited"));
          }else{
            ACTIVE_SET = S_A;
          }
          break;
        case STATE_FAR:
          shock_start = millis();
          ACTIVE_SET = S_F;
          break;
        case STATE_CLOSE:
          shock_start = millis();
          ACTIVE_SET = S_C;
          break;
      }
    }
  }else{
    switch(DIST_STATE){
      case STATE_ALONE:
        ACTIVE_SET = C_A;
        break;
      case STATE_FAR:
        ACTIVE_SET = C_F;
        break;
      case STATE_CLOSE:
        ACTIVE_SET = C_C;
        break;
    }
  }

  if(ACTIVE_SET != OLD_ACTIVE_SET){
    reset_variable_sets();
    ACTION_COUNT = 0;
    START_TIME = millis();
    Serial.println(F("New active set: "));
    Serial.println(ACTIVE_SET);
  }

  // Select action from action set
  set_active_action(ACTIVE_SET, ACTION_COUNT);

  // Execute action
  bool done = handler(ACTIVE_ACTION);

  if(done){
    // Either progress on to next action, loop, or exit transition
    START_TIME = millis();
    if(shock_transition){
      shock_transition = false;
      shock_start = millis();
      Serial.println(F("Shock Transition Ended"));
    }else{
      ACTION_COUNT++;
      if(ACTION_COUNT >= get_length(ACTIVE_SET)){
        ACTION_COUNT = 0;
        reset_variable_sets();
      }
    }
  }

  OLD_SHOCK_STATE = SHOCK_STATE;
  OLD_DIST_STATE = DIST_STATE;
  OLD_ACTIVE_SET = ACTIVE_SET;
}
