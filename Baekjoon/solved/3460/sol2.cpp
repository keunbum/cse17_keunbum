// ������


#include<iostream>
using namespace std;

int main() {
    int loop;
    cin >> loop;

    while (loop--) {
        int value;
        int pos = 0;
        cin >> value; // �� �Է�
        do {
            if (value % 2 == 1) {
                cout << pos << " "; //1�̸� ���
            }
            pos++;
            value /= 2; // 2������ ����� ����
        } while (value != 0); //��� �� �� ����
    }
}