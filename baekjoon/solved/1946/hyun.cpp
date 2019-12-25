//신입 사원

#include<iostream>
#include<ctime>
using namespace std;

class Employee {
    // 사원
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
    cin >> loop; // 반복 횟수

    for (int k = 0; k < loop; k++) {
        int person;
        cin >> person; //사람 수
        Employee** e = new Employee*[person];
        cerr << "hi" << '\n';
        //사람 수만큼 배열 생성

        int how_many = 0; //뽑을 수 있는 인원 수
        for (int i = 0; i < person; i++) {
            cerr << "hi0" << '\n';
            int doc, inter;
            cin >> doc >> inter;
            for (int j = 0; j < i; j++) {
                if (e[i]->document > e[j]->document && e[i]->interview > e[j]->interview) {
                    cerr << "hi1" << '\n';
                    // 만약 서류점수, 인터뷰에서 모두 밀리는 경우
                    // 탈락
                    e[i]->is_ok = false;
                    break; //해당 반복문을 더이상 돌 필요가 없음
                }
                else if (e[i]->document < e[j]->document && e[i]->interview < e[j]->interview) {
                    cerr << "hi2" << '\n';
                    // 반대로 앞쪽 참가자가 밀리는 경우
                    // 앞쪽 참가자는 탈락해야함
                    if (e[j]->is_ok) {
                        cerr << "hi3" << '\n';
                        e[j]->is_ok = false;; //해당 인원 탈락 (제거)
                        how_many--;
                    }
                }
            }
            if (e[i]->is_ok) { //모두와 비교했을 때 밀리지 않으면
                how_many++; //뽑힐 확률 있음
                cerr << "hi4" << '\n';
               }
        } // 배열 입력 완료
        cout << how_many << '\n';
    }
    cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
}

Employee::Employee(int i_doc, int i_int) {
    document = i_doc;
    interview = i_int; // 값 입력 생성자
    is_ok = true; //일단은 합격 가능
}