#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int buildingsNumber = 0,lastBuildingHeight = 0, result = 0;
int buildingsHeight[250000] = {0};
int buildingsWidth[250000] = {0};
int buildings[15000] = {0};
int it=0;
bool flag = false;

void addBuilding(int buildingHeight){
    if(buildingHeight == buildings[it]){
        return;
    }
    else if(buildingHeight > buildings[it]){
        buildings[++it] = buildingHeight;
        return;
    }
    for(int i = 0; i <= it; i++)
    {
        if(buildings[i] >= buildingHeight){
            for(int j = i; j <= it; j++){
                buildings[j] = 0;
            }
            buildings[i] = buildingHeight;
            it=i;
            return;
        }
    }
}

int main() {

    //From keyboard
   /*
    scanf("%d", &buildingsNumber);
    for(int i = 0; i < buildingsNumber; i++){
        scanf("%d %d", &buildingsWidth[i], &buildingsHeight[i]);
    }*/

   //From file
    fstream file;
    file.open("buildings.txt", ios::in);
    if(file.good()){
        file >> buildingsNumber;
        for(int i = 0; i< buildingsNumber; i++){
            file >> buildingsWidth[i];
            file >> buildingsHeight[i];
        }
    } else{
        printf("Error!!");
    }
    file.close();
    auto begin = std::chrono::high_resolution_clock::now();
    result = 1;
    buildings[0] = buildingsHeight[0];
    lastBuildingHeight = buildingsHeight[0];

    for(int i = 1; i < buildingsNumber; i++){
        if (lastBuildingHeight == buildingsHeight[i]){
            //cout<<"Warunek 1 "<<buildingsHeight[i]<<endl;
            lastBuildingHeight = buildingsHeight[i];
            continue;
        } else if(lastBuildingHeight < buildingsHeight[i]){
            //cout<<"Warunek 2 "<<buildingsHeight[i]<<endl;
            result++;
            addBuilding(buildingsHeight[i]);
            lastBuildingHeight = buildingsHeight[i];
        } else{
            for (int j = 0; j <= it; ++j) {
                if(buildings[j] == buildingsHeight[i]){
                    //cout<<"Warunek 3 "<<buildingsHeight[i]<<endl;
                    addBuilding(buildingsHeight[i]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                //cout<<"Warunek 4 "<<buildingsHeight[i]<<endl;
                addBuilding(buildingsHeight[i]);
                result++;
            }
            flag = false;
            lastBuildingHeight = buildingsHeight[i];
        }

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Wynik: %d\n",result);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    return 0;
}
