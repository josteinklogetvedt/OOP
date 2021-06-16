
//class Wally : Turtle{
//    private:
//        float speed;
//        float turn;
 //   public:
//        void setSpeed(float sp){speed = sp;}
//        void setTurn(float tr){turn = tr;}
//        float getSpeed(){return speed;}
//        float getTurn(){return turn;}
//        Wally(int width, int height, float speed, float turn)
//            :speed{speed},turn{turn},Turtle(width, height){}
//        void forward(float distance);
//};

//void Wally::forward(float distance){  
//  Turtle::forward(distance);
//    if (x < -width/2){x = width/2;}
//    if (x> width/2){x = width;}
//    if (y1 < -height/2){y = -height/2;}
//    if (y1 > height/2){y = height/2;}
//}

//void Wally::run(){
//    float dist;
//    while (true){
//        dist = sense();
//        if (dist<100){
//            left(turn);
//        }if(dist > 10){
//            right(randRange(-5,5));
//            forward(speed);
//        }        
//    }
//}
