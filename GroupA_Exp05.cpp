// Write C++ program to draw a concave polygon and fill it with desired color using scan fill
// algorithm.

#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
    int gd=DETECT,gm,dx,dy,x,y,temp,n,i,j,k;
    initgraph(&gd,&gm,"NULL");

    int p[20][2],xi[20];
    float slope[20];
    cout<<"Enter total number of vertices of the polygon: ";
    cin>>n;
    cout<<"Enter x and y cordinates of the vertices:\n ";

//For getting the co-ordinates
    for(i=0; i<n; i++)
    {
        cout<<"x"<<i<<"y"<<i<<" ";
        cin>>p[i][0]>>p[i][1];
    }
    p[n][0]=p[0][0];
    p[n][1]=p[0][1];
    for(i=0; i<n; i++)
    {
        line(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);
        delay(100);
    }
    for(i=0; i<n; i++)
    {
        dx=p[i+1][0]-p[i][0];
        dy=p[i+1][1]-p[i][1];
        if(dy==0)
        {
            slope[i]=1.0;
        }
        if(dx==0)
        {
            slope[i]=0.0;
        }
        if((dy!=0) && (dx!=0))
        {
            slope[i]=(float) dx/dy;
        }
    }
    for(y=480; y>0; y--)
    {
        k=0;
        for(i=0; i<n; i++)
        {
            if(((p[i][1]<=y)&&(p[i+1][1]>y))||((p[i][1]>y)&&(p[i+1][1]<=y)))
            {
                xi[k]=(int)(p[i][0]+slope[i]*(y-p[i][1]));
                k++;
            }
        }
        for(j=0; j<k-1; j++)
            for(i=0; i<k-1; i++)
            {
                if(xi[i]>xi[i+1])
                {
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }

        setcolor(6);
        for(i=0; i<k; i+=2)
        {
            line(xi[i],y,xi[i+1],y);
            delay(10);
        }
    }

    getch();
    closegraph();

    return 0;
}
