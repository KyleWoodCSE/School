#include <iostream>
#include <cmath>
#include <fstream>

// function calculating total bots power
float matrix_power(int botsPower_c[], int botsCount_c, float bossPower_c) {
    int sum = 0;
    for (int i=0; i < botsCount_c; i++) {
        sum+=botsPower_c[i];
    }
    return (float)sum + bossPower_c;
}

// function determining missile power
template <typename T>
T single_missile_power(T botPower_c){
    if (botPower_c <= 15) {
        return botPower_c * 2;
    }
    return botPower_c * 5;
}

// load function for needed matrix power
void load_dva(float& defenseMatrix, float matrixPowerRequired_c) {
    if (defenseMatrix < matrixPowerRequired_c) {
        defenseMatrix = matrixPowerRequired_c;
    }
}

// overloaded load function for needed number of missiles
void load_dva(int& microMissiles, float missilePowerRequired_c) {
    int neededMissiles = ceil(missilePowerRequired_c/60);
    if (microMissiles < neededMissiles) {
        microMissiles = neededMissiles;
    }
}

int main() {
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

    // calculate required matrix power
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);

    // calculate missile power
    float missilePowerRequired = 0.0;
    for (int i=0; i < botsCount; i++) {
        missilePowerRequired+=single_missile_power(botsPower[i]);
    }
    missilePowerRequired+=single_missile_power(bossPower);
    
    // load micro missiles
    int microMissiles;
    combatFile >> microMissiles;
    load_dva(microMissiles, missilePowerRequired);

    // load defense matrix
    float defenseMatrix;
    combatFile >> defenseMatrix;
    load_dva(defenseMatrix, matrixPowerRequired);

    // close combat file
    combatFile.close();

    // open report file
    std::ofstream reportFile;
    reportFile.open("report.txt");

    // check if file is open
    if (!reportFile.is_open()) {
        std::cout << "Report file failed to open." << std::endl;
        return 0;
    }

    // write information to report file
    reportFile << "D.Va's Combat Report" << std::endl;
    reportFile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << "." << std::endl;
    reportFile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << "." << std::endl;
    reportFile << "Ready for combat!" << std::endl;

    // close report file
    reportFile.close();

    // end program
    return 0;
}

