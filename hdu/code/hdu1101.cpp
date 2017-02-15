#include <math.h>
#include <stdio.h>
#define eps (1e-8)
#define pi 3.1415926536
struct rectangle {
    double x1, x2, y1, y2;
} b, g[800];
double x, y, l[1005], r[1005];
void adjust(rectangle & r) {
    double t;
    if (r.x1 - r.x2 > eps) {
        t = r.x1;
        r.x1 = r.x2;
        r.x2 = t;
    }
    if (r.y1 - r.y2 > eps) {
        t = r.y1;
        r.y1 = r.y2;
        r.y2 = t;
    }
}
int pos(rectangle a) {
    if ((a.x1 - x <= eps)  && (x - a.x2 <= eps) && (a.y1 - y <= eps) && (y - a.y2 <= eps)) {
        return 0;
    }
    if (x - a.x1 < eps) {
        if (y > a.y2) {
            return 8;
        } else if (y - a.y1 < eps) {
            return 6;
        } else {
            return 7;
        }
    } else if (x - a.x2 > eps) {
        if (y > a.y2) {
            return 2;
        } else if (y - a.y1 < eps) {
            return 4;
        } else {
            return 3;
        }
    } else {
        if (y - a.y2 > eps) {
            return 1;
        } else {
            return 5;
        }
    }
}
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf%lf", &b.x1, &b.y1, &b.x2, &b.y2);
        adjust(b);
        scanf("%lf%lf%d", &x, &y, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf%lf", &g[i].x1, &g[i].y1, &g[i].x2, &g[i].y2);
            adjust(g[i]);
            g[i + n].x1 = g[i].x1;
            g[i + n].y1 = 2 * b.y1 - g[i].y1;
            g[i + n].x2 = g[i].x2;
            g[i + n].y2 = 2 * b.y1 - g[i].y2;
            adjust(g[i + n]);
            g[i + 2 * n].x1 = g[i].x1;
            g[i + 2 * n].y1 = 2 * b.y2 - g[i].y1;
            g[i + 2 * n].x2 = g[i].x2;
            g[i + 2 * n].y2 = 2 * b.y2 - g[i].y2;
            adjust(g[i + 2 * n]);
            g[i + 3 * n].x1 = 2 * b.x1 - g[i].x1;
            g[i + 3 * n].y1 = g[i].y1;
            g[i + 3 * n].x2 = 2 * b.x1 - g[i].x2;
            g[i + 3 * n].y2 = g[i].y2;
            adjust(g[i + 3 * n]);
            g[i + 4 * n].x1 = 2 * b.x2 - g[i].x1;
            g[i + 4 * n].y1 = g[i].y1;
            g[i + 4 * n].x2 = 2 * b.x2 - g[i].x2;
            g[i + 4 * n].y2 = g[i].y2;
            adjust(g[i + 4 * n]);
        }
        n *= 5;
        int m = 0;
        bool flag = false;
        double a1, a2;
        for (int i = 1; i <= n; i++) {
            int tmp = pos(g[i]);
            if (tmp == 0) {
                flag = true;
                break;
            } else if (tmp == 1) {
                m++;
                a1 = atan2(y - g[i].y2, x - g[i].x1);
                a2 = atan2(y - g[i].y2, g[i].x2 - x);
                l[m] = pi + a1;
                r[m] = 2 * pi - a2;
            } else if (tmp == 2) {
                m++;
                a1 = atan2(y - g[i].y2, x - g[i].x1);
                a2 = atan2(x - g[i].x2, y - g[i].y1);
                l[m] = pi + a1;
                r[m] = 1.5 * pi - a2;
            } else if (tmp == 3) {
                m++;
                a1 = atan2(x - g[i].x2, g[i].y2 - y);
                a2 = atan2(x - g[i].x2, y - g[i].y1);
                l[m] = 0.5 * pi + a1;
                r[m] = 1.5 * pi - a2;
            } else if (tmp == 4) {
                m++;
                a1 = atan2(x - g[i].x2, g[i].y2 - y);
                a2 = atan2(g[i].y1 - y, x - g[i].x1);
                l[m] = 0.5 * pi + a1;
                r[m] = pi - a2;
            } else if (tmp == 5) {
                m++;
                a1 = atan2(g[i].y1 - y, g[i].x2 - x);
                a2 = atan2(g[i].y1 - y, x - g[i].x1);
                l[m] = a1;
                r[m] = pi - a2;
            } else if (tmp == 6) {
                m++;
                a1 = atan2(g[i].y1 - y, g[i].x2 - x);
                a2 = atan2(g[i].x1 - x, g[i].y2 - y);
                l[m] = a1;
                r[m] = 0.5 * pi - a2;
            } else if (tmp == 7) {
                m++;
                a1 = atan2(g[i].y2 - y, g[i].x1 - x);
                l[m] = 0;
                r[m] = a1;
                m++;
                a2 = atan2(y - g[i].y1, g[i].x1 - x);
                l[m] = 2 * pi - a2;
                r[m] = 2 * pi;
            } else {
                m++;
                a1 = atan2(g[i].x1 - x, y - g[i].y1);
                a2 = atan2(y - g[i].y2, g[i].x2 - x);
                l[m] = 1.5 * pi + a1;
                r[m] = 2 * pi - a2;
            }
        }
        if (flag) {
            printf("100.00%%\n");
        } else {
            double tot = 0, t, ll, rr;
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (l[i] - l[j] > eps) {
                        t = l[i];
                        l[i] = l[j];
                        l[j] = t;
                        t = r[i];
                        r[i] = r[j];
                        r[j] = t;
                    }
                }
            }
            ll = l[1];
            rr = r[1];
            m++;
            l[m] = 361;
            r[m] = 461;
            for (int i = 2; i <= m; i++) {
                if (l[i] - rr <= eps) {
                    if (rr - r[i] < eps) {
                        rr = r[i];
                    }
                } else {
                    tot += (rr - ll);
                    ll = l[i];
                    rr = r[i];
                }
            }
            printf("%.2lf%%\n", tot * 50 / pi);
        }
    }
    return 0;
}