#pragma once
#include <iostream>
using namespace std;

class Store
{



public:
    string id; //identified
    int num_products; // number of products
    float* prices = nullptr; // price of each product


    // TODO: implement the following functions (Details mentioned in the question text above).
    // 1. default constructor
   Store(){
       id = "default";
       num_products = 10;
       prices = new float[10];
       for(int i = 0; i < 10; i++){
          prices[i] = 0;
       }
    }

    // 2. Parameterized constructor
    Store(string name, int num, float* array){
       id = name;
       num_products = num;
       prices = new float[num_products];
       for(int i = 0; i < 10; i++){
          prices[i] = array[i];
       }
    }

    Store(const Store& param){
     this->id = param.id;
     this->num_products = param.num_products;
     prices = new float[num_products];
     for(int i = 0; i < num_products; i++){
        this->prices[i] = param.prices[i];
     }
    }

    // 3. Assignment operator
   Store& operator=(const Store& param){

      if(this != &param){
         delete[] prices;


       this->id = param.id;
       this->num_products = param.num_products;
       prices = new float[this->num_products];
        for(int i = 0; i < this->num_products ; i++){
          this->prices[i] = param.prices[i];
       }

   }
    return *this;
   }

    ~Store()
    {
        delete[] prices;
    }


    void print() {
        cout << this->id << ", [";
        for(int i = 0; i < num_products; i++) {
            cout << prices[i] << ", ";
        }
        cout << "]" << endl;
    }

};