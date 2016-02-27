#include <iostream>
#include <regex>
#include "unicode_ver.h"

using namespace std;

int main()
{
    string s = "This is 100 Heaven";
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
    for (auto i:sm) {
        cout << "[" << i << "] " << endl;
    }
    // for �j��ܤ֦��o�T�إΪk
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

    // ��X�����ŦX���r��
    s = "This is 100 Heaven";
    e = "\\d+";
    if(regex_search(s,e))
        cout << "���ŦX�r�� \\d+" << endl;
    else
        cout << "�S���ŦX�r��" << endl;


    // ��X�����ŦX���r��, �åB�v�@�O���U��
    s = "�p�O�ڻD�A�@�ɦ�b�ٽð�M�i����Ϊiù�ꦫ�ڡC";
    e = "(.{4})��.*?(.{4})��";
    if(regex_search(s,sm,e))
    {
        cout << "��� " << sm.size() << " �ӲŦX�r��." << endl;
        for (auto i:sm)
            cout << i << endl;
        cout << "prefix : " << sm.prefix() << endl;
        cout << "suffix : " << sm.suffix() << endl;
        cout << "length : " << sm.length() << endl;
        cout << "position : " << sm.position() << endl;
    }
    else cout << "�S���ŦX�r��" << endl;
    cout << endl;

    // �������N�r�� s/��/�j��/g
    // r = regex_replace(s,e,"�j��")

    s = "�p�O�ڻD�A�@�ɦ�b�ٽð�M�i����Ϊiù�ꦫ�ڡC";
    e = "��";

    string r = regex_replace(s,e,"�j��");
    cout << "s:" << s << endl;
    cout << "e:" << "��" << endl;
    cout << "r = regex_replace(s,e,\"�j��\")" << endl;
    cout << "r:" << r << endl << endl;

    // �u���N�Ĥ@�� (flag)
    e = "��";
    r = regex_replace(s,e,"�j��",regex_constants::format_first_only);
    cout << "s:" << s << endl;
    cout << "e:" << "��" << endl;
    cout << "r = regex_replace(s,e,\"�j��\",regex_constants::format_first_only)" << endl;
    cout << "r:" << r << endl << endl;


    // �B�z�ǰt�����e, �åB�⵲�G��b�Ĥ@�ӶǤJ���Ѽ�, ����l�r��n�����Y�M��
    e = "(�ٽð�)(.*)(�i����)";
    r="";
    regex_replace(back_inserter(r),s.begin(),s.end(),e,"$3$2$1",regex_constants::format_first_only);
    cout << "s:" << s << endl;
    cout << "e:" << "(�ٽð�)(.*)(�i����)" << endl;
    cout << "regex_replace(back_inserter(r),s.begin(),s.end(),e,\"$3$2$1\")" << endl;
    cout << "r:" << r << endl << endl;


    // �u�����G���X�m (flag)
    e = "��";
    r = regex_replace(s,e,"�j��",regex_constants::format_no_copy);
    cout << "s:" << s << endl;
    cout << "e:" << "��" << endl;
    cout << "r = regex_replace(s,e,\"�j��\",regex_constants::format_no_copy)" << endl;
    cout << "r:" << r << endl << endl;  // r = "�j��j��j��"

    run_unicode_ver();

    cout << endl;
    return 0;
}
