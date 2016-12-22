#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct package{
  int arrived_at;
  int started_at;
  int finished_at;
  int processing_time;
}package;

int main()
{
  int s, n;

  vector<package*> set_of_packages;
  queue<package*> q;

  cin >> s >> n;

  for(int i = 0; i < n; i++)
  {
    package* new_package = new package;
    cin >> new_package->arrived_at >> new_package->processing_time;
    set_of_packages.push_back(new_package);
  }

  for(int i = 0; i < n; i++)
  {
    package *current_package = set_of_packages[i];
    int current_time = current_package->arrived_at;

    if(!q.empty())
    {
      package* processed_package = q.front();
      while(!q.empty() && processed_package->finished_at <= current_time)
      {
        q.pop();
        s = s+1;
        processed_package = q.front();
      }

      if(s > 0)
      {
        if(!q.empty())
         current_package->started_at = q.back()->finished_at;
        else
         current_package->started_at = current_package->arrived_at;

        current_package->finished_at = current_package->started_at + current_package->processing_time;

        q.push(current_package);
        s = s-1;
      }
      else
        current_package->started_at = -1;
    }
    else
    {
      current_package->started_at = current_package->arrived_at;
      current_package->finished_at = current_package->arrived_at + current_package->processing_time;
      q.push(current_package);
      s = s-1;
    }

    cout << current_package->started_at << endl;
  }

  return 0;
}