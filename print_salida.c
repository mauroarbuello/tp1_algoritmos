#define START_XML "<?"
#define MSJ_XML "xml"
#define MSJ_VERSION "version="
#define MSJ_ENCODING "encoding="
#define END_XML "?>"
#define START_GPX "<gpx" //a proposito la falta de >
#define END_GPX "</gpx>"
#define MSJ_VERSION "version="
#define MSJ_CREATOR "creator="
#define MSJ_XMLNS "xmlns="
#define START_METADATA "<metadata>"
#define END_METADATA "</metadata>"
#define START_NAME "<name>"
#define END_NAME "</name>"
#define START_TIME "<time>"
#define END_TIME "</time>"
#define START_TRK "<trk>"
#define END_TRK "</trk>"
#define START_TRKSEG "<trkseg>"
#define END_TRKSEG "</trkseg>"
#define START_TRKPT "<trkpt" //a proposito la falta de >
#define END_TRKPT "</trkpt>"
#define MSJ_LAT "lat="
#define MSJ_LON "lon="
#define CLOSE ">"
#define START_ELE "<ele>"
#define END_ELE "</ele>"

//puede que haya que agregar mas argumentos
void print_salida (struct fix_t, struct fecha_t, struct hora_t) {

  printf("%s %s %s"%.1f" %s"%s"%s\n",
  START_XML, MSJ_XML, MSJ_VERSION, ***version***, MSJ_ENCODING, ***encoding***, END_XML);

  //---gpx
  printf("%s %s"%.1f" %s"%s" %s"%s"\n",
  START_GPX, MSJ_VERSION, version, MSJ_CREATOR, ***creator***, MSJ_XMLNS, xmlns);

    //---metadata
    printf ("\t%s\n", START_METADATA);

      //name. poner un predefinido y si mandan por argv se pisa.
      printf("\t\t%s%s%s\n", START_NAME, ***name***, END_NAME);

      // time --- hay HC, sacarlos
      printf ("\t\t%s%d-%d-%dT%d:%d:%dZ%s\n",
      START_TIME, fix->fecha.year, fix->fecha.month, fix->fecha.day,
      fix->hora.hh , fix->hora.mm, fix->hora.ss, END_TIME);

    printf("\t%s\n", END_METADATA);

    //---trk
    printf("\t%s\n", START_TRK);

      //---trkseg
      printf("\t\t%s\n", START_TRKSEG);

        //---trkpt --- aca empiezan los datos
        /* definir como sabe el programa que se llego al ultimo dato*/
        for (i = 0, /*definir condicion*/, i++) {

          //lat y lon
        printf ("\t\t\t%s %s"%d" %s"%d"%c",
        START_TRKPT, MSJ_LAT, fix->latitud, MSJ_LON, fix->longitud, CLOSE);

          // --trkpt --> elevacion
          printf("\t\t\t\t%s%f%s\n", START_ELE, fix->elevacion, END_ELE);

          //--trkpt -->time (hay HC en "T" y "Z")
          printf ("\t\t\t\t%s%d-%d-%dT%d:%d:%dZ%s\n",
          START_TIME, fix->.fecha.year, fix->.fecha.month, fix->.fecha.day,
          fix->.hora.hh , fix->.hora.mm, fix->.hora.ss, END_TIME);

        //---end trkpt
        printf("\t\t\t%s\n", END_TRKPT);
      } //end for

      //---end trkseg
      printf("\t\t%s\n", END_TRKSEG);

    //---end trk
    printf("\t%s\n", END_TRK);

  //end gpx
  printf("%s\n", END_GPX);

}//end function
