#include "simpleGraphics.h"


void plotPoints(Simple_window& win, int x[], int y[], int n){
    Vector_ref<Circle> vr;
    for (int i=0; i<n; ++i){
        vr.push_back(new Circle{Point{x[i],y[i]},radius});
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
}

void plotLines(Simple_window& win, int x[], int y[], int n){
    Vector_ref<Line> vr;
    if (n % 2 != 0){return;}
    for (int i=0; i<n; i+=2){
        vr.push_back(new Line{Point{x[i],y[i]},Point{x[i+1],y[i+1]}});
        vr[vr.size()-1].set_fill_color(Color::blue);
        win.attach(vr[vr.size()-1]);
    }
}

void alim(int a[], int n, int& amin, int& amax){
    amin = a[0];
    amax = a[0];
    for (int i=1; i<n; ++i){
        if (a[i]<amin){amin = a[i];}
        else if(a[i]>amax){amax=a[i];}
    }
}

int scaleX(Simple_window& win, int x, int xmin, int xmax){
    float val = win.x_max() * (static_cast<float>(x - xmin)/static_cast<float>(xmax-xmin));
    return static_cast<int>(round(val));
}

int scaleY(Simple_window& win, int y, int ymin, int ymax){
    float val = win.y_max() * (static_cast<float>(y - ymin)/static_cast<float>(ymax - ymin));
    return static_cast<int>(round(val));
}

void plotScaled(Simple_window& win, int x[], int y[], int n, Color c, int xmin, int xmax, int ymin, int ymax){
    Vector_ref<Circle> vc;
    Vector_ref<Line> vl;
    for (int i=0; i<n; ++i){
        x[i] = scaleX(win,x[i],xmin,xmax);
        y[i] = scaleY(win,y[i],ymin,ymax);
        vc.push_back(new Circle{Point{x[i],y[i]},radius});
        vc[vc.size()-1].set_fill_color(c);
        win.attach(vc[vc.size()-1]);
    }
    for (int i=0; i<n; i+=2){
        vl.push_back(new Line{Point{x[i],y[i]},Point{x[i+1],y[i+1]}});
        vl[vl.size()-1].set_color(c);
        win.attach(vl[vl.size()-1]);
    }
    win.wait_for_button();
}

void plotScaled(Simple_window& win, int x[], int y[], int n, Color c){
    int xmin,xmax,ymin,ymax=0;
    alim(x,n,xmin,xmax);
    alim(y,n,ymin,ymax);
    plotScaled(win,x,y,n,c,xmin,xmax,ymin,ymax);
}

float sinDeg(int deg){
    float rad = (static_cast<float>(deg)*PI)/180.0;
    return sin(rad);
}

float cosDeg(int deg){
    float rad = (static_cast<float>(deg)*PI)/180.0;
    return cos(rad);
}

int scaleYfloat(Simple_window& win, float y, float ymin, float ymax){
    float val = win.y_max() * ((y - ymin)/(ymax - ymin));
    return static_cast<int>(round(val));
}

void plotMathFuncs(Simple_window& win, int num){
    int x[360];
    if (num == 1){
        int sinX[360];
        for (int i=0; i<360;++i){
            x[i] = i;
            sinX[i] = scaleYfloat(win,sinDeg(i),-1.0, 1.0);
        }
        plotScaled(win,x,sinX,360, Color::red);
    }else if (num == 2){
        int cosX[360];
        for (int i=0; i<360;++i){
            x[i] = i;
            cosX[i] = scaleYfloat(win,cosDeg(i),-1.0, 1.0);
        }
        plotScaled(win,x,cosX,360, Color::blue);
    }
}

