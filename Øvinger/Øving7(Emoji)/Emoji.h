#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji{
    public:
        // Disable copying. Disable slicing, etc.
        Emoji(const Emoji&) = delete;
        Emoji& operator=(const Emoji&) = delete;

        // Deleting the copy constructor also deletes the default constructor.
        // Emoji needs a default constructor.
        Emoji() {}
        // Emoji() = default; // is an alternative way of achieving the same.

        // The pure virtual function that has to be overriden for a deriving class
        // to be instantiable. Every class deriving from Emoji is supposed to
        // attach all its Shapes to a window. This makes the class abstract.
        virtual void attach_to(Graph_lib::Window&) = 0;

        // Relevant because Vector_ref can own Emojis and automatically cleans up.
        // Subject will be visited later in the course.
        virtual ~Emoji() {}
};

class Face : public Emoji{
    private:
        Circle face;
    public:
        Face(Point c, int r)
            :face{c,r}{
            face.set_fill_color(Color::yellow);    
            }
        void attach_to(Graph_lib::Window& win) override;
};

class EmptyFace : public Face{     
    protected:
        int centerX;
        int centerY;
        int radiusEye;
        Circle eyeLeft;
        Circle eyeRight;
    public:
        EmptyFace(Point c, int cX, int cY, int r)
            :Face{c,r},centerX{cX},centerY{cY},radiusEye{r/5}, eyeLeft{Point{centerX-2*radiusEye,centerY-2*radiusEye}, radiusEye},
            eyeRight{Point{centerX+2*radiusEye,centerY-2*radiusEye}, radiusEye}{
            eyeLeft.set_fill_color(Color::white);
            eyeRight.set_fill_color(Color::white);
            }
        void attach_to(Graph_lib::Window& win) override;
};

class SmilingFace : public EmptyFace{
    protected:
        Arc arcSmiling;
    public:       
        SmilingFace(Point c, int cX, int cY, int r)
            :EmptyFace{c,cX,cY,r}, arcSmiling{c,radiusEye*5,radiusEye*3,-150,-30}{
                arcSmiling.set_color(Color::black);
            }
        void attach_to(Graph_lib::Window& win) override;
};

class SadFace : public EmptyFace{   //Arver fra EmptyFace fordi jeg ikke har noe bruk for SmilingFace, lager en ny arc uansett
    protected:
        Arc arcSad;
    public:     
        SadFace(Point c, int cX, int cY, int r)
            :EmptyFace{c,cX,cY,r}, arcSad{Point{centerX,centerY+radiusEye*2},radiusEye*5,radiusEye*2,10,170}{
                arcSad.set_color(Color::black);
            }
        void attach_to(Graph_lib::Window& win) override;
};

class AngryFace : public SadFace{
    protected:
        Line eyebrowLeft;
        Line eyebrowRight;
    public:
        AngryFace(Point c, int cX, int cY, int r)
        :SadFace{c,cX,cY,r}, eyebrowLeft{Point{centerX-5,centerY-25},Point{centerX-25,centerY-35}},eyebrowRight{Point{centerX+5,centerY-25},Point{centerX+25,centerY-35}}{
            eyeLeft.set_fill_color(Color::black);
            eyeRight.set_fill_color(Color::black);
            eyebrowLeft.set_color(Color::black);
            eyebrowRight.set_color(Color::black);
        }
        void attach_to(Graph_lib::Window& win) override;

};

class WinkingFace : public SmilingFace{
    protected:
        Line eyeTop;
        Line eyeBot;
    public:       
        WinkingFace(Point c, int cX, int cY, int r)
            :SmilingFace{c,cX,cY,r}, eyeTop{Point{centerX+radiusEye,centerY-15},Point{centerX+25,centerY-25}},
            eyeBot{Point{centerX+radiusEye,centerY-15},Point{centerX+30,centerY-15}}{}
        void attach_to(Graph_lib::Window& win) override;
};

class SurprisedFace : public EmptyFace{
    protected:
        Ellipse mouthSurprised;
    public:
        SurprisedFace(Point c, int cX, int cY, int r)
            :EmptyFace{c,cX,cY,r}, mouthSurprised{Point{centerX,centerY+15},20,17}{
                mouthSurprised.set_fill_color(Color::black);
            }
        void attach_to(Graph_lib::Window& win) override;    
};
