#include <iostream>
#include <string>

using namespace std;

int healthStat, hungerStat, energyStat, loveStat;
int currentTime;

void setStats() {
    healthStat = 80;
    hungerStat = 80;
    energyStat = 80;
    loveStat = 80;
    currentTime = 720;
}

void confirmStats() {
    if(healthStat > 100)
        healthStat = 100;
    if(hungerStat > 100)
        hungerStat = 100;
    if(energyStat > 100)
        energyStat = 100;
    if(loveStat > 100)
        loveStat = 100;
}

bool isAlive() {
    if(healthStat < 0 || hungerStat < 0 || energyStat < 0 || loveStat < 0)
        return false;
    else
        return true;
}

void addTime(int pass) {
    currentTime += pass;
    
    if(currentTime >= 1440)
        currentTime -= 1440;
}

string getTime() {
    int hour = currentTime / 60;
    int min = currentTime % 60;

    string timeDigital = to_string(hour) + ":" + to_string(min);

    return timeDigital;
}

void toStringStats() {
    cout << "\n\n\nHealth: " << healthStat << endl;
    cout << "Hunger: " << hungerStat << endl;
    cout << "Energy: " << energyStat << endl;
    cout << "Love: " << loveStat << endl;
    cout << "The time is: " << getTime() << endl;
}

int main()
{
    setStats();

    if(isAlive())
        cout << "Is alive" << endl;
    else
        cout<< "Is dead" << endl;

    addTime(30);
    cout << "The time is: " << getTime() << endl;
    
    addTime(240);
    cout << "The time is: " << getTime() << endl;
    
    addTime(680);
    cout << "The time is: " << getTime() << endl;

    toStringStats();

    return 0;
}
