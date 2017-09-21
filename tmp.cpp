#include <iostream>
#define QUERY(q, a) cout << q << ": "; \
                    cin >> a;

using namespace std;
int main(){
  int a1, a2, a3, a4, test, exam;
  double average;
  double a_weight = 0.2, test_weight = 0.2, exam_weight = 0.6;
  QUERY("a1", a1);
  QUERY("a2", a2);
  QUERY("a3", a3);
  QUERY("a4", a4);
  QUERY("Test", test);
  QUERY("Exam", exam);
  average = (a1 + a2 + a3 + a4) / (double) 4 * a_weight;
  average += test * test_weight;
  average += exam * exam_weight;
  cout << "Average: " << average << endl;
}
