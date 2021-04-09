

///My solution of task "Plakatowanie" from XV Olympiad in Informatics, www.oi.edu.pl
///Author: Michał Ryszka, 04.2021

///Moje rozwiązanie zadania "Plakatowanie" z 15 Olimpiady Informatycznej, www.oi.edu.pl
///Autor: Michał Ryszka, 04.2021


#include <iostream>
#include <fstream>

using namespace std;

int amountOfBuildings = 0,lastBuildingHeight = 0, result = 0;
int buildingsHeight[250000] = {0};
int buildingsWidth[250000] = {0};
int buildingsTable[250000] = {0};
int lastBuildingNumber = 0;

void addBuilding(int buildingHeight){
    if(buildingHeight == buildingsTable[lastBuildingNumber]){
        return;
    }
    else if(buildingHeight > buildingsTable[lastBuildingNumber]){
        buildingsTable[++lastBuildingNumber] = buildingHeight;
        return;
    }
}

bool addBuilding(int loopNumber, int buildingHeight){

    if(buildingsTable[loopNumber] < buildingHeight){
        buildingsTable[loopNumber + 1] = buildingHeight;
        lastBuildingNumber = loopNumber + 1;
        return true;
    }

    if(loopNumber == 0 && buildingsTable[0] >= buildingHeight){
        buildingsTable[0] = buildingHeight;
        lastBuildingNumber = 0;
        return true;
    }

    return false;
}

int main() {

    //Data from keyboard
    scanf("%d", &amountOfBuildings);
    for(int i = 0; i < amountOfBuildings; i++){
        scanf("%d %d", &buildingsWidth[i], &buildingsHeight[i]);
    }

   //Data from file (used to testing program)
    /*fstream file;
    //file.open("..\\tests_data\\in\\pla1a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla1b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla1c.in", ios::in);
    //file.open("..\\tests_data\\in\\pla1ocen.in", ios::in);
    //file.open("..\\tests_data\\in\\pla2a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla2b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla2c.in", ios::in);
    //file.open("..\\tests_data\\in\\pla2ocen.in", ios::in);
    //file.open("..\\tests_data\\in\\pla3a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla3b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla3c.in", ios::in);
    //file.open("..\\tests_data\\in\\pla3ocen.in", ios::in);
    //file.open("..\\tests_data\\in\\pla4a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla4b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla4ocen.in", ios::in);
    //file.open("..\\tests_data\\in\\pla5a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla5b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla6a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla6b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla7a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla7b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla8a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla8b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla9a.in", ios::in);
    //file.open("..\\tests_data\\in\\pla9b.in", ios::in);
    //file.open("..\\tests_data\\in\\pla10a.in", ios::in);
    file.open("..\\tests_data\\in\\pla10b.in", ios::in);
    if(file.good()){
        file >> amountOfBuildings;
        for(int i = 0; i < amountOfBuildings; i++){
            file >> buildingsWidth[i];
            file >> buildingsHeight[i];
        }
    } else{
        printf("Error! File not found!\n");
    }
    file.close();*/

    result = 1;
    buildingsTable[0] = buildingsHeight[0];
    lastBuildingHeight = buildingsHeight[0];

    for(int i = 1; i < amountOfBuildings; i++){
        if (lastBuildingHeight == buildingsHeight[i]){
            lastBuildingHeight = buildingsHeight[i];
        } else if(lastBuildingHeight < buildingsHeight[i]){
            result++;
            addBuilding(buildingsHeight[i]);
            lastBuildingHeight = buildingsHeight[i];
        } else{
            for (int j = lastBuildingNumber; j >= 0; j--) {

                if(buildingsTable[j] == buildingsHeight[i]){
                    lastBuildingNumber = j;
                    break;
                }

                if(addBuilding(j, buildingsHeight[i])){
                    result++;
                    break;
                }
            }
            lastBuildingHeight = buildingsHeight[i];
        }

    }
    printf("%d\n",result);
    return 0;
}

