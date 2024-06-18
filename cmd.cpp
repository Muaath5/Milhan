#include <bits/stdc++.h>
#include <ctime>
#include <time.h>
#define ll long long
using namespace std;

// 2024/6/18 == 2
const int INIT = 19892;

const ll SEC_PER_DAY = 86400;

ll curday() {
    return time(0)/SEC_PER_DAY;
}

ll input_date() {
    ll curunix = time(0);
    printf("Input date (YYYY/M/D): ");
    ll y=0, m=0, d=0;
    if (scanf("%lld/%lld/%lld", &y, &m, &d) != 3)
        return curday();
    tm c = *localtime(&curunix);
    c.tm_year = y - 1900;
    c.tm_mon = m-1;
    c.tm_mday = d;
    const ll unix = mktime(&c);
    return unix/SEC_PER_DAY;
}

bool is_us(ll day_id) {
    return ((day_id - INIT) / 7) % 2 == 1;
}

int main()
{
    bool u = is_us(input_date());
    printf(u ? "Us" : "Them");
}