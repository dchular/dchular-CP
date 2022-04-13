#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[100005];
    int y[100005];
    for(int i=0;i<n;i++){
      cin >> x[i] >> y[i];
    }
    int m;
    cin >> m;
    int dpXY[100005];
    long long dp1C[100005];
    long long dp2C[100005];

    // 1-> (x,y)
    // 2-> (-x,y)
    // 3-> (x,-y)
    // 4-> (-x,-y)
    // 5-> (y,x)
    // 6-> (-y,x)
    // 7-> (y,-x)
    // 8-> (-y,-x)
    //
    // 1-> x,y -> y,-x 1->7
    // -x,y -> y,x 2->5
    // x,-y -> -y,-x 3->8
    // -x,-y -> -y,x 4->6
    //
    // x,-y 5->3
    // x,y 6->1
    // -x,-y 7->4
    // -x,y 8->2
    //
    // xy   ->-y  x 1->6
    // -xy  ->-y -x 2->8
    // x-y  -> y  x 3->5
    // -x-y -> y -x 4->7
    // -x  y 5->2
    // -x -y 6->4
    //  x  y 7->1
    //  x -y 8->3
    dpXY[0] = 1;
    dp1C[0] = 0;
    dp2C[0] = 0;

    for(int i=1;i<=m;i++){
      int op;
      cin >> op;
      if(op == 1){
        if(dpXY[i-1] == 1){
          dpXY[i] = 7;
        }
        if(dpXY[i-1] == 2){
          dpXY[i] = 5;
        }
        if(dpXY[i-1] == 3){
          dpXY[i] = 8;
        }
        if(dpXY[i-1] == 4){
          dpXY[i] = 6;
        }
        if(dpXY[i-1] == 5){
          dpXY[i] = 3;
        }
        if(dpXY[i-1] == 6){
          dpXY[i] = 1;
        }
        if(dpXY[i-1] == 7){
          dpXY[i] = 4;
        }
        if(dpXY[i-1] == 8){
          dpXY[i] = 2;
        }

        dp1C[i] = dp2C[i-1];
        dp2C[i] = dp1C[i-1] * -1;
      }

      // 1-> (x,y)
      // 2-> (-x,y)
      // 3-> (x,-y)
      // 4-> (-x,-y)
      // 5-> (y,x)
      // 6-> (-y,x)
      // 7-> (y,-x)
      // 8-> (-y,-x)
      //
      // xy   ->-x  y 1->2
      // -xy  -> x  y 2->1
      // x-y  ->-x -y 3->4
      // -x-y -> x -y 4->3
      // -y  x        5->6
      //  y  x        6->5
      // -y -x        7->8
      //  y -x        8->7
      if(op == 2){
        if(dpXY[i-1] == 1){
          dpXY[i] = 6;
        }
        if(dpXY[i-1] == 2){
          dpXY[i] = 8;
        }
        if(dpXY[i-1] == 3){
          dpXY[i] = 5;
        }
        if(dpXY[i-1] == 4){
          dpXY[i] = 7;
        }
        if(dpXY[i-1] == 5){
          dpXY[i] = 2;
        }
        if(dpXY[i-1] == 6){
          dpXY[i] = 4;
        }
        if(dpXY[i-1] == 7){
          dpXY[i] = 1;
        }
        if(dpXY[i-1] == 8){
          dpXY[i] = 3;
        }

        dp1C[i] = dp2C[i-1] * -1;
        dp2C[i] = dp1C[i-1];
      }
      if(op == 3){
        int p;
        cin >> p;
        // xy   ->-y  x 1->6
        // -xy  ->-y -x 2->8
        // x-y  -> y  x 3->5
        // -x-y -> y -x 4->7
        // -x  y 5->2
        // -x -y 6->4
        //  x  y 7->1
        //  x -y 8->3
        //
        if(dpXY[i-1] == 1){
          dpXY[i] = 2;
        }
        if(dpXY[i-1] == 2){
          dpXY[i] = 1;
        }
        if(dpXY[i-1] == 3){
          dpXY[i] = 4;
        }
        if(dpXY[i-1] == 4){
          dpXY[i] = 3;
        }
        if(dpXY[i-1] == 5){
          dpXY[i] = 6;
        }
        if(dpXY[i-1] == 6){
          dpXY[i] = 5;
        }
        if(dpXY[i-1] == 7){
          dpXY[i] = 8;
        }
        if(dpXY[i-1] == 8){
          dpXY[i] = 7;
        }

        dp1C[i] = -1*dp1C[i-1] + 2*p;
        dp2C[i] = dp2C[i-1];
      }

      if(op == 4){
        int p;
        cin >> p;
        // 1-> (x,y)
        // 2-> (-x,y)
        // 3-> (x,-y)
        // 4-> (-x,-y)
        // 5-> (y,x)
        // 6-> (-y,x)
        // 7-> (y,-x)
        // 8-> (-y,-x)
        //
        // xy   -> x -y 1->3
        // -xy  -> x  y 2->1
        // x-y  -> x y 3->1
        // -x-y -> x -y 4->3
        // -y  x        5->6
        //  y  x        6->5
        // -y -x        7->8
        //  y -x        8->7
        if(dpXY[i-1] == 1){
          dpXY[i] = 3;
        }
        if(dpXY[i-1] == 2){
          dpXY[i] = 4;
        }
        if(dpXY[i-1] == 3){
          dpXY[i] = 1;
        }
        if(dpXY[i-1] == 4){
          dpXY[i] = 2;
        }
        if(dpXY[i-1] == 5){
          dpXY[i] = 7;
        }
        if(dpXY[i-1] == 6){
          dpXY[i] = 8;
        }
        if(dpXY[i-1] == 7){
          dpXY[i] = 5;
        }
        if(dpXY[i-1] == 8){
          dpXY[i] = 6;
        }

        dp1C[i] = dp1C[i-1];
        dp2C[i] = -1*dp2C[i-1] + 2*p;
      }
    }

    // 1-> (x,y)
    // 2-> (-x,y)
    // 3-> (x,-y)
    // 4-> (-x,-y)
    // 5-> (y,x)
    // 6-> (-y,x)
    // 7-> (y,-x)
    // 8-> (-y,-x)
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
      int a,b;
      cin >> b >> a;
      a--;

      if(dpXY[b] == 1){
        cout << x[a] + dp1C[b] << ' ' << y[a] + dp2C[b] << endl;
      }
      if(dpXY[b] == 2){
        cout << -1* x[a] + dp1C[b] << ' ' << y[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 3){
        cout << x[a] + dp1C[b] << ' ' << -1*y[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 4){
        cout << -1*x[a] + dp1C[b] << ' ' << -1*y[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 5){
        cout << y[a] + dp1C[b] << ' ' << x[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 6){
        cout << -1*y[a] + dp1C[b] << ' ' << x[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 7){
        cout << y[a] + dp1C[b] << ' ' << -1*x[a] + dp2C[b]<< endl;
      }
      if(dpXY[b] == 8){
        cout << -1*y[a] + dp1C[b] << ' ' << -1*x[a] + dp2C[b]<< endl;
      }
    }
    return 0;
}
