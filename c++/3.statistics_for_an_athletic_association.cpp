/*You are the "computer expert" of a local Athletic Association (C.A.A.). Many teams of runners come to compete. Each time you get a string of all race results of every team who has run. For example here is a string showing the individual results of a team of 5:

"01|15|59, 1|47|6, 01|17|20, 1|32|34, 2|3|17"

Each part of the string is of the form: h|m|s where h, m, s are positive or null integer (represented as strings) with one or two digits. There are no traps in this format.

To compare the results of the teams you are asked for giving three statistics; range, average and median.

Range : difference between the lowest and highest values. In {4, 6, 9, 3, 7} the lowest value is 3, and the highest is 9, so the range is 9 − 3 = 6.

Mean or Average : To calculate mean, add together all of the numbers in a set and then divide the sum by the total count of numbers.

Median : In statistics, the median is the number separating the higher half of a data sample from the lower half. The median of a finite list of numbers can be found by arranging all the observations from lowest value to highest value and picking the middle one (e.g., the median of {3, 3, 5, 9, 11} is 5) when there is an odd number of observations. If there is an even number of observations, then there is no single middle value; the median is then defined to be the mean of the two middle values (the median of {3, 5, 6, 9} is (5 + 6) / 2 = 5.5).

Your task is to return a string giving these 3 values. For the example given above, the string result will be

"Range: 00|47|18 Average: 01|35|15 Median: 01|32|34"

of the form:

"Range: hh|mm|ss Average: hh|mm|ss Median: hh|mm|ss"

where hh, mm, ss are integers (represented by strings) with each 2 digits.

Remarks:

if a result in seconds is ab.xy... it will be given truncated as ab.
if the given string is "" you will return ""*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int to_time(const std::string& t) {
    int t1;
    std::stringstream ss;
    if (t.size() == 2 && t[0] == 0) {
        ss << t[1];
        ss >> t1;
    }
    else {
        ss << t;
        ss >> t1;
    }
    return t1;
}

struct MyT
{
    int h;
    int m;
    int s;
    MyT(int h0, int m0, int s0):h(h0),m(m0),s(s0) {

    }
    MyT(int s0) {
        h = s0 / (60 * 60);
        m = (s0 - h * 60 * 60) / 60;
        s = s0 - h * 60 * 60 - m * 60;
    }
    int tos() const {
        return h * 60 * 60 + m * 60 + s;
    }

    std::string tostr() const {
        std::stringstream ss;
        if (h < 10) {
            ss << '0' << h << "|";
        }
        else {
            ss << h << "|";
        }

        if (m < 10) {
            ss << '0' << m << "|";
        }
        else {
            ss << m << "|";
        }

        if (s < 10) {
            ss << '0' << s;
        }
        else {
            ss << s;
        }

        return ss.str();
    }
    
};
bool operator < (const MyT& t0, const MyT& t1) {
    if (t0.h < t1.h) {
        return true;
    }
    else if (t0.h > t1.h) {
        return false;
    }
    else {
        if (t0.m < t1.m) {
            return true;
        }
        else if (t0.m > t1.m) {
            return false;
        }
        else {
            if (t0.s < t1.s) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

MyT operator - (const MyT& t0, const MyT& t1) {
    return MyT(t0.tos() - t1.tos());
}

class Stat
{
public:
    static std::string stat(const std::string &strg) {
        if (strg == "") {
            return "";
        }
        std::vector<MyT> tt;
        std::vector<std::string> group;
        split(strg, group, ",");
        for (size_t i=0;i<group.size();++i) {
            std::vector<std::string> ti;
            split(group[i], ti , "|");
            tt.push_back(MyT(to_time(ti[0]), to_time(ti[1]), to_time(ti[2])));
        }

        std::sort(tt.begin(), tt.end());

        int hsum = 0, msum = 0, ssum = 0;
        for (size_t i = 0; i < tt.size(); i++) {
            hsum += tt[i].h;
            msum += tt[i].m;
            ssum += tt[i].s;
        }
        ;
        MyT av((MyT(hsum, msum, ssum).tos())/ tt.size());
        MyT mid = tt[tt.size() / 2];
        if (tt.size() % 2 == 0) {
            mid = MyT((tt[tt.size() / 2 - 1].tos() + tt[tt.size() / 2].tos()) / 2);
        }
        MyT mi = tt[0];
        MyT ma = tt[tt.size()-1];
        MyT range = ma - mi;

        std::stringstream ss;
        ss << "Range: " << range.tostr() << " " <<
            "Average: " << av.tostr() << " " <<
            "Median: " << mid.tostr();
        return ss.str();
    }
};



int main(int argc, char *argv[]) {
    std::string l = "02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41";
    std::cout<<  Stat::stat(l) << std::endl;
    return 0;
}
