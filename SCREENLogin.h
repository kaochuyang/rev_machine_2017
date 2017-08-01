#ifndef SCREENLoginH
#define SCREENLoginH

#include "SCREEN.h"
//---------------------------------------------------------------------------
class SCREENLogin:public SCREEN
{
    public:

      SCREENLogin(void);
      ~SCREENLogin(void);

      void DisplayLogin(void);                                                  //���LOGIN��
      void DoKeyWork(BYTE);                                                     //�ھ�KEY���ȧ@��


    private:

      DISP_WORD pwd[6];                                                         //�������ťճB,�w�q�y��
      unsigned int cPosition;                                                   //�{�b����m
      char passWord[6];                                                         //�O���K�X

      BYTE loginBitmap[3840];                                                   //����

      void LoadBitmapFromFile(void);                                            //�N����Load�i�O����
      void InitDispWord(void);                                                  //��l�Ʀ��e�����y�е��Ѽ�

      void DoKey0Work(void);
      void DoKey1Work(void);
      void DoKey2Work(void);
      void DoKey3Work(void);
      void DoKey4Work(void);
      void DoKey5Work(void);
      void DoKey6Work(void);
      void DoKey7Work(void);
      void DoKey8Work(void);
      void DoKey9Work(void);
      void DoKeyAWork(void);
      void DoKeyBWork(void);
      void DoKeyCWork(void);
      void DoKeyDWork(void);
      void DoKeyEWork(void);
      void DoKeyFWork(void);
      void DoKeyF1Work(void);
      void DoKeyF2Work(void);
      void DoKeyUPWork(void);
      void DoKeyDOWNWork(void);
      void DoKeyLEFTWork(void);
      void DoKeyRIGHTWork(void);
      void DoKeyEnterWork(void);
};
//---------------------------------------------------------------------------
extern SCREENLogin screenLogin;
#endif