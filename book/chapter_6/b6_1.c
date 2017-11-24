/* 6.1 结构的基本知识　*/
/* ６．２　结构与函数　*/

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};


/* makepoint函数：　通过x,y坐标构造一个点　*/
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}


struct rect screen;
struct point middle;
struct point makepoint(int, int);
screen.pt1 = makepoint(0, 0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                   (screen.pt1.y + screen.pt2.y)/2);


/* addpoint函数：　将两个点相加　*/
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}


/* ptinrect函数：　如果点p在矩形r之内，则返回1，否则返回0 */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect 函数：　将矩形坐标规范化　*/
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.p1.x = min(r.pt1.x, r.pt2.x);
    temp.p1.y = min(r.pt1.y, r.pt2.y);
    temp.p2.x = max(r.pt1.x, r.pt2.x);
    temp.p2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}


struct point origin, *pp;

pp = &origin;
printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
printf("origin is (%d, %d)\n", pp->x, pp->y);


