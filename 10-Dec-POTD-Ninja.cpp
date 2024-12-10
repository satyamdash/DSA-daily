int find(int n, vector<int> &position, vector<int> &speed, int d)
{

vector<pair<int,double>>cars;

  for(int i=0;i<n;i++)
  {
      double time=(double)(d-position[i])/speed[i];
      cars.push_back({position[i], time});
  }  

  sort(cars.rbegin(),cars.rend());

 double maxtime=0.0;
 vector<double>times;
for(auto car:cars)
{
    if(car.second>maxtime)
    {
        maxtime=car.second;
        times.push_back(maxtime);
    }
}

return times.size();
}