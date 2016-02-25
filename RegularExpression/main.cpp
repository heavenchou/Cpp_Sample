#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string s ("This is 100 Heaven");
    regex e ("(This)(.*?)(\\d+)(.*ven)");

    // �����r���� : regex_match (s,e)
    if (regex_match (s,e))
        cout << "���W����� OK." << endl;

    smatch sm;    // ����O match_results<string::const_iterator> sm;

    // �O����ﵲ�G
    regex_match (s,sm,e);
    cout << "�ŦX���ƶq�� : " << sm.size() << endl;

    // �v�@�L�X�C�@�ӲŦX�����G, �]�N�O perl �� $0 , $1, $2 ....
    cout << "�ŦX���r�ꬰ : " << endl;

    // for �j��ܤ֦��o�T�إΪk
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
