//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MultiplePlanet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    HDC hDC = this->Canvas->Handle;
    MoveWindowOrg(hDC, ClientWidth/2, ClientHeight/2);
    
  /*Draw a yello circle (the sun) and create a planet that revolves around
    it on an elliptical path.*/
	
    Canvas->Pen->Color = clBlue;
    Canvas->Brush->Color = clYellow;
    Canvas->Ellipse(-50, -50, 50, 50);
	
	/*Erase the previous planet by replacing it with the background color*/
    Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clBlack;
    Canvas->Ellipse(x2, y2, x2+10, y2+10);

    Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clBlack;
    Canvas->Ellipse(x4, y4, x4+15, y4+15);

    Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clBlack;
    Canvas->Ellipse(x6, y6, x6+20, y6+20);

    /*Draw the Planet in the new location*/
	Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clRed;
    Canvas->Ellipse(x1, y1, x1+10, y1+10);
    Canvas->Pen->Color = clBlack;

    Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clWhite;
    Canvas->Ellipse(x3, y3, x3+15, y3+15);
    Canvas->Pen->Color = clBlack;

    Canvas->Pen->Color = clBlack;
    Canvas->Brush->Color = clBlue;
    Canvas->Ellipse(x5, y5, x5+20, y5+20);
    Canvas->Pen->Color = clBlack;

    /*Adjust the coordinates of the x,y axis so that the origin is in the center*/
	Canvas->MoveTo(ClientWidth/2, 0);
    Canvas->LineTo(ClientWidth/2, ClientHeight);
    Canvas->MoveTo(0, ClientHeight/2);
    Canvas->LineTo(ClientWidth, ClientHeight/2);
    
	/*Store the current planet location before calculating new location so we
    can erase it before drawing new planet*/
	x2 = x1;
    y2 = y1;
    x4 = x3;
    y4 = y3;
    x6 = x5;
    y6 = y5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    /*Initialize x and y and angle variables. Locate center of solar system
    at the origin using xCenter = 0 and yCenter = 0*/
	x1 = 10;
    y1 = 10;
    x2 = 0;
    y2 = 0;
    x3 = 50;
    y3 = 50;
    x4 = 0;
    y4 = 0;
    x5 = 100;
    y5 = 100;
    x6 = 0;
    y6 = 0;
    a = 0;
    b = 0;
    c = 0;
    xCenter = 0;
    yCenter = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    /*Use the timer function to pause and increment the orbit angle from
        0 to 360 degrees. Reset angle to 0 when it reaches 360
        Convert Degrees to Ratians by multiplying by PI and dividing by 180*/
		if (a<360){
            x1 = 100*(cos(a*3.14/180))+xCenter;
            y1 = 100*(sin(a*3.14/180))+yCenter;
            a=a+4; //Sets the velocity of the planet orbit
            }
        else a=0;
        if (b<360){
            x3 = 200*(cos(b*3.14/180))+xCenter;
            y3 = 200*(sin(b*3.14/180))+yCenter;
            b=b+2; //Sets the velocity of the planet orbit
            }
        else b=0;
        if (c<360){
            x5 = 300*(cos(c*3.14/180))+xCenter;
            y5 = 300*(sin(c*3.14/180))+yCenter;
            c=c+1; //Sets teh velocity of the planet orbit
            }
        else c=0;
        Form1->Paint();
}
//---------------------------------------------------------------------------
