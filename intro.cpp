#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct modes {
  double frequency;
  int n;
  int m;
};

vector<modes> retArrOfStr (int maxMode, double k = 3) {
  vector <modes> val;
  for(int i=1; i<=maxMode; i++){
    for(int j=0; j<i; j++){
      modes temp;
      temp.frequency = k * sqrt(i*i + j*j);
      temp.m = i;
      temp.n = j;
      val.push_back(temp);
    }
  }
  return val;
}

modes getStruct(const vector<modes>& vec, double freq){
  double lowest = vec[0].frequency - freq;
  
  for(const auto& val: vec ){
    if(lowest > (fabs(freq-val.frequency))){
      lowest = fabs(freq-val.frequency);
    }
    if(val.frequency==freq){
      return val;
    }
  }
  return;
}

double chladni_formula(double x, double y, int n, int m){
  const double pi = 3.14159265358979;
  double value= cos(m*pi*x)*cos(n*pi*y) - cos(n*pi*x)*cos(m*pi*y);
  return value;
}

vector<vector<int>> getSigns ( int width, int height, int n, int m){
  vector<vector<int>> signs(height, vector<int> (width));
  for(size_t i= 0; i<signs.size(); i++){
    for(size_t j=0; j<signs[0].size();j++){
      double x = (double)j/(width-1);
      double y =(double)i/(height-1);
      double value = chladni_formula(x,y, n, m);
      if(value >= 0){
        signs[i][j] = 1;
      } else {
        signs[i][j] = -1;
      }
    }
  }
  return signs;
}

void printGraph(const vector<vector<int>>& signs){
  for(size_t i=0; i<signs.size(); i++){
    for(size_t j=0; j<signs[0].size(); j++){
      if((i+1 <signs.size() && signs[i+1][j] != signs[i][j]) || (j+1<signs[0].size() && signs[i][j+1] != signs[i][j])){
        cout<<"#";
      } else {
        cout<< " ";
      }
    }
    cout<<endl;
  }
}

int main() {
  vector<modes> val = retArrOfStr(10);
  int width = 100, height = 50;
  vector<vector<int>>signs;
  int n = 20, m = 25;
  signs = getSigns(width, height, n , m);
  printGraph(signs);
  //trying to do the freaking search optimization
  
  return 0;
}