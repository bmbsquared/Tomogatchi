#include <iostream>
#include <string>

using namespace std;

int healthStat, hungerStat, energyStat, loveStat, currentTime;
int c_MAXSTAT = 100; //Max value for stats

// check if tomogatchi is alive
// return true if all stats above 0, false if any stat below or equal to 0
bool isAlive() {
    if (healthStat > 0 && hungerStat > 0 && energyStat > 0 && loveStat > 0) {
        return true;
    } else {
        return false;
    }   
    
};

// kill the tomogatchi
// used to test isAlive function
void kill() {
    hungerStat = 0;
};

// sets up stats to play game
void setup() {
    healthStat = 100;
    hungerStat = 100;
    energyStat = 100;
    loveStat = 100;
    currentTime = 720; //time is stored in minutes, military time
};

// if any stat is over Max stat value sets stat to max value
void confirmStats() {
    if(healthStat > c_MAXSTAT)
        healthStat = c_MAXSTAT;
    if(hungerStat > c_MAXSTAT)
        hungerStat = c_MAXSTAT;
    if(energyStat > c_MAXSTAT)
        energyStat = c_MAXSTAT;
    if(loveStat > c_MAXSTAT)
        loveStat = c_MAXSTAT;
};

// adds time, in minutes, to simulate the passage of time
void addTime(int pass) {
    currentTime += pass;
    
    if(currentTime >= 1440) //if time is over 1440 minutes(24 hours) sub 1440 mins to begin new "day"
        currentTime -= 1440;
}

// return time as string in expected 24 hour (hour:minute) format
string getTime() {
    int hour = currentTime / 60;
    int min = currentTime % 60;

    string timeDigital = to_string(hour) + ":" + to_string(min);

    return timeDigital;
}

// print all stat values and time
void toStringStats() {
    cout << "\n\n\nHealth: " << healthStat << endl;
    cout << "Hunger: " << hungerStat << endl;
    cout << "Energy: " << energyStat << endl;
    cout << "Love: " << loveStat << endl;
    cout << "The time is: " << getTime() << endl;
}

//---------------------------------------------------------//
//                         ACTIONS                         //
//---------------------------------------------------------//

void eatSnack() {
    addTime(10);
    hungerStat = hungerStat + 10;
    energyStat = energyStat + 5;
};

void eatMeal() {
    addTime(30);
    hungerStat = hungerStat + 25;
    energyStat = energyStat + 10;
};
	
void eatTreat() {
    addTime(5);
    hungerStat = hungerStat + 5;
    loveStat = loveStat + 10;
    healthStat = healthStat - 10;
}
	
void playFetch() {
    addTime(30);
    energyStat = energyStat - 15;
    loveStat = loveStat + 10;
    healthStat = healthStat + 5;
}
	
void goOnRun() {
    addTime(60);
    energyStat = energyStat - 40;
    loveStat = loveStat + 10;
    healthStat = healthStat + 15;
}
	
void pets() {
    addTime(10);
    loveStat = loveStat + 30;
    healthStat = healthStat + 10;
    energyStat = energyStat - 5;
}
	
void takeNap() {
    addTime(30);
    energyStat = energyStat + 10;
    hungerStat = hungerStat - 5;
}
	
void goBed() {
    addTime(480);
    energyStat = energyStat + 40;
    hungerStat = hungerStat - 20;
}
	
void scold() {
    addTime(10);
    loveStat = loveStat - 15;
}



// main function to test
int main() {
 
    setup();
    string name; 
    cout << "what would you like to name your pet" << endl;
    cin >> name; 
    cout << "your pet is named: \n" << endl;
    cout << name << endl; 
    int input; 
    cout << "what would you like to do"<< endl;
    cout << "(1) feed pet snack" << endl;
    cout << "(2) feed a meal" << endl;
    cout << "(3) play fetch " << endl;
    cout << "(4)go for a run " << endl;
    cout << "(5) give pets" << endl;
    cout << "(6) pet nap " << endl;
    cout <<"(7) sleep the night " << endl;
    cin >> input; 
    while (isAlive()) {
        switch(input){
            case 1: cout << "you gave your pet a snack \n"  << endl;
         eatSnack();
        cout << "your pets health stats are now \n" << endl; 
         toStringStats();  
        break;

        case 2: cout << "you fed your pet a meal \n" << endl;
         eatMeal();
         cout << "your pets health stats are now \n"  <<endl;
         toStringStats();
         break;

        case 3: cout << "you played fetch with your pet \n" << endl;
            playFetch();
            cout << "your pet's health stats are now \n" << endl;
            toStringStats();
            break;
        
        case 4 : cout << " you took you pet for a run \n" << endl;
            goOnRun();
            cout << "your pet's health stats are now \n" << endl;
            toStringStats();
            break; 
        
        case 5: cout << "you gave your pet a belly rub \n" << endl;
        pets();
        cout << "your pet's health stats are now \n " << endl;
        toStringStats();
        break;

        case 6: cout << "your pet took a nap \n" << endl;
        takeNap();
        cout << "your pet's health stats are now \n" << endl;
        toStringStats();
        break;

        case 7: cout << "your pet fell asleep! \n" << endl; 
        goBed();
        cout << "your pet's health stats are now \n" << endl;
        toStringStats();
        break;


        }
        cout << "I am alive \n" << endl;
        cout << hungerStat << endl;
        eatMeal();
        cout << hungerStat << endl;
        kill();
    }
    cout << hungerStat << endl;
    cout << "I am dead \n" << endl;

    return 0;
};