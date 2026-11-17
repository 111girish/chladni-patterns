#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int width = 100, height = 100;
  int n = 2, m = 3;
  const double pi = 3.14159265358979;
  for(int i= 0; i<height; i++){
    for(int j=0; j<width; j++){
      double x = (double)j/(width-1); x = 2*x-1;
      double y =(double)i/(height-1); y = 2*y-1;
      double points = cos(m*pi*x)*cos(n*pi*y) - cos(n*pi*x)*cos(m*pi*y);
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