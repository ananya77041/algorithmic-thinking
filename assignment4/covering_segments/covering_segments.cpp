#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

struct {
  bool operator()(Segment a, Segment b)
    {   
      return a.end < b.end;
    }   
} SortByRight;

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int max_point = -1;
  sort (segments.begin(), segments.end(), SortByRight);
  for (int i = 0; i < segments.size(); ++i) {
    if (!(segments[i].start <= max_point)) {
      max_point = segments[i].end;
      points.push_back(segments[i].end);
    }
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
