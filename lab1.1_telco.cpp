#include <bits/stdc++.h>
using namespace std;

bool validPhone(const string &s) {
    if (s.size() != 10) return false;

    for (char c : s) {
        if (!isdigit((unsigned char)c)) return false;
    }

    return true;
}

int timeToSec(const string &t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    int s = stoi(t.substr(6, 2));

    return h * 3600 + m * 60 + s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> numberCalls;
    unordered_map<string, long long> timeCalls;

    long long totalCalls = 0;
    bool allPhonesValid = true;

    string cmd;

    while (cin >> cmd && cmd != "#") {
        if (cmd == "call") {
            string fromNumber, toNumber;
            string date, startTime, endTime;

            cin >> fromNumber >> toNumber >> date >> startTime >> endTime;

            if (!validPhone(fromNumber) || !validPhone(toNumber)) {
                allPhonesValid = false;
            }

            int duration =
                timeToSec(endTime) - timeToSec(startTime);

            numberCalls[fromNumber]++;
            timeCalls[fromNumber] += duration;
            totalCalls++;
        }
    }

    while (cin >> cmd && cmd != "#") {
        if (cmd == "?check_phone_number") {
            cout << (allPhonesValid ? 1 : 0) << '\n';
        }

        else if (cmd == "?number_calls_from") {
            string phone;
            cin >> phone;

            cout << numberCalls[phone] << '\n';
        }

        else if (cmd == "?number_total_calls") {
            cout << totalCalls << '\n';
        }

        else if (cmd == "?count_time_calls_from") {
            string phone;
            cin >> phone;

            cout << timeCalls[phone] << '\n';
        }
    }

    return 0;
}