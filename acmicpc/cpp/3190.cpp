#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

// template class priority_queue<Node>;

struct Point
{
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Point &rhs) const
    {
        return tie(x, y) < tie(rhs.x, rhs.y);
    }
};

char changeDirection(char origin, char rotate)
{
    string directions = "urdlurdlurdl";
    int runningTime = rotate == 'D' ? 1 : -1;
    return directions[directions.find(origin, 3) + runningTime];
}

void printSet(set<Point> set)
{
    cout << "----" << endl;
    for (Point el : set)
    {
        cout << el.x << ' ' << el.y << endl;
    }
    cout << "----" << endl;
}

int main()
{
    int N;
    cin >> N;

    set<Point> apple;
    int n_apple;
    cin >> n_apple;
    for (int i = 0; i < n_apple; i++)
    {
        int a, b;
        cin >> a >> b;
        apple.insert(Point(b, a));
    }

    char direction = 'r';
    map<int, char> direction_map;
    int n_direction;
    cin >> n_direction;
    for (int i = 0; i < n_direction; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        direction_map[a] = b;
    }

    set<Point> snake_set;
    queue<Point> snake_q;

    int runningTime = 0;
    int x = 1, y = 1;
    snake_q.push(Point(x, y));
    snake_set.insert(Point(x, y));

    while (true)
    {
        runningTime++;

        switch (direction)
        {
        case 'u':
            y--;
            break;
        case 'r':
            x++;
            break;
        case 'd':
            y++;
            break;
        default:
            x--;
            break;
        }
        // cout << runningTime << ' ' << snake_set.size() << ' ' << x << ' ' << y << endl;
        if (x == N + 1 || y == N + 1 || x == 0 || y == 0 || snake_set.find(Point(x, y)) != snake_set.end())
        {
            cout << runningTime << endl;
            return 0;
        }

        Point point = Point(x, y);
        snake_q.push(point);
        snake_set.insert(Point(x, y));

        // exist apple
        if (apple.find(point) != apple.end())
        {
            apple.erase(point);
        }
        else
        {
            snake_set.erase(snake_q.front());
            snake_q.pop();
        }

        if (direction_map.find(runningTime) != direction_map.end())
        {
            direction = changeDirection(direction, direction_map[runningTime]);
        }
    }

    return 0;
}