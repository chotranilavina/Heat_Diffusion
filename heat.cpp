#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<fstream>
#include<boost/tuple/tuple.hpp>
#include"gnuplot.h"

using namespace std;
int main() {
    float h=0.01,time=7200;
    float alpha=1.9*pow(10,-5);
    float dt=((pow(h,2)/(4*alpha))-1);
    int lent=time/dt;
    int lenx=1/h;
    vector<float> Time(time,0);
    for(int i=1;i<Time.size();i++)
    Time[i]=Time[i-1]+dt;
    vector<float> x(lenx,0);
    vector<float> y(lenx,0);
    for(int i=1;i<lenx;i++)
    {
        x[i]=x[i-1]+h;
        y[i]=y[i-1]+h;
    }
    vector<vector<vector<float>>> T(lent,vector<vector<float>>(lenx, vector<float>(lenx,0)));
    for(int i=0;i<lenx;i++)
    for(int j=0;j<lenx;j++)
    {
        if(pow(x[i]-0.5,2)+pow(y[j]-0.5,2)<0.2)
        T[0][i][j]=40.000;
        else
        T[0][i][j]=20.000;
    }
    for(int t=1;t<lent;t++)
    for(int i=1;i<lenx-1;i++)
    for(int j=1;j<lenx-1;j++)
    T[t][i][j]=T[t-1][i][j]*(1-(4*alpha*dt)/(pow(h,2))) + (alpha*dt/pow(h,2))*(T[t][i+1][j]+T[t][i-1][j]+T[t][i][j-1]+T[t][i][j+1]);
    ofstream file;
    file.open("data.dat",ios::out);
    for(int t=0;t<lent;t++)
    {
        for(int i=0;i<lenx;i++)
        for(int j=0;j<lenx;j++)
        {
            string data=to_string(x[i])+ " " +to_string(y[j])+" "+to_string(T[t][i][j]);
            file<<data<<endl;
        }
        file<<endl;
    }
    file.close();
}