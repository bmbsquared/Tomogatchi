#include <iostream>
#include <string>

int healthStat, hungerStat, energyStat, loveStat, timeVar;

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
    timeVar = 1200;
};

//---------------------------------------------------------//
//                         ACTIONS                         //
//---------------------------------------------------------//

void eatSnack() {
    timeVar = timeVar + 10;
    hungerStat = hungerStat + 10;
    energyStat = energyStat + 5;
};

void eatMeal() {
    timeVar = timeVar + 30;
    hungerStat = hungerStat + 25;
    energyStat = energyStat + 10;
};
	
void eatTreat() {
    timeVar = timeVar + 5;
    hungerStat = hungerStat + 5;
    loveStat = loveStat + 10;
    healthStat = healthStat - 10;
}
	
void playFetch() {
    timeVar = timeVar + 30;
    energyStat = energyStat - 15;
    loveStat = loveStat + 10;
    healthStat = healthStat + 5;
}
	
void goOnRun() {
    timeVar = timeVar + 60;
    energyStat = energyStat - 40;
    loveStat = loveStat + 10;
    healthStat = healthStat + 15;
}
	
void pets() {
    timeVar = timeVar + 10;
    loveStat = loveStat + 30;
    healthStat = healthStat + 10;
    energyStat = energyStat - 5;
}
	
void takeNap() {
    timeVar = timeVar + 30;
    energyStat = energyStat + 10;
    hungerStat = hungerStat - 5;
}
	
void goBed() {
    timeVar = timeVar + 800; // add 8 hours so time function is easier
    energyStat = energyStat + 40;
    hungerStat = hungerStat - 20;
}
	
void scold() {
    timeVar = timeVar + 10;
    loveStat = loveStat - 15;
}



// main function to test
int main() {
 
    setup();

    while (isAlive()) {
        std::cout << "I am alive \n" << std::endl;
        std::cout << hungerStat << std::endl;
        eatMeal();
        std::cout << hungerStat << std::endl;
        kill();
    }
    std::cout << hungerStat << std::endl;
    std::cout << "I am dead \n" << std::endl;

    return 0;
};