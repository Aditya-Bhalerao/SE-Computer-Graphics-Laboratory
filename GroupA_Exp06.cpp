// Write C++ program to implement Cohen Southerland line clipping algorithm.

#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,yl,xh,yh;
int getcode(int x,int y)
{
    int code = 0;
//Perform Bitwise OR to get outcode
    if(y > yh) code = code | TOP;
    if(y < yl) code = code | BOTTOM;
    if(x < xl) code = code | LEFT;
    if(x > xh) code = code | RIGHT;
    return code;
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    setcolor(BLUE);
    cout<<"Enter bottom left and top right co-ordinates of window: ";
    cin>>xl>>yl>>xh>>yh;
    rectangle(xl,yl,xh,yh);
    int x1,y1,x2,y2;
    cout<<"Enter the endpoints of the line: ";
    cin>>x1>>y1>>x2>>y2;
    line(x1,y1,x2,y2);
    char y;
    cout<<"Press y to clip";
    cin>>y;
    int outcode1=getcode(x1,y1); // getcode(50,150) ;
//After return outcode1 = 0001
    int outcode2=getcode(x2,y2); // getcode(150,150) ;
//After return outcode2 = 0000
    int accept = 0; //decides if line is to be drawn
    while(1)
    {
        float m =(float)(y2-y1)/(x2-x1);
// m=0/100; // Line is horizontal & straight
//Both points inside. Accept line
        if(outcode1==0 && outcode2==0) // Not true
        {
//after clipping both outcodes are 0000
            cout<<"Both point inside polygon";
            accept = 1; // set to 1
            break;
        }
//AND of both codes != 0.Line is outside. Reject line
        else if((outcode1 & outcode2)!=0) //Not True
        {
            break;
        }
        else // Executed
        {
            int x,y;
            int temp;
//Decide if point1 is inside, if not, calculate intersection

            if(outcode1==0) // 0001 == 0000 False
                temp = outcode2;
            else
                temp = outcode1; // temp= 0001
            if(temp & TOP)
            {
//Line clips top edge
                x = x1+ (yh-y1)/m;
                y = yh;
            }
            else if(temp & BOTTOM)
            {
//Line clips bottom edge
                x = x1+ (yl-y1)/m;
                y = yl;
            }
            else if(temp & LEFT)//Executed
            {
//Line clips left edge
                x = xl; //x=100;
                y = y1+ m*(xl-x1); //y = 150
            }
            else if(temp & RIGHT)
            {
//Line clips right edge
                x = xh;
                y = y1+ m*(xh-x1);
            }

//Check which point we had selected earlier as temp, and replace its co-ordinates 0;
            if(temp == outcode1) // 0001 == 0001 True
            {
                x1 = x; //x1,y1 = 100,150
                y1 = y;
                outcode1 = getcode(x1,y1); //getcode(100,150) == value 0000
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2,y2);
            }
        }
    }
    setcolor(WHITE);
    cout<<"\t\t After clipping:";
    if(accept) // True
    {
        line(x1,y1,x2,y2); //line(100,150,150,150)
        rectangle(xl,yl,xh,yh);
    }
    getch();
    closegraph();

    return 0;
}
