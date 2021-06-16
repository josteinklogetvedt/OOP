#include "Plant.h"


float readSensor(int id){
    float hum = static_cast<float>(rand() % 100);
    return hum;
}

float Plant::readHumidity(){
    humidity = readSensor(sensorId);
    cout << humidity << " " << name << endl; //Fjernes
    return humidity;
}

PlantStatus Plant::getStatus(){
    if (humidity < 0){return SENSOR_ERROR;}
    if(humidity < humidityMin){return WATER_LOW;}
    if(humidity > humidityMax){return WATER_HIGH;}
    return HAPPY_PLANT;
}

bool Plant::operator==(Plant  &rhs){
    return sensorId == rhs.sensorId;
} 

ostream& operator<<(ostream &os, Plant &p){
    os << p.name << " @ " << p.location;
    return os;
}

void Garden::addPlant(Plant p){
    plants.push_back(p);
}

void Garden::removePlant(Plant p){
    for (auto it = plants.begin(); it != plants.end(); ++it){
        if (*it == p){
            plants.erase(it);
            return;
        }
    }
}

vector<Plant> Garden::needsHelp(){
    vector<Plant> badPlants;
    for (int i=0; i<plants.size(); ++i){
        plants[i].readHumidity();
        if (plants[i].getStatus() != HAPPY_PLANT){
            badPlants.push_back(plants[i]);
        }
    } 
    return badPlants;
}

void Garden::monitor(int interval){
    while (true){
        vector<Plant> badPlants = needsHelp();
        for (auto p : badPlants){
            string status;
            PlantStatus stat = p.getStatus();
            if (stat == WATER_LOW){
                status = "trenger vann!";
            }else if (stat==WATER_HIGH){
                status = "har for mye vann!";
            }else{
                status = "sensorfeil";
            }
            cout << p << ": <" << status << ">" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
}

void menu(){
    Plant orkide{"Orkide","Stue",1,10.0,25.0};
    Plant kaktus{"Kaktus", "Stue",2,5.0,10.0};
    Plant basilikum{"Basilikum","Kjokken",3,25.0,50.0};
    Plant mynte{"Mynte", "Kjokken",4,20.0,50.0};
    Garden hus{"Hus"};
    hus.addPlant(orkide);
    hus.addPlant(kaktus);
    hus.addPlant(basilikum);
    hus.addPlant(mynte);
    hus.monitor(5*60*100);
}