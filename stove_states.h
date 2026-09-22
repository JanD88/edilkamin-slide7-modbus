#pragma once
#include <string>

inline std::string ek_state_name(int v) {
  switch (v) {
    case   1: return "OFF";
    case   2: return "ON  FAKE";
    case   3: return "CHK RC";
    case   4: return "CHK PLT";
    case   5: return "CHK TF";
    case   6: return "CLEAN_F";
    case   7: return "LOAD_F";
    case   8: return "START 1_F";
    case   9: return "START 2_F";
    case  10: return "WARM UP";
    case  11: return "Pmin";
    case  12: return "Pmax";
    case  13: return "CLEAN_S3";
    case  14: return "CLEAN_S4";
    case  15: return "CLEAN_S5";
    case  16: return "CLEAN_C";
    case  17: return "START 1_C";
    case  18: return "START 2_C";
    case  19: return "CLEAN_R1";
    case  20: return "CLEAN_R2";
    case  21: return "LEVEL 1";
    case  22: return "LEVEL 2";
    case  23: return "LEVEL 3";
    case  24: return "LEVEL 4";
    case  25: return "LEVEL 5";
    case  26: return "MUTE";
    case  27: return "MUTE";
    case  28: return "LIMIT TF";
    case  29: return "UNLOCK";
    case  31: return "LEVEL 1";
    case  32: return "LEVEL 2";
    case  33: return "LEVEL 3";
    case  34: return "LEVEL 4";
    case  35: return "LEVEL 5";
    case  36: return "MUTE";
    case  37: return "MUTE";
    case  38: return "TF LIMIT";
    case  41: return "Missed Ignition";
    case  42: return "OFF";
    case  44: return "Fluegas Overtemp.";
    case  45: return "Smoke Probe Failure";
    case  46: return "Flame Extinction";
    case  47: return "Pressure Switch";
    case  49: return "Pellet Safety";
    case  50: return "Room.Sens. Failure";
    case  51: return "Room.Sens2 Failure";
    case  52: return "Room.Sens3 Failure";
    case  53: return "Smoke Fan";
    case  54: return "Leonardo Connect.";
    case  55: return "Clean Brazier";
    case  56: return "EL.Board Overtemp";
    case  57: return "Auger Motor";
    case  58: return "Alarm EQ";
    case  61: return "Missed Ignition";
    case  62: return "OFF";
    case  64: return "Fluegas Overtemp.";
    case  65: return "Smoke Probe Failure";
    case  66: return "Flame Extinction";
    case  67: return "Pressure Switch";
    case  69: return "Pellet Safety";
    case  70: return "Room.Sens. Failure";
    case  71: return "Room.Sens2 Failure";
    case  72: return "Room.Sens3 Failure";
    case  73: return "Smoke Fan";
    case  74: return "Leonardo Connect.";
    case  75: return "Clean Brazier";
    case  76: return "EL.Board Overtemp";
    case  77: return "Auger Motor";
    case  78: return "Alarm EQ";
    case  81: return "OFF";
    case  82: return "RESET?";
    case  83: return "OFF";
    case  84: return "OFF";
    case  85: return "OFF_Stb";
    case  86: return "COOL";
    case  87: return "COOL";
    case  88: return "Stand_by";
    case  89: return "EndPlt_OFF";
    case  90: return "End Plt_ON";
    case  92: return "OFF";
    case  93: return "CHK PULIT.";
    case  94: return "OFF";
    case  99: return "PLT";
    case 100: return "TEST";
    case 101: return "ON";
    case 102: return "OFF";
    default: break;
  }
  switch (v) {
    case  30:
    case  39:
    case  40:
    case  43:
    case  48:
    case  59:
    case  60:
    case  63:
    case  68:
    case  79:
    case  80:
    case  91:
    case  95:
    case  96:
    case  97:
    case  98:
      return "unlabelled";
    default: break;
  }
  return std::string("state ") + std::to_string(v);
}

inline bool ek_state_is_alarm(int v) {
  switch (v) {
    case 41: case 44: case 45: case 46: case 47: case 49: case 50: case 51:
    case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 61:
    case 64: case 65: case 66: case 67: case 69: case 70: case 71: case 72:
    case 73: case 74: case 75: case 76: case 77: case 78:
      return true;
    default:
      return false;
  }
}
