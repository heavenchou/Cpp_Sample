#include <iostream>
#include <regex>
#include "unicode_ver.h"

using namespace std;

int main()
{
    string s = "This is 100 Heaven";
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
    for (auto i:sm) {
        cout << "[" << i << "] " << endl;
    }
    // for 迴圈至少有這三種用法
    /*
    for (unsigned i=0; i<sm.size(); ++i) {
        cout << "[" << sm[i] << "] " << endl;
    }
    for (auto i = sm.begin(); i!=sm.end(); i++) {
        cout << "[" << *i << "] " << endl;
    }
    for (auto i:sm) {
        cout << "[" << i << "] " << endl;
    }
    */

    // 找出部份符合的字串
    s = "This is 100 Heaven";
    e = "\\d+";
    if(regex_search(s,e))
        cout << "找到符合字串 \\d+" << endl;
    else
        cout << "沒找到符合字串" << endl;


    // 找出部份符合的字串, 並且逐一記錄下來
    s = "如是我聞，一時佛在舍衛國和波斯國及波羅國托缽。";
    e = "(.{4})國.*?(.{4})國";
    if(regex_search(s,sm,e))
    {
        cout << "找到 " << sm.size() << " 個符合字串." << endl;
        for (auto i:sm)
            cout << i << endl;
        cout << "prefix : " << sm.prefix() << endl;
        cout << "suffix : " << sm.suffix() << endl;
        cout << "length : " << sm.length() << endl;
        cout << "position : " << sm.position() << endl;
    }
    else cout << "沒找到符合字串" << endl;
    cout << endl;

    // 全部取代字串 s/國/大國/g
    // r = regex_replace(s,e,"大國")

    s = "如是我聞，一時佛在舍衛國和波斯國及波羅國托缽。";
    e = "國";

    string r = regex_replace(s,e,"大國");
    cout << "s:" << s << endl;
    cout << "e:" << "國" << endl;
    cout << "r = regex_replace(s,e,\"大國\")" << endl;
    cout << "r:" << r << endl << endl;

    // 只取代第一組 (flag)
    e = "國";
    r = regex_replace(s,e,"大國",regex_constants::format_first_only);
    cout << "s:" << s << endl;
    cout << "e:" << "國" << endl;
    cout << "r = regex_replace(s,e,\"大國\",regex_constants::format_first_only)" << endl;
    cout << "r:" << r << endl << endl;


    // 處理匹配的內容, 並且把結果放在第一個傳入的參數, 但原始字串要分成頭和尾
    e = "(舍衛國)(.*)(波斯國)";
    r="";
    regex_replace(back_inserter(r),s.begin(),s.end(),e,"$3$2$1",regex_constants::format_first_only);
    cout << "s:" << s << endl;
    cout << "e:" << "(舍衛國)(.*)(波斯國)" << endl;
    cout << "regex_replace(back_inserter(r),s.begin(),s.end(),e,\"$3$2$1\")" << endl;
    cout << "r:" << r << endl << endl;


    // 只有結果的旗幟 (flag)
    e = "國";
    r = regex_replace(s,e,"大國",regex_constants::format_no_copy);
    cout << "s:" << s << endl;
    cout << "e:" << "國" << endl;
    cout << "r = regex_replace(s,e,\"大國\",regex_constants::format_no_copy)" << endl;
    cout << "r:" << r << endl << endl;  // r = "大國大國大國"

    run_unicode_ver();

    cout << endl;
    return 0;
}
