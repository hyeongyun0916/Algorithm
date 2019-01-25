#include <iostream>
#include <tuple>

using namespace std;

struct Node {
    int pos;
    int distance;
    int value;
    Node(int _pos, int _distance, int _value)
     : pos(_pos), distance(_distance), value(_value) {}
    bool operator < (const Node &rhs) const {
        return tie(value, distance, pos) < tie(rhs.value, rhs.distance, rhs.pos);
	}
};

int main() {
    return 0;
}