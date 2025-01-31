#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

class Battle {
private:
    int botsPower[10];
    int botsCount;
    float bossPower;

public:
    // Constructor
    Battle(int bots[], int count, float boss) {
        std::copy_n(bots, count, botsPower);
        botsCount = count;
        bossPower = boss;
    }
    // destructor
    ~Battle() {
        std::cout << "The Battle class object is destroyed" << std::endl;
    }
    
    // calculate needed matrix power
    float matrix_power() {
        int sum = 0;
        for(int i=0; i < botsCount; i++) {
            sum+=botsPower[i];
        }
        // std::cout << "sum is: " << sum << std::endl;  only here for debugging purposes
        return (float)sum + bossPower;
    }

    // declare friend class
    friend class Mech;
};

class Mech {
private:
    float defenseMatrix;
    int microMissiles;

public:
    // constructor
    Mech() {
        defenseMatrix = 100.0;
        microMissiles = 10;
    }
    // destructor
    ~Mech() {
        std::cout << "The Mech class object is destroyed" << std::endl;
    }

    // getter functions
    float getMatrix() {
        return defenseMatrix;
    }
    int getMissiles() {
        return microMissiles;
    }

    void load(float matrixPowerRequired, float missilePowerRequired) {
        if (defenseMatrix < matrixPowerRequired) {
        defenseMatrix = matrixPowerRequired;
        }

        int neededMissiles = ceil(missilePowerRequired/60);
        if (microMissiles < neededMissiles) {
        microMissiles = neededMissiles;
        }
    }

    // calcululate needed missile power
    float micro_missile(Battle dvaBattle) {
        int power = 0.0;
        for (int i = 0; i<dvaBattle.botsCount; i++) {
            power+=dvaBattle.botsPower[i];
        }
        return (float)(2 * power) + (5 * dvaBattle.bossPower);
    }
};

int main() {
    // Open and read file
    // open file with ifstream
    std::ifstream combatFile;
    combatFile.open("combat.txt");

    // logic to check if file is open
    if (!combatFile.is_open()) {
        std::cout << "Combat file failed to open." << std::endl;
        return 0;
    }

    // read the number of bots
    int botsCount;
    combatFile >> botsCount;

    // create an array to hold bots power
    int botsPower[botsCount];

    // fill array with bots' powers
    for (int i=0; i < botsCount; i++) {
        combatFile >> botsPower[i];
    }

    // store boss power
    float bossPower;
    combatFile >> bossPower;

    // close combat file
    combatFile.close();

    //Initialize battle and dva
    Battle dvaBattle(botsPower, botsCount, bossPower);
    Mech dva;

    //Calculate power needed
    float matrixPowerRequired = dvaBattle.matrix_power();
    float missilePowerRequired = dva.micro_missile(dvaBattle);

    //Load D.Va
    dva.load(matrixPowerRequired, missilePowerRequired);

    // Open and write results to file
    // open report file
    std::ofstream reportFile;
    reportFile.open("report.txt");

    // check if file is open
    if (!reportFile.is_open()) {
        std::cout << "Report file failed to open." << std::endl;
        return 0;
    }

    // write information to report file
    int microMissiles = dva.getMissiles();
    float defenseMatrix = dva.getMatrix();
    reportFile << "D.Va's Combat Report" << std::endl;
    reportFile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << "." << std::endl;
    reportFile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << "." << std::endl;
    reportFile << "Ready for combat!" << std::endl;

    // close report file
    reportFile.close();

    // end program
    return 0;
}