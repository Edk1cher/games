#include "TXLib.h"

struct Car
{
  int x;
  int y;
  HDC left;
  HDC right;
  HDC up;
  HDC down;
  HDC UpLeft;
  HDC UpRight;
  HDC DownLeft;
  HDC DownRight;
  HDC picture;
};


int main()
{
    txCreateWindow (1200, 600);


    txDisableAutoPause();
    txTextCursor(false);
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);

    Car car = { 100,
                100,
                txLoadImage ("Pictures/Left.bmp"),
                txLoadImage ("Pictures/Right.bmp"),
                txLoadImage ("Pictures/Up.bmp"),
                txLoadImage ("Pictures/Down.bmp"),
                txLoadImage ("Pictures/UpLeft.bmp"),
                txLoadImage ("Pictures/UpRight.bmp"),
                txLoadImage ("Pictures/DownLeft.bmp"),
                txLoadImage ("Pictures/DownRight.bmp"),
                car.right};

    HDC MAP = txLoadImage ("Pictures/�����.bmp");




    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txClear();

        txBitBlt(txDC(), 0, 0, 1200, 600, MAP);

        if(car.picture==car.left || car.picture==car.right)
        txTransparentBlt (txDC(), car.x+40, car.y+20, 80, 40, car.picture, 0, 0, TX_WHITE);

        if(car.picture==car.down || car.picture==car.up)
        txTransparentBlt (txDC(), car.x+40, car.y+20, 40, 80, car.picture, 0, 0, TX_WHITE);

        if(GetAsyncKeyState ('W'))
        {
            car.y =car.y-10;
            car.picture = car.up;
        }

         else if(GetAsyncKeyState ('S'))
        {
            car.y =car.y+10;
            car.picture = car.down;
        }

        else if(GetAsyncKeyState ('A'))
        {
            car.x =car.x-10;
            car.picture = car.left;
        }

        else if(GetAsyncKeyState ('D'))
        {
            car.x =car.x+10;
            car.picture = car.right;
        }

        else if(GetAsyncKeyState ('D'))
        {
            car.x =car.x+10;
            car.picture = car.right;
        }

        else if(GetAsyncKeyState ('W') && GetAsyncKeyState ('A'))
        {
            car.x =car.x+10;
            car.picture = car.UpLeft;
        }

        else if(GetAsyncKeyState ('AS'))
        {
            car.x =car.x+10;
            car.picture = car.right;
        }

        else if(GetAsyncKeyState ('SD'))
        {
            car.x =car.x+10;
            car.picture = car.right;
        }
        else if(GetAsyncKeyState ('DW'))
        {
            car.x =car.x+10;
            car.picture = car.right;
        }

        txEnd();
        txSleep(50);
    }
    txDeleteDC(MAP);
    txDeleteDC(car.picture);
    txDeleteDC(car.up);
    txDeleteDC(car.down);
    txDeleteDC(car.left);
    txDeleteDC(car.right);



    return 0;
}

