#include "snake.h"


void initSnake(vector<Rectangle*>& snake, Simple_window& win){
    for (int i=0; i<4;++i){
        snake.push_back(new Rectangle{Point{win.x_max()/2-2*RECT_WIDTH + i*RECT_WIDTH, win.y_max()/2},RECT_WIDTH,RECT_HEIGHT});
        snake[snake.size()-1]->set_fill_color(Color::green);
        win.attach(*(snake[snake.size()-1]));
    }
}

void addLength(vector<Rectangle*>& snake, Simple_window& win, Direction dir){
    int posx = snake[snake.size()-1]->point(0).x;
    int posy = snake[snake.size()-1]->point(0).y;
    if(dir == Direction::RIGHT){
        snake.push_back(new Rectangle{Point{posx+RECT_WIDTH,posy},RECT_WIDTH,RECT_HEIGHT});
    }else if(dir == Direction::LEFT){
        snake.push_back(new Rectangle{Point{posx-RECT_WIDTH,posy},RECT_WIDTH,RECT_HEIGHT});
    }else if(dir == Direction::UP){
        snake.push_back(new Rectangle{Point{posx,posy-RECT_HEIGHT},RECT_WIDTH,RECT_HEIGHT});
    }else{
        snake.push_back(new Rectangle{Point{posx,posy+RECT_HEIGHT},RECT_WIDTH,RECT_HEIGHT});
    }
    snake[snake.size()-1]->set_fill_color(Color::red);
    win.attach(*(snake[snake.size()-1]));
}

void moveSnake(vector<Rectangle*>& snake, Simple_window& win, Direction dir){
    win.detach(*(snake[0]));
    snake.erase(snake.begin());
    addLength(snake,win,dir);
}

bool detectCollision(const Rectangle& a, const Rectangle& b){
    int aX = a.point(0).x;
    int aY = a.point(0).y;
    int bX = b.point(0).x;
    int bY = b.point(0).y;
    if (abs(aX-bX)<RECT_WIDTH && abs(aY-bY)<RECT_HEIGHT){return true;}
    return false;
}

void placePiece(Rectangle& piece, const vector<Rectangle*>& snake){
    bool overlap = true;
    while (overlap){
        overlap = false;
        int dx = rand() % (WIN_WIDTH-RECT_WIDTH)- piece.point(0).x;
        int dy = rand() % (WIN_HEIGHT-RECT_HEIGHT) - piece.point(0).y;
        piece.move(dx,dy);
        for (auto rect : snake){
            if (detectCollision(piece,*rect)){
                overlap = true;
                break;
            }
        } 
    }
}

bool selfCollide(vector<Rectangle*>& snake){
    bool val = false;
    for (int i=0; i<snake.size()-1; ++i){
        if (detectCollision(*(snake[snake.size()-1]),*(snake[i]))){
            val = true;
            break;
        }
    }
    return val;
}

Direction operator++(Direction& dir){
    if (dir==Direction::RIGHT){return Direction::UP;}
    else{return Direction(int(dir)+1);}
}

Direction operator--(Direction& dir){
    if (dir==Direction::UP){return Direction::RIGHT;}
    else{return Direction(int(dir)-1);}
}


Direction& steer(Direction& current){
    if (Fl::event_key('a')){
        ++current;
    }else if(Fl::event_key('d')){
        --current;
    }
    return current;
}