//??????????????????????????
#include <algorithm>
#define ?(?, ?, ?) fill(?, ?, ?)
//#define ?(?, ?, ?) find(?, ?, ?)
#define ?(??, ?) for_each(?(??), ?(??) + ?, [](? ?) { ??(?) << " "; })
#define ??(?, ?, ??) lower_bound(?, ?, ??)
#define ??(?, ?) max_element(?, ?)
//#define ?(??, ??, ??, ??) merge(??, ??, ??, ??, back_inserter(?))
#define ??(?, ?) min_element(?, ?)
#define ?(?, ?) reverse(?, ?)
#define ??(?, ?, ??) sort(?, ?, ??)
#define ??(?, ?) sort(?, ?, greater<?>())
#define ?(?, ?) unique(?, ?)
#define ??(?, ?, ??) upper_bound(?, ?, ??)

//???
#include <climits>

//??,???????????????
#include <cmath>
#define ??(?) abs(?)
#define ??(?) floor(?)
#define ??(?) ceil(?)
#define ?(?) sqrt(?)
#define ??(??) sin(??)
#define ??(??) cos(??)

//??????
#include <iostream>
#define ??(?) cin >> ?
#define ??(?) cout << ?

//???
#include <iterator>
#define ?(???) (???).begin()
#define ?(???) (???).end()

//??,??????????????????????????
#include <map>
#define ?(?) count(?);

//??,????????????????????
#include <queue>
#define ?(??) ??.pop()
#define ?(??, ?) ??.push(?)
#define ?(??) ??.front()

//?,???????????
#include <stack>
#define ?(??) ??.top()

//?,????????,???
#include <set>
//#define ?(?, ?) ?.find(?)

//???????????????
#include <string>
#define ?(??) ??.length()
#define ??(??, ?, ?) ??.substr(?, ?)

//??,????????????????????????
#include <utility>
#define ?(?) ?.first
#define ?(?) ?.second
#define ?(?, ?) make_pair(?, ?)
#define ?(?, ?) swap(?, ?)

//??,????????
#include <vector>
#define ?(??) (??).clear()
#define ?(??) ??.empty()
#define ?(??, ?) ??.erase(?)
#define ?(??, ?) ??.insert(?)
#define ?(??, ?) ??.push_back(?)
#define ??(??, ?) ??.resize(?)

//??
#define ?(??) if (??)
#define ??(??) else if (??)
#define ? else

//??
#define ?(??, ?, ?) for (? ?? ? ?; ?? <= ?; ?? ? ?? + 1)
#define ??(??, ?, ?) for (? ?? ? ?; ?? >= ?; ?? ? ?? - 1)
#define ?(??) while (??)
#define ? break
#define ? continue

//??
#define ?() main()
#define ? return

//???
#define ? =
#define ? ==
#define ? &&
#define ? ||
#define ? &
#define ? <<
#define ?? >>

#define ? struct
#define ? const
#define ? true
#define ? false
#define ?? endl

//???
using namespace std;

//????
typedef bool ?;
typedef char ?;
typedef double ?;
typedef int ??;
typedef long long ?;
typedef string ??;
typedef void ?;
typedef map<?, ?> ??;
typedef map<?, ??> ??;
typedef pair<?, ?> ??;
typedef pair<?, ?> ??;
typedef pair<?, ?> ???;
typedef priority_queue<?> ??;
typedef queue<?> ??;
typedef queue<??> ???;
typedef set<?> ??;
typedef stack<?> ??;
typedef vector<?> ??;
typedef vector<??> ???;
typedef vector<???> ????;
typedef vector<?> ??;
typedef vector<??> ???;
typedef vector<?> ??;
typedef vector<??> ???;
typedef vector<??> ???;
typedef vector<??> ???;
typedef vector<??> ???;
typedef vector<???> ????;
typedef vector<???> ????;
typedef vector<?> ??;
typedef vector<??> ???;

? ? { ? ?, ?; };
typedef vector<?> ?;

? ??(? ?, ? ?) { ? max(?, ?); }
? ??(? ?, ? ?) { ? min(?, ?); }

//? ? ?? = LLONG_MAX;
//? ? ? = 1000000007;
//? ? ?? = 1e-9;
//? ? ?? = acos(-1.0);
//? ? ? = 100;
//? ? ? = 1000;
//? ? ? = 10000;
//? ? ? = 100000000;
//? ? ??[4] = {1, 0, -1, 0};
//? ? ??[4] = {0, -1, 0, 1};
? ?, ??;

? ????()
{
    ??(?) >> ??;
}

? ??(?? &??, ?? &??)
{
    ? ?(??) < ?(??);
}

?? ?()
{
    ????();
    ??? ?(??);
    ?(?, 0, ?? - 1)
    {
        ? a, b;
        ??(a) >> b;
        ?(?[?])
        ? a;
        ?(?[?])
        ? b;
    }
    ??(?(?), ?(?), ??);

    ? ? ? ?(?[0]) - 1;
    ? ? ? 1;
    ?(?, 1, ?? - 1)
    {
        ?(? < ?(?[?]))
        {
            ? ? ?(?[?]) - 1;
            ? ? ? + 1;
        }
    }

    ??(?) << ??;
    ? 0;
}