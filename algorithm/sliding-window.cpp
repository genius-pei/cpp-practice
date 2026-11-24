#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <cctype>
//using namespace std;
//
//int main() {
//    string line;
//    getline(cin, line);  // 读取一整行，按回车结束输入
//
//    stringstream ss(line);
//    string word;
//    string result = "";
//
//    while (ss >> word) {  // 从这一行中提取每个单词
//        result += toupper(word[0]);
//    }
//
//    cout << result << endl;
//    return 0;
//}

//_________________________________________________
//02
#include <iostream>
#include <vector>
using namespace std;

//int main() {
//    int n, x;
//    cin >> n >> x;
//
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    int minLen = n + 1;
//    int ansL = 0, ansR = 0;
//
//    // 枚举左边界
//    for (int l = 0; l < n; l++) {
//        int sum = 0;
//        // 从 l 开始向右扩展
//        for (int r = l; r < n; r++) {
//            sum += a[r];
//
//            // 如果和 >= x，检查是否更优
//            if (sum >= x) {
//                int curLen = r - l + 1;
//                if (curLen < minLen) {
//                    minLen = curLen;
//                    ansL = l;
//                    ansR = r;
//                }
//                break;  // 从 l 开始已经找到最短的，可以跳出
//            }
//        }
//    }
//
//    cout << ansL + 1 << " " << ansR + 1 << endl;
//    return 0;
//
//}
//_______________________________________
//03
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> evenPQ;  // 只存偶数
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (x % 2 == 0) {
            evenPQ.push(x);  // 只有偶数才加入
        }
    }

    // 每次从偶数堆中取最大的偶数
    while (k > 0 && !evenPQ.empty()) {
        int top = evenPQ.top();
        evenPQ.pop();

        int half = top / 2;
        sum -= half;  // 减少 half

        if (half % 2 == 0) {
            evenPQ.push(half);  // 如果除以2后还是偶数，放回去
        }
        k--;
    }

    cout << sum << endl;
    return 0;
}