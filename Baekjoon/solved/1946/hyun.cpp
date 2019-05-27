//���� ���

#include<iostream>
#include<ctime>
using namespace std;

class Employee {
    // ���
public:
    int document;
    int interview;
    bool is_ok;
    Employee() {}
    Employee(int i_doc, int i_int);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int loop;
    cin >> loop; // �ݺ� Ƚ��

    for (int k = 0; k < loop; k++) {
        int person;
        cin >> person; //��� ��
        Employee** e = new Employee*[person];
        cerr << "hi" << '\n';
        //��� ����ŭ �迭 ����

        int how_many = 0; //���� �� �ִ� �ο� ��
        for (int i = 0; i < person; i++) {
            cerr << "hi0" << '\n';
            int doc, inter;
            cin >> doc >> inter;
            for (int j = 0; j < i; j++) {
                if (e[i]->document > e[j]->document && e[i]->interview > e[j]->interview) {
                    cerr << "hi1" << '\n';
                    // ���� ��������, ���ͺ信�� ��� �и��� ���
                    // Ż��
                    e[i]->is_ok = false;
                    break; //�ش� �ݺ����� ���̻� �� �ʿ䰡 ����
                }
                else if (e[i]->document < e[j]->document && e[i]->interview < e[j]->interview) {
                    cerr << "hi2" << '\n';
                    // �ݴ�� ���� �����ڰ� �и��� ���
                    // ���� �����ڴ� Ż���ؾ���
                    if (e[j]->is_ok) {
                        cerr << "hi3" << '\n';
                        e[j]->is_ok = false;; //�ش� �ο� Ż�� (����)
                        how_many--;
                    }
                }
            }
            if (e[i]->is_ok) { //��ο� ������ �� �и��� ������
                how_many++; //���� Ȯ�� ����
                cerr << "hi4" << '\n';
               }
        } // �迭 �Է� �Ϸ�
        cout << how_many << '\n';
    }
    cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
}

Employee::Employee(int i_doc, int i_int) {
    document = i_doc;
    interview = i_int; // �� �Է� ������
    is_ok = true; //�ϴ��� �հ� ����
}