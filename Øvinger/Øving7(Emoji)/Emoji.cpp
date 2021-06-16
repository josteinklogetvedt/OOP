#include "Emoji.h"

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
}
void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(eyeRight);
}
void SmilingFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(eyeRight);
    win.attach(arcSmiling);
}
void SadFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(eyeRight);
    win.attach(arcSad);
}
void AngryFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(eyeRight);
    win.attach(arcSad);
    win.attach(eyebrowLeft);
    win.attach(eyebrowRight);
}
void WinkingFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(arcSmiling);
    win.attach(eyeTop);
    win.attach(eyeBot);
}
void SurprisedFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeLeft);
    win.attach(eyeRight);
    win.attach(mouthSurprised);
}
