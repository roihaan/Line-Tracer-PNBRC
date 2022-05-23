#include <ichibotArduinoNano.h>
ichibotArduinoNano ichibot;

void setup() {
  //  ichibot.sudutGripperAngkat = 60;
  //  ichibot.sudutGripperTaruh  = 30;
  //  ichibot.sudutGripperJepit  = 70;
  //  ichibot.sudutGripperLepas  = 130;
  //  ichibot.delayGripper = 1000;

  ichibot.begin();                                                                        // inisialisasi robot
  //ichibot.useAutoScanMenu = 1;                                                            // 1 = autoscan, 0 = manual scan
  ichibot.setSensorSensivity(50);                                                         // set sensivity untuk kalibrasi otomatis; set nilai dari 1 (paling tidak sensitif) sampai 100 (paling sensisitif);
  //ichibot.setLimitSensorManual(1023,200,1023,200,200,200,200,200,200,200,200, 1023);      // set nilai kalibrasi manual jika ingin memakai set manual secara hardcode;
  ichibot.setFanMode(ACTIVE_HIGH);                                                        // set mode activasi kipas
  ichibot.setBuzzerMode(HIGH);                                                            // set buzzer notifikasi index
  ichibot.setLineWidth(TWO_CM);                                                           // set lebar garis TWO_CM, THREE_CM, FOUR_CM, MIX (gabungan)

  //set inisialisasi PID : nomor, Kp, Ki, Kd , PMax , PMin
  ichibot.setPID(PID_0, 7, 0, 5, 255, -50);
  ichibot.setPID(PID_1, 8, 10, 10, 255, -60);
  ichibot.setPID(PID_2, 9, 15, 15, 255, -70);
  ichibot.setPID(PID_3, 10, 20, 20, 255, -80);
  ichibot.setPID(PID_4, 12, 25, 25 , 255, -90);
  ichibot.setPID(PID_5, 13, 30, 30, 255, -100);

  // ========================== CHECK POINT ==========================  //
  // MENGATUR INDEX PADA SETIAP CHECK POINT, TERDAPAT 6 BUAH CHECKPOINT //
  ichibot.setCheckPoint (CP_0, 0);
  ichibot.setCheckPoint (CP_1, 5);
  ichibot.setCheckPoint (CP_2, 3);
  ichibot.setCheckPoint (CP_3, 7);
  ichibot.setCheckPoint (CP_4, 9);

  // =============================                TEMPLATE             =============================  //
  /*
                                  L    R   D                   SA  TA
     ichibot.setIndex(0, MOTION, 100, 100, 10, SENSOR_SEMUA,  150, 0, PID_3, GARIS_HITAM, KIPAS_OFF,NORMAL);
                                      D                        SA  TA
     ichibot.setIndex(1, BELOK_KIRI, 100, SENSOR_KIRI_TENGAH,  170, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL)
                                D                         SA  TA
     ichibot.setIndex(2, STOP, 100, SENSOR_KANAN_TENGAH ,  0, 30, PID_0, GARIS_HITAM, KIPAS_ON,NORMAL);
  */
     
  // =============== STOP INDEX =============== ROBOT AKAN BERHENTI JIKA SUDAH MENCAPAI INDEX DIBAWAH INI //
     //ichibot.setStopIndex(0);
     ichibot.setStopIndex(5);
     //ichibot.setStopIndex(5);

  // ============================= TEMPAT MENULISKAN SEMUA PERINTAH INDEX =============================  //
     
    ichibot.setIndex(0, MOTION, 85, 80, 1100, SENSOR_KOSONG, 150, 0, PID_0, GARIS_HITAM, KIPAS_OFF,NORMAL);
      //ichibot.setIndex(0,LURUS, 100, SENSOR_SEMUA,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
      ichibot.setIndex(1,LURUS, 70, SENSOR_SEMUA,  80, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL); 
      ichibot.setIndex(2,BELOK_KANAN, 80, SENSOR_KANAN_TENGAH,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
      //ichibot.setIndex(3, MOTION, 80, 80, 1100, SENSOR_KOSONG, 150, 0, PID_0, GARIS_HITAM, KIPAS_OFF,NORMAL);
      ichibot.setIndex(3,BELOK_KIRI, 80, SENSOR_KIRI,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
      ichibot.setIndex(4,BELOK_KANAN, 80, SENSOR_KANAN_TENGAH,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
      //ichibot.setIndex(4,LURUS, 0.1, SENSOR_SEMUA,  50, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
      ichibot.setIndex(5,BELOK_KIRI, 80, SENSOR_KIRI_TENGAH,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF);
     //ichibot.setIndex(1, LURUS, , SENSOR_KOSONG ,  0, 30, PID_0, GARIS_HITAM, KIPAS_ON,NORMAL);
     
     //ichibot.setIndex(0, MOTION, 0.5 , SENSOR_SEMUA,  100, 10, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL);
     //ichibot.setIndex(1, BELOK_KANAN, 100, SENSOR_KANAN_TENGAH,  50, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL); 
     //ichibot.setIndex(2, BELOK_KANAN, 50, SENSOR_KANAN_TENGAH,  100, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL);
     //ichibot.setIndex(3, BELOK_KANAN, 0.5 , SENSOR_KANAN,  100, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL);
     //ichibot.setIndex(4, BELOK_KANAN, 0.5 , SENSOR_KANAN_TENGAH,  100, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL);
     //ichibot.setIndex(2, BELOK_KANAN, 0.5 , SENSOR_KANAN_TENGAH,  100, 5, PID_3, GARIS_HITAM , KIPAS_OFF,NORMAL);
                                
     //ichibot.setIndex(2, STOP, 100, SENSOR_KANAN_TENGAH ,  0, 30, PID_0, GARIS_HITAM, KIPAS_ON,NORMAL);

}

   void loop() {
   ichibot.run();
   }
