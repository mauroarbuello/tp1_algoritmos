/* Mando la estructura fix_t y un tipo de dato que se llama canlidad_t, que indica
la calidad del fix*/

#define MSJ_0 "invalido"
#define MSJ_1 "fix GPS (SPS)"
#define MSJ_2 "fix DGPS"
#define MSJ_3 "fix PPS"
#define MSJ_4 "Real Time Kinematic"
#define MSJ_5 "Float RTK"
#define MSJ_6 "Estimada (dead reckoning)"
#define MSJ_7 "Manual"
#define MSJ_8 "Simulación"

typedef enum CALIDAD {

  "MSJ_0", "MSJ_1", "MSJ_2", "MSJ_3", "MSJ_4",
  "MSJ_5", "MSJ_6", "MSJ_7", "MSJ_8"

}calidad_t;

typedef struct FIX {

  double fecha;
  double latitud, longitud;
  char ns, we;
  calidad_t calidad; //hacer un tipo de dato calidad_t
  unsigned cant_sat;
  float hdop;
  float elevacion;
  float, sep_geoide;

}fix_t;
