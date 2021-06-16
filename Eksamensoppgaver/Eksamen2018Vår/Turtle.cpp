//void Turtle::setPosition(float x, float y){
//    this -> x = x;
//    this -> y = y;
//}

//sf::Vector2f Turtle::getPosition(){
//    return sf::Vector2f(x, y);
//}

//Turtle::Turtle(int width, int height, sf::Color bgColor, sf::Color color)
//   :x{0.0},y{0.0},angle{0.0},width{width},height{height},bgColor{bgColor}{
//      if (!canvas.creat(width, height)){
//          throw "Failed to create canvas";
//      }
//      setColor(color);
//      setLineWidth(1.0);
//      clear();
//}

//void Turtle::forward(float distance){
//    float x0 = x;
//    float y0 = y;
//  x += distance*cos(deg2rad(angle));
//  y += distance*sin(deg2rad(angle));
//  drawLine(x0, y0, x, y);
//}

//void Turtle::backward(float distance){
//  forward(-distance);
//}

//void Turtle::left(float angle){
//  this->angle += angle;   
//}

//void Turtle::right(float angle){
//  this->angle -= angle;   
//}

//void hexagon(Turtle* turtle){
//  turtle-> setColor(sf::Color(200, 100, 0);     
//  for (int i=0; i<6; ++i){
//      turtle -> forward(100.0);      
//      turtle -> left(60);
//}

//float randRange(float min, float max){
//  return min + rand() % (max-min)
//}

//void randomWalk(Turtle *turtle, int steps){
//for (int i=0; i<steps; ++i){
//  float angle = randRange(-90,90);
//  float distance = randRange(0,10);
//  turtle -> setAngle(angle);
//  turtle -> forward(distance);
//}
//}

//void koch(Turtle *turtle, float length, int level){
//     if (level == 0){
//          turtle -> forward(length)  
//    else{
//    turtle -> length = length/3;
//    level -= 1;
//    koch(turtle, length, level);
//    turte -> right(60);  
//    koch(turtle, length, level);
//    turtle -> left(120);
//    koch(turtle, length, level);
//    turtle -> right(60);}
//}


//void snowflake(Turtle *turtle, float length, int level){
//  for (int i=0; i<3; ++i){
//      koch(turtle, length, level);
//      turtle -> left(120);
//  }
//}
