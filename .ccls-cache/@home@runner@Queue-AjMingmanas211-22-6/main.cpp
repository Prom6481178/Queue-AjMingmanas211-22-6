#include <iostream>
using namespace std;
#include "queue.h"

int main(int argc, char *argv[]) {
  Queue q;
  int i, price, order;

  int customer = 1;
  for (i = 1; i < argc; i++) {
    if (argv[i][0] == 'x') {
      order = q.node()->order_number();
      price = q.dequeue();
      cout << "Customer No." << customer++ << endl;
      switch (order) {
      case 1:
        cout << "Ramen" << endl;
        break;
      case 2:
        cout << "Somtum" << endl;
        break;
      case 3:
        cout << "Fried Chicken" << endl;
        break;
      }
      cout << "You have to pay " << price << endl;
      int money, change;
      do {
        cout << "Cash: ";
        cin >> money;
        if (money < price)
          continue;
        if (money > price) {
          change = money - price;
          cout << "Change: " << change << endl;
          cout << "Thank you" << endl;
          break;
        }
        if (money == price) {
          cout << "Thank you" << endl;
          break;
        }
      } while (1);

    } else {
      q.enqueue(atoi(argv[i]), atoi(argv[i + 1]));
      i++;
    }
  }
  cout << "====================================" << endl;
  if (q.getSize()!=0)
    cout << "There are " << q.getSize() << " customers left in the queue"
         << endl;

  // ask the customer to pay
}

// cout<<"End of program"<<endl;
