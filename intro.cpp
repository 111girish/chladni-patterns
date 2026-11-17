#include<iostream>
#include<cmath>
using namespace std;

double chladni_formula(double x, double y, int n, int m){
  const double pi = 3.14159265358979;
  double value= cos(m*pi*x)*cos(n*pi*y) - cos(n*pi*x)*cos(m*pi*y);
  return value;
}

int main() {
  int width = 100, height = 100;
  int n = 2, m = 1;
  for(int i= 0; i<height; i++){
    for(int j=0; j<width; j++){
      double x = (double)j/(width-1); x = 2*x-1;
      double y =(double)i/(height-1); y = 2*y-1;
      int points = chladni_formula(x,y, n, m);
      if(fabs(points) < 0.1){
        cout<<"#";
      }else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}