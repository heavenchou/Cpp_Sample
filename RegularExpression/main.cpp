#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string s ("This is 100 Heaven");
    regex e ("(This)(.*?)(\\d+)(.*ven)");

    // 全部字串比對 : regex_match (s,e)
    if (regex_match (s,e))
        cout << "正規式比對 OK." << endl;

    smatch sm;    // 等於是 match_results<string::const_iterator> sm;

    // 記錄比對結果
    regex_match (s,sm,e);
    cout << "符合比對數量為 : " << sm.size() << endl;

    // 逐一印出每一個符合的結果, 也就是 perl 的 $0 , $1, $2 ....
    cout << "符合的字串為 : " << endl;

    // for 迴圈至少有這三種用法
    for (unsigned i=0; i<sm.size(); ++i) {
        cout << "[" << sm[i] << "] " << endl;
    }
    for (auto i:sm) {
        cout << "[" << i << "] " << endl;
    }
    for (auto i = sm.begin(); i!=sm.end(); i++) {
        cout << "[" << *i << "] " << endl;
    }

    cout << endl;
    return 0;
}
