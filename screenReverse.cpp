#include "screenReverse.h"
#include "screenReverseMenu.h"
#include "SCREENMain.h"
#include "LCD240x128.h"

#include "CSTC.h"
#include "var.h"
#include <stdio.h>

#include "SMEM.h"
//---------------------------------------------------------------------------
ScreenReverse screenReverse;
//---------------------------------------------------------------------------
ScreenReverse::ScreenReverse(void)
{
    loadBitmapFromFile();
    initDispWord();
    cPosition=0;
    cSelect=0;

}
//---------------------------------------------------------------------------
ScreenReverse::~ScreenReverse(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::loadBitmapFromFile(void)
{
try {
    FILE *bitmap;
    bitmap=fopen("//cct//bitmap//backGround//TC5F//rev.bit","rb");
    if (bitmap) {
        fread(reverseBitmap,3840,1,bitmap);
        fclose(bitmap);
    }
  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::DisplayReverse(unsigned short int usiLoadRevIn)
{
try {
    smem.SetcFace(cREVERSE);
    usiLoadRev = usiLoadRevIn;
    lcd240x128.DISPLAY_GRAPHIC(0,reverseBitmap,128,30);
    cPosition=0;
    cSelect=0;

    LoadRev();
    DisplayRev();
    setCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::initDispWord(void)
{
try {
  timeWord1[0].X = 24;
  timeWord1[1].X = 32;
  timeWord1[2].X = 48;
  timeWord1[3].X = 56;

  timeWord2[0].X = 72;
  timeWord2[1].X = 80;
  timeWord2[2].X = 96;
  timeWord2[3].X = 104;

  timeWord3[0].X = 136;
  timeWord3[1].X = 144;
  timeWord3[2].X = 160;
  timeWord3[3].X = 168;

  timeWord4[0].X = 184;
  timeWord4[1].X = 192;
  timeWord4[2].X = 208;
  timeWord4[3].X = 216;

  for(int i = 0; i < 4; i++) {
    timeWord1[i].Y = 41;
    timeWord1[i].width = 8;
    timeWord1[i].height = 16;
    timeWord2[i].Y = 41;
    timeWord2[i].width = 8;
    timeWord2[i].height = 16;
    timeWord3[i].Y = 41;
    timeWord3[i].width = 8;
    timeWord3[i].height = 16;
    timeWord4[i].Y = 41;
    timeWord4[i].width = 8;
    timeWord4[i].height = 16;
  }

  noWord.X = 208;
  noWord.Y = 74;
  noWord.width = 8;
  noWord.height = 16;

  secWord1[0].X = 136;
  secWord1[1].X = 144;
  secWord1[2].X = 152;
  for(int i = 0; i < 3; i++) {
    secWord1[i].Y = 74;
    secWord1[i].width = 8;
    secWord1[i].height = 16;
  }

  secWord2[0].X = 64;
  secWord2[1].X = 72;
  secWord2[2].X = 80;
  for(int i = 0; i < 3; i++) {
    secWord2[i].Y = 90;
    secWord2[i].width = 8;
    secWord2[i].height = 16;
  }

  secWord3[0].X = 64;
  secWord3[1].X = 72;
  secWord3[2].X = 80;
  for(int i = 0; i < 3; i++) {
    secWord3[i].Y = 106;
    secWord3[i].width = 8;
    secWord3[i].height = 16;
  }

  } catch (...) {}
}
//---------------------------------------------------------------------------
/*
void ScreenRev::DisplayDate(void)
{
try {
    unsigned short cYear=0,cMonth=0,cDay=0;
    time_t currentTime=time(NULL);
    struct tm *now=localtime(&currentTime);
    cYear=now->tm_year+1900;
    cMonth=now->tm_mon+1;
    cDay=now->tm_mday;


    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[0].X,dateWord[0].Y,word8x16[cYear/1000],dateWord[0].height,dateWord[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[1].X,dateWord[1].Y,word8x16[(cYear/100)%10],dateWord[1].height,dateWord[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[2].X,dateWord[2].Y,word8x16[(cYear/10)%10],dateWord[2].height,dateWord[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[3].X,dateWord[3].Y,word8x16[cYear%10],dateWord[3].height,dateWord[3].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[4].X,dateWord[4].Y,word8x16[cMonth/10],dateWord[4].height,dateWord[4].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[5].X,dateWord[5].Y,word8x16[cMonth%10],dateWord[5].height,dateWord[5].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[6].X,dateWord[6].Y,word8x16[cDay/10],dateWord[6].height,dateWord[6].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(dateWord[7].X,dateWord[7].Y,word8x16[cDay%10],dateWord[7].height,dateWord[7].width/8);
  } catch (...) {}
}
*/
//---------------------------------------------------------------------------
void ScreenReverse::LoadRev(void)
{
try {
//    for (int i=3;i<=6;i++) {
  //error
         stc.Lock_to_Load_ReverseTime_Step1(1, usiLoadRev);

/*
         printf("OT load reverse time id: %d\n", stc._panel_reversetime._reverse_time_type);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiDirectIn);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiHourStartIn);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiMinStartIn);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiHourEndIn);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiMinEndIn);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiDirectOut);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiHourStartOut);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiMinStartOut);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiHourEndOut);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiMinEndOut);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiClearTime);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiFlashGreen);
         printf("OT load reverse: %d\n", stc._panel_reversetime.usiGreenTime);
*/

         /*
         reverseInfo._reverse_time_type=stc._panel_holidayrev._reverse_time_type;
         reverseInfo._start_year=stc._panel_holidayrev._start_year;
         reverseInfo._start_month=stc._panel_holidayrev._start_month;
         reverseInfo._start_day=stc._panel_holidayrev._start_day;
         reverseInfo._end_year=stc._panel_holidayrev._end_year;
         reverseInfo._end_month=stc._panel_holidayrev._end_month;
         reverseInfo._end_day=stc._panel_holidayrev._end_day;
         //CCJ++
         tmpReverseTimeInfo._reverse_time_type=stc._panel_holidayrev._reverse_time_type;
         tmpReverseTimeInfo._start_year=stc._panel_holidayrev._start_year;
         tmpReverseTimeInfo._start_month=stc._panel_holidayrev._start_month;
         tmpReverseTimeInfo._start_day=stc._panel_holidayrev._start_day;
         tmpReverseTimeInfo._end_year=stc._panel_holidayrev._end_year;
         tmpReverseTimeInfo._end_month=stc._panel_holidayrev._end_month;
         tmpReverseTimeInfo._end_day=stc._panel_holidayrev._end_day;
         //CCJ++
         */

         tmpReverseTimeInfo.usiHourStartIn = stc._panel_reversetime.usiHourStartIn;
         tmpReverseTimeInfo.usiMinStartIn = stc._panel_reversetime.usiMinStartIn;
         tmpReverseTimeInfo.usiHourEndIn = stc._panel_reversetime.usiHourEndIn;
         tmpReverseTimeInfo.usiMinEndIn = stc._panel_reversetime.usiMinEndIn;
         tmpReverseTimeInfo.usiHourStartOut = stc._panel_reversetime.usiHourStartOut;
         tmpReverseTimeInfo.usiMinStartOut = stc._panel_reversetime.usiMinStartOut;
         tmpReverseTimeInfo.usiHourEndOut = stc._panel_reversetime.usiHourEndOut;
         tmpReverseTimeInfo.usiMinEndOut = stc._panel_reversetime.usiMinEndOut;
         tmpReverseTimeInfo.usiGreenTime = stc._panel_reversetime.usiGreenTime;
         tmpReverseTimeInfo.usiClearTime = stc._panel_reversetime.usiClearTime;
         tmpReverseTimeInfo.usiFlashGreen = stc._panel_reversetime.usiFlashGreen;
         tmpReverseTimeInfo._reverse_time_type = stc._panel_reversetime._reverse_time_type;

         tmpReverseTimeInfo.ucNonRevLight = stc._panel_reversetime.ucNonRevLight;

//    }
  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::DisplayRev(void)
{
try {
    BYTE space[16]={0};

//    cFace=page;
//    DisplayItem(page);  DisplayItem(page);

    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[0].X,timeWord1[0].Y,word8x16[tmpReverseTimeInfo.usiHourStartIn/10],timeWord1[0].height,timeWord1[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[1].X,timeWord1[1].Y,word8x16[tmpReverseTimeInfo.usiHourStartIn%10],timeWord1[1].height,timeWord1[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[2].X,timeWord1[2].Y,word8x16[tmpReverseTimeInfo.usiMinStartIn/10],timeWord1[2].height,timeWord1[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[3].X,timeWord1[3].Y,word8x16[tmpReverseTimeInfo.usiMinStartIn%10],timeWord1[3].height,timeWord1[3].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[0].X,timeWord2[0].Y,word8x16[tmpReverseTimeInfo.usiHourEndIn/10],timeWord2[0].height,timeWord2[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[1].X,timeWord2[1].Y,word8x16[tmpReverseTimeInfo.usiHourEndIn%10],timeWord2[1].height,timeWord2[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[2].X,timeWord2[2].Y,word8x16[tmpReverseTimeInfo.usiMinEndIn/10],timeWord2[2].height,timeWord2[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[3].X,timeWord2[3].Y,word8x16[tmpReverseTimeInfo.usiMinEndIn%10],timeWord2[3].height,timeWord2[3].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[0].X,timeWord3[0].Y,word8x16[tmpReverseTimeInfo.usiHourStartOut/10],timeWord3[0].height,timeWord3[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[1].X,timeWord3[1].Y,word8x16[tmpReverseTimeInfo.usiHourStartOut%10],timeWord3[1].height,timeWord3[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[2].X,timeWord3[2].Y,word8x16[tmpReverseTimeInfo.usiMinStartOut/10],timeWord3[2].height,timeWord3[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[3].X,timeWord3[3].Y,word8x16[tmpReverseTimeInfo.usiMinStartOut%10],timeWord3[3].height,timeWord3[3].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[0].X,timeWord4[0].Y,word8x16[tmpReverseTimeInfo.usiHourEndOut/10],timeWord4[0].height,timeWord4[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[1].X,timeWord4[1].Y,word8x16[tmpReverseTimeInfo.usiHourEndOut%10],timeWord4[1].height,timeWord4[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[2].X,timeWord4[2].Y,word8x16[tmpReverseTimeInfo.usiMinEndOut/10],timeWord4[2].height,timeWord4[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[3].X,timeWord4[3].Y,word8x16[tmpReverseTimeInfo.usiMinEndOut%10],timeWord4[3].height,timeWord4[3].width/8);

    lcd240x128.DISPLAY_GRAPHIC_XY(noWord.X,noWord.Y,word8x16[tmpReverseTimeInfo._reverse_time_type],noWord.height,noWord.width/8);

    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[0].X,secWord1[0].Y,word8x16[(tmpReverseTimeInfo.usiGreenTime/100)%10],secWord1[0].height,secWord1[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[1].X,secWord1[1].Y,word8x16[(tmpReverseTimeInfo.usiGreenTime/10)%10],secWord1[1].height,secWord1[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[2].X,secWord1[2].Y,word8x16[(tmpReverseTimeInfo.usiGreenTime%10)],secWord1[2].height,secWord1[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[0].X,secWord2[0].Y,word8x16[(tmpReverseTimeInfo.usiClearTime/100)%10],secWord2[0].height,secWord2[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[1].X,secWord2[1].Y,word8x16[(tmpReverseTimeInfo.usiClearTime/10)%10],secWord2[1].height,secWord2[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[2].X,secWord2[2].Y,word8x16[(tmpReverseTimeInfo.usiClearTime%10)],secWord2[2].height,secWord2[2].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[0].X,secWord3[0].Y,word8x16[(tmpReverseTimeInfo.usiFlashGreen/100)%10],secWord3[0].height,secWord3[0].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[1].X,secWord3[1].Y,word8x16[(tmpReverseTimeInfo.usiFlashGreen/10)%10],secWord3[1].height,secWord3[1].width/8);
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[2].X,secWord3[2].Y,word8x16[(tmpReverseTimeInfo.usiFlashGreen%10)],secWord3[2].height,secWord3[2].width/8);
  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::SaveRev(void)
{
try {

//  if( reverseInfo.usiHourStartIn != tmpReverseTimeInfo.usiHourStartIn )
//  {
//    stc._panel_reversetime._reverse_time_type = tmpReverseTimeInfo.usiHourStartIn;
//  }

/*
  reverseInfo.usiHourStartIn = tmpReverseTimeInfo.usiHourStartIn;
  reverseInfo.usiMinStartIn = tmpReverseTimeInfo.usiMinStartIn;
  reverseInfo.usiHourEndIn = tmpReverseTimeInfo.usiHourEndIn;
  reverseInfo.usiMinEndIn = tmpReverseTimeInfo.usiMinEndIn;
  reverseInfo.usiHourStartOut = tmpReverseTimeInfo.usiHourStartOut;
  reverseInfo.usiMinStartOut = tmpReverseTimeInfo.usiMinStartOut;
  reverseInfo.usiHourEndOut = tmpReverseTimeInfo.usiHourEndOut;
  reverseInfo.usiMinEndOut = tmpReverseTimeInfo.usiMinEndOut;

  reverseInfo.usiGreenTime = tmpReverseTimeInfo.usiGreenTime;
  reverseInfo.usiClearTime = tmpReverseTimeInfo.usiClearTime;
  reverseInfo.usiFlashGreen = tmpReverseTimeInfo.usiFlashGreen;

  reverseInfo._reverse_time_type = tmpReverseTimeInfo._reverse_time_type;
  */

  bool bCheck = true;

  int iRevInCitySec = tmpReverseTimeInfo.usiHourStartIn * 3600 + tmpReverseTimeInfo.usiMinStartIn * 60;
  int iRevInCityEndSec = tmpReverseTimeInfo.usiHourEndIn * 3600 + tmpReverseTimeInfo.usiMinEndIn * 60;
  int iRevOutCitySec = tmpReverseTimeInfo.usiHourStartOut * 3600 + tmpReverseTimeInfo.usiMinStartOut * 60;
  int iRevOutCityEndSec = tmpReverseTimeInfo.usiHourEndOut * 3600 + tmpReverseTimeInfo.usiMinEndOut * 60;

  if(iRevInCitySec > iRevInCityEndSec)                                          //reverse
    bCheck = false;
  if(iRevOutCitySec > iRevOutCityEndSec)
    bCheck = false;

  if(iRevOutCitySec != iRevOutCityEndSec) {
    if(iRevOutCitySec >= iRevInCitySec && iRevOutCitySec <= iRevInCityEndSec)       //marge
      bCheck = false;
    if(iRevOutCityEndSec >= iRevInCitySec && iRevOutCityEndSec <= iRevInCityEndSec)
      bCheck = false;
  }

  if(iRevInCitySec != iRevInCityEndSec) {
    if(iRevInCitySec >= iRevOutCitySec && iRevInCitySec <= iRevOutCityEndSec)
      bCheck = false;
    if(iRevInCityEndSec >= iRevOutCitySec && iRevInCityEndSec <= iRevOutCityEndSec)
      bCheck = false;
  }

 /* if(tmpReverseTimeInfo.usiGreenTime > 255)
    bCheck = false;
  if(tmpReverseTimeInfo.usiClearTime > 999)
    bCheck = false;
  if(tmpReverseTimeInfo.usiFlashGreen > 255)
    bCheck = false;*///kaochu

  if(iRevInCitySec != iRevInCityEndSec) {
    if( (iRevInCityEndSec - iRevInCitySec) <= (tmpReverseTimeInfo.usiGreenTime + tmpReverseTimeInfo.usiClearTime + tmpReverseTimeInfo.usiFlashGreen) )
      bCheck = false;
  }
  if(iRevOutCitySec != iRevOutCityEndSec) {
    if( (iRevOutCityEndSec - iRevOutCitySec) <= (tmpReverseTimeInfo.usiGreenTime + tmpReverseTimeInfo.usiClearTime + tmpReverseTimeInfo.usiFlashGreen) )
      bCheck = false;
  }

  if(iRevInCitySec != 0 || iRevInCityEndSec != 0) {  //have only InCity Rev.
    if(iRevOutCitySec == 0 && iRevOutCityEndSec == 0) {
//      tmpReverseTimeInfo.ucNonRevLight = 1;
        tmpReverseTimeInfo.ucNonRevLight = 0;
    }
  } else if(iRevOutCitySec != 0 || iRevOutCityEndSec != 0) {  //have only OutCity Rev
    if(iRevInCitySec == 0 && iRevInCityEndSec == 0) {
//      tmpReverseTimeInfo.ucNonRevLight = 2;
        tmpReverseTimeInfo.ucNonRevLight = 0;
    }
  } else {  //unknow type.
      tmpReverseTimeInfo.ucNonRevLight = 0;
  }
  printf("tmpReverseTimeInfo.ucNonRevLight:%d\n", tmpReverseTimeInfo.ucNonRevLight);

  if(iRevInCitySec == 0 && iRevInCityEndSec == 0 &&
     iRevOutCitySec == 0 && iRevOutCityEndSec == 86340 &&
     tmpReverseTimeInfo.usiGreenTime == 1 &&
     tmpReverseTimeInfo.usiClearTime == 3 &&
     tmpReverseTimeInfo.usiFlashGreen == 1) {
       bCheck = true;
  } else if(iRevInCitySec == 0 && iRevInCityEndSec == 86340 &&
          iRevOutCitySec == 0 && iRevOutCityEndSec == 0 &&
          tmpReverseTimeInfo.usiGreenTime == 1 &&
          tmpReverseTimeInfo.usiClearTime == 3 &&
          tmpReverseTimeInfo.usiFlashGreen == 1) {
       bCheck = true;
  }

  if(bCheck) {
    stc._panel_reversetime.ucNonRevLight = 0;  //Init.

    stc._panel_reversetime.usiHourStartIn = tmpReverseTimeInfo.usiHourStartIn;
    stc._panel_reversetime.usiMinStartIn = tmpReverseTimeInfo.usiMinStartIn;
    stc._panel_reversetime.usiHourEndIn = tmpReverseTimeInfo.usiHourEndIn;
    stc._panel_reversetime.usiMinEndIn = tmpReverseTimeInfo.usiMinEndIn;
    stc._panel_reversetime.usiHourStartOut = tmpReverseTimeInfo.usiHourStartOut;
    stc._panel_reversetime.usiMinStartOut = tmpReverseTimeInfo.usiMinStartOut;
    stc._panel_reversetime.usiHourEndOut = tmpReverseTimeInfo.usiHourEndOut;
    stc._panel_reversetime.usiMinEndOut = tmpReverseTimeInfo.usiMinEndOut;
    stc._panel_reversetime.usiGreenTime = tmpReverseTimeInfo.usiGreenTime;
    stc._panel_reversetime.usiClearTime = tmpReverseTimeInfo.usiClearTime;
    stc._panel_reversetime.usiFlashGreen = tmpReverseTimeInfo.usiFlashGreen;
    stc._panel_reversetime._reverse_time_type = usiLoadRev;

    stc._panel_reversetime.ucNonRevLight = tmpReverseTimeInfo.ucNonRevLight;

    stc._panel_reversetime.usiDirectIn = 0;
    stc._panel_reversetime.usiDirectOut = 1;

    stc.Lock_to_Save_ReverseTime_Step1(1);

    doKeyF4Work();

  }


  } catch (...) {}
}
//---------------------------------------------------------------------------
/*
void ScreenReverse::DisplayItem(int page)
{
try {
    BYTE space[16]={0};
    for (int i=0;i<6;i+=2) {
         if ((page*3-(2-i/2))<=13) {
             lcd240x128.DISPLAY_GRAPHIC_XY(itemWord[i].X,itemWord[i].Y,word8x16[(page*3-(2-i/2))/10],itemWord[i].height,itemWord[i].width/8);
             lcd240x128.DISPLAY_GRAPHIC_XY(itemWord[i+1].X,itemWord[i+1].Y,word8x16[(page*3-(2-i/2))%10],itemWord[i+1].height,itemWord[i+1].width/8);
         } else {
             lcd240x128.DISPLAY_GRAPHIC_XY(itemWord[i].X,itemWord[i].Y,space,itemWord[i].height,itemWord[i].width/8);
             lcd240x128.DISPLAY_GRAPHIC_XY(itemWord[i+1].X,itemWord[i+1].Y,space,itemWord[i+1].height,itemWord[i+1].width/8);
         }
    }
  } catch(...) {}
}
*/
//---------------------------------------------------------------------------
void ScreenReverse::doKeyWork(BYTE key)
{
try {
    switch (key) {
        case 0x80:
          doKey0Work();
        break;
        case 0x81:
          doKey1Work();
        break;
        case 0x82:
          doKey2Work();
        break;
        case 0x83:
          doKey3Work();
        break;
        case 0x84:
          doKey4Work();
        break;
        case 0x85:
          doKey5Work();
        break;
        case 0x86:
          doKey6Work();
        break;
        case 0x87:
          doKey7Work();
        break;
        case 0x88:
          doKey8Work();
        break;
        case 0x89:
          doKey9Work();
        break;
        case 0x8A:
          doKeyAWork();
        break;
        case 0x8B:
          doKeyBWork();
        break;
        case 0x8C:
          doKeyCWork();
        break;
        case 0x8D:
          doKeyDWork();
        break;
        case 0x8E:
          doKeyEWork();
        break;
        case 0x8F:
          doKeyFWork();
        break;
        case 0x90:
          doKeyF1Work();
        break;
        case 0x91:
          doKeyF2Work();
        break;
        case 0x92:
          doKeyF3Work();
        break;
        case 0x93:
          doKeyF4Work();
        break;
        case 0x94:
          doKeyUPWork();
        break;
        case 0x95:
          doKeyDOWNWork();
        break;
        case 0x96:
          doKeyLEFTWork();
        break;
        case 0x97:
          doKeyRIGHTWork();
        break;
        case 0x98:
          doKeyEnterWork();
        break;
        default:
        break;
    }
  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey0Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[0],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[0],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[0],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[0],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[0],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[0],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[0],secWord3[cPosition].height,secWord3[cPosition].width/8);
  ModifyRev(0);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey1Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[1],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[1],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[1],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[1],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[1],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[1],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[1],secWord3[cPosition].height,secWord3[cPosition].width/8);

  ModifyRev(1);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey2Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[2],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[2],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[2],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[2],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[2],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[2],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[2],secWord3[cPosition].height,secWord3[cPosition].width/8);

  ModifyRev(2);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey3Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[3],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[3],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[3],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[3],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[3],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[3],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[3],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(3);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey4Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[4],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[4],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[4],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[4],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[4],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[4],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[4],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(4);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey5Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[5],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[5],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[5],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[5],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[5],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[5],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[5],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(5);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey6Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[6],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[6],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[6],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[6],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[6],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[6],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[6],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(6);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey7Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[7],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[7],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[7],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[7],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[7],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[7],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[7],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(7);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey8Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[8],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[8],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[8],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[8],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[8],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[8],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[8],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(8);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKey9Work(void)
{
  if(cSelect == 0)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord1[cPosition].X,timeWord1[cPosition].Y,word8x16[9],timeWord1[cPosition].height,timeWord1[cPosition].width/8);
  else if (cSelect == 1)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord2[cPosition].X,timeWord2[cPosition].Y,word8x16[9],timeWord2[cPosition].height,timeWord2[cPosition].width/8);
  else if (cSelect == 2)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord3[cPosition].X,timeWord3[cPosition].Y,word8x16[9],timeWord3[cPosition].height,timeWord3[cPosition].width/8);
  else if (cSelect == 3)
    lcd240x128.DISPLAY_GRAPHIC_XY(timeWord4[cPosition].X,timeWord4[cPosition].Y,word8x16[9],timeWord4[cPosition].height,timeWord4[cPosition].width/8);
  else if(cSelect == 4)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord1[cPosition].X,secWord1[cPosition].Y,word8x16[9],secWord1[cPosition].height,secWord1[cPosition].width/8);
  else if(cSelect == 5)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord2[cPosition].X,secWord2[cPosition].Y,word8x16[9],secWord2[cPosition].height,secWord2[cPosition].width/8);
  else if(cSelect == 6)
    lcd240x128.DISPLAY_GRAPHIC_XY(secWord3[cPosition].X,secWord3[cPosition].Y,word8x16[9],secWord3[cPosition].height,secWord3[cPosition].width/8);


  ModifyRev(9);
  doKeyRIGHTWork();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyAWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyBWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyCWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyDWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyEWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyFWork(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyF1Work(void)
{
    screenMain.DisplayMain();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyF2Work(void)
{
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyF3Work(void)
{
    SaveRev();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyF4Work(void)
{
    screenReverseMenu.DisplayReverseMenu();
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyUPWork(void)
{
try {
    if (cSelect==0) {
    } else if (cSelect==1) {
      clearCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
      cSelect = 0;
      cPosition = 0;
      setCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
    } else if (cSelect==2) {
      clearCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
      cSelect = 1;
      cPosition = 0;
      setCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
    } else if (cSelect==3) {
      clearCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
      cSelect = 2;
      cPosition = 0;
      setCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
    } else if (cSelect==4) {
      clearCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
      cSelect = 3;
      cPosition = 0;
      setCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
    } else if (cSelect==5) {
      clearCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
      cSelect = 4;
      cPosition = 0;
      setCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
    } else if (cSelect==6) {
      clearCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
      cSelect = 5;
      cPosition = 0;
      setCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
    }

  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyDOWNWork(void)
{
try {
  if (cSelect==0) {
    clearCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
    cSelect = 1;
    cPosition = 0;
    setCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
  } else if (cSelect==1) {
    clearCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
    cSelect = 2;
    cPosition = 0;
    setCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
  } else if (cSelect==2) {
    clearCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
    cSelect = 3;
    cPosition = 0;
    setCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
  } else if (cSelect==3) {
    clearCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
    cSelect = 4;
    cPosition = 0;
    setCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
  } else if (cSelect==4) {
    clearCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
    cSelect = 5;
    cPosition = 0;
    setCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
  } else if (cSelect==5) {
    clearCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
    cSelect = 6;
    cPosition = 0;
    setCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
  } else if (cSelect==6) {
  }

  } catch (...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyLEFTWork(void)
{
try {
  if (cSelect==0) {
  } else if (cSelect==1) {
    clearCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
    cSelect = 0;
    cPosition = 0;
    setCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
  } else if (cSelect==2) {
    clearCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
    cSelect = 1;
    cPosition = 0;
    setCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
  } else if (cSelect==3) {
    clearCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
    cSelect = 2;
    cPosition = 0;
    setCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
  } else if (cSelect==4) {
    clearCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
    cSelect = 3;
    cPosition = 0;
    setCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
  } else if (cSelect==5) {
    clearCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
    cSelect = 4;
    cPosition = 0;
    setCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
  } else if (cSelect==6) {
    clearCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
    cSelect = 5;
    cPosition = 0;
    setCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
  }
} catch(...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyRIGHTWork(void)
{
try {
  if (cSelect==0) {
    if(cPosition < 3) {
      clearCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
      cPosition++;
      setCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
    } else {
      clearCursor8x16(timeWord1[cPosition].X,timeWord1[cPosition].Y+16);
      cSelect = 1;
      cPosition = 0;
      setCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
    }
  } else if (cSelect==1) {
    if(cPosition < 3) {
      clearCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
      cPosition++;
      setCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
    } else {
      clearCursor8x16(timeWord2[cPosition].X,timeWord2[cPosition].Y+16);
      cSelect = 2;
      cPosition = 0;
      setCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
    }
  } else if (cSelect==2) {
    if(cPosition < 3) {
      clearCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
      cPosition++;
      setCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
    } else {
      clearCursor8x16(timeWord3[cPosition].X,timeWord3[cPosition].Y+16);
      cSelect = 3;
      cPosition = 0;
      setCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
    }
  } else if (cSelect==3) {
    if(cPosition < 3) {
      clearCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
      cPosition++;
      setCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
    } else {
      clearCursor8x16(timeWord4[cPosition].X,timeWord4[cPosition].Y+16);
      cSelect = 4;
      cPosition = 0;
      setCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
    }
  } else if (cSelect==4) {
    if(cPosition < 2) {
      clearCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
      cPosition++;
      setCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
    } else {
      clearCursor8x16(secWord1[cPosition].X,secWord1[cPosition].Y+16);
      cSelect = 5;
      cPosition = 0;
      setCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
    }
  } else if (cSelect==5) {
    if(cPosition < 2) {
      clearCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
      cPosition++;
      setCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
    } else {
      clearCursor8x16(secWord2[cPosition].X,secWord2[cPosition].Y+16);
      cSelect = 6;
      cPosition = 0;
      setCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
    }
  } else if (cSelect==6) {
    if(cPosition < 2) {
      clearCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
      cPosition++;
      setCursor8x16(secWord3[cPosition].X,secWord3[cPosition].Y+16);
    }

  }
  } catch(...) {}
}
//---------------------------------------------------------------------------
void ScreenReverse::doKeyEnterWork(void)
{
try {

  } catch (...){}
}
//---------------------------------------------------------------------------
void ScreenReverse::ModifyRev(int tmp_value)
{
try{

  int tmp = 0;
  if(cSelect == 0) {
    if(cPosition == 0) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiHourStartIn % 10;
      tmpReverseTimeInfo.usiHourStartIn = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiHourStartIn /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiHourStartIn = tmp;
    } else if(cPosition == 2) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiMinStartIn % 10;
      tmpReverseTimeInfo.usiMinStartIn = tmp;
    } else if(cPosition == 3) {
      tmp = (tmpReverseTimeInfo.usiMinStartIn /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiMinStartIn = tmp;
    }
  } else if(cSelect == 1) {
    if(cPosition == 0) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiHourEndIn % 10;
      tmpReverseTimeInfo.usiHourEndIn = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiHourEndIn /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiHourEndIn = tmp;
    } else if(cPosition == 2) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiMinEndIn % 10;
      tmpReverseTimeInfo.usiMinEndIn = tmp;
    } else if(cPosition == 3) {
      tmp = (tmpReverseTimeInfo.usiMinEndIn /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiMinEndIn = tmp;
    }
  } else if(cSelect == 2) {
    if(cPosition == 0) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiHourStartOut % 10;
      tmpReverseTimeInfo.usiHourStartOut = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiHourStartOut /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiHourStartOut = tmp;
    } else if(cPosition == 2) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiMinStartOut % 10;
      tmpReverseTimeInfo.usiMinStartOut = tmp;
    } else if(cPosition == 3) {
      tmp = (tmpReverseTimeInfo.usiMinStartOut /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiMinStartOut = tmp;
    }
  } else if(cSelect == 3) {
    if(cPosition == 0) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiHourEndOut % 10;
      tmpReverseTimeInfo.usiHourEndOut = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiHourEndOut /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiHourEndOut = tmp;
    } else if(cPosition == 2) {
      tmp = tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiMinEndOut % 10;
      tmpReverseTimeInfo.usiMinEndOut = tmp;
    } else if(cPosition == 3) {
      tmp = (tmpReverseTimeInfo.usiMinEndOut /10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiMinEndOut = tmp;
    }
  } else if(cSelect == 4) {
    if(cPosition == 0) {
      tmp = tmp_value * 100;
      tmp += ((tmpReverseTimeInfo.usiGreenTime / 10)  % 10) * 10;
      tmp += tmpReverseTimeInfo.usiGreenTime % 10;
      tmpReverseTimeInfo.usiGreenTime = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiGreenTime / 100) * 100;
      tmp += tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiGreenTime % 10;
      tmpReverseTimeInfo.usiGreenTime = tmp;
    } else if(cPosition == 2) {
      tmp = (tmpReverseTimeInfo.usiGreenTime / 100) * 100;
      tmp += ((tmpReverseTimeInfo.usiGreenTime / 10)  % 10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiGreenTime = tmp;
    }

//clear
    } else if(cSelect == 5) {
     if(cPosition == 0) {
      tmp = tmp_value * 100;
      tmp += ((tmpReverseTimeInfo.usiClearTime / 10)  % 10) * 10;
      tmp += tmpReverseTimeInfo.usiClearTime % 10;
      tmpReverseTimeInfo.usiClearTime = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiClearTime / 100) * 100;
      tmp += tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiClearTime % 10;
      tmpReverseTimeInfo.usiClearTime = tmp;
    } else if(cPosition == 2) {
      tmp = (tmpReverseTimeInfo.usiClearTime / 100) * 100;
      tmp += ((tmpReverseTimeInfo.usiClearTime / 10)  % 10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiClearTime = tmp;
    }

//flash
  } else if(cSelect == 6) {
    if(cPosition == 0) {
      tmp = tmp_value * 100;
      tmp += ((tmpReverseTimeInfo.usiFlashGreen / 10)  % 10) * 10;
      tmp += tmpReverseTimeInfo.usiFlashGreen % 10;
      tmpReverseTimeInfo.usiFlashGreen = tmp;
    } else if(cPosition == 1) {
      tmp = (tmpReverseTimeInfo.usiFlashGreen / 100) * 100;
      tmp += tmp_value * 10;
      tmp += tmpReverseTimeInfo.usiFlashGreen % 10;
      tmpReverseTimeInfo.usiFlashGreen = tmp;
    } else if(cPosition == 2) {
      tmp = (tmpReverseTimeInfo.usiFlashGreen / 100) * 100;
      tmp += ((tmpReverseTimeInfo.usiFlashGreen / 10)  % 10) * 10;
      tmp += tmp_value;
      tmpReverseTimeInfo.usiFlashGreen = tmp;
    }
  }

 }catch(...){}
}
