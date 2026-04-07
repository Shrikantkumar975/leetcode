class Robot {
public:
    int n, m;

    int x = 0, y = 0, dir = 1;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    Robot(int width, int height) {
        n = width;
        m = height;
    }

    void step(int num) {
        int cycle = 2 * (n + m - 2);
        num %= cycle;

        if (num == 0) {
            if (x == 0 && y == 0)
                dir = 2;
            return;
        }
        while (num > 0) {
            if (dir == 0) {
                int curr = min(num, m - y - 1);
                if (curr == 0) {
                    dir = 3;
                    continue;
                }
                y += curr;
                num -= curr;
                if (num > 0 && y == m - 1)
                    dir = 3;
            } else if (dir == 1) {
                int curr = min(num, n - x - 1);
                if (curr == 0) {
                    dir = 0;
                    continue;
                }
                x += curr;
                num -= curr;
                if (num > 0 && x == n - 1)
                    dir = 0;
            } else if (dir == 2) {
                int curr = min(num, y);
                if (curr == 0) {
                    dir = 1;
                    continue;
                }
                y -= curr;
                num -= curr;
                if (num > 0 && y == 0)
                    dir = 1;
            } else {
                int curr = min(num, x);
                if (curr == 0) {
                    dir = 2;
                    continue;
                }
                x -= curr;
                num -= curr;
                if (num > 0 && x == 0)
                    dir = 2;
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (dir == 0)
            return "North";
        else if (dir == 1)
            return "East";
        else if (dir == 2)
            return "South";
        else
            return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */