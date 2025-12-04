class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;

        for (char c : directions) {

            if (c == 'R') {
                st.push(c);
            }

            else if (c == 'S') {
                // All previous R's will collide and stop
                while (!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            }

            else { // c == 'L'
                if (st.empty()) {
                    // L moves off — no collision
                    continue;
                }

                if (st.top() == 'R') {
                    // One R meets this L -> 2 collisions
                    ans += 2;
                    st.pop();

                    // Any more R's behind -> each adds 1 collision
                    while (!st.empty() && st.top() == 'R') {
                        ans++;
                        st.pop();
                    }

                    // Collided cars become stopped
                    st.push('S');
                }
                else if (st.top() == 'S') {
                    // S stops the L -> 1 collision
                    ans++;
                    st.push('S');
                }
                else {
                    // L meeting L -> no collision
                    st.push('L');
                }
            }
        }
        return ans;
    }
};
