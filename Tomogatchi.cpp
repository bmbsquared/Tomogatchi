#include <iostream>
#include <string>

using namespace std;

int healthStat, hungerStat, energyStat, loveStat, currentTime;
int c_MAXSTAT = 100; //Max value for stats
string petAscii = "        _\no'')}__//\n `/      )\n ((/-(/";
string name; 
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

void printPet() {
    std::cout << petAscii << endl;
}

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
    cout<< "\n" << name << "\n" << endl;
    cout << "Health: " << healthStat << endl;
    cout << "Hunger: " << hungerStat << " out of 100" <<  endl;
    cout << "Energy: " << energyStat << " out of 100" << endl;
    cout << "Love: " << loveStat << " out of 100" <<  endl;
    cout << "The time is currently: " << getTime() << endl;
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
    cout << "What would you like to name your pet?" << endl;
    cin >> name; 
    cout << "Your pet's name is : \n" << endl;
    cout << name << endl; 
    printPet();
    int input; 
    bool isScold = false;
    while (isAlive()) {
        if(healthStat < 50 && isScold == false) {
            input = 9;
        } 
    else {
	cout << "What would you like to do with " << name << endl;
   	cout << "(1) Feed  " << name << "  snack" << endl;
        cout << "(2) Feed "<< name << " meal" << endl;
        cout << "(3) Play fetch with " << name << endl;
        cout << "(4) Go for a run with " << name << endl;
        cout << "(5) Give " <<name << " a belly rub" << endl;
        cout << "(6) Let  " << name << " take a nap " << endl;
        cout <<"(7) Tuck " << name << " in for bed " << endl; 
        cout <<"(8) Feed "  << name << " a treat " << endl; 
        cin >> input;
        }
        switch(input){
            case 1: cout << "You fed" << name << "a snack!\n" << endl; 
                cout << name << "'s health stats are now \n" << endl; 
                toStringStats();  
                break;

            case 2: cout << "You fed your "<< name << "a meal! \n" << endl;
                eatMeal();
                cout << name << "gained energy and hunger points! \n" << endl;
                cout << name <<"'s health stats are now \n"  <<endl;
                toStringStats();
                break;

            case 3: cout << "You played fetch with "<< name <<" \n" << endl;
                playFetch();
                cout << name << " lost energy points but gained love and health points!\n" << endl;
                cout << name  << "'s pet's health stats are now \n" << endl;
                toStringStats();
                break;
            
            case 4 : cout << " You took"  << name << " for a run! \n" << endl;
                goOnRun();
                cout << name << "'s health stats are now \n" << endl;
                toStringStats();
                break; 
            
            case 5: cout << "You gave your pet a belly rub! \n" << endl;
                pets();
                cout << name << " lost energy points but gained love and health points!\n" << endl;
                cout << name << "'s health stats are now \n " << endl;
                toStringStats();
                break;

            case 6: cout << name << "took a nap!\n" << endl;
                takeNap();
                cout << name << " gained energy points but lost hunger points!\n" << endl;
                cout << name << "'s health stats are now \n " << endl;
                toStringStats();
                break;

            case 7: cout << name << " fell asleep! \n" << endl; 
                goBed();
                cout << name << " gained energy points but lost hunger points!\n" << endl;
                cout << name << "'s health stats are now \n " << endl;
                toStringStats();
                break;
            
            case 8: cout << "You feed " << name << " a treat! \n" << endl;
                eatTreat();
                cout << name << " gained points in hunger and love but lost points in health.\n" << endl;
                cout << name << "'s health stats are now \n " << endl;
                toStringStats();
                break;

            case 9: cout << "Oh no! " << name << " had an accident on the floor!\n " <<endl;
                scold();
                isScold = true;
                cout << name << "lost points in love\n" << endl;
                cout << name << "'s health stats are now \n " << endl;
                toStringStats();
                break;
        }
        printPet();
        confirmStats();
    }
    cout << "good game" << endl;
    return 0;
};
