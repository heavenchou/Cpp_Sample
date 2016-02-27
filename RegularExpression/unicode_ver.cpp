#include "unicode_ver.h"

void run_unicode_ver()
{
    cout << endl << "Unicode Version" << endl;

    wstring ws = L"佛陀持鉢至舍衛國";

    wcout << "size:" << ws.size() << endl;  // size : 8 (一個中文字算一個字)

    // 找出部份符合的字串, 並且逐一記錄下來
    wstring s = L"如是我聞，一時佛陀在舍衛國和波斯國及波羅國托鉢";
    wregex e (L"(.{2})國.*?(.{2})國");
    wsmatch sm;
    if(regex_search(s,sm,e))
    {
        cout << "find " << sm.size() << " words." << endl;  // find 3
        for (auto i:sm)
            cout << i.length() << endl; // 7 , 2 , 2
        wstring t = sm.prefix();
        cout << "prefix : " << t.size() << endl;        // 10 : 如是我聞，一時佛陀在
        t = sm.suffix();
        cout << "suffix : " << t.size() << endl;        //  6 : 及波羅國托鉢

        cout << "length : " << sm.length() << endl;     //  7 : 舍衛國和波斯國
        cout << "position : " << sm.position() << endl; //  10
    }
    else cout << "no match word" << endl;

    // 全部取代字串 s/國/大國/g
    // r = regex_replace(s,e,"大國")

    s = L"一時佛在舍衛國和波斯國及波羅國托鉢。";
    e = L"國";

    wstring r = regex_replace(s,e,L"大國");
    if (r == L"一時佛在舍衛大國和波斯大國及波羅大國托鉢。")
        cout << "all replace OK!" << endl;
    else
        cout << "all replace xxxxxxxxxxxxxxx!" << endl;

    // 只取代第一組 (flag)
    e = L"國";
    r = regex_replace(s,e,L"大國",regex_constants::format_first_only);
    if (r == L"一時佛在舍衛大國和波斯國及波羅國托鉢。")
        cout << "first replace OK!" << endl;
    else
        cout << "first replace xxxxxxxxxxxxxxx!" << endl;

    // 處理匹配的內容, 並且把結果放在第一個傳入的參數, 但原始字串要分成頭和尾
    e = L"(舍衛國)(.*)(波斯國)";
    r = L"";
    regex_replace(back_inserter(r),s.begin(),s.end(),e,L"$3$2$1");
    if (r == L"一時佛在波斯國和舍衛國及波羅國托鉢。")
        cout << "change replace OK!" << endl;
    else
        cout << "change replace xxxxxxxxxxxxxxx!" << endl;

    // 只有結果的旗幟 (flag)
    e = L"國";
    r = regex_replace(s,e,L"大國",regex_constants::format_no_copy);
    if (r == L"大國大國大國")
        cout << "no copy replace OK!" << endl;
    else
        cout << "no copy replace xxxxxxxxxxxxxxx!" << endl;

}
