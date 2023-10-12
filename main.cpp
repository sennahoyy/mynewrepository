#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Data{
  public:
  string date;
  string region;
  string rep;
  string item;
  int units;
  double unitCost;

  double total()const{
    return units*unitCost;
  }
  string date1()const{
    return date;
  }
};

bool compareData(const Data* c1, const Data* c2) {
    //return (c1.total() < c2.total());
   if (c1->total() < c2->total()){
     //cout << "something";
      return true;
    } else if (c1->total() == c2->total()){
      return (c1->date > c2->date);
    } else {
      return false;
    }
      /*
      if (c1.total() < c2.total()){
      return true;
    } else if (c1.total() == c2.total()){
      return c1.date < c2.date;
    } else {
      return false;
    }
      string delimiter = "/";
        string temp;
        string temp2;
        string temp3;
        size_t pos = 0;
        stringstream ss;
        stringstream ss1;
        temp = c1.date;
        pos = temp.find(delimiter);
        temp2 = temp.substr(0,pos);
        temp.erase(0,pos+delimiter.length());

        pos = temp.find(delimiter);
        temp2 = temp.substr(0,pos);
        temp.erase(0,pos+delimiter.length());

        temp2 = c2.date;
        pos = temp2.find(delimiter);
        temp3 = temp2.substr(0,pos);
        temp2.erase(0,pos+delimiter.length());


        pos = temp2.find(delimiter);
        temp3 = temp2.substr(0,pos);
        temp2.erase(0,pos+delimiter.length());
        int x = std::stoi(temp);
        int y = std::stoi(temp2);
      if(x > y){
        return(true);
      } else{
        return(false);
      }
        */
    }


int main() {
  vector<Data*> salesData;

  ifstream infile("SalesDataDyn.csv");
  if (infile.is_open()){
      string line;
      for(int i=0; i<1;i++){
        getline(infile,line);
      }
      while (getline(infile, line)){
        std::istringstream str(line);
        stringstream ss;
        stringstream ss1;
        string unit, unitCosts;
        //Data* data = (Data*)malloc(sizeof(Data));
        Data* data = new Data();
        string delimiter = ", ";
        string delimiter2 = ",";
        size_t pos = 0;
        pos = line.find(delimiter);
        data->date = line.substr(0,pos);
        line.erase(0,pos+delimiter.length());
        pos = line.find(delimiter);
        data->region = line.substr(0,pos);
        line.erase(0,pos+delimiter.length());
        pos = line.find(delimiter);
        data->rep = line.substr(0,pos);
        line.erase(0,pos+delimiter.length());
        pos = line.find(delimiter2);
        data->item = line.substr(0,pos);
        line.erase(0,pos+delimiter2.length());
        pos = line.find(delimiter2);
        unit = line.substr(0,pos);
        line.erase(0,pos+delimiter2.length());
        pos = line.find(delimiter2);
        unitCosts = line.substr(0,pos);
        line.erase(0,pos+delimiter2.length());
        ss << unit;
        int x = 0;
        ss >> x;
        ss1 << unitCosts;
        double y = 0.0;
        ss1 >> y;
        data->units = x;
        data->unitCost = y;
        salesData.push_back(data);
      }


    } else{
        cout << "Falied to read file";
    }

    infile.close();

  cout << "Record: OrderDate, Region, Rep, Item, Units, UnitCost, Total"<< endl;

  sort(salesData.begin(), salesData.end(), compareData);

  for(const auto* data: salesData){
    double total = data->total();
    cout  << "Record: " << data->date << ", " << data->region << ", " << data->rep << ", " << data->item << ", " << data->units << ", " << data->unitCost << ", " << total << "\n";
  }
  for(const auto* data: salesData){
    delete data;
  }

  return 0;
}