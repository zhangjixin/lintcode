/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        unordered_map<double, int> umap;
        int n = points.size(), cnt = 0, lineY = 0, ans = 0;
        double diffX = 0, diffY = 0;
        for (int i = 0; i < n; ++i) {
            cnt = 1, lineY = 0;
            umap.clear();
            for (int j = i+1; j < n; ++j) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    ++cnt;
                    continue;
                }
                diffX = points[j].x - points[i].x;
                diffY = points[j].y - points[i].y;
                if (diffX == 0) {
                    ++lineY;
                }
                else {
                    ++umap[diffY / diffX];
                }
            }
            for (auto it = umap.begin(); it != umap.end(); ++it) {
                if (ans <= it->second)
                    ans = it->second + cnt;
            }
            if (ans <= lineY)
                ans = lineY + cnt;
        }
        return ans;
    }
};
