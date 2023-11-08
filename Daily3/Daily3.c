#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    return MAX(ABS(sx - fx), ABS(sy - fy)) <= t && (t != 1 || ABS(sx - fx) + ABS(sy - fy) != 0);
}